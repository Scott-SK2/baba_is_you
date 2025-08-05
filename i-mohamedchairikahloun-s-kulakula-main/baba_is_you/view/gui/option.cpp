#include "option.h"

Option::Option()
{
    add_app_decoration();
    initial_attributs();
}

void Option::initial_attributs()
{
    container = new QVBoxLayout(this);
    undoLabel = new QLabel("Z - UNDO");
    exitLabel = new QLabel("ESC - Exit");
    replayLabel = new QLabel("R - REPLAY");
    nextLevelLabel = new QLabel("N - NEXT LEVEL");
    previewLevelLabel = new QLabel("P - PREVIEW LEVEL");

}

void Option::add_app_decoration()
{
    this->setWindowTitle("Options");
    this->setWindowIcon(QIcon("./images/baba.png"));
    this->setStyleSheet("QDialog { background-color: black; }");

}

void Option::add_labels_decoration()
{
    undoLabel->setStyleSheet("QLabel { color: blue; font-size: 40px; }");
    exitLabel->setStyleSheet("QLabel { color: red; font-size: 40px; }");
    replayLabel->setStyleSheet("QLabel { color: green; font-size: 40px; }");
    nextLevelLabel->setStyleSheet("QLabel { color: purple; font-size: 40px; }");
    previewLevelLabel->setStyleSheet("QLabel { color: orange; font-size: 40px; }");
}

void Option::add_labels_in_container(){
    container->addWidget(undoLabel);
    container->addWidget(exitLabel);
    container->addWidget(replayLabel);
    container->addWidget(nextLevelLabel);
    container->addWidget(previewLevelLabel);
}

void Option::display_option()
{
    add_labels_in_container();
    add_labels_decoration();
    this->exec();
}


