#pragma once
#include "BaseGame.h"
#include "Player.h"
#include "Villain.h"
#include "Walls.h"
#include "ScorePoint.h"
#include <vector>
class Game : public BaseGame
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update( float elapsedSec ) override;
	void Draw( ) const override;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e ) override;
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e ) override;
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e ) override;

private:

	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;

	Player* player{};
	std::vector<Villain*> VillainPtr{};
	Rectf GameScreen{ 50, 30, 1180, 740 };
	std::vector<ScorePoint*> ScorePointPtr{};
	std::vector<Walls*> WallsPtr{};
	Color4f m_RectColor{ 1.f, 0.f, 0.f, 1.f };
	
};