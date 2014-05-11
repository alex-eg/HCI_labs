#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
namespace Ui
{
    class MainWindow;
}

class TestGenerator;
class DigitsDemonstrator;
class TestAnswersChooser;
class Statistics;
class StatisticsWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Statistics *statistics() const;
    Statistics *statistics(const QString& _user) const;
    QList<QString> users() const;

private slots:
    void startTest();
    void chooseAnswers();
    void testFinished();

    void showStatistics();
    void statisticsClosed();

private:
    bool eventFilter(QObject* _obj, QEvent* _ev);

    void userNameClicked();
    void userNameEditingFinished();
    void resetPreviousUserName();
    inline QString currentUserName() const;
//  ---------------------------------------

    void saveStatistics();

private:
    Ui::MainWindow *ui;

    TestGenerator* m_testGenerator;

    DigitsDemonstrator* m_demonstrator;
    TestAnswersChooser* m_testChooser;
    StatisticsWidget* m_statisticsWidget;

    QMap<QString, Statistics*> m_userStatistics;
};

#endif // MAINWINDOW_H
