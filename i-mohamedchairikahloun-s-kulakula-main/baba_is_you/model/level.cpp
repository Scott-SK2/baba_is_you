#include "level.h"
#include "board.h"

namespace model{


Level::Level(unsigned level_number): level_number_{level_number}
{}

void Level::read_file()
{
    std::fstream file;
    read_file(file);
    size();
}

void Level::save_level(Board board, unsigned level)
{
    std::fstream file;
    std::string file_name = "levels/level_5.txt";
    file.open(file_name, std::ofstream::out);
    //the size of level
    std::string size = std::to_string(board.width()) + " " + std::to_string(board.height()) + '\n';
    file << size;
    std::vector<std::pair<Position, ElementType>> vec = board.types_at_map();
    for(auto e : vec){
        Position pos = e.first;
        std::string s = string_text(e.second);
        std::string line = s + " " + std::to_string(pos.column()) + " " + std::to_string(pos.row());
        file << line + '\n';
    }
    file << std::to_string(level);
    file.close();
}


void Level::put_the_world(Board &board){
    //the first line is ignored
    for(unsigned i{1}; i < container_.size(); ++i){
        //each line of container
        auto line = container_[i];
        if(line.size() != 1){
            //position of element
            Position p(std::stoi(line.at(2)), std::stoi(line.at(1)));
            set_element_at_board(container_[i][0], board, p);
        }
    }
}


//Getters
unsigned Level::height(){
    return height_;
}

unsigned Level::width(){
    return width_;
}

unsigned Level::saved_level_number()
{
    auto lg{container_.back()};
    return  std::stoi(lg.at(0));
}

void Level::size(){
    //the first line that contains the height and width of the map
    auto lg{container_.at(0)};
    height_ = std::stoi(lg.at(0));
    width_ = std::stoi(lg.at(1));
}

void Level::read_file(std::fstream  & file)
{
    open_file(file);
    std::string my_line;
    if(file.is_open())    push_line_on_vector(file);
    else    throw std::invalid_argument("Fichier n'est pas ouvert");
    container_.pop_back();
    file.close();
}

void Level::open_file(std::fstream  & file)
{
    if(level_number_ > 5){
        throw std::invalid_argument("Your level doesn't existe!" + level_number_);
    }
    std::string file_name = "levels/level_";
    file_name += std::to_string(level_number_);
    file_name += ".txt";
    file.open(file_name);
}

void Level::push_line_on_vector(std::fstream  & file)
{
    std::string my_line;
    while(file){
        getline(file, my_line);
        std::stringstream ss(my_line);
        //vector contains all the words at the line
        std::vector<std::string> words;
        std::string word;
        while (ss >> word) {
            words.push_back(word);
        }
        container_.push_back(words);
    }
}

void Level::set_element_at_board(std::string s, Board &board,Position p){
    if(s == "is"){
        board.set_element(p, Element{ElementType::IS});
    }else if(s == "lava"){
        board.set_element(p, Element{ElementType::LAVA});
    }else if(s == "flag"){
        board.set_element(p, Element{ElementType::FLAG});
    }else if(s == "rock"){
        board.set_element(p, Element{ElementType::ROCK});
    }else if(s == "wall"){
        board.set_element(p, Element{ElementType::WALL});
    }else if(s == "grass"){
        board.set_element(p, Element{ElementType::GRASS});
    }else if(s == "metal"){
        board.set_element(p, Element{ElementType::METAL});
    }else if(s == "baba"){
        board.set_element(p, Element{ElementType::BABA});
    }else if(s == "water"){
        board.set_element(p, Element{ElementType::WATER});
    }else if(s == "kill"){
        board.set_element(p, Element{ElementType::KILL});
    }else if(s == "you"){
        board.set_element(p, Element{ElementType::YOU});
    }else if(s == "win"){
        board.set_element(p, Element{ElementType::WIN});
    }else if(s == "stop"){
        board.set_element(p, Element{ElementType::STOP});
    }else if(s == "push"){
        board.set_element(p, Element{ElementType::PUSH});
    }else if(s == "sink"){
        board.set_element(p, Element{ElementType::SINK});
    }else if(s == "text_water"){
        board.set_element(p, Element{ElementType::TWATER});
    }else if(s == "text_baba"){
        board.set_element(p, Element{ElementType::TBABA});
    }else if(s == "text_wall"){
        board.set_element(p, Element{ElementType::TWALL});
    }else if(s == "text_flag"){
        board.set_element(p, Element{ElementType::TFLAG});
    }else if(s == "text_rock"){
        board.set_element(p, Element{ElementType::TROCK});
    }else if(s == "text_lava"){
        board.set_element(p, Element{ElementType::TLAVA});
    }else {
        //if the object not declared on ElementType
        throw std::invalid_argument("Your object does not exicte!");
    }
}
std::string Level::string_text(ElementType type){
    switch (type) {
    case ElementType::BABA:
        return "baba";
    case ElementType::TBABA:
        return "text_baba";
    case ElementType::FLAG:
        return "flag";
    case ElementType::TFLAG:
        return "text_flag";
    case ElementType::GRASS:
        return "grass";
    case ElementType::IS:
        return "is";
    case ElementType::KILL:
        return "kill";
    case ElementType::LAVA:
        return "lava";
    case ElementType::WALL:
        return "wall";
    case ElementType::TWALL:
        return "text_wall";
    case ElementType::TLAVA:
        return "text_lava";
    case ElementType::WATER:
        return "water";
    case ElementType::TWATER:
        return "text_water";
    case ElementType::WIN:
        return "win";
    case ElementType::ROCK:
        return "rock";
    case ElementType::TROCK:
        return "text_rock";
    case ElementType::METAL:
        return "metal";
    case ElementType::PUSH:
        return "push";
    case ElementType::SINK:
        return "sink";
    case ElementType::STOP:
        return "stop";
case ElementType::YOU:
        return "you";
default:
        throw std::invalid_argument("You cant write this element at the file");
    }
}

} //namespace model
