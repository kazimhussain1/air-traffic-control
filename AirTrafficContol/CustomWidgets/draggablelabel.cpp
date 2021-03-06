#include "draggablelabel.h"




DraggableLabel::~DraggableLabel()
{

}

void DraggableLabel::mousePressEvent(QMouseEvent *event)
{
    offset = event->pos();
}

void DraggableLabel::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        this->move(mapToParent(event->pos() - offset));
        emit mouseReleased();
        this->myParent->update();
    }

}

