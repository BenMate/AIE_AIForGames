#include "Application.h"
#include "raygui.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include "SplashState.h"
#include "MenuState.h"

Application::Application(int windowWidth, int windowHeight, const char* windowTitle) :
	m_windowWidth(windowWidth),
	m_windowHeight(windowHeight),
	m_windowTitle(windowTitle)
{

}

Application::~Application()
{

}

void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, m_windowTitle);
	SetTargetFPS(60);

	m_gameStateManager = new GameStateManager();
	m_gameStateManager->SetState("Splash", new SplashState(this)); // Load();
	m_gameStateManager->SetState("Menu", new MenuState(this)); //Load();

	m_gameStateManager->PushState("Splash");

	//loading in assets
	Load();

	//main game loop
	while (!WindowShouldClose())
	{
		float deltaTime = GetFrameTime();
		Update(deltaTime);
		Draw();
	}

	//unload assets
	UnLoad();

	//de-Initialization
	CloseWindow();
}

void Application::Load()
{
	

}

void Application::UnLoad()
{
	delete m_gameStateManager;
}

void Application::Update(float deltaTime)
{
	m_gameStateManager->Update(deltaTime);

}

void Application::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	m_gameStateManager->Draw();

	DrawText("Ben's Demo", m_windowWidth / 4, 10, 40, GRAY);

	if (IsKeyDown(KEY_SPACE)) DrawText("Big Boom", 250, 200, 80, ORANGE); // just ignore this haha :)

	EndDrawing();
}


GameStateManager* Application::GetGameStateManager() {
	return m_gameStateManager;
}
