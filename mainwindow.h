#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QLabel>

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

    void on_listView_colorNames_clicked(const QModelIndex &index);

    void on_pushButton_conserver_clicked();

private:
    Ui::MainWindow *ui;
    void RGBAdjust(); // Met à jour le label couleur en fonction de la couleur actuelle
    void Init(); // Initialise les sliders à 255 chacun
    void ColorChoice(QModelIndex model); // Met à jour le label couleurs et les sliders à la
                                         // nouvelle couleur choisi dans la liste préfabriqué

    QStringListModel *modeleCouleurs; // Model de liste des couleurs préfabriqué
    int circularIncrementation; // Compteur pour la logique de conservation de couleur
    QLabel* ColorConcerve[6]; // Tableau de QLabel pour les 6 label de conservation de couleur
};
#endif // MAINWINDOW_H
