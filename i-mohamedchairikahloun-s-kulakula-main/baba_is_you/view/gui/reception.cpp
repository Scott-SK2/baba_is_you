#include "reception.h"

Reception::Reception(){
    initial_attributs();
}

Reception::~Reception(){
    delete playButton;
    delete replayButton;
    delete optionButton;
    delete backgroundLabel;
    delete buttonLayout;
}

void Reception::initial_reception()
{
    add_background();
    add_buttons();
}

void Reception::add_background()
{
    backgroundLabel->setPixmap(QPixmap("./images/reception.png").scaled(600,500));
    backgroundLabel->setScaledContents(true);
    this->addWidget(backgroundLabel, 0, 0, 1, 2);
}

void Reception::add_buttons(){
    add_btns_decoration();
    // set the buttons in the hbox
    buttonLayout->addWidget(playButton);
    buttonLayout->addWidget(replayButton);
    buttonLayout->addWidget(optionButton);

    this->addLayout(buttonLayout, 0, 0, 1, 2);
}

void Reception::add_btns_decoration()
{
    playButton->setFixedSize(150, 50);
    replayButton->setFixedSize(150, 50);
    optionButton->setFixedSize(150, 50);
    playButton->setStyleSheet("QPushButton { background-color: blue; color: white; }");
    replayButton->setStyleSheet("QPushButton { background-color: green; color: white; }");
    optionButton->setStyleSheet("QPushButton { background-color: orange; color: white; }"); //
}

QPushButton & Reception::play_btn()
{
    return *playButton;
}

QPushButton & Reception::replay_btn()
{
    return *replayButton;
}

QPushButton & Reception::option_btn()
{
    return *optionButton;
}

void Reception::initial_attributs()
{
    backgroundLabel = new QLabel;
    playButton = new QPushButton("Play");
    replayButton = new QPushButton("Replay");
    optionButton = new QPushButton("- Option -");
    buttonLayout = new QHBoxLayout;
}

