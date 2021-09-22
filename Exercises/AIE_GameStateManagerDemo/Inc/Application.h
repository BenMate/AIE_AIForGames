#pragma once

//-Forward Declare / pre declare
class GameObject;

class IGameState;
class GameStateManager;

class Player;
class Goblin;

class Application {

public:

	Application(int windowWidth, int windowHeight);
	~Application();

	void Run();

	void Load();
	void UnLoad();

	void Update(float deltaTime);
	void Draw();

	GameStateManager* GetGameStateManager();

	

protected:

private:

	int m_windowWidth;
	int m_windowHeight;
	

	
	GameStateManager* m_gameStateManager = nullptr;
	
	Player* m_player = nullptr;
	Goblin* m_goblin = nullptr;
};
