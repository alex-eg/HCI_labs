#ifndef STATISTICSWIDGET_H
#define STATISTICSWIDGET_H

#include <QWidget>

namespace Ui {
class StatisticsWidget;
}

class MainWindow;
class Statistics;
class StatisticsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticsWidget(MainWindow *_mainWindow, QWidget* _parent = 0);
    ~StatisticsWidget();

signals:
    void finished();

private:
    void closeEvent(QCloseEvent*);

    inline QRect diagrammRect() const;

    inline int total() const;

private:
    Ui::StatisticsWidget *ui;
    MainWindow* m_mainWindow;
    Statistics* m_statistics;
};

#endif // STATISTICSWIDGET_H
