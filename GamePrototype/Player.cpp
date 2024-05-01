#include "pch.h"
#include "Player.h"
#include "utils.h"
#include <iostream>

Player::Player()
{
	m_Speed = 100.f;
	m_Player.center = m_CenterStartPoint;
	m_Player.radius = 20;
}

Player::~Player()
{
}



bool Player::CheckHit(const Circlef enemy)
{
	bool result{ utils::IsOverlapping(m_Player, enemy) };
	return result;
}

void Player::Draw()
{
	utils::SetColor(m_RectColor);
	utils::DrawRect(50, 30, 1180, 740);
	utils::SetColor(m_Color);
	utils::FillEllipse(m_Player.center.x, m_Player.center.y, m_Player.radius, m_Player.radius);
}

void Player::UpdateUp(float elapsedSec)
{
	m_Player.center.y+=m_Speed * elapsedSec;
}

void Player::UpdateDown(float elapsedSec)
{
	m_Player.center.y-= m_Speed * elapsedSec;
}

void Player::UpdateLeft(float elapsedSec)
{
	m_Player.center.x-= m_Speed * elapsedSec;
}

void Player::UpdateRight(float elapsedSec)
{
	m_Player.center.x+= m_Speed * elapsedSec;
}




