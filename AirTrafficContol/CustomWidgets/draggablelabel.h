#ifndef DRAGGABLELABEL_H
#define DRAGGABLELABEL_H

#include <QMouseEvent>
#include <QApplication>
#include <QMainWindow>

#include <QPropertyAnimation>

#include <QLabel>

class DraggableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit DraggableLabel(QMainWindow* parent = nullptr): QLabel(parent)
    {
        myParent = parent;
        connect(this, SIGNAL(mouseReleased()), myParent, SLOT(updateGraphWeights()));
    }
    virtual ~DraggableLabel();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);

signals:
    void mouseReleased();


private:
    QMainWindow *myParent;
    QPoint offset;
    QPoint startingPosition;


};

#endif // DRAGGABLELABEL_H
