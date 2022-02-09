#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QFileDialog>
#include<QScrollArea>
#include"myresume.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->text_obj);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    path = "";
    ui->text_obj->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString str = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(str);
    path = str;
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        QString text = in.readAll();
        ui->text_obj->setText(text);
        file.close();
    }
    else
    {
        ui->text_obj->setText("");
        QMessageBox::warning(this,"Error","Error in Opening the File");
        return;
    }



}


void MainWindow::on_actionSave_triggered()
{
    QFile file(path);

    if(file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&file);
        QString text = ui->text_obj->toPlainText();
        out<<text;
        file.flush();
        file.close();
        QMessageBox::information(this,"Success","File Saved Successfully");

    }
    else
    {
         ui->text_obj->setText("");
        QMessageBox::warning(this,"Error","Error in Opening the File");
    }
}


void MainWindow::on_actionSave_As_triggered()
{
    QString str = QFileDialog::getSaveFileName(this,"Open the file");
    QFile file(str);
    path = str;
    if(file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&file);
        QString text = ui->text_obj->toPlainText();
        out<<text;
        file.flush();
        file.close();
        QMessageBox::information(this,"Success","File Saved Successfully");

    }
    else
    {
         ui->text_obj->setText("");
        QMessageBox::warning(this,"Error","Error in Opening the File");
    }
}


void MainWindow::on_actionCut_triggered()
{
    ui->text_obj->cut();
}


void MainWindow::on_actionCopy_triggered()
{
     ui->text_obj->copy();
}


void MainWindow::on_actionPaste_triggered()
{
     ui->text_obj->paste();
}


void MainWindow::on_actionUndo_triggered()
{
     ui->text_obj->undo();
}


void MainWindow::on_actionRedo_triggered()
{
     ui->text_obj->redo();
}


