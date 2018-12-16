#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox_2->hide();
    Map = new Graph;

    QButtonGroup *bg = new QButtonGroup(this);
    Switch* item1 = new Switch("Edit Menu", this);
    Switch* item2 = new Switch("Departure", this);
    bg->addButton(item1);
    bg->addButton(item2);

    item1->setGeometry(1100,10,200,30);
    item2->setGeometry(1100,40,200,30);

    item1->toggleSwitch(Qt::Unchecked);
    

    connect(item1, SIGNAL(clicked(bool)), this, SLOT(showEditMenu()));
    connect(item2, SIGNAL(clicked(bool)), this, SLOT(showDepartMenu()));

//    mySwitch = new Switch(this);
//    mySwitch->setGeometry(1150,20,50,30);
//    mySwitch->show();



    QSize newSize( 1280, 720 );
        setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                newSize,
                qApp->desktop()->availableGeometry()
            )
        );



    connect(ui->VertexNameBox, SIGNAL(returnPressed()), ui->pushButton, SIGNAL(clicked()));
    connect(ui->DestinationNameBox, SIGNAL(returnPressed()), ui->pushButton_2, SIGNAL(clicked()));

    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEditMenu()
{
    ui->groupBox->show();
    ui->groupBox_2->hide();
}

void MainWindow::showDepartMenu()
{
    ui->groupBox_2->show();
    ui->groupBox->hide();
}

void MainWindow::updateGraphWeights()
{
    VertexNODE* currentVertex = Map->getRoot();
    while (currentVertex)
    {
        EdgeNODE* currentEdge = (EdgeNODE*)currentVertex->header;
        QPoint SourceCenter = currentVertex->visualNode->geometry().center();
        while (currentEdge)
        {
            QPoint DestinationCenter = currentEdge->address->visualNode->geometry().center();

            double Weight = sqrt( pow(SourceCenter.x() - DestinationCenter.x(), 2) + pow(SourceCenter.y() - DestinationCenter.y(), 2) );
            currentEdge->weight = Weight;

            currentEdge = currentEdge->nextEdge;
        }
        currentVertex = currentVertex->nextVertex;
    }
    //this->update();
}

bool MainWindow::animatePlane(string path)
{
    int i = path.length();
    QTimer *AnimationTimer = new QTimer;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->VertexNameBox->text() != "")
    {
        DraggableLabel *temp = new DraggableLabel(this);
        temp->setText(ui->VertexNameBox->text().at(0));
        temp->setStyleSheet("color:black;"
                            "background-color:red;"
                            "font: bold 15px arial;"
                            "border: solid 1px red;"
                            "border-radius: 15px;"
                            "qproperty-alignment: 'AlignHCenter | AlignVCenter';"
                            "qproperty-wordWrap: true;"

                            );
        temp->setGeometry(50 + posX,50 + posY,30,30);
        posX+= 50;

        if(posX >950)
        {
            posX = 0;
            posY+=50;
        }

        temp->show();

        char myChar = (ui->VertexNameBox->text().toStdString())[0];
        Map->InsertVertex(myChar, temp);

        ui->SourceCombo->addItem(ui->VertexNameBox->text());
        ui->DestinationCombo->addItem(ui->VertexNameBox->text());


        ui->VertexNameBox->setText("");
    }
    else
    {
        this->update();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->SourceNameBox->text() != "" && ui->DestinationNameBox->text() != "")
    {
        char Source = ui->SourceNameBox->text().toStdString()[0];
        char Destination = ui->DestinationNameBox->text().toStdString()[0];

        QPoint SourceCenter = Map->searchVertex(Source)->visualNode->geometry().center();
        QPoint DestinationCenter = Map->searchVertex(Destination)->visualNode->geometry().center();

        double distance = sqrt( pow(SourceCenter.x() - DestinationCenter.x(), 2) + pow(SourceCenter.y() - DestinationCenter.y(), 2) );

        Map->InsertEdge(Source, Destination, distance);

        //EdgeNODE* temp = (EdgeNODE*)Map->getRoot()->header;

        ui->SourceNameBox->setText("");
        ui->DestinationNameBox->setText("");
        this->update();
    }
    else
    {
        updateGraphWeights();
        this->update();
    }
}






void MainWindow::on_pushButton_3_clicked()
{
    char SourceName = ui->SourceCombo->currentText().toStdString()[0];
    char DestinationName = ui->DestinationCombo->currentText().toStdString()[0];

    VertexNODE* SourceVertex =  Map->searchVertex(SourceName);
    VertexNODE* DestinationVertex =  Map->searchVertex(DestinationName);

    QRect SourceGeometry = SourceVertex->visualNode->geometry();
    SourceGeometry.adjust(10,10,-10,-10);

    QRect DetinationGeometry = DestinationVertex->visualNode->geometry();
    DetinationGeometry.adjust(10,10,-10,-10);

    QLabel *temp = new QLabel(this);

    temp->show();

    temp->setStyleSheet(
                "color:green;"
                "background-color:light-green;"
                "font: bold 10px arial;"
                "border: solid 1px green;"
                "border-radius: 5px;"
                "qproperty-alignment: 'AlignHCenter | AlignVCenter';"
                "qproperty-wordWrap: true;"
                );

    std::string path = Map->DjikstraShortestPath(SourceName,DestinationName);

    animatePlane(path);

    QPropertyAnimation *animation = new QPropertyAnimation(temp, "geometry");
    animation->setDuration(20000);
    animation->setStartValue(SourceGeometry);
    animation->setEndValue(DetinationGeometry);



    animation->start();

    connect(animation,SIGNAL(finished()), this, SLOT());


}
