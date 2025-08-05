#include <iostream>
#include "test.h"
#include "model/direction.h"
#include "model/move_command.h"

void test(){
    std::string s(100,'_');
    std::string t(100,'-');
    std::cout << s << std::endl;
    test_element();
    test_box();
    test_level();
    test_board();
    test_rule();
    test_move_cmd();
    std::cout << t << std::endl;
}

//=============================   Element   =========================
void test_element()
{
    std::cout << "|Element tests : " << std::endl;
    bool test_passed = true;
    model::Element e(model::ElementType::BABA);

    if(!(e.state() == model::State::TRAVERSABLE || e.type() != model::ElementType::BABA))
        test_passed = false;

    e.state(model::State::PUSHABLE);
    e.type(model::ElementType::WALL);

    if(e.state() != model::State::PUSHABLE || e.type() != model::ElementType::WALL)
        test_passed = false;

    if(test_passed)
        std::cout << "|\tpassed test element :)" << std::endl;
    else
        std::cout << "|\tfailled test element :(" << std::endl;

}

//======================================    Box    =====================
void test_box(){
    std::cout << "|Box tests : " << std::endl;
    default_earth_in_box();
    change_type_box();
    change_state_box();
    get_type_and_state();
//   exception();
}

void default_earth_in_box(){
    model::Box box;

    if(box.last_element().type() == model::ElementType::EARTH && box.size() == 1){
        std::cout << "|\tpassed Earth in the box :)" << std::endl;
    }else{
        std::cout << "|\tpassed Earth in the box :(" << std::endl;
    }
}

void change_type_box(){
    model::Box box;
    bool test_passed = true;
    box.add_element(model::Element(model::ElementType::BABA));

    if(!box.contains(model::ElementType::BABA)
            || box.size() != 2
            || box.last_element().type() != model::ElementType::BABA)
        test_passed = false;

    box.change_type(model::ElementType::BABA, model::ElementType::WALL);

    if(box.last_element().type() != model::ElementType::WALL)
        test_passed =false;

    if(test_passed){
        std::cout << "|\tpassed add element :)" << std::endl;
        std::cout << "|\tpassed change type :)" << std::endl;

    }else{
        std::cout << "|\tfailled add element :(" << std::endl;
        std::cout << "|\tfailled change type :(" << std::endl;
    }

}
void change_state_box(){
    model::Box box;
    bool test_passed = true;

    box.add_element(model::Element(model::ElementType::ROCK));

    if(!box.contains(model::ElementType::ROCK)
            || box.size() != 2
            || box.last_element().type() != model::ElementType::ROCK)
        test_passed = false;

    box.add_element(model::Element(model::ElementType::FLAG));

    box.change_state(model::ElementType::FLAG, model::State::WINING);
    box.change_state(model::ElementType::ROCK, model::State::PUSHABLE);

    if(box.last_element().type() != model::ElementType::FLAG
            || box.size() != 3
            || !box.contains(model::ElementType::FLAG)
            || !box.contains(model::State::WINING)
            || box.last_element().state() != model::State::WINING)
        test_passed = false;

    //drop the flag
    box.drop_last();

    if(!box.contains(model::ElementType::ROCK)
            || box.size() != 2
            || box.last_element().state() != model::State::PUSHABLE)
        test_passed = false;

    if(test_passed){
        std::cout << "|\tpassed drop last :)" << std::endl;
        std::cout << "|\tpassed contains state :)" << std::endl;
        std::cout << "|\tpassed contains type :)" << std::endl;
        std::cout << "|\tpassed change state :)" << std::endl;
    }else{
        std::cout << "|\tfailled drop last :(" << std::endl;
        std::cout << "|\tfailled contains state :(" << std::endl;
        std::cout << "|\tfailled contains type :(" << std::endl;
        std::cout << "|\tfailled change state :(" << std::endl;
    }
}

void get_type_and_state()
{
    model::Box box;
    //add baba with state you
    box.add_element(model::Element{model::ElementType::BABA, model::State::YOU});
    //metal state traversable
    box.add_element(model::Element{model::ElementType::METAL});
    //flag state wining
    box.add_element(model::Element{model::ElementType::FLAG, model::State::WINING});

    model::ElementType result = box.type(model::State::WINING);
    model::ElementType exp_result = model::ElementType::FLAG;

    if(result == exp_result){
        std::cout << "|\tpassed type(State state) :)" << std::endl;
    }else{
        std::cout << "|\tfailled type(State state) :(" << std::endl;
    }

    model::State result2 = box.state(model::ElementType::BABA);
    model::State exp_result2 = model::State::YOU;

    if(result == exp_result){
        std::cout << "|\tpassed state(ElementType type) :)" << std::endl;
    }else{
        std::cout << "|\tfailled state(ElementType type) :(" << std::endl;
    }


}

