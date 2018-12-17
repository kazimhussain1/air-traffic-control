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


    Schedule = new LinkedList;


    QXlsx::Document myDocument("Test.xlsx");

    if (myDocument.isLoadPackage())
    {
        int i =1;
        while(true)
        {
            QXlsx::Cell* Cell1 = myDocument.cellAt(i,1);
            QXlsx::Cell* Cell2 = myDocument.cellAt(i,2);
            QXlsx::Cell* Cell3 = myDocument.cellAt(i,3);
            QXlsx::Cell* Cell4 = myDocument.cellAt(i,4);


            if(Cell1 == NULL || Cell2 == NULL || Cell3 == NULL || Cell4 == NULL)
                break;
            QVariant VariantS = Cell1->value();
            QVariant VariantD = Cell2->value();
            QVariant Variant1 = Cell3->value();
            QVariant Variant2 = Cell4->value();


            QString Source = VariantS.toString();
            QString Destination = VariantD.toString();

            QString myTime = Variant1.toString();
            QString myDate = Variant2.toString();

            QDate date = QDate::fromString(myDate,"dd.MM.yyyy");
            QTime time = QTime::fromString(myTime,"hh:mm:ss");

            QDateTime temp(date,time);

            Schedule->insert(Source.toStdString()[0], Destination.toStdString()[0], temp);

            i++;
        }


        Schedule->BubbleSort();
    }

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


void MainWindow::animatePlane(int& i,int& count,std::string& path, bool& finished, QLabel* dot, QPropertyAnimation* Animator)
{

    if((i < count-1 &&  finished) || i == 0)
    {

        dot->hide();


        finished = false;
        dot->close();
        dot->clear();

        emit deleteDot();
        dot->setWindowOpacity(0);
        dot->setStyleSheet("background-color: rgba(255,255,255,1);"
                           "color: rgba(0,0,0,0)");
        char SourceName = path[i];
        char DestinationName = path[i+1];

        VertexNODE* SourceVertex =  Map->searchVertex(SourceName);
        VertexNODE* DestinationVertex =  Map->searchVertex(DestinationName);

        QRect SourceGeometry = SourceVertex->visualNode->geometry();
        SourceGeometry.adjust(10,10,-10,-10);

        QRect DetinationGeometry = DestinationVertex->visualNode->geometry();
        DetinationGeometry.adjust(10,10,-10,-10);

        dot = new QLabel(this);
        connect(this, SIGNAL(deleteDot()), dot, SLOT(close()));

        dot->show();

        dot->setStyleSheet(
                    "color:green;"
                    "background-color:black;"
                    "font: bold 10px arial;"
                    "border: solid 1px black;"
                    "border-radius: 5px;"
                    "qproperty-alignment: 'AlignHCenter | AlignVCenter';"
                    "qproperty-wordWrap: true;"
                    );


        Animator->setTargetObject(dot);
        Animator->setPropertyName("geometry");
        Animator->setDuration(2000);
        Animator->setStartValue(SourceGeometry);
        Animator->setEndValue(DetinationGeometry);




        Animator->start();

        i++;
    }
    else if(i == count -1)
    {
        emit stopTimer();
    }
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

    std::string path = Map->DjikstraShortestPath(SourceName,DestinationName);

    int i = path.length();
    LimitedTimer *AnimationTimer = new LimitedTimer(path,i);
    AnimationTimer->setInterval(500);
    connect(AnimationTimer, SIGNAL(tick(int&,int&,std::string&,bool&,QLabel*,QPropertyAnimation*)),this,SLOT(animatePlane(int&,int&,std::string&,bool&,QLabel*,QPropertyAnimation*)));
    connect(this, SIGNAL(stopTimer()), AnimationTimer, SLOT(stop()));

    AnimationTimer->start();



    //connect(animation,SIGNAL(finished()), this, SLOT());


}
