#include "view.h"

namespace model{

View::View(): header(95, '_'), footer(95, '-')
{}

void View::display_welcome() {
    std::cout << " " << header<< std::endl;
    std::cout <<"\t\tWelcome to the BABA IS YOU game  (Autor: Filali & Scott)"<< std::endl;
    std::cout << " " <<  footer << std::endl;
}

void View::display_menu() {
    std::string s(36,'_');
    std::cout << s << " How to play the game : " << s << std::endl;
    std::cout << "  *\t u - UP / l - LEFT / d - DOWN / r - RIGHT / z - UNDO / \n"
                 "  *  re - REPLAY / n - NEXT LEVEL / p - PREVIOUS LEVEL / h - help / q - Exit  " << std::endl;
}

void View::display_board(std::vector<std::vector<Box>> map)
{
    std::cout << " " <<  header << std::endl;
    for(auto &e : map){
        std::cout << "|  ";
        for(auto &box : e){
            std::cout << box.last_element() << " ";
        }
        std::cout << "  |" <<std::endl;
    }
    std::cout << " " <<  footer << std::endl;
}

void View::display_end_level(){
    std::cout << "NEXT LEVEL : " << std::endl;
}

void View::ask_direction(){
    std::cout << "Enter your command : ";
}

void View::display_error(){
    std::cout << "Your command is not valid!" << std::endl;
}

void View::display_continue()
{
    std::cout << "Tap 'y' if you want continue the game : ";
}


}



