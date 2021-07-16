#include "GameStateManager.h"
#include "IGameState.h"


GameStateManager::GameStateManager()
{


}

GameStateManager::~GameStateManager()
{
	for (auto iter = m_states.begin(); iter != m_states.end(); iter++)
	{
		if (iter->second != nullptr)
		{
			iter->second->Unload();
			delete iter->second;
		}
	}
	m_states.clear();
}

void GameStateManager::Update(float deltaTime)
{
	//invoke all recoreded commands
	for (auto cmd : m_commands)
		cmd();

	m_commands.clear();

	for (auto state : m_stack)
	{
		state->Update(deltaTime);
	}
}

void GameStateManager::Draw()
{
	for (auto state : m_stack)
	{
		state->Draw();
	}
}

void GameStateManager::SetState(const char* name, IGameState* state)
{
	m_commands.push_back([=]() {

		if (m_states[name] != nullptr)
		{
			m_states[name]->Unload();
			delete m_states[name];
		}

		m_states[name] = state;

		if (m_states[name] != NULL) {
			m_states[name]->Load();
		}

		});
}

void GameStateManager::PushState(const char* name)
{
	m_commands.push_back([=]() {
		m_stack.push_back(m_states[name]);
		});
}

void GameStateManager::PopState()
{
	m_commands.push_back([=]() {
		m_stack.pop_back();
		});
}

IGameState* GameStateManager::GetCurrentState()
{
	return m_stack.back();
}


//TODO:

//- CREATE a "PLAY" state
// - create a "pause" state
// - create a "score" state

//when we press 'space' on the menu state - change state to play
//when we press p on the play state - push_state('pause');
//when we press the 'p' on the pause state - pop the pause state from the stack

//Challange see if you can update the game state manager so that only the 'top' state is updating

//all states should draw.   ...//blocking others from drawing 