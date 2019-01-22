#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // initialize lists to store custo tabs
    new_widgets = new QList<QWidget*>;
    new_layouts = new QList<QVBoxLayout*>;

    initGroupBoxes();
    initTabInCode();
}

Widget::~Widget()
{
    delete widget_tab4;
    delete layout_tab4;
    delete p_languages_group;
    delete new_layouts;
    delete new_widgets;
    delete ui;
}

void Widget::on_button_tab1_select_clicked()
{
    qDebug() << "Select";
    if(p_languages_group->checkedButton()){
        // if radio button is checked
        qDebug() << "Programming language is: "
                 << p_languages_group->checkedButton()->text();
    }
}

void Widget::initGroupBoxes()
{
    // for tab 1
    p_languages_group = new QButtonGroup(this);
    p_languages_group->addButton(ui->radioButton_cpp);
    p_languages_group->addButton(ui->radioButton_java);
    p_languages_group->addButton(ui->radioButton_python);
    p_languages_group->addButton(ui->radioButton_labview);

    // to hide new tab form
    ui->groupBox_new_tab_form->setVisible(false);
}

void Widget::initTabInCode()
{
    //creating a tab in code
    // Declare the widget
    widget_tab4 = new QWidget(this);

    // Declare the layout for the widget
    layout_tab4 = new QVBoxLayout(this);
    // adding elements
    layout_tab4->addWidget(new QPushButton("Button1", this));
    layout_tab4->addWidget(new QPushButton("Button2", this));
    layout_tab4->addWidget(new QPushButton("Button3", this));
    QPushButton * button4 = new QPushButton("Button4", this);

    // connect a slot to button4
    connect(button4, &QPushButton::clicked,[=](){
        qDebug() << "button 4 (custom tab) clicked";
    });
    layout_tab4->addWidget(button4);
    // adding a responsive spacer given the app widht and height
    layout_tab4->addSpacerItem(new QSpacerItem(this->width()/20,
                                               this->height()/10));
    // set the layout to the widget
    widget_tab4->setLayout(layout_tab4);

    // set the widget tab to tab container
    //ui->tabWidget->addTab(widget_tab4, "Tab 4");

    // to insert new tab in specific area between other tabs
    ui->tabWidget->insertTab(1, widget_tab4, "Tab 4");
}

void Widget::on_pushButton_new_section_clicked()
{
    // show a form to select user custom tab element
    ui->groupBox_new_tab_form->setVisible(true);
}

void Widget::on_pushButton_clicked()
{
    if(ui->lineEdit_new_tab->text() != "")
    {
        QWidget *wid = new QWidget(this);

        QVBoxLayout *layout = new QVBoxLayout(this);

        layout->addWidget(new QPushButton("Button1", this));

        wid->setLayout(layout);

        ui->tabWidget->addTab(wid, ui->lineEdit_new_tab->text());

        // to have the new tab available in all the class
        new_widgets->append(wid);
        new_layouts->append(layout);
    } else {
        QMessageBox::critical(this, "New tab",
                              "No title for new tab is set",
                              QMessageBox::Ok);
    }
}
