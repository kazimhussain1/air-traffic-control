#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QLabel>
#include <QStyle>

#include <vector>
#include <math.h>


#include <QPixmap>
#include <QPainter>
#include <QPropertyAnimation>




#include <Graph/Graph.h>
#include <CustomWidgets/draggablelabel.h>
#include <CustomWidgets/togglebutton.h>

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


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();






    void on_SourceCombo_activated(int index);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QPainter *myPainter;
    Switch *mySwitch;

    std::vector<DraggableLabel*> LabelList;
    int pos=0;

    Graph *Map;
};

#endif // MAINWINDOW_H
