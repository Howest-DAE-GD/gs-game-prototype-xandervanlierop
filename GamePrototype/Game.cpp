#include "pch.h"
#include "Game.h"
#include "utils.h"
#include "Walls.h"
#include "ScorePoint.h"
#include <iostream>

Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize()
{
	player = new Player();
	villain = new Villain();
	

	WallsPtr.reserve(8);
	WallsPtr.push_back( new Walls(Rectf{ 50.f,90.f,100.f,30.f }));
	WallsPtr.push_back( new Walls(Rectf{ 300.f,200.f,300.f,30.f }));
	WallsPtr.push_back( new Walls(Rectf{ 200.f,300.f,40.f,100.f }));
	WallsPtr.push_back( new Walls(Rectf{ 500.f,400.f,400.f,60.f }));
	WallsPtr.push_back( new Walls(Rectf{ 403.f,45.f,50.f,100.f }));
	WallsPtr.push_back( new Walls(Rectf{ 700.f,100.f,30.f,200.f }));
	WallsPtr.push_back( new Walls(Rectf{ 750.f,500.f,50.f,200.f}));
	WallsPtr.push_back(new Walls(Rectf{ 900.f,250.f,50.f,300.f }));
	
	ScorePointPtr.reserve(10);
	for (int ScorePointIndex{}; ScorePointIndex < 10; ScorePointIndex++)
	{
		ScorePointPtr.push_back(new ScorePoint(WallsPtr,GameScreen));
	}
}

void Game::Cleanup( )
{
	
	delete player;
	if (villain != nullptr)
	{
		delete villain;
	}

	for (int WallIndex{}; WallIndex < WallsPtr.size(); WallIndex++)
	{
		delete WallsPtr[WallIndex];
	}
	
	for (int ScorePointIndex{}; ScorePointIndex < ScorePointPtr.size(); ScorePointIndex++)
	{
		delete ScorePointPtr[ScorePointIndex];
	}
}

void Game::Update( float elapsedSec )
{
	// Check keyboard state
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );



	if (pStates[SDL_SCANCODE_UP])
	{
		player->UpdateUp(elapsedSec);
	}
	if (pStates[SDL_SCANCODE_DOWN])
	{
		player->UpdateDown(elapsedSec);
	}
	if ( pStates[SDL_SCANCODE_RIGHT] )
	{
		player->UpdateRight(elapsedSec);
	}
	if (pStates[SDL_SCANCODE_LEFT])
	{
		player->UpdateLeft(elapsedSec);
	}
	

	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void Game::Draw( ) const
{
	ClearBackground();
	utils::SetColor(m_RectColor);
	utils::DrawRect(GameScreen);

	villain->Draw();

	player->Draw();
	
	for (int WallIndex{}; WallIndex < WallsPtr.size(); WallIndex++)
	{
		WallsPtr[WallIndex]->Draw();
	}
	
	for (int ScorePointIndex{}; ScorePointIndex < ScorePointPtr.size(); ScorePointIndex++)
	{
		ScorePointPtr[ScorePointIndex]->Draw();
	}
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	switch ( e.keysym.sym )
	{
	case SDLK_x:
		if (player->CheckHit(villain->GetHitbox()))
		{
			delete villain;
			villain = nullptr;
		}
		break;
	}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
