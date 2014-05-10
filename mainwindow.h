#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
namespace Ui
{
    class MainWindow;
}

class TestGenerator;
class DigitsDemonstrator;
class TestAnswersChooser;
class Statistics;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void startTest();
    void chooseAnswers();
    void testFinished();

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
    Statistics* m_statistics;
};

#endif // MAINWINDOW_H
