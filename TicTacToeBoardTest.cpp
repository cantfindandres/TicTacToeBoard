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


TEST(TicTacToeBoardTest, toggle_no)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.toggleTurn(),O);
}

TEST(TicTacToeBoardTest, toggle_1)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.toggleTurn(),X);
}

TEST(TicTacToeBoardTest, toggle_2)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	ASSERT_EQ(board.toggleTurn(),O);
}

TEST(TicTacToeBoardTest, toggle_inv)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,1);
	ASSERT_EQ(board.toggleTurn(),O);
}
/**********************************************/
TEST(TicTacToeBoardTest, placePiece0)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,0),X);
}

TEST(TicTacToeBoardTest, placePiece1)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.placePiece(0,0),X);
}

TEST(TicTacToeBoardTest, placePiece2)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.placePiece(0,1),O);
}

TEST(TicTacToeBoardTest, placePiece3)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	ASSERT_EQ(board.placePiece(0,2),X);
}

TEST(TicTacToeBoardTest, placePiece4)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,4),Invalid);
}

TEST(TicTacToeBoardTest, placePiece5)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,-1),Invalid);
}