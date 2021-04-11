#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <unordered_set>
#include <QMainWindow>
#include <QObject>
#include <QLineEdit>
#include <QTextBrowser>
#include <DictionaryWorker.h>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent*) override;
private slots:
    void inputChanged();
    void outputChanged();

private:
    std::unique_ptr<Ui::MainWindow> ui;
    DictionaryWorker worker;
    uint64_t version = 1;
};
#endif // MAINWINDOW_H
