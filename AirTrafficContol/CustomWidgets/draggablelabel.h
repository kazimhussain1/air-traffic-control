#ifndef DRAGGABLELABEL_H
#define DRAGGABLELABEL_H

#include <QMouseEvent>
#include <QApplication>
#include <QMainWindow>

#include <QPropertyAnimation>

#include <QLabel>

class DraggableLabel : public QLabel
{
public:
    explicit DraggableLabel(QMainWindow* parent = nullptr): QLabel(parent){myParent = parent;}

protected:
    void mousePressEvent(QMouseEvent *event)
    {
        offset = event->pos();
    }

    void mouseMoveEvent(QMouseEvent *event)
    {
        if(event->buttons() & Qt::LeftButton)
        {
            this->move(mapToParent(event->pos() - offset));
            this->myParent->update();
        }

    }
    void mouseReleaseEvent(QMouseEvent *event)
    {
        this->myParent->update();
        QLabel::mouseReleaseEvent(event);
    }
    void mouseDoubleClickEvent()
    {

    }






private:
    QMainWindow *myParent;
    QPoint offset;
    QPoint startingPosition;

    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};

#endif // DRAGGABLELABEL_H
