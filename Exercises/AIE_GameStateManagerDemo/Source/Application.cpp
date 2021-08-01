#include "Application.h"

#include "raylib.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include "MenuState.h"
#include "Demo1.h"
#include "Demo2.h"

#include "PauseState.h"
#include "GameState.h"
#include "GameMenuState.h"
#include "GameOverState.h"
#include "GuideState.h"


Application::Application(int windowWidth, int windowHeight) : m_windowWidth(windowWidth), m_windowHeight(windowHeight)	
{

}

Application::~Application()
{

}

void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "AIE Game state Manager");
	SetTargetFPS(60);

	m_gameStateManager = new GameStateManager();

	//tests - graphs and behaviours
	m_gameStateManager->SetState("Menu", new MenuState(this)); 
	m_gameStateManager->SetState("Agent", new DemoOne(this));
	m_gameStateManager->SetState("Graph", new DemoTwo(this));
	m_gameStateManager->SetState("Pause", new PauseState(this));

	//gamestates
	m_gameStateManager->SetState("GameState", new GameState(this));
	m_gameStateManager->SetState("GameMenu", new GameMenuState(this));
	m_gameStateManager->SetState("GameOver", new GameOverState(this));
	m_gameStateManager->SetState("Guide", new GuideState(this));

	//stats the app on gamemenu
	m_gameStateManager->PushState("GameMenu");
	

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

	ClearBackground(WHITE);

	m_gameStateManager->Draw();

	EndDrawing();
}

GameStateManager* Application::GetGameStateManager() {
	return m_gameStateManager;
}