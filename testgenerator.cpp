#include <QDebug>

#include "testgenerator.h"

#include "stylednums/stylednumberrenderer.h"
#include "stylednums/arabnumsrenderer.h"
#include "stylednums/romenumsrenderer.h"
#include "stylednums/wordpresentationnumsrenderer.h"
#include "stylednums/symbolicpresentationnumersrenderer.h"

TestGenerator::TestGenerator()
{
}

void TestGenerator::generateOtherTest()
{
    foreach(StyledNumberRenderer* renderer, m_generatedTest)
        delete renderer;
    m_generatedTest.clear();

    int digits[10];
    fillByRandomUniqueNums(digits, 10);

    int digitsCount = qrand() % 8 + 2;
    for(int i = 0; i < digitsCount; i++)
    {
        Style style = static_cast<Style>(qrand() % StylesCount);
        m_generatedTest << styledNumberFactory(style, digits[i]);
    }
    qDebug() << "generated " << digitsCount << " digits";
}

QList<StyledNumberRenderer *> TestGenerator::generatedTest() const
{
    return m_generatedTest;
}

void TestGenerator::fillByRandomUniqueNums(int* _arr, int _size) const
{
    int* placeToWrite = _arr;
    for(int i = 0; i < _size; i++)
        *(placeToWrite++) = i;

    int randomNum;
    for(int i = 0; i < _size/2; i++)
    {
        randomNum = qrand() % _size;
        std::swap(_arr[i], _arr[randomNum]);
    }
}

StyledNumberRenderer *TestGenerator::styledNumberFactory(Style _style, int _digit) const
{
    switch(_style)
    {
    case ArabNums:
            return new ArabNumsRenderer(_digit);
    case RomeNums:
            return new RomeNumsRenderer(_digit);
    case Words:
            return new WordPresentationNumsRenderer(_digit);
    case SymbolicNum:
        return new SymbolicPresentationNumersRenderer(_digit);
    }
    Q_ASSERT(false);
    return NULL;
}
