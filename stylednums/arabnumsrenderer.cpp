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

void ArabNumsRenderer::render(const QStyleOption& _option)
{
    renderWithText(_option, QString::number(m_num));
}
