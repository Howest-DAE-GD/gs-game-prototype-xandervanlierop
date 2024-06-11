#pragma once
class Player
{
public:
	Player();
	~Player();

	bool CheckHitWithEnemy(const Rectf enemy);
	bool CheckHitWithPoints(const Rectf scorePoint);

	void Draw();
	void UpdateUp(float elapsedSec);
	void UpdateDown(float elapsedSec);
	void UpdateLeft(float elapsedSec);
	void UpdateRight(float elapsedSec);

	
private:
	Rectf m_Player{};
	Point2f m_PlayerBottom{80, 40};
	float m_PlayerLength{ 40 };
	Color4f m_Color{ 1.f, 1.f, 1.f, 1.f };
	float m_Speed{};
	float m_AmountOfLives{};
};


	


