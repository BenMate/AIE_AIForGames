#include "Application.h"
#include "raygui.h"

#include "Player.h"
#include "GameObject.h"
#include "KeyBoardBehaviour.h"

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
	m_player1 = new Player();
	m_player1->SetPosition({ m_windowWidth * 0.25f , m_windowHeight / 2.0f });
	m_player1->SetFriction(1.0f);

	//m_player->SetBehaviour ( new seekbehaviour()) ;
	//m_player->SetBehaviour ( new Fleeboardbehaviour()) ;
}

void Application::UnLoad()
{
	delete m_player1;
	m_player1 = nullptr;
}

void Application::Update(float deltaTime)
{
	m_player1->Update(deltaTime);
}

void Application::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	m_player1->Draw();

	DrawText("Ben's Raylib Thingy!", m_windowWidth / 4, 10, 40, GRAY);

	if (IsKeyDown(KEY_SPACE)) DrawText("Big Boom", 250, 200, 80, ORANGE); // just ignore this haha :)

	EndDrawing();
}