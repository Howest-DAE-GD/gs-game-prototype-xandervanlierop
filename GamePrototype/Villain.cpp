#include "pch.h"
#include "Villain.h"
#include "utils.h"

Villain::Villain()
{
	m_Villain.center = m_SpawnPos;
	m_Villain.radius = 20;
}

Villain::~Villain()
{
}

void Villain::Draw()
{
	utils::SetColor(m_Color);
	utils::FillEllipse(m_SpawnPos, m_Villain.radius, m_Villain.radius);
}

void Villain::Update()
{
}

Circlef Villain::GetHitbox()
{
	return Circlef(m_Villain);
}
