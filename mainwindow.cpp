#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Filesystem = new QFileSystemModel(this);
    Filesystem->setReadOnly(true);
    Filesystem->setRootPath("/");
    /*file_model->setSorting(QDir::DirsFirst |
                      QDir::IgnoreCase |
                      QDir::Name);*/
    Filesystem->setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);

    FolderProxyModel = new QSortFilterProxyModel(this);
    FolderProxyModel->setSourceModel(Filesystem);
    FolderProxyModel->setFilterKeyColumn(2);
    FolderProxyModel->setFilterRegExp("Drive|Folder");


    MyFileModel = new FileProxy(this);
    MyFileModel->setSourceModel(Filesystem);
    //MyFileModel->setDynamicSortFilter(true);
    //FileProxyModel->setFilterRole();
    //FileProxyModel->setFilterRegExp("File");

    ui->treeView->setModel(FolderProxyModel);
    QModelIndex index = FolderProxyModel->mapFromSource(Filesystem->index("/home/"));
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    //ui->treeView->setCurrentIndex(index);
    ui->treeView->resizeColumnToContents(0);


    ui->listView->setModel(MyFileModel);
    ui->listView->setRootIndex(MyFileModel->mapFromSource(FolderProxyModel->mapToSource(index)));


    ui->wPlot->xAxis->setLabel("Retention Time");
    ui->wPlot->yAxis->setLabel("Intensity");
    ui->wPlot->xAxis->setRange(0, 45);
    ui->wPlot->yAxis->setRange(0, 1500000);
    ui->wPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes);



}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    qDebug() << "clicked";

    ui->listView->setRootIndex(MyFileModel->mapFromSource(FolderProxyModel->mapToSource(index)));
}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{


}


