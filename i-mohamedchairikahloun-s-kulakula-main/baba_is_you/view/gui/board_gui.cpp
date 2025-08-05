#include "board_gui.h"

namespace view_gui
{

QBoard::QBoard()
    : rock("./images/rock.png"), baba("./images/baba.png"), earth("./images/earth.png"),
      water("./images/water.png") , gras("./images/gras.png") , flag("./images/flag.png"),
      wall("./images/wall.png"), metal("./images/metal.png"), lava("./images/lava.png"),
      kill("./images/kill.png"), you("./images/you.png"), win("./images/win.png"),
      stop("./images/stop.png"), push("./images/push.png"), sink("./images/sink.png"),
      is("./images/is.png"), text_water("./images/twater.png"), text_baba("./images/tbaba.png"),
      text_wall("./images/twall.png"), text_flag("./images/tflag.png"), text_rock("./images/trock.png"),
      text_lava("./images/tlava.png"), cadre("./images/cadre.png")
{
    this->setSpacing(0);
}

QBoard::~QBoard()
{
    clear_world();
}

void QBoard::display_world(std::vector<std::vector<model::Box>> map)
{
    //display the above frame of the game
    display_header_or_footer();

    for(auto &e : map){
        QHBoxLayout * line = new QHBoxLayout;
        line->setContentsMargins(0, 0, 0, 0);
        line->setSpacing(0);

        add_cadre_picture(line);

        for(auto &box : e){
            //add the picture to the Line
            add_picture_in_hbox(box.last_element().type(), line);
        }

        add_cadre_picture(line);
        this->addLayout(line);
    }

    //display the below frame of the game
    display_header_or_footer();
}

void QBoard::clear_world()
{
    QLayoutItem* item;
    while((item = this->takeAt(0)) != nullptr){

        QLayoutItem* item2;
        while((item2 = item->layout()->takeAt(0)) != nullptr){
            item->layout()->removeItem(item2);
            delete item2->widget();
            delete item2;
        }
        this->removeItem(item->layout());  //remove the QHBoxLayout from the application
        delete item->layout();      //delete the zone of QHBoxLayout
    }
    delete item;    //delete the layout item itself
}


void QBoard::add_cadre_picture(QHBoxLayout *hbox)
{
    QLabel * image = new QLabel;
    image->setPixmap(cadre.scaled(30, 30));
    image->setScaledContents(true);
    hbox->addWidget(image);
}

void QBoard::display_header_or_footer()
{
        QHBoxLayout * line = new QHBoxLayout;
        line->setContentsMargins(0, 0, 0, 0);
        line->setSpacing(0);

        for(int i = 0; i < 20; ++i){
            QLabel * image = new QLabel;
            image->setPixmap(cadre.scaled(30, 30));
            image->setScaledContents(true);
            line->addWidget(image);
        }
        this->addLayout(line);
}

void QBoard::add_picture_in_hbox(model::ElementType type, QHBoxLayout *hbox)
{
    QLabel * image = new QLabel;
    switch (type) {
    case model::ElementType::FLAG :
        image->setPixmap(flag.scaled(30,30));
        break;
    case model::ElementType::WALL :
        image->setPixmap(wall.scaled(30,30));
        break;
    case model::ElementType::METAL :
        image->setPixmap(metal.scaled(30,30));
        break;
    case model::ElementType::BABA :
        image->setPixmap(baba.scaled(30,30));
        break;
    case model::ElementType::ROCK :
        image->setPixmap(rock.scaled(30,30));
        break;
    case model::ElementType::WATER :
        image->setPixmap(water.scaled(30,30));
        break;
    case model::ElementType::LAVA :
        image->setPixmap(lava.scaled(30,30));
        break;
    case model::ElementType::GRASS :
        image->setPixmap(gras.scaled(30,30));
        break;
    case model::ElementType::KILL :
        image->setPixmap(kill.scaled(30,30));
        break;
    case model::ElementType::YOU :
        image->setPixmap(you.scaled(30,30));
        break;
    case model::ElementType::WIN :
        image->setPixmap(win.scaled(30,30));
        break;
    case model::ElementType::STOP :
        image->setPixmap(stop.scaled(30,30));
        break;
    case model::ElementType::PUSH :
        image->setPixmap(push.scaled(30,30));
        break;
    case model::ElementType::SINK :
        image->setPixmap(sink.scaled(30,30));
        break;
    case model::ElementType::IS :
        image->setPixmap(is.scaled(30,30));
        break;
    case model::ElementType::TWATER :
        image->setPixmap(text_water.scaled(30,30));
        break;
    case model::ElementType::TBABA :
        image->setPixmap(text_baba.scaled(30,30));
        break;
    case model::ElementType::TWALL :
        image->setPixmap(text_wall.scaled(30,30));
        break;
    case model::ElementType::TFLAG :
        image->setPixmap(text_flag.scaled(30,30));
        break;
    case model::ElementType::TROCK :
        image->setPixmap(text_rock.scaled(30,30));
        break;
    case model::ElementType::TLAVA :
        image->setPixmap(text_lava.scaled(30,30));
        break;
    default:
        image->setPixmap(earth.scaled(30,30));
        break;
    }

    image->setScaledContents(true);
    hbox->addWidget(image);
}



}   //namespace view_gui







