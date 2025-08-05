#ifndef POSITION_H
#define POSITION_H

namespace model
{

//definition participé
enum class Direction;

/**
 * @brief The Position class Position of the box on the board
 */
class Position
{
    int row_;
    int column_;

public:
    Position(int row, int column);

    //Getters
    int row();
    int column();

    Position next(Direction dir);
};

bool operator == (Position &p1 ,Position &p2);
Direction oposite(Direction dir);


}   //namespace model

#endif // POSITION_H
