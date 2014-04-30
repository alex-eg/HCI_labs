#ifndef DIGITSDEMONSTRATOR_H
#define DIGITSDEMONSTRATOR_H

#include <QWidget>
#include <QList>

namespace Ui {
class DigitsDemonstrator;
}

class AbstractStyledNumberRenderer;

class DigitsDemonstrator : public QWidget
{
    Q_OBJECT

public:
    explicit DigitsDemonstrator(QWidget *parent = 0);
    ~DigitsDemonstrator();

signals:
    void finished();

private:
    void generateTest();    

private:
    Ui::DigitsDemonstrator *ui;
    QList<AbstractStyledNumberRenderer*> m_generatedTest;
};

#endif // DIGITSDEMONSTRATOR_H
