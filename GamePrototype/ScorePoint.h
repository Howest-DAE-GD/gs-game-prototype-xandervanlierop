#pragma once
#include <vector>
#include "Walls.h"
class ScorePoint
{
public:
	ScorePoint(const std::vector<Walls*>& walls, const Rectf& gameWindow);
	~ScorePoint();

	void Draw();
	void Update(float elapsedSec);
	void CountPoints();

	Rectf GetHitbox();

	
private:
	void GenerateNewPos(const std::vector<Walls*>& walls, const Rectf& gameWindow);

	Rectf m_ScorePoint{};
	Color4f m_ScorePointColor{ 0.f,1.f,0.f,1.f };


};

