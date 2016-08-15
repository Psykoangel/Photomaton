#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        void keyPressEvent(QKeyEvent* event);

    private:
        void init();
        void initUI();
        void setTimer();
        void setFonts();

        Ui::MainWindow *ui;

    private slots:
        void showtime();
};

#endif // MAINWINDOW_H
