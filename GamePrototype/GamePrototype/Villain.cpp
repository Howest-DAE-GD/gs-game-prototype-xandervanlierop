#include "pch.h"
#include "Villain.h"
#include "utils.h"
#include "Walls.h"

Villain::Villain()
{
	m_Villain.width = 30.f;
	m_Villain.height = 30.f;
}

Villain::~Villain()
{
}

void Villain::Draw()
{
	utils::SetColor(m_Color);
	utils::FillRect(m_Villain);
}

void Villain::Update()
{
}

Rectf Villain::GetHitbox()
{
	return Rectf{ m_Villain };
}

void Villain::GenerateNewPos(const std::vector<Walls*>& walls, const Rectf& gameWindow)
{
	while (true)
	{
		bool IsOverlapping{ false };
		m_Villain.left = rand() % int(gameWindow.width) - (m_Villain.width * 2) + 60;
		m_Villain.bottom = rand() % int(gameWindow.height) - (m_Villain.height * 2) + 40;
		for (int WallIndex{}; WallIndex < walls.size(); WallIndex++)
		{
			if (utils::IsOverlapping(m_Villain, walls[WallIndex]->GetHitbox()))
			{
				IsOverlapping = true;

				break;
			}
		}

		if (!IsOverlapping)
		{
			break;
		}
	}
}