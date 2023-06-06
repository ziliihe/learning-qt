#include "qwdlgmanual.h"

void QWDlgManual::on_chkBoxUnder(bool checked)
{
    QFont   font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxItlic(bool checked)
{
    QFont   font = txtEdit->font();
    font.setStyle(checked ? QFont::StyleItalic : QFont::StyleNormal);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxBold(bool checked) {
    QFont   font = txtEdit->font();
    font.setWeight(checked ? QFont::Bold : QFont::Normal);
    txtEdit->setFont(font);
}

QWDlgManual::QWDlgManual(QWidget *parent)
    : QDialog(parent)
{
    initUI();
    initSignalSlots();
    setWindowTitle("Form Created mannually");
}

QWDlgManual::~QWDlgManual()
{
}

void QWDlgManual::initUI() {
    // 创建三个 checkbox，水平布局
    chkBoxUnder = new QCheckBox(tr("Underline"));
    chkBoxBold  = new QCheckBox(tr("Bold"));
    chkBoxItalic= new QCheckBox(tr("Italic"));

    QHBoxLayout *HLay1 = new QHBoxLayout;
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxBold);
    HLay1->addWidget(chkBoxItalic);

    // 创建三个 RadioButton，水平布局
    rBtnBlack = new QRadioButton(tr("Black"));
    rBtnBlue  = new QRadioButton(tr("Blue"));
    rBtnRed   = new QRadioButton(tr("Red"));
    rBtnBlack->setChecked(true);

    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(rBtnRed);
    HLay2->addWidget(rBtnBlue);
    HLay2->addWidget(rBtnBlack);

    // 创建三个 PushButton, 水平布局
    btnOK     = new QPushButton(tr("确认"));
    btnCancel = new QPushButton(tr("取消"));
    btnClose  = new QPushButton(tr("退出"));
    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addStretch();
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);

    // 创建文本框，并设置初始字体
    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello World\n\nIt is New World\n");
    QFont   font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    // 创建垂直布局，并设置主布局
    QVBoxLayout *VLay = new QVBoxLayout;
    VLay->addLayout(HLay1);
    VLay->addLayout(HLay2);
    VLay->addWidget(txtEdit);
    VLay->addLayout(HLay3);
    setLayout(VLay);
}

void QWDlgManual::setTextFontColor()
{
    QPalette  plet = txtEdit->palette();
    if ( rBtnBlue->isChecked() ) {
        plet.setColor(QPalette::Text, Qt::blue);
    } else if ( rBtnRed->isChecked() ) {
        plet.setColor(QPalette::Text, Qt::red );
    } else if ( rBtnBlack->isChecked() ) {
        plet.setColor(QPalette::Text, Qt::black );
    } else {
        plet.setColor(QPalette::Text, Qt::black );
    }

    txtEdit->setPalette(plet);
}


void QWDlgManual::initSignalSlots()
{
    connect(rBtnBlue, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rBtnRed, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rBtnBlack, SIGNAL(clicked()), this, SLOT(setTextFontColor()));

    connect(chkBoxUnder, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxUnder(bool)));
    connect(chkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxItlic(bool)));
    connect(chkBoxBold, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxBold(bool)));

    connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
}
