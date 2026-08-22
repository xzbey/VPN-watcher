#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>

#include "HostChecker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool downloadHostList(const QString& path);

    void loadJson();

    QVector<QSharedPointer<BaseInfo>> getHostList() const;

    void print(const FullInfo& fullInfo) const;

    void setTable();

public slots:
    void onHostCheckerFinished(const FullInfo& fullInfo);

    void startPool();

private:
    Ui::MainWindow *ui;

    QVector<QSharedPointer<BaseInfo>> hostList;
    QTimer* timer;

};
#endif // MAINWINDOW_H