void exception(){
    model::Box box;
    box.add_element(model::Element(model::ElementType::TWALL));
    model::Element baba(model::ElementType::BABA);
    baba.state(model::State::YOU);

    box.add_element(baba);
}

//===================================   Level   ======================
void test_level()
{
    std::cout << "|Level tests : " << std::endl;
    height_level();
    width_level();
}

void height_level()
{
    model::Level l(0);
    model::Level l1(1);

    l.read_file();
    l1.read_file();

    //test the first level
    unsigned exp_result = 18;
    unsigned result = l.height();

    if(exp_result == result){
        std::cout << "|\tpassed height level0 :)" << std::endl;
    }else{
        std::cout << "|\tfailled height level0 :(" << std::endl;
    }

    //test the second level
    unsigned exp_result2 = 18;
    unsigned result2 = l1.height();

    if(exp_result2 == result2){
        std::cout << "|\tpassed height level1 :)" << std::endl;
    }else{
        std::cout << "|\tfailled height level1 :(" << std::endl;
    }

}

void width_level()
{
    model::Level l(0);
    model::Level l1(1);

    l.read_file();
    l1.read_file();

    unsigned exp_result = 18;
    unsigned result = l.width();

    if(exp_result == result){
        std::cout << "|\tpassed width level0 :)" << std::endl;
    }else{
        std::cout << "|\tfailed width level0 :(" << std::endl;
    }

    //test the second level
    unsigned exp_result2 = 18;
    unsigned result2 = l1.width();

    if(exp_result2 == result2){
        std::cout << "|\tpassed width level1 :)" << std::endl;
    }else{
        std::cout << "|\tfailled width level1 :(" << std::endl;
    }
}

//===============================  Board  ==================
void test_board(){
    std::cout << "|Board tests : " << std::endl;
    all_positions_wall();
    positions_text();
    positions_of_state();
    change_type_board();
    change_state_board();
}

void all_positions_wall()
{
    model::Board board(0);

    board.set_element(model::Position(6,3), model::Element(model::ElementType::WATER));
    std::vector<model::Position> all_positions_of_wall;
    all_positions_of_wall.insert(all_positions_of_wall.end(), {
                                     model::Position(6,3), model::Position(6,4)
                                   , model::Position(6,5), model::Position(6,6)
                                   , model::Position(6,7), model::Position(6,8)
                                   , model::Position(6,9), model::Position(6,10)
                                   , model::Position(6,11), model::Position(6,12)
                                   , model::Position(6,13), model::Position(6,14)
                                   , model::Position(10,3), model::Position(10,4)
                                   , model::Position(10,5), model::Position(10,6)
                                   , model::Position(10,7), model::Position(10,8)
                                   , model::Position(10,9), model::Position(10,10)
                                   , model::Position(10,11), model::Position(10,12)
                                   , model::Position(10,13), model::Position(10,14)});

    if(board.positions_of_element(model::ElementType::WALL).size() != all_positions_of_wall.size()){
        std::cout << "|\tfailled positions_of_element(ElementType type) :(" << std::endl;
        return ;
    }

    for(unsigned i{}; i < all_positions_of_wall.size(); ++i){
        if(!(board.positions_of_element(model::ElementType::WALL).at(i) ==
                all_positions_of_wall.at(i))){
            std::cout << "|\tfailled positions_of_element(ElementType type) :(" << std::endl;
            return ;
        }
    }
    std::cout << "|\tpassed positions_of_element(ElementType type) :)" << std::endl;
}

void positions_of_state(){
    model::Board board(0);

    std::vector<model::Position> result = board.positions_of_element(model::State::PUSHABLE);
    std::vector<model::Position> exp_result;
    exp_result.insert(exp_result.end(),{
                          model::Position(6,3), model::Position(6,4)
                        , model::Position(6,5), model::Position(6,6)
                        , model::Position(6,7), model::Position(6,8)
                        , model::Position(6,9), model::Position(6,10)
                        , model::Position(6,11), model::Position(6,12)
                        , model::Position(6,13), model::Position(6,14)
                        , model::Position(10,3), model::Position(10,4)
                        , model::Position(10,5), model::Position(10,6)
                        , model::Position(10,7), model::Position(10,8)
                        , model::Position(10,9), model::Position(10,10)
                        , model::Position(10,11), model::Position(10,12)
                        , model::Position(10,13), model::Position(10,14)} );
    if(result.size() == exp_result.size()){
        for(unsigned i{}; i < result.size(); ++i){
            if(result[i] != exp_result[i]){
                std::cout << "|\tfailled positions_of_element(State state) :(" << std::endl;
                return ;
            }
        }
    }
    std::cout << "|\tpassed positions_of_element(State state) :)" << std::endl;
}


