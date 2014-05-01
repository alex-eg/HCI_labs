#ifndef DIGITSDEMONSTRATOR_H
#define DIGITSDEMONSTRATOR_H

#include <QWidget>
#include <QList>

namespace Ui {
class DigitsDemonstrator;
}

class AbstractStyledNumberRenderer;
class TestGenerator;

class DigitsDemonstrator : public QWidget
{
    Q_OBJECT

public:
    explicit DigitsDemonstrator(const TestGenerator* _testGenerator, QWidget *parent = 0);
    ~DigitsDemonstrator();

signals:
    void finished();

private:
    void renderNumsPics();

private:
    Ui::DigitsDemonstrator *ui;
    const TestGenerator* m_testGenerator;
};

#endif // DIGITSDEMONSTRATOR_H
