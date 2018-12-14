#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Map = new Graph;

    QSize newSize( 1280, 720 );
        setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                newSize,
                qApp->desktop()->availableGeometry()
            )
        );


    /*scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    view->show();
    view->resize(1080,720);
    myPixmap = new QPixmap(1040, 700);
    scene->addPixmap(*myPixmap);*/


    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    DraggableLabel *temp = new DraggableLabel(this);
    temp->setStyleSheet("color:red; background-color:red");
    temp->setGeometry(50 + pos,50,20,20);
    pos+= 40;
    temp->show();
    LabelList.push_back(temp);
    this->update();
}

