#include "pch.h"
#include "Villain.h"
#include "utils.h"

Villain::Villain()
{

}

Villain::~Villain()
{
}

void Villain::Draw()
{
	utils::SetColor(m_Color);
	utils::FillEllipse(m_SpawnPos, g_Villain.radius, g_Villain.radius);
}

void Villain::Update()
{
}
