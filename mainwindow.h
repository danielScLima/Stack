#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow
     * \param parent
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /*!
     * \brief on_insertPushButton_clicked
     */
    void on_insertPushButton_clicked();

    /*!
     * \brief on_RemovePushButton_clicked
     */
    void on_RemovePushButton_clicked();

    /*!
     * \brief on_TopPushButton_clicked
     */
    void on_TopPushButton_clicked();

private:
    Ui::MainWindow *ui;
    Stack stack;

    /*!
     * \brief updateImage
     */
    void updateImage();

    /*!
     * \brief renderImage
     */
    void renderImage();

    /*!
     * \brief updateDotFile
     */
    void updateDotFile();
};
#endif // MAINWINDOW_H
