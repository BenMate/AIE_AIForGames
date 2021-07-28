#include "Assets.h"

Texture2D MyAssets::worldBG;
Texture2D MyAssets::colourBG;
Texture2D MyAssets::MenuBG;
Image MyAssets::colourBGRaw;

Texture2D MyAssets::playerCharacter;

Texture2D MyAssets::goblinWand;
Texture2D MyAssets::goblinPath;

Texture2D MyAssets::chestC;
Texture2D MyAssets::chestO;


void MyAssets::LoadAssets()
{
	MenuBG = LoadTexture("./Assets/BackGround/Menu.png");
	worldBG = LoadTexture("./Assets/BackGround/Map.png");
	colourBG = LoadTexture("./Assets/BackGround/ColorBackGround.png");//gpu
	colourBGRaw = LoadImage("./Assets/BackGround/ColorBackGround.png"); //cpu 

	playerCharacter = LoadTexture("./Assets/Entity/Player.png");

	goblinWand = LoadTexture("./Assets/Entity/Goblin.png");
	goblinPath = LoadTexture("./Assets/Entity/Goblin2.png");

	chestC = LoadTexture("./Assets/Entity/ClosedChest.png");
	chestO = LoadTexture("./Assets/Entity/OpenChest.png");
}

void MyAssets::UnLoadAssets()
{	
	UnloadTexture(MenuBG);
	UnloadTexture(worldBG);
	UnloadTexture(colourBG);
	UnloadImage(colourBGRaw);

	UnloadTexture(playerCharacter);
	UnloadTexture(goblinWand);
	UnloadTexture(goblinPath);
	UnloadTexture(chestC);
	UnloadTexture(chestO);
}

unsigned int MyAssets::GetImagePixel(Image img, int xPos, int yPos)
{
	unsigned int* data = (unsigned int*)img.data;
	unsigned int color = data[yPos * img.width + xPos];
	return color;
}