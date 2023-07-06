#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->radioButtonBlack,SIGNAL(clicked()), this, SLOT(setFontColor()));
    connect(ui->radioButton_Blue,SIGNAL(clicked()), this, SLOT(setFontColor()));
    connect(ui->radioButton_Red,SIGNAL(clicked()), this, SLOT(setFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButtonClear_clicked()
{
    ui->plainTextEdit->clear();
}


void Dialog::on_checkBox_clicked(bool checked)
{
    // 拿到当前字体
    QFont font = ui->plainTextEdit->font();
    // 设置下划线
    font.setUnderline(checked);
    // 再将字体写回plainTextEdit
    ui->plainTextEdit->setFont(font);

}



void Dialog::on_checkBox_2_clicked(bool checked)
{
    // 拿到当前字体
    QFont font = ui->plainTextEdit->font();
    // 设置下划线
    font.setItalic(checked);
    // 再将字体写回plainTextEdit
    ui->plainTextEdit->setFont(font);
}




void Dialog::on_checkBox_3_clicked(bool checked)
{
    // 拿到当前字体
    QFont font = ui->plainTextEdit->font();
    // 设置下划线
    font.setBold(checked);
    // 再将字体写回plainTextEdit
    ui->plainTextEdit->setFont(font);
}

void Dialog::setFontColor()
{
    QPalette palette = ui->plainTextEdit->palette();
    if(ui->radioButtonBlack->isChecked())
        palette.setColor(QPalette::Text,Qt::black);
    if(ui->radioButton_Blue->isChecked())
        palette.setColor(QPalette::Text,Qt::blue);
    if(ui->radioButton_Red->isChecked())
        palette.setColor(QPalette::Text,Qt::red);

    ui->plainTextEdit->setPalette(palette);
}

