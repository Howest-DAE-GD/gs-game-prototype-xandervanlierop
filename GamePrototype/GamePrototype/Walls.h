#pragma once
class Walls
{
public:
	Walls(Rectf wallRect);
	~Walls();

	void Draw();
	bool IsOverlapping(const Rectf& player);
	Rectf GetHitbox();
private:
	Rectf m_WallRange;
	Color4f m_WallColor{ 1.f,1.f,1.f,1.f };
};

