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

void SymbolicPresentationNumersRenderer::render(const QStyleOption& _option)
{
    int randomSymbol = qrand() % m_symbols.size();
    QString s(m_num, m_symbols[randomSymbol]);
    renderWithText(_option, s);
}
