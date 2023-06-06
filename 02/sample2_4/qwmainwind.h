#ifndef QWMAINWIND_H
#define QWMAINWIND_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QWMainWind; }
QT_END_NAMESPACE

class QWMainWind : public QMainWindow
{
    Q_OBJECT

public:
    QWMainWind(QWidget *parent = nullptr);
    ~QWMainWind();

private:
    Ui::QWMainWind *ui;
};
#endif // QWMAINWIND_H
