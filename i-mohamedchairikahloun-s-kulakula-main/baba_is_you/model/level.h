#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include "position.h"
#include "element.h"


namespace model {

class Board;

class Level
{
    unsigned level_number_;
    //height of the game's board
    unsigned height_;
    //width of the game's board
    unsigned width_;

    //vector contains all the lines of the file
    std::vector<std::vector<std::string>> container_;


    void open_file(std::fstream  & file);
    void read_file(std::fstream  & file);
    //push each line on container_
    void push_line_on_vector(std::fstream  & file);
    //inizial height_ and width_
    void size();

    //with string of text we check the element that we will put on the table
    void set_element_at_board(std::string s,Board &board,Position p);
    std::string string_text(ElementType type);

public:
    Level() = default;
    Level(unsigned level_number);
    /**
     * @brief read_file Read a file and initial the size of level
     */
    void read_file();
    /**
     * @brief put_the_world Put all the elemnt that we read on the Board
     * @param board Board where we set the elements
     */
    void put_the_world(Board &board);

    /**
     * @brief save_level Write the level in the file
     */
    void save_level(Board board, unsigned level);

    //Getters
    unsigned height();
    unsigned width();
    unsigned saved_level_number();


};

}   //namespace model

#endif // LEVEL_H
