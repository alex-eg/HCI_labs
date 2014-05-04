#ifndef TESTANSWERSCHOOSER_H
#define TESTANSWERSCHOOSER_H

#include <QWidget>

namespace Ui {
class TestAnswersChooser;
}

class TestAnswersChooser : public QWidget
{
    Q_OBJECT

public:
    explicit TestAnswersChooser(QWidget *parent = 0);
    ~TestAnswersChooser();

private:
    Ui::TestAnswersChooser *ui;
};

#endif // TESTANSWERSCHOOSER_H
