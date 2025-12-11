#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_verticalSlider_red_valueChanged(int value);

    void on_spinBox_red_valueChanged(int arg1);

    void on_verticalSlider_green_valueChanged(int value);

    void on_spinBox_green_valueChanged(int arg1);

    void on_verticalSlider_blue_valueChanged(int value);

    void on_spinBox_blue_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    void RGBAdjust();
    void Init();
};
#endif // MAINWINDOW_H
