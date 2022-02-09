/********************************************************************************
** Form generated from reading UI file 'myresume.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYRESUME_H
#define UI_MYRESUME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_MyResume
{
public:
    QHBoxLayout *horizontalLayout;
    QTextEdit *resume;

    void setupUi(QDialog *MyResume)
    {
        if (MyResume->objectName().isEmpty())
            MyResume->setObjectName(QString::fromUtf8("MyResume"));
        MyResume->resize(400, 300);
        horizontalLayout = new QHBoxLayout(MyResume);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        resume = new QTextEdit(MyResume);
        resume->setObjectName(QString::fromUtf8("resume"));

        horizontalLayout->addWidget(resume);


        retranslateUi(MyResume);

        QMetaObject::connectSlotsByName(MyResume);
    } // setupUi

    void retranslateUi(QDialog *MyResume)
    {
        MyResume->setWindowTitle(QCoreApplication::translate("MyResume", "Dialog", nullptr));
        resume->setHtml(QCoreApplication::translate("MyResume", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyResume: public Ui_MyResume {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYRESUME_H
