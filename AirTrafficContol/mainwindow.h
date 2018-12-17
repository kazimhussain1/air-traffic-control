#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QLabel>
#include <QStyle>
#include <QTableWidget>
#include <QVariant>
#include <QDateTime>
#include <QTimer>


#include <vector>
#include <math.h>

#include <QPixmap>
#include <QPainter>
#include <QPropertyAnimation>

#include <Graph/Graph.h>
#include <CustomWidgets/draggablelabel.h>
#include <CustomWidgets/togglebutton.h>
#include <CustomWidgets/limitedtimer.h>
//#include <LinkedList/LinkedList.h>

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

class NODE
{
public:

    NODE(char Source, char Destination, QDateTime value)
    {
        this->Source = Source;
        this->value = value;
        this->Destination = Destination;
    }

    bool operator <(NODE& B)
    {
        return this->value < B.value? true : false;
    }

    bool operator >(NODE& B)
    {
        return this->value > B.value? true : false;
    }

    bool operator <=(NODE& B)
    {
        return this->value <= B.value? true : false;
    }

    bool operator >=(NODE& B)
    {
        return this->value >= B.value? true : false;
    }

    char Source;
    char Destination;
    QDateTime value;


};



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event)
    {
        event->type();//JUST TO STOP NOT USED WARNING


        QPainter painter(this);
        painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::RoundCap));
        painter.setFont(QFont("Sans Serif", 10));

        VertexNODE* currentVertex = Map->getRoot();
        while(currentVertex)
        {
            QPoint myPos1 = currentVertex->visualNode->pos();
            myPos1.setX(myPos1.x() + 15);
            myPos1.setY(myPos1.y() + 15);

            EdgeNODE* currentEdge = (EdgeNODE*)currentVertex->header;
            while(currentEdge)
            {
                QPoint myPos2 = currentEdge->address->visualNode->pos();
                myPos2.setX(myPos2.x() + 15);
                myPos2.setY(myPos2.y() + 15);

                painter.drawLine(myPos1, myPos2);
                painter.setBackground(QBrush(QColor("black")));
                painter.setBackgroundMode(Qt::OpaqueMode);
                painter.drawText(QPoint((myPos1 + myPos2)/2), QString::number(currentEdge->weight));

                currentEdge = currentEdge->nextEdge;
            }
            currentVertex = currentVertex->nextVertex;
        }
    }



public slots:
    void showEditMenu();
    void showDepartMenu();
    void updateGraphWeights();
    void animatePlane(int& i,int& count,std::string& path, bool& finished, QLabel* dot, QPropertyAnimation* Animator);
    void autoDepart();





private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
    void stopTimer();
    void deleteDot();

private:
    Ui::MainWindow *ui;
    QPainter *myPainter;
    Switch *mySwitch;
    QDateTime *currentTime;
    QTimer *departTimer;

    std::vector<DraggableLabel*> LabelList;
    int posX=0;
    int posY=0;

    //LinkedList *Schedule;
    std::vector<NODE> *table;

    Graph *Map;


};

#endif // MAINWINDOW_H