void positions_text()
{
    model::Board board(0);

    std::vector<model::Position> vec;
    vec.insert(vec.end(), {model::Position(4,4), model::Position(4,11)
                           ,model::Position(12,4), model::Position(12,11)});
    if(vec.size() != board.positions_text().size()){
        std::cout << "|\tfailled positions_text() Board :(" << std::endl;
        return ;
    }
    for(unsigned i{}; i < vec.size(); ++i)
    {
        if(vec.at(i) != board.positions_text().at(i)){
             std::cout << "|\tfailled positions_text() Board :(" << std::endl;
             return ;
        }
    }
    std::cout << "|\tpassed positions_text() Board :)" << std::endl;
}


void change_type_board(){
    model::Board board(0);
    bool test_passed = true;

    board.change_type(model::ElementType::BABA, model::ElementType::FLAG);
    std::vector<model::Position> vec = board.positions_of_element(model::State::WINING);
    if(board.contains(model::Position(8,5), model::State::YOU)
            || !board.contains(model::Position(8,5), model::State::WINING)
            || !board.positions_of_element(model::ElementType::BABA).empty()){
        std::cout << "|\tfailled change_type() Board :(" << std::endl;
        return ;
    }
    std::cout << "|\tpassed change_type Board :)" << std::endl;
}

void change_state_board(){
    model::Board board(0);

    board.change_state(model::ElementType::WALL, model::State::TRAVERSABLE);

    if(!board.positions_of_element(model::State::STOP).empty()){
        std::cout << "|\tfailled change_state() Board :(" << std::endl;
        return ;
    }

    std::cout << "|\tpassed change_state() Board :)" << std::endl;

}

//=============================  Rule  =====================================
void test_rule(){
    std::cout << "|Rule tests : " << std::endl;
    model::Board board(0);
    bool test_passed = true;

    model::Element text_wall = board.last_element(model::Position(4,4));
    model::Element wall = board.last_element(model::Position(6,3));
    model::Element metal = board.last_element(model::Position(7,3));
    model::Element rock = board.last_element(model::Position(8,8));
    model::Element baba = board.last_element(model::Position(8,5));
    model::Element flag = board.last_element(model::Position(8,12));

    if(text_wall.state() != model::State::PUSHABLE
            || text_wall.type() != model::ElementType::TWALL){
        test_passed = false;
    }

    if(wall.state() != model::State::STOP
            || wall.type() != model::ElementType::WALL){
        test_passed = false;
    }

    if(metal.state() != model::State::TRAVERSABLE
            || metal.type() != model::ElementType::METAL){
        test_passed = false;
    }

    if(rock.state() != model::State::PUSHABLE
            || rock.type() != model::ElementType::ROCK){
        test_passed = false;
    }

    if(baba.state() != model::State::YOU
            || baba.type() != model::ElementType::BABA){
        test_passed = false;
    }

    if(flag.state() != model::State::WINING
            || flag.type() != model::ElementType::FLAG){
        test_passed = false;
    }

    if(test_passed){
        std::cout << "|\tpassed applies_all_rulles() :)" << std::endl;
    }else{
        std::cout << "|\tfailled applies_all_rulles() :(" << std::endl;
    }
}

//============================== MoveCommand ===================
void test_move_cmd(){
    std::cout << "|MoveCommand tests : " << std::endl;
    model::Board board(0);
    bool test_passed = true;

    if(model::Position p(8,5); board.positions_of_element(model::State::YOU).at(0) != p){
        test_passed = false;
    }

    model::Move_command move(board, model::Direction::RIGHT);
    move.execute();

    if(model::Position p(8,6); board.positions_of_element(model::State::YOU).at(0) != p){
        test_passed = false;
    }

    move.unexecute();
    if(model::Position p(8,5); board.positions_of_element(model::State::YOU).at(0) != p){
        test_passed = false;
    }

    //set water in above the flag
    board.set_element(model::Position(8,12), model::ElementType::WATER);

    board.change_state(model::ElementType::WATER, model::State::YOU);

    model::Move_command move2(board, model::Direction::UP);
    move2.execute();

    model::Position baba(7,5);
    model::Position water(7,12);

    if(board.positions_of_element(model::ElementType::WATER).at(0) != water
            || board.positions_of_element(model::ElementType::BABA).at(0) != baba){
        test_passed = false;
    }

    board.change_state(model::ElementType::WATER, model::State::YOU);
    move2.unexecute();

    baba = model::Position(8,5);
    water = model::Position(8,12);

    if(board.positions_of_element(model::ElementType::WATER).at(0) != water
            || board.positions_of_element(model::ElementType::BABA).at(0) != baba){
        std::cout << "err1" << std::endl;
        test_passed = false;
    }

    if(test_passed){
        std::cout << "|\tpassed exucute MoveCommand :)" << std::endl;
        std::cout << "|\tpassed unexecute MoveCommand :)" << std::endl;
    }else{
        std::cout << "|\tfailled exucute MoveCommand :(" << std::endl;
        std::cout << "|\tfailled unexecute MoveCommand :(" << std::endl;
    }

}




