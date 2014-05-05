#ifndef DIGITSDEMONSTRATOR_H
#define DIGITSDEMONSTRATOR_H

#include <QWidget>
#include <QList>

namespace Ui {
class DigitsDemonstrator;
}

class StyledNumberRenderer;
class TestGenerator;

class DigitsDemonstrator : public QWidget
{
    Q_OBJECT

public:
    explicit DigitsDemonstrator(const TestGenerator* _testGenerator, int _timeToShow = 10, QWidget* _parent = 0);
    ~DigitsDemonstrator();

signals:
    void finished();

private slots:
    void timerTicked();

private:
    void renderNumsPics();

private:
    Ui::DigitsDemonstrator *ui;
    const TestGenerator* m_testGenerator;
    int m_timeLeft;
};

#endif // DIGITSDEMONSTRATOR_H
