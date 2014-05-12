#ifndef TOTALSTATISTICS_H
#define TOTALSTATISTICS_H

#include "statistics/statistics.h"

class TotalStatistics : public Statistics
{
public:
    TotalStatistics();
    void addUserStats(const QList<StyledNumberRenderer*>& _showedData, const QList<int>& _userCheckedData) Q_DECL_OVERRIDE ;

};

#endif // TOTALSTATISTICS_H
