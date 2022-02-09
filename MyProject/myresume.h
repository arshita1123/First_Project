#ifndef MYRESUME_H
#define MYRESUME_H

#include <QDialog>

namespace Ui {
class MyResume;
}

class MyResume : public QDialog
{
    Q_OBJECT

public:
    explicit MyResume(QWidget *parent = nullptr);
    ~MyResume();

private:
    Ui::MyResume *ui;
};

#endif // MYRESUME_H
