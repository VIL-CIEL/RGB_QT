#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QLabel>

#include "mylabel.h"

#include <QFileDialog>
#include <QFile>
#include <QFileInfo>

#include <QMessageBox>

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
    /// INTERACTION IHM
    void on_verticalSlider_red_valueChanged(int value);

    void on_spinBox_red_valueChanged(int arg1);

    void on_verticalSlider_green_valueChanged(int value);

    void on_spinBox_green_valueChanged(int arg1);

    void on_verticalSlider_blue_valueChanged(int value);

    void on_spinBox_blue_valueChanged(int arg1);

    void on_listView_colorNames_clicked(const QModelIndex &index);
    ///

    /// INTERACTION SOURIS
    void conserver_couleur(); // Slot pour doubleclicked sens principal vers stock

    void utiliser_couleur(); // Slot pour doubleclicked sens stock vers principal

    void changerLabelParDefault(); // Slot pour clicked

    void modifParDrop(); // Slot pour changed
    ///

    /// MENU
    void newFile(); // Slot pour actionNew

    void open(); // Slot pour actionOpen

    bool save(); // Slot pour actionSave

    bool saveAs(); // Slot pour actionSave_As

    void about(); // Slot pour actionAbout
    ///

private:
    Ui::MainWindow *ui;
    void Init(); // Initialise les sliders à 255 chacun

    void ColorChoice(QModelIndex model); // Met à jour le label couleurs et les sliders à la
                                         // nouvelle couleur choisi dans la liste préfabriqué

    QStringListModel *modeleCouleurs; // Model de liste des couleurs préfabriqué

    int circularIncrementation; // Compteur pour la logique de conservation de couleur

    MyLabel* ColorConcerve[6]; // Tableau de QLabel pour les 6 label de conservation de couleur

    QString currentFile; // Le nom du fichier en cours d'utilisation

    MyLabel *labelParDefault; // Le label qui sera modifié par les sliders etc..
};
#endif // MAINWINDOW_H
