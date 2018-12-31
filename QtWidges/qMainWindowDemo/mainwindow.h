#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QSize sizeHint() const;
    void addCentralWidget();
    void addMenubar();
    void initStatusBar();
};

#endif // MAINWINDOW_H
