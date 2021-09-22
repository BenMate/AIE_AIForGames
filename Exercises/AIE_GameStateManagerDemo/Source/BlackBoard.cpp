#include "BlackBoard.h"

#include "Goblin.h"
#include "MainCharacter.h"



BlackBoard::BlackBoard() 
{

}

BlackBoard::~BlackBoard() 
{

}

void BlackBoard::SetPlayerPos(Vector2 pos, bool posKnown)
{
	positionKnown = posKnown;
	playersPos = pos;
}

