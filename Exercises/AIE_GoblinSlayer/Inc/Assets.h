#pragma once

#include "raylib.h"


class MyAssets 
{
public:
	
	//Images
	//--------------------------------------------------
	static Texture2D worldBG;
	static Texture2D colourBG;
	static Texture2D MenuBG;

	static Texture2D Ladder;

	static Texture2D playerCharacter;

	static Texture2D goblinWand;
	static Texture2D goblinPath;

	static Texture2D chestC;
	static Texture2D chestO;

	static Image colourBGRaw;



	//Sounds
	//------------------------------------------------------



	//------------------------------------------------------
	static void LoadAssets();
	static void UnLoadAssets();

	static unsigned int GetImagePixel(Image img, int xPos, int yPos);


protected:


private:
	
	

};
