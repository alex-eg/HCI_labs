#include <QDebug>
#include <QImage>
#include <QPainter>


#include "arabnumsrenderer.h"

ArabNumsRenderer::ArabNumsRenderer(int _number)
    : AbstractStyledNumberRenderer(_number)
{}

void ArabNumsRenderer::render(const QStyleOption& _option)
{
    delete m_img;
    m_img = new QImage(_option.rect.size(), QImage::Format_RGB888);
    m_img->fill(Qt::white);

    qDebug() << m_img << m_img->isNull();

    QPainter painter(m_img);

    painter.setBrush(_option.palette.text());
    painter.drawText(_option.rect, QString::number(m_num));
}
