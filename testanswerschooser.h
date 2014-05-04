#ifndef TESTANSWERSCHOOSER_H
#define TESTANSWERSCHOOSER_H

#include <QWidget>

namespace Ui {
class TestAnswersChooser;
}

class DigitsDemonstrator;
class TestGenerator;

class TestAnswersChooser : public QWidget
{
    Q_OBJECT

public:
    explicit TestAnswersChooser(const TestGenerator* _testGenerator, QWidget* _parent = 0);
    ~TestAnswersChooser();

private slots:
    void userChoosedVariants();

private:
    enum ChooserState {ChooseNums, ShowCorrect};

    void setState(ChooserState _state);

private:
    Ui::TestAnswersChooser *ui;
    const TestGenerator* m_testGenerator;
    DigitsDemonstrator* m_demonstrator;
};

#endif // TESTANSWERSCHOOSER_H
