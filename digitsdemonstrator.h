#ifndef DIGITSDEMONSTRATOR_H
#define DIGITSDEMONSTRATOR_H

#include <QWidget>
#include <QList>
#include <QStyleOption>

namespace Ui {
class DigitsDemonstrator;
}

class StyledNumberRenderer;
class TestGenerator;
class QTimer;

class DigitsDemonstrator : public QWidget
{
    Q_OBJECT

public:
    explicit DigitsDemonstrator(const TestGenerator* _testGenerator, int _timeToShow = 10, QWidget* _parent = 0);
    ~DigitsDemonstrator();

    void setCountdown(int _seconds);

signals:
    void finished();

private slots:
    void timerTicked();

private:
    void renderNumsPics();
    QFont generateFont() const;
    QStyleOption generateOption() const;

private:
    Ui::DigitsDemonstrator *ui;
    const TestGenerator* m_testGenerator;
    QTimer* m_timer;

    int m_timeLeft;
};

#endif // DIGITSDEMONSTRATOR_H
