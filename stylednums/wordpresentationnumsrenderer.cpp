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

Style WordPresentationNumsRenderer::type() const
{
    return Words;
}

void WordPresentationNumsRenderer::render(const QStyleOption &_option, const QFont &_font)
{
    renderWithText(_option, _font, words[m_num]);
}
