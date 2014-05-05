#include <QDebug>
#include <QPainter>

#include "symbolicpresentationnumersrenderer.h"

static QVector<QChar> defaultSymbols;

SymbolicPresentationNumersRenderer::SymbolicPresentationNumersRenderer(int _num)
    : StyledNumberRenderer(_num)
{
    if(defaultSymbols.isEmpty())
        defaultSymbols << '♠' << '♥' << '♦' << '♣';

    m_symbols << defaultSymbols;
}

SymbolicPresentationNumersRenderer::SymbolicPresentationNumersRenderer(int _num, QVector<QChar> _specificSymbols)
    : StyledNumberRenderer(_num),
      m_symbols(_specificSymbols)
{
    if(m_symbols.isEmpty())
        qDebug() << "empty symbol list! in " << Q_FUNC_INFO;
}

Style SymbolicPresentationNumersRenderer::type() const
{
    return SymbolicNum;
}

void SymbolicPresentationNumersRenderer::render(const QStyleOption &_option)
{
    delete m_img;
    m_img = new QImage(_option.rect.size(), QImage::Format_RGB888);
    m_img->fill(Qt::white);

    QPainter painter(m_img);

    painter.setBrush(_option.palette.text());

    int randomSymbol = qrand() % m_symbols.size();
    QString s(m_num, m_symbols[randomSymbol]);
    painter.drawText(_option.rect, s);
}
