#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H

#include <QList>
#include "stylednums/stylednumsapi.h"

class StyledNumberRenderer;

class TestGenerator
{
public:
    TestGenerator();
    void generateOtherTest();
    QList<StyledNumberRenderer*> generatedTest() const;

private:
    void fillByRandomUniqueNums(int* _arr, int _size) const;
    StyledNumberRenderer* styledNumberFactory(Style _style, int _digit) const;

private:
    QList<StyledNumberRenderer*> m_generatedTest;
};

#endif // TESTGENERATOR_H
