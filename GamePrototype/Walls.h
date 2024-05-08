#pragma once
class Walls
{
public:
	Walls(Rectf wallRect);
	~Walls();

	void Draw();
	void CheckHit();
private:
	Rectf m_WallRange;
	Color4f m_WallColor{ 1.f,1.f,1.f,1.f };
};

