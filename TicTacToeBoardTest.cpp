/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};



/******************************************************************************/
/******************************     toggle( )     *****************************/
/******************************************************************************/
TEST(TicTacToeBoardTest, toggle_new_game)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.toggleTurn(),O);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, toggle_after_piece1)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.toggleTurn(),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, toggle_after_piece2)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	ASSERT_EQ(board.toggleTurn(),O);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, toggle_after_Invalid)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,4);
	ASSERT_EQ(board.toggleTurn(),O);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, toggle_game_over)
{
	TicTacToeBoard board;
	board.placePiece(0,0);board.placePiece(0,1);board.placePiece(0,2);
	board.placePiece(1,0);board.placePiece(1,1);board.placePiece(1,2);
	board.placePiece(2,0);board.placePiece(2,1);board.placePiece(2,2);
	ASSERT_EQ(board.toggleTurn(),X);
}
/******************************************************************************/
/****************************     placePiece( )     ***************************/
/******************************************************************************/
TEST(TicTacToeBoardTest, placePiece_Invalid)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(-1,0),Invalid);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_already_set)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.placePiece(0,0),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_1)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,0),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_2)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.placePiece(0,1),O);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_gameover)
{
	TicTacToeBoard board;
	board.placePiece(0,0);board.placePiece(0,1);board.placePiece(0,2);
	board.placePiece(1,0);board.placePiece(1,1);board.placePiece(1,2);
	board.placePiece(2,0);board.placePiece(2,1);board.placePiece(2,2);
	ASSERT_EQ(board.placePiece(2,2),X);
}
/******************************************************************************/
/******************************     getPiece( )     ***************************/
/******************************************************************************/
TEST(TicTacToeBoardTest, getPiece_invalid_column_neg)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,-1),Invalid);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, getPiece_invalid_column_ofb)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,3),Invalid);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, getPiece_invalid_row_neg)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(-1,0),Invalid);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, getPiece_invalid_row_ofb)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(3,0),Invalid);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, getPiece_invalid_row_column_neg)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(-1,-1),Invalid);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, getPiece_invalid_row_column_ofb)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(3,3),Invalid);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, getPiece_new_game)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(0,0),Blank);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, getPiece_after1)
{
	TicTacToeBoard board;
	board.placePiece(0,1);
	ASSERT_EQ(board.getPiece(0,1),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, getPiece_after2)
{
	TicTacToeBoard board;
	board.placePiece(0,1);
	board.placePiece(0,2);
	ASSERT_EQ(board.getPiece(0,2),O);
}
/******************************************************************************/
/******************************     getWinner( )     **************************/
/******************************************************************************/
TEST(TicTacToeBoardTest, placePiece_winner_row0X)
{
	TicTacToeBoard board;
	board.placePiece(0,0);board.placePiece(1,0);
	board.placePiece(0,1);board.placePiece(1,1);
	board.placePiece(0,2);board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_row0O)
{
	TicTacToeBoard board;
	board.placePiece(1,0);board.placePiece(0,0);
	board.placePiece(1,1);board.placePiece(0,1);
	board.placePiece(2,2);board.placePiece(0,2);
	ASSERT_EQ(board.getWinner(),O);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_row1X)
{
	TicTacToeBoard board;
	board.placePiece(1,0);board.placePiece(0,0);
	board.placePiece(1,1);board.placePiece(0,1);
	board.placePiece(1,2);board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_row1O)
{
	TicTacToeBoard board;
	board.placePiece(0,0);board.placePiece(1,0);
	board.placePiece(0,1);board.placePiece(1,1);
	board.placePiece(2,2);board.placePiece(1,2);
	ASSERT_EQ(board.getWinner(),O);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_row2X)
{
	TicTacToeBoard board;
	board.placePiece(2,0);board.placePiece(0,0);
	board.placePiece(2,1);board.placePiece(0,1);
	board.placePiece(2,2);board.placePiece(1,2);
	ASSERT_EQ(board.getWinner(),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_row2O)
{
	TicTacToeBoard board;
	board.placePiece(0,0);board.placePiece(2,0);
	board.placePiece(0,1);board.placePiece(2,1);
	board.placePiece(1,2);board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(),O);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_column0X)
{
	TicTacToeBoard board;
	board.placePiece(0,0);board.placePiece(0,1);
	board.placePiece(1,0);board.placePiece(1,1);
	board.placePiece(2,0);board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_column0O)
{
	TicTacToeBoard board;
	board.placePiece(0,1);board.placePiece(0,0);
	board.placePiece(1,1);board.placePiece(1,0);
	board.placePiece(2,2);board.placePiece(2,0);
	ASSERT_EQ(board.getWinner(),O);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_column1X)
{
	TicTacToeBoard board;
	board.placePiece(0,1);board.placePiece(0,0);
	board.placePiece(1,1);board.placePiece(1,0);
	board.placePiece(2,1);board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_column1O)
{
	TicTacToeBoard board;
	board.placePiece(0,0);board.placePiece(0,1);
	board.placePiece(1,0);board.placePiece(1,1);
	board.placePiece(2,2);board.placePiece(2,1);
	ASSERT_EQ(board.getWinner(),O);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_column2X)
{
	TicTacToeBoard board;
	board.placePiece(0,2);board.placePiece(0,0);
	board.placePiece(1,2);board.placePiece(1,0);
	board.placePiece(2,2);board.placePiece(2,1);
	ASSERT_EQ(board.getWinner(),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_column2O)
{
	TicTacToeBoard board;
	board.placePiece(0,0);board.placePiece(0,2);
	board.placePiece(1,0);board.placePiece(1,2);
	board.placePiece(2,1);board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(),O);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_diagona0X)
{
	TicTacToeBoard board;
	board.placePiece(0,0);board.placePiece(0,1);
	board.placePiece(1,1);board.placePiece(0,2);
	board.placePiece(2,2);board.placePiece(1,0);
	ASSERT_EQ(board.getWinner(),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_diagona0O)
{
	TicTacToeBoard board;
	board.placePiece(0,1);board.placePiece(0,0);
	board.placePiece(0,2);board.placePiece(1,1);
	board.placePiece(1,0);board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(),O);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_diagonalX)
{
	TicTacToeBoard board;
	board.placePiece(0,2);board.placePiece(0,0);
	board.placePiece(1,1);board.placePiece(0,1);
	board.placePiece(2,0);board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(),X);
}
/////////////////////////////////////////////////
TEST(TicTacToeBoardTest, placePiece_winner_diagonalO)
{
	TicTacToeBoard board;
	board.placePiece(0,0);board.placePiece(0,2);
	board.placePiece(0,1);board.placePiece(1,1);
	board.placePiece(2,2);board.placePiece(2,0);
	ASSERT_EQ(board.getWinner(),O);
}
/////////////////////////////////////////////////