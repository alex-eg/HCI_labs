#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
namespace Ui
{
    class MainWindow;
}

class DigitsDemonstrator;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void startTest();

private:
    bool eventFilter(QObject* _obj, QEvent* _ev);

    void userNameClicked();
    void userNameEditingFinished();

    void resetPreviousUserName();

    inline QString currentUserName() const;

private:
    Ui::MainWindow *ui;
    DigitsDemonstrator* m_demonstrator;
};

#endif // MAINWINDOW_H
