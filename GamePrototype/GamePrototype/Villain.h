#pragma once
#include <vector>
#include "Walls.h"
class Villain
{
public:
	Villain();
	~Villain();

	void Draw();
	void Update();
	Rectf GetHitbox();
private:
	void GenerateNewPos(const std::vector<Walls*>& walls, const Rectf& gameWindow);
	Rectf m_Villain{};
	Color4f m_Color{ 1.f, 0.f, 0.f, 1.f };
};

