#include "dialog.h"
#include "ui_dialog.h"
#include <qdebug.h>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->rBtnRed, SIGNAL(clicked()), this, SLOT(setTextFontColor()) );
    connect(ui->rBtnBlue, SIGNAL(clicked()), this, SLOT(setTextFontColor()) );
    connect(ui->rBtnBlack, SIGNAL(clicked()), this, SLOT(setTextFontColor()) );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_chkBoxUnder_clicked(bool checked)
{
    QFont  font = ui->textEdit->font();
    font.setUnderline(checked);
    ui->textEdit->setFont(font);
    qDebug() << "Underline";
}

void Dialog::on_chkBoxBold_clicked(bool checked)
{
    QFont  font = ui->textEdit->font();
//    font.setBold(checked);
    qDebug() << "bold: checked = " << (checked ? "true" : "false");
    font.setWeight(checked ? QFont::Bold : QFont::Normal );
    ui->textEdit->setFont(font);
    qDebug() << "bold";
}

void Dialog::on_chkBoxItalic_clicked(bool checked)
{
    QFont  font = ui->textEdit->font();
//    font.setItalic(checked);
    qDebug() << "Italic: checked = " << (checked ? "true" : "false");
    font.setStyle(checked ? QFont::StyleItalic : QFont::StyleNormal );
    ui->textEdit->setFont(font);
    qDebug() << "Italic";
}

void Dialog::setTextFontColor()
{
    QPalette  plet = ui->textEdit->palette();
    if ( ui->rBtnBlue->isChecked() ) {
        plet.setColor(QPalette::Text, Qt::blue);
    } else if ( ui->rBtnRed->isChecked() ) {
        plet.setColor(QPalette::Text, Qt::red );
    } else if ( ui->rBtnBlack->isChecked() ) {
        plet.setColor(QPalette::Text, Qt::black );
    } else {
        plet.setColor(QPalette::Text, Qt::black );
    }

    ui->textEdit->setPalette(plet);
}
