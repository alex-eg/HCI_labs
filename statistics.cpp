#include <QDebug>
#include "statistics.h"

Statistics::Statistics()
    : m_statistics()
{}

void Statistics::addUserStats(const QString& _user, const QVector<Stat>& _stats)
{
    if(!m_statistics.contains(_user))
       m_statistics[_user] << defaultUserStats();

    QVector<Stat> userStats = m_statistics[_user];

    for(int i = 0; i < StylesCount; i++)
    {
        userStats[i].success   += _stats[i].success;
        userStats[i].unsuccess += _stats[i].unsuccess;
    }
    m_statistics[_user] = userStats;

    info();
}

QVector<Statistics::Stat> Statistics::defaultUserStats()
{
    QVector<Statistics::Stat> stats;
    stats.resize(StylesCount);
    return stats;
}

void Statistics::info() const
{
    QMapIterator<QString, QVector<Stat> > i(m_statistics);
    while (i.hasNext())
    {
        i.next();
        qDebug() << i.key();
        for(int j = 0; j < i.value().size(); j++)
            qDebug() << "\t" << i.value().at(j).success << i.value().at(j).unsuccess;
    }
}
