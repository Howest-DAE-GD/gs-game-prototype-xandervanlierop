#include "pch.h"
#include "Game.h"
#include "utils.h"
#include "Walls.h"
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

	wall1 = new Walls(Rectf{ 50.f,90.f,100.f,30.f });
	wall2 = new Walls(Rectf{ 300.f,200.f,300.f,30.f });
	wall3 = new Walls(Rectf{ 200.f,300.f,40.f,100.f });
	wall4 = new Walls(Rectf{ 500.f,400.f,400.f,60.f });
	wall5 = new Walls(Rectf{ 403.f,45.f,50.f,100.f });
	wall6 = new Walls(Rectf{ 700.f,100.f,30.f,200.f });
	wall7 = new Walls(Rectf{ 750.f,500.f,50.f,200.f});
	wall8 = new Walls(Rectf{ 900.f,250.f,50.f,300.f});
	
}

void Game::Cleanup( )
{
	
	delete player;
	delete villain;

	delete wall1;
	delete wall2;
	delete wall3;
	delete wall4;
	delete wall5;
	delete wall6;
	delete wall7;
	delete wall8;
	
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

	if (player->CheckHit(villain->g_Villain))
	{
		delete villain;
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
	utils::DrawRect(50, 30, 1180, 740);

	villain->Draw();

	player->Draw();
	
	wall1->Draw();
	wall2->Draw();
	wall3->Draw();
	wall4->Draw();
	wall5->Draw();
	wall6->Draw();
	wall7->Draw();
	wall8->Draw();
	
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
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
