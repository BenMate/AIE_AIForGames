#pragma once

#include "IGameState.h"
#include "raylib.h"
#include <list>

class GameStateManager;
class Application;
class MainCharacter;

class Graph2DEditor;
class Graph2D;
class GameObject;

class GameState : public IGameState
{

public:

	GameState(Application* app);
	virtual ~GameState();

	virtual void Load();
	virtual void Unload();
	virtual void Update(float deltaTime);
	virtual void Draw();

	//GameObject* CreateChest(Vector2 pos);
	GameObject* CreatePlayer(Vector2 pos);
	//GameObject* CreateGoblin(Vector2 pos);

	void DrawDebugGraph();
	void BuildGraphMap();

	void UpdateGameCamera(float deltaTime);
	bool IsInCameraView(Vector2 pos);

	void UpdateColRec();
	void DrawColRec();



protected:

private:

	Application* m_app;
	GameStateManager* m_gameStateManager = nullptr;
	Graph2D* m_graph = nullptr;

	Camera2D m_camera;

	std::list<GameObject*> m_chest;
	std::list<GameObject*> m_goblin;

	MainCharacter* m_mainCharacter = nullptr;
};