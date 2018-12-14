#include "splashscreen.h"
#include "ui_splashscreen.h"

SplashScreen::SplashScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);

    setWindowFlags( Qt::SplashScreen );

        QSize newSize( 500, 300 );
        setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                newSize,
                qApp->desktop()->availableGeometry()
            )
        );

        QPixmap bkgnd("splash-screen-t.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

        myTimer = new QTimer(this);
        myTimer->setSingleShot(true);

        connect(myTimer, SIGNAL(timeout()), this, SLOT(InitiateMainActivity()));

        myTimer->start(2500);
}

SplashScreen::~SplashScreen()
{
    delete ui;
}

void SplashScreen::InitiateMainActivity()
{
    this->MainActivity = new MainWindow();
    MainActivity->show();
    this->hide();
}
