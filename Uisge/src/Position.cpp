/** @file Position.cpp
 */
#include "Position.h"
#include <iostream>

// Constructors & Destructor
Position::Position() : mRow(A), mColumn(0), mVacant(true), mToken(NULL)
{
}

Position::Position(ROW row, COLUMN column) : mRow(row), mColumn(column), mVacant(true), mToken(NULL)
{
}

Position::~Position(void)
{
}

// Public Methods

ROW Position::getRow() const
{
    return mRow;
}

void Position::setRow(ROW row)
{ 
    if (checkRow(row))
        mRow=row;
}
COLUMN Position::getColumn() const
{ 
    return mColumn;
}

void Position::setColumn(COLUMN column)
{
    if (checkColumn(column))
        mColumn=column;
}
bool Position::Check() const
{
    return checkRow(getRow()) && checkColumn(getColumn()) ;
}
bool Position::isVacant() const
{
    return mVacant;
}

bool Position::isOccupied() const
{
    return !isVacant();
}
void Position::setVacant()
{
    mVacant=true;
}
void Position::setOccupied()
{
    mVacant = false;
}

Token* Position::getToken() const
{
    return mToken;
}

void  Position::connectTo(Token *token)
{
    mToken=token;
}

unsigned int Position::getDistance(Position* ToPosition) const
{
    int delta_h=getColumnDistance(ToPosition);   // horizontal distance
    int delta_v=getRowDistance(ToPosition);      // vertical distance

    delta_h= delta_h >0 ? delta_h : -delta_h;    // distances are positive
    delta_v= delta_v >0 ? delta_v : -delta_v;

    unsigned int distance = delta_h + delta_v;   // sum metrics

    return distance;
}
int Position::getRowDifference(Position *thePosition) const
{
/// \todo vertical difference
}

int Position::getColumnDifference(Position *thePosition) const
{
/// \todo horizontal difference
}

ADJACENCY Position::getAdjacency(Position* thePosition) const
{
    int delta_h=getColumnDifference(thePosition); // horizontal difference
    int delta_v=getRowDifference(thePosition);    // vertical difference

    //
    // from the differences in rows and columns, determine the direction
    //
    //             NORTH_WEST  NORTH   NORTH_EAST
    //             WEST        this    EAST
    //             SOUTH_WEST  SOUTH   SOUTH_EAST
    //

    // \todo insert the correct distances

    if ( (delta_h ==    )  &&  ( delta_v ==   ) ) return NORTH;
    if ( (delta_h ==    )  &&  ( delta_v ==   ) ) return NORTH_EAST;
    if ( (delta_h ==    )  &&  ( delta_v ==   ) ) return EAST;
    if ( (delta_h ==    )  &&  ( delta_v ==   ) ) return SOUTH_EAST;
    if ( (delta_h ==    )  &&  ( delta_v ==   ) ) return SOUTH;
    if ( (delta_h ==    )  &&  ( delta_v ==   ) ) return SOUTH_WEST;
    if ( (delta_h ==    )  &&  ( delta_v ==   ) ) return WEST;
    if ( (delta_h ==    )  &&  ( delta_v ==   ) ) return NORTH_WEST;

    return NOT_ADJACENT;
}

bool Position::isDiagonallyAdjacent(Position* thePosition) const
{
    switch (getAdjacency(thePosition))
    {
    case NORTH_EAST:
    case SOUTH_EAST:
    case SOUTH_WEST:
    case NORTH_WEST:
        return true;
    default:
        return false;
    }
    return false; // You should never get here.
}

// Private Methods
bool Position::checkRow(ROW row) const
{
    return ( (A <=row) && (row <= F) );
}

bool Position::checkColumn(COLUMN column) const
{
    return ( (1 <= column) && (column <= HORIZONTAL_DIM) );
}
