#ifndef STATISTICSWIDGET_H
#define STATISTICSWIDGET_H

#include <QWidget>

namespace Ui {
class StatisticsWidget;
}

class QStandardItemModel;
class MainWindow;
class StatisticsAggregator;

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
    void showOtherUserStatistics(QString _newUser);

private:
    void closeEvent(QCloseEvent*);
    void resetModel();
    inline QColor getColorForChart(int _pos);

private:
    Ui::StatisticsWidget *ui;

    MainWindow* m_mainWindow;
    StatisticsAggregator* m_statistics;
    QStandardItemModel* m_model;
};

#endif // STATISTICSWIDGET_H
