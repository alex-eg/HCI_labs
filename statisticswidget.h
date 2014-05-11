#ifndef STATISTICSWIDGET_H
#define STATISTICSWIDGET_H

#include <QWidget>

namespace Ui {
class StatisticsWidget;
}

class Statistics;
class StatisticsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticsWidget(Statistics* _statistics, QWidget* _parent = 0);
    ~StatisticsWidget();

private:
    Ui::StatisticsWidget *ui;
    Statistics* m_statistics;
};

#endif // STATISTICSWIDGET_H
