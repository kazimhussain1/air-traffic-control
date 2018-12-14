#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QLabel>
#include <QStyle>

#include <vector>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QPainter>
#include <QDrag>
#include <QMimeData>


#include <Graph/Graph.h>
#include <CustomWidgets/draggablelabel.h>

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
            QPainter painter(this);
            painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::RoundCap));
            std::vector<DraggableLabel*>::iterator i;
            for(i = LabelList.begin();i<LabelList.end();i++)
            {
                QPoint myPos = (*i)->pos();
                myPos.setX(myPos.x() + 10);
                myPos.setY(myPos.y() + 10);
                painter.drawLine(myPos.x(),myPos.y(), 500, 500);
            }
        }


private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPixmap *myPixmap;
    QPainter *myPainter;

    std::vector<DraggableLabel*> LabelList;
    int pos=0;

    Graph *Map;
};

#endif // MAINWINDOW_H
