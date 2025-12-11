#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();

    // Init la liste de couleurs préfabriqué
    QStringList listeCouleurs = QColor::colorNames();
    modeleCouleurs = new QStringListModel(listeCouleurs);
    ui->listView_colorNames->setModel(modeleCouleurs);
    //

    // Init la logique de la conservation de couleur
    circularIncrementation = 0;
    ColorConcerve[0] = ui->label_choix1;
    ColorConcerve[1] = ui->label_choix2;
    ColorConcerve[2] = ui->label_choix3;
    ColorConcerve[3] = ui->label_choix4;
    ColorConcerve[4] = ui->label_choix5;
    ColorConcerve[5] = ui->label_choix6;
    //
}

MainWindow::~MainWindow()
{
    delete modeleCouleurs;
    delete ui;
}

void MainWindow::on_verticalSlider_red_valueChanged(int value)
{
    ui->spinBox_red->setValue(value); // Associe la valeur du slider à la valeur du spinbox
    RGBAdjust(); // Met à jour le label couleur avec la nouvelle couleur
}


void MainWindow::on_spinBox_red_valueChanged(int arg1)
{
    ui->verticalSlider_red->setValue(arg1); // Associe la valeur du spinbox à la valeur du slider
    RGBAdjust(); // Met à jour le label couleur avec la nouvelle couleur
}


void MainWindow::on_verticalSlider_green_valueChanged(int value)
{
    ui->spinBox_green->setValue(value); // Associe la valeur du slider à la valeur du spinbox
    RGBAdjust(); // Met à jour le label couleur avec la nouvelle couleur
}


void MainWindow::on_spinBox_green_valueChanged(int arg1)
{
    ui->verticalSlider_green->setValue(arg1); // Associe la valeur du spinbox à la valeur du slider
    RGBAdjust(); // Met à jour le label couleur avec la nouvelle couleur
}


void MainWindow::on_verticalSlider_blue_valueChanged(int value)
{
    ui->spinBox_blue->setValue(value); // Associe la valeur du slider à la valeur du spinbox
    RGBAdjust(); // Met à jour le label couleur avec la nouvelle couleur
}


void MainWindow::on_spinBox_blue_valueChanged(int arg1)
{
    ui->verticalSlider_blue->setValue(arg1); // Associe la valeur du spinbox à la valeur du slider
    RGBAdjust(); // Met à jour le label couleur avec la nouvelle couleur
}

void MainWindow::RGBAdjust()
{
    ui->label_color->setAutoFillBackground(true);

    // Recupère la couleur actuelle
    QPalette palette;
    QColor currentColor(ui->spinBox_red->value(), ui->spinBox_green->value(), ui->spinBox_blue->value());
    //

    // Attribue la couleur au fond du label couleur
    palette.setColor(QPalette::Window, currentColor);
    ui->label_color->setPalette(palette);
    //

    ui->label_color->setText(currentColor.name()); // Attribue le code hexa au texte du label couleur
}

void MainWindow::Init()
{
    // Initialise à 255 tout les sliders
    ui->verticalSlider_red->setValue(255);
    ui->verticalSlider_green->setValue(255);
    ui->verticalSlider_blue->setValue(255);
    //
}

void MainWindow::ColorChoice(QModelIndex model)
{
    QVariant nom = model.data(Qt::DisplayRole); // Recupère le nom de la couleur choisi
    QColor newColor(nom.toString()); // Recupère la couleur associé au nom
    ui->verticalSlider_red->setValue(newColor.red()); // Recupère et associe le code rouge
    ui->verticalSlider_green->setValue(newColor.green()); // Recupère et associe le code vert
    ui->verticalSlider_blue->setValue(newColor.blue()); // Recupère et associe le code bleu
    RGBAdjust(); // Met à jour le label couleur
}


void MainWindow::on_listView_colorNames_clicked(const QModelIndex &index)
{
    ColorChoice(index); // Met à jour les sliders et le label couleur avec la couleur choisi
}


void MainWindow::on_pushButton_conserver_clicked()
{
    // Recupère la couleur actuelle
    QPalette palette;
    QColor currentColor(ui->spinBox_red->value(), ui->spinBox_green->value(), ui->spinBox_blue->value());
    palette.setColor(QPalette::Window, currentColor);
    //

    // Attribue la couleur à son espace de stockage en fonction de
    // la logique de distribution circulaire géré par "circularIncementation"
    QLabel *currentSave = ColorConcerve[circularIncrementation];
    currentSave->setAutoFillBackground(true);
    currentSave->setText(ui->label_color->text());
    currentSave->setPalette(palette);
    //

    // Attribue un nouvel indice en fonction de l'ancien pour la prochaine conservation
    if(circularIncrementation == 5)
    {
        circularIncrementation = 0;
    }
    else
    {
        circularIncrementation ++;
    }
    //
}

