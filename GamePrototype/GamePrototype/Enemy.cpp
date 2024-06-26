#include "pch.h"
#include "Enemy.h"
#include "utils.h"

Enemy::Enemy()
{
	m_Villain.x = rand() % 1000 + 100;

	g_Enemy.center = m_Villain;
	g_Enemy.radius = 20;
}

Enemy::~Enemy()
{
}

void Enemy::Draw()
{
	utils::FillEllipse(m_Villain, g_Enemy.radius, g_Enemy.radius);
}

void Enemy::Update()
{
}
