#ifndef STATISTICSMODEL_H
#define STATISTICSMODEL_H

#include <QAbstractTableModel>
#include "statistics/statisticsapi.h"

class StatisticsAggregator;
class StatisticsModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    StatisticsModel(StatisticsAggregator* _statistics);

    QModelIndex index(int _row, int _column, const QModelIndex& _parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex& _index, int _role = Qt::DisplayRole) const;

public slots:
    void setStatType(StatTypes _type);

private:
    inline double statisticsValueAt(int _pos) const;
    inline const QVector<int>* currStatistics() const;
    inline const QVector<QString>* currDescription() const;

private:
    StatisticsAggregator* m_statistics;
    QVector<QString> m_randomColors;
    StatTypes m_statType;
};

#endif // STATISTICSMODEL_H
