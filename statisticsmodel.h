#ifndef STATISTICSMODEL_H
#define STATISTICSMODEL_H

#include <QAbstractTableModel>

class Statistics;
class StatisticsModel : public QAbstractTableModel
{
public:
    StatisticsModel(Statistics* _statistics);

    QModelIndex index(int _row, int _column, const QModelIndex& _parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &_child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex& _index, int _role = Qt::DisplayRole) const;

//private:
//    inline Qt::GlobalColor randomColor() const;

private:
    Statistics* m_statistics;
};

#endif // STATISTICSMODEL_H
