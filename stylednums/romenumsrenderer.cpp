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

StyledNumberRenderer::Style RomeNumsRenderer::type() const
{
    return RomeNums;
}

void RomeNumsRenderer::render(const QStyleOption &_option)
{
    delete m_img;
    m_img = new QImage(_option.rect.size(), QImage::Format_RGB888);
    m_img->fill(Qt::white);

    QPainter painter(m_img);

    painter.setBrush(_option.palette.text());
    painter.drawText(_option.rect, romanNums[m_num]);
}
