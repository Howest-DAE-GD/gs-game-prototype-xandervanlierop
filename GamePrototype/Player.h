#pragma once
class Player
{
public:
	Player();
	~Player();

	bool CheckHit(const Circlef enemy);

	void Draw();
	void UpdateUp(float elapsedSec);
	void UpdateDown(float elapsedSec);
	void UpdateLeft(float elapsedSec);
	void UpdateRight(float elapsedSec);

	
	
private:
	Circlef m_Player{};
	Point2f m_CenterStartPoint{80, 60};
	Color4f m_Color{ 1.f, 1.f, 1.f, 1.f };
	Color4f m_RectColor{ 1.f, 0.f, 0.f, 1.f };
	float m_Speed{};
	float m_AmountOfLifes{};
};


	


