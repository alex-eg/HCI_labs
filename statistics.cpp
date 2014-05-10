#include <QDebug>
#include "statistics.h"

Statistics::Statistics()
{
}

void Statistics::addUserStats(const QString& _user, const UserStats& _stats)
{
    //@@@
    info();
    UserStats stats = m_statistics.value(_user, UserStats());
    stats.merge(_stats);
    m_statistics[_user] = stats;
}

void Statistics::info() const
{
    QMapIterator<QString, UserStats> i(m_statistics);
    while (i.hasNext())
    {
        i.next();
        qDebug() << i.key() << ": \t";
        for(Style j = Invalid; j < StylesCount; inc(j))
            qDebug() << "\t" << i.value()[j].success << i.value()[j].unsuccess << endl;
    }
}
