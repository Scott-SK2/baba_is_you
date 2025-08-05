#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <vector>
#include "model/box.h"

namespace model
{
class View
{
private:
    unsigned level_;
    const std::string header;
    const std::string footer;


public:
    View();

    void display_welcome();
    void display_menu();
    void display_board(std::vector<std::vector<Box>> map);
    void display_end_level();

    void ask_direction();
    void display_error();
    void display_continue();

};

}//namespace model



#endif // VIEW_H
