#pragma once
#pragma once

//-Forward Declare / pre declare
class IGameState;
class GameStateManager;

class Application {

public:

	Application(int windowWidth, int windowHeight, const char* windowTitle);
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
	const char* m_windowTitle;


	GameStateManager* m_gameStateManager = nullptr;

};
