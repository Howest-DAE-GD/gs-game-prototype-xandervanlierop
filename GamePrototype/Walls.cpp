#include "pch.h"
#include "Walls.h"
#include "utils.h"

Walls::Walls(Rectf wallRect)
{
	m_WallRange.bottom	= wallRect.bottom;
	m_WallRange.left	= wallRect.left;
	m_WallRange.width	= wallRect.width;
	m_WallRange.height	= wallRect.height;

	
}

Walls::~Walls()
{

}

void Walls::Draw()
{
	
		utils::SetColor(m_WallColor);
		utils::DrawRect(m_WallRange);
}

void Walls::CheckHit()
{
}
