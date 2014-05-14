#ifndef STATISTICSWIDGET_H
#define STATISTICSWIDGET_H

#include <QWidget>

namespace Ui {
class StatisticsWidget;
}

class MainWindow;
class StatisticsAggregator;
class StatisticsModel;

class StatisticsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticsWidget(MainWindow *_mainWindow, QWidget* _parent = 0);
    ~StatisticsWidget();

signals:
    void finished();

private slots:
    void showOtherStatistics(int _index);

private:
    void closeEvent(QCloseEvent*);

private:
    Ui::StatisticsWidget *ui;

    MainWindow* m_mainWindow;
    StatisticsAggregator* m_statistics;

    StatisticsModel* m_model;
};

#endif // STATISTICSWIDGET_H
