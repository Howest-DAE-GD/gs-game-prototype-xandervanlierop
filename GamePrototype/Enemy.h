#pragma once
class Enemy
{
	public:
		Enemy();
		~Enemy();

		void Draw();
		void Update();
		Circlef g_Enemy{};
	private:
		Point2f m_SpawnPos{};
		int m_AmountOfEnemies{};
		Color4f m_Color{ 1.f, 0.f, 0.f, 1.f };
};

