#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QMap>
#include <QtAlgorithms>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer * t;
    int time;
    QString returnString(bool ispictograms, int num);
    QMap<int, int> nnums;
private slots:
    void updateTimer();
    void startExperiment();
    void continueExperiment();
    void proceedToRusults();
    void startOver();
};

#endif // MAINWINDOW_H
