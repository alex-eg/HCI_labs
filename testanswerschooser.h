#ifndef TESTANSWERSCHOOSER_H
#define TESTANSWERSCHOOSER_H

#include <QWidget>
#include <QList>

namespace Ui {
class TestAnswersChooser;
}

class DigitsDemonstrator;
class TestGenerator;

class TestAnswersChooser : public QWidget
{
    Q_OBJECT

public:
    explicit TestAnswersChooser(const TestGenerator* _testGenerator, DigitsDemonstrator* _demonstrator, QWidget* _parent = 0);
    ~TestAnswersChooser();

    QList<int> checkedNums() const;

signals:
    void finished();

private slots:
    void nextState();

private:
    enum ChooserState {NoState, ChooseNums, ShowCorrect, Finish};

    void setState(ChooserState _state);

private:
    Ui::TestAnswersChooser *ui;
    const TestGenerator* m_testGenerator;
    DigitsDemonstrator* m_demonstrator;
    ChooserState m_state;
};

#endif // TESTANSWERSCHOOSER_H
