#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <vector>
#include <memory>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:

    int WINDOW_WIDTH{310};
    int WINDOW_HEIGHT{380};
    int BUTTON_WIDTH{50};
    int BUTTON_HEIGHT{25};
    QFont textFont;
    QLabel *mLabel;
    QTextEdit *textEdit;
    // buttons container
    std::shared_ptr<std::vector<QPushButton*>> buttons;

    void initLabels();
    void initButtons();
    void initText();
    void initSignalsAndSlots();
    QSize sizeHint() const;
};

#endif // WIDGET_H
