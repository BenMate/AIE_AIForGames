#pragma once

//-Forward Declare / pre declare
class GameObject;

class IGameState;
class GameStateManager;

class Application {

public:

	Application(int windowWidth, int windowHeight);
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
	

	GameObject* m_player1 = nullptr;

	GameStateManager* m_gameStateManager = nullptr;

};
