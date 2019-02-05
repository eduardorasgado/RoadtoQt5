#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QColor>
#include <QButtonGroup>
#include <QDebug>
#include <QColorDialog>
#include <QSettings>

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
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButton_saveColors_clicked();

    void on_pushButton_loadColors_clicked();

private:
    Ui::Widget *ui;
    // default data for QSettings
    QString companyName{"com"};
    QString applicationName{"qSettingsDemo"};
    QString buttonGroupName{"ButtonColor"};
    // to store initial button colors
    QList<QColor> colorList;
    QList<QWidget*> *buttonList;

    void setDefaultColors();
    void initButtonList();
    void getNewColor(int&);
    void saveColor(QString, QColor);
    QColor loadColor(QString);
    void setButtonColorBackground(QColor&, int&);
};

#endif // WIDGET_H
