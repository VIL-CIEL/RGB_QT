#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_verticalSlider_red_valueChanged(int value)
{
    ui->spinBox_red->setValue(value);
    RGBAdjust();
}


void MainWindow::on_spinBox_red_valueChanged(int arg1)
{
    ui->verticalSlider_red->setValue(arg1);
    RGBAdjust();
}


void MainWindow::on_verticalSlider_green_valueChanged(int value)
{
    ui->spinBox_green->setValue(value);
    RGBAdjust();
}


void MainWindow::on_spinBox_green_valueChanged(int arg1)
{
    ui->verticalSlider_green->setValue(arg1);
    RGBAdjust();
}


void MainWindow::on_verticalSlider_blue_valueChanged(int value)
{
    ui->spinBox_blue->setValue(value);
    RGBAdjust();
}


void MainWindow::on_spinBox_blue_valueChanged(int arg1)
{
    ui->verticalSlider_blue->setValue(arg1);
    RGBAdjust();
}

void MainWindow::RGBAdjust()
{
    ui->label_color->setAutoFillBackground(true);

    QPalette palette;
    QColor currentColor(ui->spinBox_red->value(), ui->spinBox_green->value(), ui->spinBox_blue->value());

    palette.setColor(QPalette::Window, currentColor);
    ui->label_color->setPalette(palette);

    ui->label_color->setText(currentColor.name());
}

void MainWindow::Init()
{
    ui->verticalSlider_red->setValue(255);
    ui->verticalSlider_green->setValue(255);
    ui->verticalSlider_blue->setValue(255);
}

