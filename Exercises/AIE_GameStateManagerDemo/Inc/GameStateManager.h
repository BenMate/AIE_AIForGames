#pragma once
#include <list>
#include <map>
#include <functional>

//pre declare instead of #include
class IGameState;


class GameStateManager
{
public:

	GameStateManager();
	~GameStateManager();

	void Update(float deltaTime);
	void Draw();

	void SetState(const char* name, IGameState* state);
	void PushState(const char* name);
	void PopState();

	IGameState* GetCurrentState();

protected:

	std::map<const char*, IGameState* > m_states;
	std::list<IGameState*> m_stack;
	std::list < std::function<void()> > m_commands;

private:

};