#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void clickButton();

private:
    // slots
    QPushButton *button1;
    // actions
    QAction *quitAction;
    QAction *msgAction;

    QMessageBox message;

    QSize sizeHint() const;
    void addCentralWidget();
    void addMenubar();
    void initStatusBar();
    void initActions();
    void initFileMenuActions();
    void initSignalsAndSlots();
};

#endif // MAINWINDOW_H
