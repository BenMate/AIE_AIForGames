#include "Assets.h"

Texture2D MyAssets::worldBG;
Texture2D MyAssets::colourBG;
Image MyAssets::colourBGRaw;

Texture2D MyAssets::player;
Texture2D MyAssets::goblin;
Texture2D MyAssets::chest;


void MyAssets::LoadAssets()
{
	worldBG = LoadTexture("./Assets/BackGround/Map.png");
	colourBG = LoadTexture("./Assets/BackGround/ColorBackGround.png");//gpu
	colourBGRaw = LoadImage("./Assets/BackGround/ColorBackGround.png"); //cpu 

	player = LoadTexture("./Assets/Entity/Player.png");
	goblin = LoadTexture("./Assets/Entity/Goblin.png");
	chest = LoadTexture("./Assets/Entity/Chest.png");	
}

void MyAssets::UnLoadAssets()
{	
	UnloadTexture(player);
	UnloadTexture(chest);
	UnloadTexture(goblin);

	UnloadTexture(worldBG);
	UnloadTexture(colourBG);
	UnloadImage(colourBGRaw);
}
