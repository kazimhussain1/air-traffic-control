#ifndef DRAGGABLELABEL_H
#define DRAGGABLELABEL_H

#include <QMouseEvent>
#include <QApplication>

#include <QLabel>

class DraggableLabel : public QLabel
{
public:
    DraggableLabel(QWidget* parent = nullptr): QLabel(parent){}

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
        }
    }




private:
    QPoint offset;
    QPoint startingPosition;

    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};

#endif // DRAGGABLELABEL_H
