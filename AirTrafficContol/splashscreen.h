#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <mainwindow.h>

#include <QWidget>
#include <QStyle>
#include <QTimer>
#include <QDesktopWidget>


namespace Ui {
class SplashScreen;
}

class SplashScreen : public QWidget
{
    Q_OBJECT

public slots:
    void InitiateMainActivity();

public:
    explicit SplashScreen(QWidget *parent = 0);
    ~SplashScreen();

private:
    Ui::SplashScreen *ui;
    QTimer *myTimer;
    MainWindow *MainActivity;
};

#endif // SPLASHSCREEN_H
