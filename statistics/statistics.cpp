#include <QDebug>

#include "statistics.h"
#include "totalstatistics.h"
#include "stylestatistics.h"
#include "numberstatistics.h"

Statistics::Statistics(StatTypes _type)
    : m_pimpl(statsFactory(_type))
{}

Statistics::~Statistics()
{
    delete m_pimpl;
}

const QVector<int> *Statistics::statistics() const
{
    if(!m_pimpl)
        return &m_statistics;
    return m_pimpl->statistics();// &m_statistics;
}

const QVector<QString> *Statistics::description() const
{
    if(!m_pimpl)
        return &m_description;
    return m_pimpl->description(); // &m_description;
}

void Statistics::addUserStats(const QList<StyledNumberRenderer *> &_showedData, const QList<int> &_userCheckedData)
{
    m_pimpl->addUserStats(_showedData, _userCheckedData);
}

StatTypes Statistics::type() const
{
    return m_pimpl->type();
}

Statistics *Statistics::statsFactory(StatTypes _type) const
{
    switch (_type)
    {
    case Total:
        return new TotalStatistics();
    case StyleSuccess:
    case StylesUnsuccess:
        return new StyleStatistics(_type);
    case NumberSuccess:
    case NumberUnsuccess:
        return new NumberStatistics(_type);
    default:
        qDebug() << "undefine stat type! in " << Q_FUNC_INFO;
    }
    return NULL;
}

