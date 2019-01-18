#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include <memory>
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
    void on_checkBox_windows_toggled(bool checked);

    void on_checkBox_beer_toggled(bool checked);

    void on_radioButton_dog_toggled(bool checked);

private:
    Ui::Widget *ui;
    QButtonGroup *b_group;
    QButtonGroup *b_drink_group;
    QButtonGroup *rb_pets_group;

    std::vector<QCheckBox*> *btns;
    void initBox();
    void initButtons();
    void initSignals();
    void checkingSlot(QString, bool&) const;
};

#endif // WIDGET_H
