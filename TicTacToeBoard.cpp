#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X){
    turn = O;
    return O;
  } else{
    turn = X;
    return X;
  }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column){
  Piece temp = getPiece(row,column);
  if(temp == Invalid){
    return Invalid;
  }
  else if(temp == X || temp == O){
    return temp;
  }
  else{
    board[row][column] = turn;
    temp = turn;
    turn = toggleTurn();
    return temp;
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column){
  if(row > BOARDSIZE || row < 0 || column > BOARDSIZE || column < 0){               //checks valid input
    return Invalid;
  }
  else{
    return board[row][column];
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner(){
  /*
  Piece temp = board[BOARDSIZE/2][BOARDSIZE/2];
  bool piecechanged;
  
  for(unsigned int i = 0; i < BOARDSIZE; i++){
    
  }
  // check for not_over conditiion
  for(unsigned int i = 0; i < BOARDSIZE; i++){
    for(unsigned int j = 0; j < BOARDSIZE; j++){
      if(getPiece(i,j) == Blank){
        return Invalid;
      }
    }
  }
  */
  return Blank;
}
