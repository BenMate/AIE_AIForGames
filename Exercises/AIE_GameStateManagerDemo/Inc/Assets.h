#pragma once

#include "raylib.h"


class MyAssets 
{
public:
	//declare Assets

	//Images
	//--------------------------------------------------
	static Texture2D worldBG;
	static Texture2D colourBG;

	static Texture2D player;
	static Texture2D chest;
	static Texture2D goblin;

	static Image colourBGRaw;

	//Sounds
	//------------------------------------------------------

	static void LoadAssets();
	static void UnLoadAssets();


protected:


private:
	
	

};
