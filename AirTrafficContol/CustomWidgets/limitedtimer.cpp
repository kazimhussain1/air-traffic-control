#include "limitedtimer.h"

LimitedTimer::LimitedTimer(QObject *parent) : QTimer(parent)
{

}

LimitedTimer::~LimitedTimer()
{

}

int LimitedTimer::getCount()
{
    return count;
}
