#ifndef OPTION_H
#define OPTION_H

#include <QLabel>
#include <QDialog>
#include <QVBoxLayout>

class Option : public QDialog
{
    QLabel* undoLabel;
    QLabel* exitLabel;
    QLabel* replayLabel;
    QLabel* nextLevelLabel;
    QLabel* previewLevelLabel;
    QVBoxLayout * container;

private:

    void initial_attributs();
    void add_app_decoration();
    void add_labels_decoration();
    void add_labels_in_container();

public:


    /**
     * @brief Option add the decoration to the application
     * and initial all the attribut.
     */
    Option();

    /**
     * @brief display_option Display the window of option to the player
     * to understrand the fonctionality of the game.
     */
    void display_option();

};


#endif // OPTION_H
