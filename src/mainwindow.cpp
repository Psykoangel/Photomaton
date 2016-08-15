#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QMediaService>
#include <QCameraViewfinder>
#include <QCameraInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setTimer()
{
    QTimer *timer = new QTimer( this );
    connect( timer, SIGNAL( timeout() ), this, SLOT( showtime() ) );
    timer->start( 1000 );
}


void MainWindow::setFonts()
{
    int id = QFontDatabase::addApplicationFont(":/font/fonts/From_Cartoon_Blocks.ttf");
    if( id < 0 )
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Cette police d'écriture n'a pu être chargée."));
        msgBox.exec();
    }

    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont fromCartoonBlocks(family);
    fromCartoonBlocks.setPointSize( 75 );
    ui->lblMainTitle->setFont(fromCartoonBlocks);
}


void MainWindow::showtime()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    QString sTime = time.toString( "hh:mm" );

    if( (time.second() % 2) == 0 )
    {
        sTime[2] = ' ';
    }

    ui->lblTime->setText( sTime );
    ui->lblDate->setText( date.toString( "dd MMM yyyy" ) );
}


void MainWindow::keyPressEvent(QKeyEvent* event)
{
//    bool altModifier = event->modifiers().testFlag(Qt::AltModifier);
    bool ctrlModifier = event->modifiers().testFlag(Qt::ControlModifier);

    switch( event->key() )
    {
        case Qt::Key_Space:
            if( ctrlModifier )
                ui->swContent->setCurrentIndex( (ui->swContent->currentIndex() + 1) % 3 );
            break;
        default:
            break;
    }
}


void MainWindow::init()
{
    initUI();
}


void MainWindow::initUI()
{
    setTimer();

    setFonts();
}
