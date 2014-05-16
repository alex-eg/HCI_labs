#include <QDebug>
#include <QImage>
#include <QPainter>


#include "arabnumsrenderer.h"

ArabNumsRenderer::ArabNumsRenderer(int _number)
    : StyledNumberRenderer(_number)
{}

Style ArabNumsRenderer::type() const
{
    return ArabNums;
}

void ArabNumsRenderer::render(const QStyleOption& _option, const QFont &_font)
{
    renderWithText(_option, _font, QString::number(m_num));
}
