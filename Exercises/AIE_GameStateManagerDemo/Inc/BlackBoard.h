#pragma once
#include "raylib.h"



class BlackBoard 
{


public:

	BlackBoard();
	 ~BlackBoard();

	 void SetPlayerPos(Vector2* pos);

	Vector2* playersPos =  nullptr;

	int score = 1;
	
protected:

	

private:


};
