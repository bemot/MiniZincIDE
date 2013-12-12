#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QProcess>

#include "codeeditor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void openFile(const QString &path = QString());

    void on_actionClose_triggered();

    void on_actionOpen_triggered();

    void tabCloseRequest(int);

    void tabChange(int);

    void on_actionRun_triggered();

    void readOutput();

    void procFinished(int);

    void procError(QProcess::ProcessError);

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    CodeEditor* curEditor;
    QProcess* process;
    void createEditor(QFile& file);
};

#endif // MAINWINDOW_H
