#ifndef HTMLWINDOW_H
#define HTMLWINDOW_H

#include <QMainWindow>

#ifdef MINIZINC_IDE_HAVE_WEBENGINE
#include <QWebEngineView>
#else
#include <QWebView>
#endif
#include "htmlpage.h"

namespace Ui {
class HTMLWindow;
}

class MainWindow;

class VisWindowSpec {
public:
    QString url;
    Qt::DockWidgetArea area;
    VisWindowSpec(const QString& url0, const Qt::DockWidgetArea& area0 = Qt::TopDockWidgetArea)
        : url(url0), area(area0) {}
    VisWindowSpec(void) {}
};

class HTMLWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HTMLWindow(const QVector<VisWindowSpec>& specs, MainWindow* mw, QWidget *parent = 0);
    ~HTMLWindow();

    void addSolution(int nVis, const QString& json);
    void selectSolution(HTMLPage* source, int n);
    void finish(qint64 runtime);
private:
    Ui::HTMLWindow *ui;
    QVector<HTMLPage*> pages;
#ifdef MINIZINC_IDE_HAVE_WEBENGINE
    typedef QWebEngineView MznIdeWebView;
#else
    typedef QWebView MznIdeWebView;
#endif
    QVector<QPair<MznIdeWebView*,QString> > loadQueue;
protected:
    void closeEvent(QCloseEvent *);
private slots:
    void loadFinished(bool);
signals:
    void closeWindow(void);
};

#endif // HTMLWINDOW_H
