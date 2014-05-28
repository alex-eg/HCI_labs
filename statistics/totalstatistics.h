#ifndef TOTALSTATISTICS_H
#define TOTALSTATISTICS_H

#include "statistics.h"

class TotalStatistics : public Statistics
{
public:
    TotalStatistics();
    void addUserStats(const QList<StyledNumberRenderer*>& _showedData, const QList<int>& _userCheckedData);
    StatTypes type() const;
};

#endif // TOTALSTATISTICS_H
