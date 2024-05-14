#include "pch.h"
#include "ScorePoint.h"
#include "utils.h"
#include "Walls.h"

ScorePoint::ScorePoint(const std::vector<Walls*>& walls, const Rectf& gameWindow)
{
	m_ScorePoint.width = 10.f;
	m_ScorePoint.height = 10.f;
	m_ScorePoint.left = rand() % int(gameWindow.width) - (m_ScorePoint.width * 2) + 60;
	m_ScorePoint.bottom = rand() % int(gameWindow.height) - (m_ScorePoint.height * 2) + 40;

	GenerateNewPos(walls, gameWindow);

}

ScorePoint::~ScorePoint()
{

}

void ScorePoint::Draw()
{
	utils::SetColor(m_ScorePointColor);
	utils::FillRect(m_ScorePoint);
}

void ScorePoint::Update(float elapsedSec)
{
}

void ScorePoint::CountPoints()
{

}

void ScorePoint::GenerateNewPos(const std::vector<Walls*>& walls, const Rectf& gameWindow)
{
	while (true)
	{
		bool IsOverlapping{ false };
		m_ScorePoint.left = rand() % int(gameWindow.width) - (m_ScorePoint.width * 2) + 60;
		m_ScorePoint.bottom = rand() % int(gameWindow.height) - (m_ScorePoint.height * 2) + 40;
		for (int WallIndex{}; WallIndex < walls.size(); WallIndex++)
		{
			if (utils::IsOverlapping(m_ScorePoint, walls[WallIndex]->GetHitbox()))
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


