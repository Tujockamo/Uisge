/** @file GlobalDefs.h
 */
#ifndef GlobalDefs_H
#define GlobalDefs_H

// for the board dimensions

const unsigned int VERTICAL_DIM = 6;    // A change here must be followed by changing etROW and the  deCodeROW function
const unsigned int HORIZONTAL_DIM = 7;  // A change here must be followed by changing the deCodeCOLUMN function

enum etROW { A=1, B, C, D, E, F, INVALID_ROW }; // There are VERTICAL_DIM allowed
typedef enum etROW ROW;

enum etADJACENCY { NOT_ADJACENT, NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST };

typedef enum etADJACENCY ADJACENCY;

typedef unsigned int COLUMN;

// Global Functions

// decodes a char into a valid ROW or into INVALID_ROW
ROW deCodeROW(char cSourceRow);

const unsigned int INVALID_COLUMN = HORIZONTAL_DIM + 1;
// decodes a char into a valid COLUMN or into INVALID_COLUMN
COLUMN deCodeCOLUMN(char cSourceColumn);

#endif
