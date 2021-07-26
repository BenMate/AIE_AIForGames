
#include "ScrabbleBoard.h"

#include <cstring>

ScrabbleBoard::ScrabbleBoard(int rows, int cols) :
	ROWS(rows), COLS(cols)
{
	m_boardModifiers = new unsigned int[ROWS * COLS];
	m_boardCharacters = new char[ROWS * COLS];

	// Initialise board values
	for (int i = 0; i < ROWS * COLS; i++)
	{
		m_boardModifiers[i] = (int)EScoreMod::NO;
		m_boardCharacters[i] = ' ';
	}
}

ScrabbleBoard::~ScrabbleBoard()
{
	delete[] m_boardModifiers;
	delete[] m_boardCharacters;
}

ScrabbleBoard::EScoreMod ScrabbleBoard::GetBoardModifier(int xIndex, int yIndex)
{
	int index = yIndex * ROWS + xIndex;
	return (EScoreMod)m_boardModifiers[index];
}

char ScrabbleBoard::GetBoardCharacter(int xIndex, int yIndex)
{
	int index = yIndex * ROWS + xIndex;
	return m_boardCharacters[index];
}

void ScrabbleBoard::SetBoardCharacter(int xIndex, int yIndex, char c)
{
	if (xIndex < 0 || yIndex < 0 || xIndex >= COLS || yIndex >= ROWS)
		return;

	int index = yIndex * ROWS + xIndex;
	m_boardCharacters[index] = c;
}

void ScrabbleBoard::SetBoardScoreModifiers(unsigned int* board)
{
	for (int i = 0; i < ROWS * COLS; i++)
		m_boardModifiers[i] = board[i];
}

void ScrabbleBoard::PlaceText(int xIndex, int yIndex, const char* text, EDirection dir)
{
	int score = CalculateScore(xIndex, yIndex, text, dir);
	m_totalScore += score;

	int xo = 0, yo = 0;
	switch (dir)
	{
	case EDirection::RIGHT: xo = 1; break;
	case EDirection::DOWN:  yo = 1; break;
	}

	int len = strlen(text);
	for (int i = 0; i < len; i++)
	{
		int xi = xIndex + (i * xo);
		int yi = yIndex + (i * yo);

		SetBoardCharacter(xi, yi, text[i]);
	}
}

unsigned int ScrabbleBoard::GetTotalScore()
{
	return m_totalScore;
}

bool ScrabbleBoard::CanPlaceText(int xIndex, int yIndex, const char* text, EDirection dir)
{
	// ========================================================================
	// DAILY WARMUP - TODO
	// ========================================================================
	// write your code here
	int i = 0;
	int overlapping = 0;
	int sizeOfText = strlen(text);

	int yDir = (dir == EDirection::DOWN ? 1 : 0);
	int xDir = (dir == EDirection::RIGHT ? 1 : 0);

	//word was greater then the board
	
	if (dir == EDirection::DOWN)
		if (yIndex + sizeOfText > ROWS) return false;
	
	if (dir == EDirection::RIGHT)
		if (xIndex + sizeOfText > COLS) return false;
	
	//the the word overlaps return false but shares a same character return true
	int sharedChacterCount = 0;
	//loop through word 
	for (int i = 0; i < sizeOfText; i++) 
	{
		char characterToPlace = text[i];
		char characterOnBoard = GetBoardCharacter(xIndex + xDir * i, yIndex + yDir * 1);

		if (characterOnBoard != ' ' && characterToPlace != characterOnBoard) return false;
		else if (characterToPlace == characterOnBoard) sharedChacterCount += 1;			
	}


	return true;
}

unsigned int ScrabbleBoard::CalculateScore(int xIndex, int yIndex, const char* text, EDirection dir)
{
	// ========================================================================
	// DAILY WARMUP - TODO
	// ========================================================================
	// write your code here





	auto characterToPlace = text[0];
	auto characterOnBoard = GetBoardCharacter(xIndex, yIndex);
	auto modifier = GetBoardModifier(xIndex, yIndex);

	int score = 1;
	return score;
}