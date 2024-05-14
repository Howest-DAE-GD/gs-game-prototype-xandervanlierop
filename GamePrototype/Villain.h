#pragma once
class Villain
{
public:
	Villain();
	~Villain();

	void Draw();
	void Update();
	Circlef GetHitbox();
private:
	Circlef m_Villain{};
	Point2f m_SpawnPos{1100,700};
	Color4f m_Color{ 1.f, 0.f, 0.f, 1.f };
};

