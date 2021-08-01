#include "BlackBoard.h"

#include "GoblinWanderer.h"
#include "MainCharacter.h"



BlackBoard::BlackBoard() 
{

}

BlackBoard::~BlackBoard() 
{

}

void BlackBoard::SetPlayerPos(Vector2* pos)
{
	playersPos = pos;
}
