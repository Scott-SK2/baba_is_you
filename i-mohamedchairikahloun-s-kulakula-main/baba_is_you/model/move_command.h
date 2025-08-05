#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H

#include <vector>
#include "board.h"


namespace model {


class Move_command
{
    Board &board_;
    Direction dir_;
    unsigned numbers_of_you_;
    //the type of YOU
    ElementType you_;

    /**
     * @brief you_to_move_ vector contains position initial
     * and final of each element of you
     */
    std::vector<std::pair<Position, Position>> you_to_move_;
    std::vector<std::pair<int ,std::pair<Position, Position>>> many_you_to_move_;
    /**
     * @brief element_to_push_ vector contains position initial
     * and final of each element need to push
     */
    std::vector<std::pair<Position, Position>> element_to_push_;
    std::vector<std::pair<ElementType, Position>> element_to_kill_;
    std::vector<std::pair<Position, std::pair<ElementType, ElementType>>> element_to_sink_;

    bool text_pushed;

public:
    Move_command(Board &borad, Direction direction);

    /**
     * @brief execute Execute the user's Command
     */
    void execute();
    /**
     * @brief unexecute Cancel the last user's Command
     */
    void unexecute();

private:

    /**
     * @brief move_element move Element has the state on parameter
     * from position initial to the position final
     * @param position_initial the Position where is the element
     * @param position_final the Position that where we will move element to
     * @param state State of element to move
     */
    void move_element(Position position_initial, Position position_final, State state);
    void move_you();
    void push_element(Position position_initial, Position position_final, State state, Direction dir);
    Position final_position(Position position);


    void sink();
    void unsink();
    void kill();
    void unkill();
    void move_and_push();
    void back();
    void execute_rule();
    void unexecute_rule();

    bool in_table_and_not_stop(Position position);
    void put_in_the_vector(State state);
    void put_in_many_you_to_move();
    bool text_is_pushed(Position next_pos);

};

} // namespace model

#endif // MOVE_COMMAND_H
