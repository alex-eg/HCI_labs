#include "statisticsaggregator.h"
#include "statistics.h"

StatisticsAggregator::StatisticsAggregator()
{
    for(unsigned int i = 0; i < StatTypesCount; i++)
    {
        StatTypes type = static_cast<StatTypes>(i);
        m_heap << new Statistics(type);
    }
}

StatisticsAggregator::~StatisticsAggregator()
{
    foreach(Statistics* stat, m_heap)
        delete stat;
}

const QVector<int> *StatisticsAggregator::statistics(StatTypes _type) const
{
    Q_ASSERT(_type < StatTypesCount);
    Q_ASSERT(m_heap.size() == StatTypesCount);

    return m_heap.at(_type)->statistics();
}

const QVector<QString> *StatisticsAggregator::description(StatTypes _type) const
{
    return m_heap.at(_type)->description();
}

void StatisticsAggregator::addUserStats(QList<StyledNumberRenderer *> _showedData, QList<int> _userCheckedData)
{
    foreach(Statistics* stat, m_heap)
        stat->addUserStats(_showedData, _userCheckedData);
}
