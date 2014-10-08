#ifndef FILEPROXY_H
#define FILEPROXY_H

#include <QSortFilterProxyModel>
#include <QFileSystemModel>
#include <QDebug>

class FileProxy : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit FileProxy(QObject *parent = 0);
    
signals:
    
public slots:

protected:

    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

};

#endif // FILEPROXY_H
