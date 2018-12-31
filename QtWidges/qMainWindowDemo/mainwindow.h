#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    // slots
    QPushButton *button1;
    // actions
    QAction *quitAction;

    QSize sizeHint() const;
    void addCentralWidget();
    void addMenubar();
    void initStatusBar();
    void initActions();
    void initFileMenuActions();
};

#endif // MAINWINDOW_H
