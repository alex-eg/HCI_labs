#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H

#include <QList>
#include "labapi.h"

class AbstractStyledNumberRenderer;

class TestGenerator
{
public:
    TestGenerator();
    void generateOtherTest();
    QList<AbstractStyledNumberRenderer*> generatedTest() const;

private:
    void fillByRandomUniqueNums(const int* _arr, int _size) const;
    AbstractStyledNumberRenderer* styledNumberFactory(Style _style, int _digit) const;

private:
    QList<AbstractStyledNumberRenderer*> m_generatedTest;
};

#endif // TESTGENERATOR_H
