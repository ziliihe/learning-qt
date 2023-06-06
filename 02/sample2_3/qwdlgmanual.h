#ifndef QWDLGMANUAL_H
#define QWDLGMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QHBoxLayout>

class QWDlgManual : public QDialog
{
    Q_OBJECT
private:
    QCheckBox  *chkBoxUnder;
    QCheckBox  *chkBoxItalic;
    QCheckBox  *chkBoxBold;

    QRadioButton  *rBtnBlack;
    QRadioButton  *rBtnBlue;
    QRadioButton  *rBtnRed;

    QPlainTextEdit  *txtEdit;

    QPushButton   *btnOK;
    QPushButton   *btnCancel;
    QPushButton   *btnClose;

    // UI 创建与初始j化
    void initUI();
    // 初始化信号与槽的链接
    void initSignalSlots();

private slots:
    void on_chkBoxUnder(bool checked);
    void on_chkBoxItlic(bool checked);
    void on_chkBoxBold(bool checked);

    void setTextFontColor();
public:
    QWDlgManual(QWidget *parent = nullptr);
    ~QWDlgManual();
};
#endif // QWDLGMANUAL_H
