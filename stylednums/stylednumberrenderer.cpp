#include <QPainter>

#include "stylednums/stylednumberrenderer.h"

StyledNumberRenderer::StyledNumberRenderer(int _num)
    : m_num(_num),
      m_img(NULL)
{}

StyledNumberRenderer::~StyledNumberRenderer()
{
    delete m_img;
}

QImage* StyledNumberRenderer::image() const
{
    return m_img;
}

void StyledNumberRenderer::renderWithText(const QStyleOption& _option, const QString &_text)
{
    delete m_img;
    m_img = new QImage(_option.rect.size(), QImage::Format_RGB888);
    m_img->fill(_option.palette.color(QPalette::Background));

    QPainter painter(m_img);
    painter.setBrush(_option.palette.text());

    painter.setFont(defaultStringsFont);

    painter.drawText(_option.rect, _text);
}
