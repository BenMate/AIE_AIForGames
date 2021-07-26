#pragma once

#include "raylib.h"


class MyAssets 
{
public:
	

	//Images
	//--------------------------------------------------
	static Texture2D worldBG;
	static Texture2D colourBG;

	static Texture2D playerCharacter;
	static Texture2D chest;
	static Texture2D goblin;

	static Image colourBGRaw;

	//Sounds
	//------------------------------------------------------

	static void LoadAssets();
	static void UnLoadAssets();

	static unsigned int GetImagePixel(Image img, int xPos, int yPos);


protected:


private:
	
	

};
