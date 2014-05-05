#include <QDebug>
#include <QImage>
#include <QPainter>


#include "arabnumsrenderer.h"

ArabNumsRenderer::ArabNumsRenderer(int _number)
    : StyledNumberRenderer(_number)
{}

StyledNumberRenderer::Style ArabNumsRenderer::type() const
{
    return ArabNums;
}

void ArabNumsRenderer::render(const QStyleOption& _option)
{
    delete m_img;
    m_img = new QImage(_option.rect.size(), QImage::Format_RGB888);
    m_img->fill(Qt::white);

    QPainter painter(m_img);

    painter.setBrush(_option.palette.text());
    painter.drawText(_option.rect, QString::number(m_num));
}
