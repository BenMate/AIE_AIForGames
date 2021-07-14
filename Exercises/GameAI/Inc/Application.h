#pragma once

//-Forward Declare / pre declare
class GameObject;

class Graph2D;
class Graph2DEditor;

class IGameState;
class GameStateManager;

class Application {

public:

	Application(int windowWidth,int windowHeight, const char * windowTitle);
	~Application();

	void Run();

	void Load();
	void UnLoad();

	void Update(float deltaTime);
	void Draw();

	GameStateManager* GetGameStateManager() {
		return m_gameStateManager;
	}

protected:

private:

	int m_windowWidth;
	int m_windowHeight;
	const char* m_windowTitle;

	GameObject* m_player1 = nullptr;
	
	Graph2DEditor* m_graphEditor = nullptr;
	Graph2D* m_graph = nullptr;

	GameStateManager* m_gameStateManager = nullptr;

};
