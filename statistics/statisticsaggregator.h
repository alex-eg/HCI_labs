#ifndef STATISTICSAGGREGATOR_H
#define STATISTICSAGGREGATOR_H

#include <QList>
#include "statisticsapi.h"

class StyledNumberRenderer;
class Statistics;

class StatisticsAggregator
{
public:
    StatisticsAggregator();
    ~StatisticsAggregator();

    const QVector<int> *statistics(StatTypes _type) const;
    const QVector<QString> *description(StatTypes _type) const;

    void addUserStats(QList<StyledNumberRenderer*> _showedData, QList<int> _userCheckedData);

private:
    QList<Statistics*> m_heap;
};

#endif // STATISTICSAGGREGATOR_H
