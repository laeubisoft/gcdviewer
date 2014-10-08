#include "fileproxy.h"

FileProxy::FileProxy(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}


bool FileProxy::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
//    QModelIndex index = sourceModel()->index(source_row, 0, source_parent);
//    QFileSystemModel *source = static_cast<QFileSystemModel*>(sourceModel());
//    QFileInfo info = source->fileInfo(index);



    //qDebug() << sourceModel()->data(index, QFileSystemModel::FileIconRole).toString();
    //qDebug() << sourceModel()->data(index, QFileSystemModel::FilePermissions).toString().toInt();

//    qDebug() << info.completeBaseName()<< info.isDir();
//    qDebug() << "isDir:" << source->isDir(index);
//    return !source->isDir(index);

    //if (info.isDir() == true) return false;
    //if (info.isFile() == true) return true;
    //return true;
    //return info.isFile();
    //return (rand()%2)?true:false;


    const QModelIndex &index =
        sourceModel()->index(source_row, filterKeyColumn(), source_parent);
    //qDebug() << sourceModel()->data(index).toString();

    //return (((QFileSystemModel*)sourceModel())->isDir(index));
    return true;
}
