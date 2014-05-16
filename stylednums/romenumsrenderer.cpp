#include <QDebug>
#include <QPainter>
#include <QVector>

#include "romenumsrenderer.h"

static QVector<QString> romanNums;

RomeNumsRenderer::RomeNumsRenderer(int _num)
    : StyledNumberRenderer(_num)
{
    if(romanNums.isEmpty())
        romanNums << "0" << "I" << "II" << "III" << "IV" << "V" << "VI" << "VII" << "VIII" << "IX";
}

Style RomeNumsRenderer::type() const
{
    return RomeNums;
}

void RomeNumsRenderer::render(const QStyleOption &_option, const QFont &_font)
{
    renderWithText(_option, _font, romanNums[m_num]);
}
