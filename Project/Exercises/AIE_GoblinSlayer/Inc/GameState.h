#pragma once

#include "IGameState.h"
#include "raylib.h"
#include <list>

class GameStateManager;
class Application;

class GameObject;

class MainCharacter;
class LadderEntity;
class Chest;
class Goblin;

class BlackBoard;

class Graph2D;
class Graph2DEditor;

class GameState : public IGameState
{

public:

	GameState(Application* app);
	virtual ~GameState();

	virtual void Load();
	virtual void Unload();
	virtual void Update(float deltaTime);
	virtual void Draw();

	MainCharacter* GetMainCharacter();
	void SetMaincharacter(MainCharacter* mainCharacter);

	LadderEntity* GetLadderEntity();
	void SetLadderEntity(LadderEntity* ladder);

	GameObject* CreateChest(Vector2 pos);
	GameObject* CreatePlayer(Vector2 pos);
	GameObject* CreateGoblin(Vector2 pos);
	GameObject* CreateLadder(Vector2 pos);

	void DrawDebugGraph();
	void BuildGraphMap();

	void UpdateGameCamera(float deltaTime);
	bool IsInCameraView(Vector2 pos);

	bool CanEscape();
	void UpdateEntities(float deltaTime);
	void DrawEntities();

	void DidWinGame();
	void GotCaught();
	
protected:

private:
	bool canEscape = false;
	
	Camera2D m_camera;
	Vector2 m_playerPos = { 0.0f , 0.0f };

	Application* m_app;
	GameStateManager* m_gameStateManager = nullptr;

	Graph2DEditor* m_graphEditor = nullptr;
	Graph2D* m_graph = nullptr;

	BlackBoard* m_blackBoard = nullptr;

	std::list<Chest*> m_chest;
	std::list<Goblin*> m_goblin;

	LadderEntity* m_ladder = nullptr;
	MainCharacter* m_mainCharacter = nullptr;	
};