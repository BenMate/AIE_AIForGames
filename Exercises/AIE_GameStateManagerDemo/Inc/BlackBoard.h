#pragma once
#include "raylib.h"



class BlackBoard 
{


public:

	BlackBoard();
	 ~BlackBoard();

	 void SetPlayerPos(Vector2 pos, bool posKnown);
	
	 bool positionKnown = false;
	 Vector2 playersPos;

	int score = 1;
	
protected:

	

private:


};
