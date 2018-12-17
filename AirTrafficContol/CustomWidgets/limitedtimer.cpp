#include "limitedtimer.h"

LimitedTimer::LimitedTimer(std::string path, int count, QObject *parent) : QTimer(parent)
{


    this->i =0;
    this->count = count;
    this->path = path;
    this->finished = false;
    dot = new QLabel;
    dot->setGeometry(-5,-5,1,1);

    Animator = new QPropertyAnimation(parent);


    connect(this, SIGNAL(timeout()),this, SLOT(timeoutConnect()));
    connect(Animator, SIGNAL(finished()), this, SLOT(finishedUpdate()));
}

LimitedTimer::~LimitedTimer()
{

}

int LimitedTimer::getCount()
{
    return count;
}

void LimitedTimer::timeoutConnect()
{

    emit tick(this->i, this->count, this->path, this->finished, this->dot, this->Animator);
}

void LimitedTimer::finishedUpdate()
{
    this->finished = true;
}

