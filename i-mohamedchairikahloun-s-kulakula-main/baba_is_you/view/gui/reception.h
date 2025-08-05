#ifndef RECEPTION_H
#define RECEPTION_H
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>


class Reception : public QGridLayout{


    QPushButton * playButton;
    QPushButton * replayButton;
    QPushButton * optionButton;
    QLabel * backgroundLabel;
    QHBoxLayout * buttonLayout;

    void add_background();
    void add_buttons();
    void add_btns_decoration();
    void initial_attributs();

public:

    /**
     * @brief Reception Constructor of reception and pointers Qwidget Object
     */
    Reception();

    /**
     * @brief display_reception
     */
    void initial_reception();

    /**
     * Destructor of all the pointers that we initilize
     */
    ~Reception();

    /**
     * @brief play_btn Getter of play button
     * @return reference of playButton
     */
    QPushButton & play_btn();
    /**
     * @brief replay_btn Getter of replay button
     * @return reference of replayButton
     */
    QPushButton & replay_btn();
    /**
     * @brief option_btn Getter of option button
     * @return reference of optionButton
     */
    QPushButton & option_btn();
};



#endif // RECEPTION_H
