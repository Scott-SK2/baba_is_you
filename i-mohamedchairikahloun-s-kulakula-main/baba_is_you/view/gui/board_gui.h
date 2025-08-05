#ifndef BOARD_GUI_H
#define BOARD_GUI_H

#include <QVBoxLayout>
#include <QLabel>
#include "model/box.h"

namespace view_gui
{


class QBoard : public QVBoxLayout
{

    //all the pictures
    QPixmap const rock;
    QPixmap const baba;
    QPixmap const earth;
    QPixmap const water;
    QPixmap const gras;
    QPixmap const flag;
    QPixmap const wall;
    QPixmap const metal;
    QPixmap const lava;
    QPixmap const kill;
    QPixmap const you;
    QPixmap const win;
    QPixmap const stop;
    QPixmap const push;
    QPixmap const sink;
    QPixmap const is;
    QPixmap const text_water;
    QPixmap const text_baba;
    QPixmap const text_wall;
    QPixmap const text_flag;
    QPixmap const text_rock;
    QPixmap const text_lava;
    QPixmap const cadre;

private:

    //the decoration above and below the table
    void display_header_or_footer();
    void delete_all_childre_line(QLayoutItem & hbox);

    void add_cadre_picture(QHBoxLayout *hbox);
    void add_picture_in_hbox(model::ElementType type, QHBoxLayout *hbox);

    void clear_world();

    void initial_pictures_size();

public:

    /**
     * @brief QBoard Contructor initializes all the pictures
     * and display the graphic table
     */
    QBoard();

    /**
     * Detructor of all the pointer that QBoard object create
     */
    ~QBoard();

    /**
     * @brief display_world Display the graphic table with the images of elements
     * @param map the Map of the the game (each level has his own map)
     */
    void display_world(std::vector<std::vector<model::Box>> map);



};


}   //namespace view_gui

#endif // BOARD_GUI_H
