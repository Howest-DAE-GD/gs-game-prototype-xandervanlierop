#pragma once
class Villain
{
public:
	Villain();
	~Villain();

	void Draw();
	void Update();
	Circlef g_Villain{m_SpawnPos, 20};
private:
	Point2f m_SpawnPos{1100,700};
	int m_AmountOfEnemies{};
	Color4f m_Color{ 1.f, 0.f, 0.f, 1.f };
};

