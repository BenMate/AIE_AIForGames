
#include "ScrabbleBoard.h"

#include <cstring>
#include <map>

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

	static std::map<char, int> scoreTable{
		{'a', 1},{'e', 1},{'l', 1},{'u', 1},{'n', 1},{'r', 1}, {'s', 1}, {'t', 1},{'o', 1},{'i', 1},
		{'g', 2},{'d', 2},
		{'b', 3}, {'c', 3}, {'m', 3},{'p', 3},
		{'y', 4},{'f', 4},{'h', 4},{'v', 4},{'w', 4},
		{'k', 5},
		{'j', 8},{'x', 8},
		{'q', 10},{'z', 10} };

	int score = 0;
	int TWWord = 0;
	int DWWord = 0;

	int sizeOfText = strlen(text);
	int yDir = (dir == EDirection::DOWN ? 1 : 0);
	int xDir = (dir == EDirection::RIGHT ? 1 : 0);

	//loop through word
	for (int i = 0; i < sizeOfText; i++)
	{
		int LetterScore = scoreTable[towlower(text[i])];
		auto modifier = GetBoardModifier(xIndex + xDir * i, yIndex + yDir * i);

		//checks the modifier on the board
		if (modifier == EScoreMod::DL) LetterScore *= 2;
		else if (modifier == EScoreMod::TL) LetterScore *= 3;
		else if (modifier == EScoreMod::DW) DWWord++;
		else if (modifier == EScoreMod::TW) TWWord++;

		score += LetterScore;
	}
	//adding the modifier values to the score
	for (int i = 0; i < TWWord; i++) 
		score *= 3;
	
	for (int i = 0; i < DWWord; i++) 
		score *= 2;
	
	return score;
}