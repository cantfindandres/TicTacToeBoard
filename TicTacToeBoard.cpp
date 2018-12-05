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
  } else{
    turn = X;
  }
  return turn;
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
  if(row > BOARDSIZE - 1 || row < 0 || column > BOARDSIZE - 1 || column < 0){               //checks valid input
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
  Piece to_return;
  bool winner;

  // checks rows
  for(unsigned int i = 0; i < BOARDSIZE; i++) {
    winner = true;
    to_return = board[i][0];
    for(unsigned int j = 1; j < BOARDSIZE; j++){
      if(board[i][j] != to_return || board[i][j] == Blank){
        winner = false;
        break;
      }
    }
    if (winner){
      return to_return;
    }
  }
  
  // checks columns
   for(unsigned int i = 0; i < BOARDSIZE; i++) {
     winner = true;
     to_return = board[0][i];
    for(unsigned int j = 1; j < BOARDSIZE; j++){
      if(board[j][i] != to_return || board[j][i] == Blank){
        winner = false;
        break;
      }
    }
    if (winner){
      return to_return;
    }
  }
  
  // checks diagonals
  to_return = board[0][0];
  winner = true;
  for(unsigned int i = 0; i < BOARDSIZE - 1; i++){
    if(board[i][i] != to_return || board[i][i] == Blank){
      winner = false;
      break;
    }
  }
  if(winner){
    return to_return;
  }
  
  
  to_return = board[BOARDSIZE - 1][0];
  winner = true;
  for(int i = BOARDSIZE - 2; i >= 0; i--){
    if(board[i][i] != to_return || board[i][i] == Blank){
      winner = false;
      break;
    }
  }
  if(winner){
    return to_return;
  }
  
  
  return to_return;
}