void MainWindow::on_actionAbout_Me_triggered()
{
    /*  QMessageBox::about(this,"My Resume",  "<h4  style='margin-left:0; overflow : scroll; '>Arshita<br> #835, Street no.8, Guru Nanak Nagar<br> Patiala (Punjab)<br> Punjab - 147001<br>7814396214 <br>arshita2523@gmail.com<br></h4>"  "<h2>Educational Qualifications: </h2><table border='2'> <tr> <th>Year</th> <th>Degree</th> <th>School/Institute</th> <th>Board/University</th> <th>Percentage/SGPA</th> </tr>  <tr> <td>2021</td> <td>B.Tech <br>(CSE)</td> <td>Chandigarh Group Of Colleges, Landran (Mohali)</td> <td>Punjab Technical University</td> <td>9.0 SGPA</td> </tr> <tr> <td>2019</td> <td>10+2</td> <td>Govt. Senior Secondary Smart School, Civil Lines, Patiala</td> <td>PSEB</td> <td>93%</td> </tr> <tr> <td>2017</td> <td>Matric</td> <td>Guru Nanak Modern Senior Secondary School, Patiala</td> <td>PSEB</td> <td>92.7%</td></tr></table>" "<h2>Academic Achievements: </h2> <table border='2'> <tr> <th>S.No</th> <th>Title of Certification</th> <th>Issued By: </th> <th>Issue Date: </th> <th>Grade/Rank</th></tr> <tr> <td>1</td> <td>Getting Started With Python</td> <td>University Of Michigan</td> <td>15 May, 2021</td> <td>100%</td></tr> <tr> <td>2</td> <td>Technical Support Fundamentals</td> <td>Google</td> <td>9 February, 2021</td> <td>97%</td></tr> <tr> <td>3</td> <td>Programming with Python</td> <td>Internshala</td> <td>23 May, 2021</td> <td>73%</td></tr> <tr> <td>4</td> <td>Problem Solving (Basic)</td> <td>Hackerrank</td> <td>13 Jun, 2021</td> <td>83%</td></tr> <tr> <td>5</td> <td>Programming with C++</td> <td>TestDome</td> <td>20 Jun, 2021</td> <td>Top 25%</td></tr> <tr><td>6</td> <td>Programming with python</td> <td>TestDome</td> <td>17 July, 2021</td> <td>Top 25%</td></tr></table>" "<h2>Software Competencies: </h2> <table border='2'> <tr><td>Languages Known </td> <td>: </td> <td>C,C++, python,html,css</td></tr> <tr><td>Other Interests </td> <td>:</td> <td>Data Structures, Design and analysis of algorithms, Operating System </td></tr></table>" "<h2>Projects Undertaken: </h2> <table border='2'> <tr><td>Project Name: Fantasy Cricket Game</td></tr> <tr> <td>Environment </td> <td> : </td> <td>Windows 10, Python IDE 3.9.2, SQLite Studio 3.3.3, Qt Designer  </td> </tr> <tr><td>Languages/ Database </td> <td> : </td> <td>Python, Sqlite3</td></tr> <tr> <td>Role </td><td> : </td><td>All Work</td></tr> <tr> <td>Project Description </td> <td> : </td><td> <ul> <li> It is a virtual cricket game which has multiple names of team players.</li> <li> Here, you can create your own virtual team of real cricket players and score depending upon how your selected players perform in real world matches.</li> <li> To win a tournament, you must try and get the maximum points and the no.1 rank amongst the other participants.</li></ul></td></tr>  <tr> <td>Project Name: Student Result Management System</td></tr> <tr> <td>Environment </td> <td> : </td> <td>Windows 10, Microsoft Visual Studio Code</td></tr> <tr> <td>Languages/ Database </td> <td> : </td> <td>Python, SQLite3</td></tr> <tr><td>Role </td> <td> : </td> <td>All Work</td></tr> <tr><td>Project Description </td><td> : </td> <td><ul> <li> It is a system that can help educational institutes in managing their student related data.</li> <li> In this system, teachers/faculties can store the data related to their institution like the courses that they offer, the student data of their students, the result data of their students. </li> <li>•	This system helps them to update, retrieve and manipulate the data efficiently along with required successful validations on the data</li> <li> The system, reduces many limitations of traditional paper-work system as it works on the basis of database connectivity. </li></ul></td></tr> <tr>Project Name: ZIPPY: An E-Learning Platform</tr> <tr><td>Environment </td><td> : </td><td>Windows 10, Microsoft Visual Studio Code</td></tr> <tr> <td>Languages </td> <td> : </td><td>HTML,CSS</td></tr> <tr><td>Role </td> <td>: </td> <td>All Work</td></tr> <tr><td>Project Description </td><td> : </td><td><ul> <li> It is a single page static website for an E-learning platform “Zippy” for graduates.</li> <li> It contains homepage (containing navbar, about section, project section (the projects that they cover during learning process”, video project section (contains demo videos of some sample projects), pricing section, blog section, team members section, life at zippy section (giving a sneak-peak of the e-learning journey), and footer.</li></ul></td></tr> <tr>Project Name : HuntPost </tr> <tr><td>Environment </td><td> : </td><td>Windows 10, Microsoft Visual Studio Code</td> </tr> <tr><td>Languages/Database </td><td> : </td><td>Python, HTML, CSS, SQLite3</td></tr> <tr> <td>Role </td><td> : </td><td>All Work</td> </tr> <tr><td>Project Description </td><td> : </td><td> <ul> <li> This project is built using the “Django” framework of python programming</li> <li> Its working is based upon the concept of “authentication” and “authorization” in Django.</li> <li> Here, non-authenticated users are authorized to only view other user’s beautiful posts and the authenticated ones can create their own posts, update their profile, view theirs and others posts and can also comment on posts, just like Instagram.</li></ul></td></tr> <tr>Project Name: Portfolio Website</tr> <tr> <td>Environment </td><td> : </td><td>Windows 10, Microsoft Visual Studio Code</td></tr> <tr><td>Languages/Database </td><td> : </td><td>Python, HTML, CSS, SqLite3</td></tr> <tr> <td>Role </td><td> : </td><td>All Work</td></tr> <tr> <td>Project Description </td><td> : </td> <td> <ul> <li> This is my own portfolio website.</li> <li> I have used the “Django” framework of python programming in order to handle the backend-side functionalities. </li></ul></td></tr></table>");
*/
    MyResume obj;
    obj.setModal(true);
    obj.exec();
}


void MainWindow::on_actionBold_triggered()
{
    int var ;
    var = ui->text_obj->fontWeight();
    if(var==QFont::Normal)
    {
        ui->text_obj->setFontWeight(QFont::Bold);  //bold
    }
    else if(var == QFont::Bold)
    {
        ui->text_obj->setFontWeight(QFont::Normal);  //unbold
    }
}


void MainWindow::on_actionItalic_triggered()
{
    bool var;
    var = ui->text_obj->fontItalic();
    ui->text_obj->setFontItalic(!var);

}


void MainWindow::on_actionUnderline_triggered()
{

    bool var;
    var = ui->text_obj->fontUnderline();
    ui->text_obj->setFontUnderline(!var);
}


void MainWindow::on_actionSuperscript_triggered()
{
    QString text = ui->text_obj->textCursor().selectedText();
    ui->text_obj->textCursor().removeSelectedText();
    ui->text_obj->insertHtml(QString("<sup>%1</sup>").arg(text));
}


void MainWindow::on_actionSubscript_triggered()
{
    QString text = ui->text_obj->textCursor().selectedText();
    ui->text_obj->textCursor().removeSelectedText();
    ui->text_obj->insertHtml(QString("<sub>%1</sub>").arg(text));
}

