#include "position.h"
#include "direction.h"

namespace model {

Position::Position(int row, int column) : row_{row}, column_{column}
{}

//Getters
int Position::row()
{
    return row_;
}

int Position::column()
{
    return column_;
}

Position Position::next(Direction dir){
    switch (dir) {
    case Direction::UP:
        return Position(row_ -1, column_);
    case Direction::DOWN:
        return Position(row_+1, column_);
    case Direction::LEFT:
        return Position(row_, column_-1);
    default:
        return Position(row_, column_ +1);
    }
}

bool operator == (Position &p1 , Position &p2){
    return( p1.column() == p2.column()) && (p1.row() == p2.row());
}

Direction oposite(Direction dir)
{
    switch (dir) {
    case Direction::UP:
        return Direction::DOWN;
    case Direction::DOWN:
        return Direction::UP;
    case Direction::LEFT:
        return Direction::RIGHT;
    default:
        return Direction::LEFT;
    }
}

} //namespace model
