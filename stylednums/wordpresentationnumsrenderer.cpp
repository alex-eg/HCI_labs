#include <QVector>
#include <QPainter>

#include "wordpresentationnumsrenderer.h"

static QVector<QString> words;

WordPresentationNumsRenderer::WordPresentationNumsRenderer(int _num)
    : StyledNumberRenderer(_num)
{
    if(words.isEmpty())
        words << "Ноль" << "Один" << "Два" << "Три" << "Четыре" << "Пять" << "Шесть" << "Семь" << "Восемь" << "Девять";
}

StyledNumberRenderer::Style WordPresentationNumsRenderer::type() const
{
    return Words;
}

void WordPresentationNumsRenderer::render(const QStyleOption &_option)
{
    delete m_img;
    m_img = new QImage(_option.rect.size(), QImage::Format_RGB888);
    m_img->fill(Qt::white);

    QPainter painter(m_img);

    painter.setBrush(_option.palette.text());
    painter.drawText(_option.rect, words[m_num]);
}
