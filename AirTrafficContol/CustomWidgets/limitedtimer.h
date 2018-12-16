#ifndef LIMITEDTIMER_H
#define LIMITEDTIMER_H

#include<QObject>
#include <QTimer>

class LimitedTimer : public QTimer
{
    Q_OBJECT
public:
    explicit LimitedTimer(QObject *parent = nullptr);
    ~LimitedTimer();

    int getCount();

signals:

public slots:

private:
    int count;
};

#endif // LIMITEDTIMER_H
