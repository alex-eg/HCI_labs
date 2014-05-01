#include "testgenerator.h"

#include "abstractstylednumberrenderer.h"
#include "arabnumsrenderer.h"


TestGenerator::TestGenerator()
{
}

void TestGenerator::generateOtherTest()
{
    foreach(AbstractStyledNumberRenderer* renderer, m_generatedTest)
        delete renderer;
    m_generatedTest.clear();

    int digits[10];
    int digitsCount = qrand() % 9 + 1;
    fillByRandomUniqueNums(digits, digitsCount);

    for(int i = 0; i < digitsCount; i++)
    {
        Style style = static_cast<Style>(qrand() % StylesCount);
        m_generatedTest << styledNumberFactory(style, digits[i]);
    }
}

QList<AbstractStyledNumberRenderer *> TestGenerator::generatedTest() const
{
    return m_generatedTest;
}

void TestGenerator::fillByRandomUniqueNums(const int *_arr, int _size) const
{
    bool used[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < _size; i++)
    {
        int randomNum;
        do
        {
            randomNum = qrand() % 10;
        }
        while(used[i]);
        used[i] = true;
    }
}

AbstractStyledNumberRenderer *TestGenerator::styledNumberFactory(Style _style, int _digit) const
{
    switch(_style)
    {
        case ArabNums:
        {
            return new ArabNumsRenderer(_digit);
            break;
        }
    }
    return NULL;
}
