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

    // Init Signal Slot pour la sauvegarde de fichier et la gestion de menu
    //connect(ui->centralwidget, SIGNAL(contentsChanged()), this, SLOT(documenWasModified()));

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveAs()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));

    ///connect(ui->actionAbout_Qt, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    //

    // Init variables pour la sauvegarde/chargement de fichier
    currentFile = "";
    setUnifiedTitleAndToolBarOnMac(true);
    //

    ui->label_name_current_file->setText("---"); // Met à none le nom du fichier ouvert actuelement
}

MainWindow::~MainWindow()
{
    delete modeleCouleurs;
    delete ui;
}

void MainWindow::on_verticalSlider_red_valueChanged(int value)
{
    ui->spinBox_red->setValue(value); // Associe la valeur du slider à la valeur du spinbox
    // Met à jour le label couleur avec la nouvelle couleur
    ui->label_color->setColor(ui->verticalSlider_red->value(), ui->verticalSlider_green->value(), ui->verticalSlider_blue->value());
    //
}


void MainWindow::on_spinBox_red_valueChanged(int arg1)
{
    ui->verticalSlider_red->setValue(arg1); // Associe la valeur du spinbox à la valeur du slider
    // Met à jour le label couleur avec la nouvelle couleur
    ui->label_color->setColor(ui->verticalSlider_red->value(), ui->verticalSlider_green->value(), ui->verticalSlider_blue->value());
    //
}


void MainWindow::on_verticalSlider_green_valueChanged(int value)
{
    ui->spinBox_green->setValue(value); // Associe la valeur du slider à la valeur du spinbox
    // Met à jour le label couleur avec la nouvelle couleur
    ui->label_color->setColor(ui->verticalSlider_red->value(), ui->verticalSlider_green->value(), ui->verticalSlider_blue->value());
    //
}


void MainWindow::on_spinBox_green_valueChanged(int arg1)
{
    ui->verticalSlider_green->setValue(arg1); // Associe la valeur du spinbox à la valeur du slider
    // Met à jour le label couleur avec la nouvelle couleur
    ui->label_color->setColor(ui->verticalSlider_red->value(), ui->verticalSlider_green->value(), ui->verticalSlider_blue->value());
    //
}


void MainWindow::on_verticalSlider_blue_valueChanged(int value)
{
    ui->spinBox_blue->setValue(value); // Associe la valeur du slider à la valeur du spinbox
    // Met à jour le label couleur avec la nouvelle couleur
    ui->label_color->setColor(ui->verticalSlider_red->value(), ui->verticalSlider_green->value(), ui->verticalSlider_blue->value());
    //
}


void MainWindow::on_spinBox_blue_valueChanged(int arg1)
{
    ui->verticalSlider_blue->setValue(arg1); // Associe la valeur du spinbox à la valeur du slider
    // Met à jour le label couleur avec la nouvelle couleur
    ui->label_color->setColor(ui->verticalSlider_red->value(), ui->verticalSlider_green->value(), ui->verticalSlider_blue->value());
    //
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
    ui->label_color->setColor(newColor); // Met à jour le label couleur
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
    MyLabel *currentSave = ColorConcerve[circularIncrementation];
    currentSave->setColor(currentColor);
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

    ui->label_name_current_file->setStyleSheet("color:rgb(0, 85, 255);"); // Montre que le fichier a été modifié et pas sauvagardé
}

void MainWindow::newFile()
{
    currentFile = QFileDialog::getSaveFileName(this, tr("Sauvegarder le fichier"), "", tr("Fichiers texte (*.pal)"));

    if(currentFile != ""){
        QFile file(currentFile);
        QFileInfo infoF(file);

        ui->label_name_current_file->setText(infoF.fileName()); // Change le nom du fichier affiché

        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream stream(&file);
        stream << "\n\n\n\n\n\n";

        ui->label_name_current_file->setStyleSheet(""); // Montre que le fichier a été sauvegardé

        file.close();
    }

}

void MainWindow::open()
{
    currentFile = QFileDialog::getOpenFileName(this, tr("Charger un fichier"), "", tr("Fichiers texte (*.pal)"));

    if(currentFile != ""){
        QFile file(currentFile);
        QFileInfo infoF(file);

        ui->label_name_current_file->setText(infoF.fileName()); // Change le nom du fichier affiché
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QString txt = file.readAll();
            QStringList NewVal = txt.split("\n");

            if(NewVal.size() == 7){
                for (int i = 0; i < 6; ++i)
                {
                    if(NewVal[i] == "")
                    {
                        ColorConcerve[i]->clear();
                    }
                    else
                    {
                        ColorConcerve[i]->setColor(QColor(NewVal[i]));

                        if(i==5)
                        {
                            circularIncrementation = 0;
                        }
                        else
                        {
                            circularIncrementation = i+1;
                        }

                    }
                }
            }
        }

        ui->label_name_current_file->setStyleSheet(""); // Montre que le fichier n'a pas de modification en cours


        file.close();
    }
}

bool MainWindow::save()
{
    if(currentFile == "")
    {
        currentFile = QFileDialog::getSaveFileName(this, tr("Sauvegarder le fichier"), "", tr("Fichiers texte (*.pal)"));
    }

    if(currentFile != ""){
        QFile file(currentFile);
        QFileInfo infoF(file);

        ui->label_name_current_file->setText(infoF.fileName()); // Change le nom du fichier affiché
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);

            for (int i = 0; i < 6; ++i)
            {
                stream << ColorConcerve[i]->text() + "\n";
            }

            if(file.flush())
            {
                ui->label_name_current_file->setStyleSheet(""); // Montre que le fichier a été sauvegardé
                file.close();
                return true;
            }
            else
            {
                file.close();
                return false;
            }
        }
    }
    return false;
}

bool MainWindow::saveAs()
{
    currentFile = QFileDialog::getSaveFileName(this, tr("Sauvegarder le fichier"), "", tr("Fichiers texte (*.pal)"));

    if(currentFile != ""){
        QFile file(currentFile);
        QFileInfo infoF(file);

        ui->label_name_current_file->setText(infoF.fileName()); // Change le nom du fichier affiché
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);

            for (int i = 0; i < 6; ++i)
            {
                stream << ColorConcerve[i]->text() + "\n";
            }

            if(file.flush())
            {
                ui->label_name_current_file->setStyleSheet(""); // Montre que le fichier a été sauvegardé
                file.close();
                return true;
            }
            else
            {
                file.close();
                return false;
            }


        }
    }
    return false;
}

void MainWindow::about()
{

}

void MainWindow::documenWasModified()
{

}

