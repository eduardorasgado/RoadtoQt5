#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QColorDialog>
#include <QFontDialog>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_textcolor_clicked();

    void on_pushButton_background_color_clicked();

    void on_pushButton_font_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
