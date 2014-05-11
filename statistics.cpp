#include <QDebug>
#include "statistics.h"

Statistics::Statistics(const int _maxLength)
    : m_maxLength(_maxLength),
      m_statistics(m_maxLength)
{
    qDebug() << Q_FUNC_INFO;
}

const QVector<Statistics::Stat> *Statistics::statistics()
{
    return &m_statistics;
}

void Statistics::addUserStats(const QVector<Stat>& _stats)
{
    Q_ASSERT(_stats.size() == m_maxLength);

    for(int i = 0; i < m_maxLength; i++)
    {
        m_statistics[i].success   += _stats[i].success;
        m_statistics[i].unsuccess += _stats[i].unsuccess;
    }

    info();
}

QVector<Statistics::Stat> Statistics::defaultUserStats()
{
    QVector<Statistics::Stat> stats;
    stats.resize(m_maxLength);
    return stats;
}

void Statistics::info() const
{
    foreach(Stat stat, m_statistics)
    {
        qDebug() << stat.success << stat.unsuccess;
    }
}
