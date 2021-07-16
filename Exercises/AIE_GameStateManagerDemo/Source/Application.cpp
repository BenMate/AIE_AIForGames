#include "Application.h"

#include "raylib.h"

#include "GameStateManager.h"
#include "IGameState.h"

#include "SplashState.h"
#include "MenuState.h"
#include "PauseState.h"

#include "Demo1.h"
#include "Demo2.h"
#include "Game.h"



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

	m_gameStateManager->SetState("Splash", new SplashState(this)); // Load();
	m_gameStateManager->SetState("Menu", new MenuState(this)); 
	m_gameStateManager->SetState("Play", new DemoOne(this));
	m_gameStateManager->SetState("Graph", new DemoTwo(this));
	m_gameStateManager->SetState("Pause", new PauseState(this));
	m_gameStateManager->SetState("Game", new GameState(this));

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

	EndDrawing();
}