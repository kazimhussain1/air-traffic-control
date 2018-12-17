#ifndef LIMITEDTIMER_H
#define LIMITEDTIMER_H

#include <QObject>
#include <QTimer>
#include <string>
#include <QPropertyAnimation>
#include <QLabel>


class LimitedTimer : public QTimer
{
    Q_OBJECT
public:
    explicit LimitedTimer(std::string path, int count, QObject *parent = nullptr);
    ~LimitedTimer();

    int getCount();



signals:

public slots:
    void timeoutConnect();
    void finishedUpdate();
signals:


    void tick(int&,int&,std::string&,bool&,QLabel*,QPropertyAnimation*);


private:
    int i;
    int count;
    std::string path;
    bool finished;
    QLabel* dot;
    QPropertyAnimation* Animator;


};

#endif // LIMITEDTIMER_H
