#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateDotFile();
    updateImage();
    renderImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDotFile()
{
    std::ofstream myFile;

    QDir::setCurrent(QCoreApplication::applicationFilePath());

    myFile.open
    (
        "file.dot"
    );

    std::string textToFile = "digraph g{";
    textToFile += "head[shape=none fontcolor=blue];";

    auto vec = stack.getElementsAsVector();
    for (int index = 0; index < vec.size(); ++index)
    {
        auto entry = vec.at(index);
        textToFile += entry;

        if (index < vec.size()-1)
            textToFile += "->";
    }

    if (vec.size() == 0)
    {
        textToFile += "NULL [ fontcolor=red ];head -> NULL";
        textToFile += ";";
    }
    else
    {
        textToFile += ";";
        textToFile += "head -> "+vec.at(0)+";";
    }

    textToFile += "}";

    myFile << textToFile;
    myFile.close();
}

void MainWindow::updateImage()
{
    std::string message =
                "dot -Tpng file.dot > file.png";
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    system(message.c_str());
}

void MainWindow::renderImage()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    QPixmap image("file.png");
    ui->label->setPixmap(image);
    ui->label->show();
}

void MainWindow::on_insertPushButton_clicked()
{
    auto text = ui->lineEditOfInsert->text();
    stack.insertNode(text.toStdString());

    updateDotFile();
    updateImage();
    renderImage();

    ui->lineEditOfInsert->setText("");
}

void MainWindow::on_RemovePushButton_clicked()
{
    struct NodeOfStack* top = stack.removeNode();

    updateDotFile();
    updateImage();
    renderImage();

    if (top != nullptr)
        delete top;
}

void MainWindow::on_TopPushButton_clicked()
{
    struct NodeOfStack* top = stack.topNode();

    updateDotFile();
    updateImage();
    renderImage();

    if (top != nullptr)
    {
        ui->lineEditOfTop->setText(top->data.c_str());
    }
}
