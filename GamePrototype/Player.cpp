#include "pch.h"
#include "Player.h"
#include "utils.h"
#include <iostream>
#include "Walls.h"
#include <vector>

Player::Player()
{
	m_Speed = 100.f;
	m_Player.bottom = m_PlayerBottom.y;
	m_Player.left	= m_PlayerBottom.x;
	m_Player.width	= m_PlayerLength;
	m_Player.height = m_PlayerLength;
}

Player::~Player()
{
}



bool Player::CheckHitWithEnemy(const Circlef enemy)
{
	bool result{ utils::IsOverlapping(m_Player, enemy) };
	return result;
}

bool Player::CheckHitWithPoints(const Rectf scorePoint)
{
	bool result{ utils::IsOverlapping(m_Player, scorePoint) };
	return result;
}

void Player::Draw()
{
	
	utils::SetColor(m_Color);
	utils::DrawRect(m_Player);
}

void Player::UpdateUp(float elapsedSec)
{
	m_Player.bottom+=m_Speed * elapsedSec;
}

void Player::UpdateDown(float elapsedSec)
{
	m_Player.bottom-= m_Speed * elapsedSec;
}

void Player::UpdateLeft(float elapsedSec)
{
	m_Player.left-= m_Speed * elapsedSec;
}

void Player::UpdateRight(float elapsedSec)
{
	m_Player.left+= m_Speed * elapsedSec;
}

//void Player::xCheckHitWithWall(const std::vector<Walls*>& walls)
//{
	//for (int WallIndex{}; WallIndex < walls.size(); WallIndex++)
	//{
		//if (utils::IsOverlapping(m_Player, walls[WallIndex]->GetHitbox()))
		//{
			//utils::HitInfo hitInfo();
		//}
	//}
//}




