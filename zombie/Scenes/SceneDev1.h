#pragma once
#include "Scene.h"
#include "ObjectPool.h"

class Player;
class Zombie;
class SpriteEffect;
class VertexArrayGo;

class SceneDev1 : public Scene
{
protected:

	Player* player;
	ObjectPool<Zombie> zombiePool;
	ObjectPool<SpriteEffect> bloodEffectPool;

	sf::FloatRect wallBounds;
	bool isGameOver;

public:
	SceneDev1();
	virtual ~SceneDev1() override;

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	VertexArrayGo* CreateBackground(sf::Vector2i size, sf::Vector2f tileSize, sf::Vector2f texSize, std::string textureId);

	void SpawnZombies(int count, sf::Vector2f center, float radius);

	template <typename T>
	void ClearObjectPool(ObjectPool<T>& pool);

	void OnDieZombie(Zombie* zombie);
	void OnDiePlayer();

	const std::list<Zombie*>* GetZombieList() const;

};

template<typename T>
inline void SceneDev1::ClearObjectPool(ObjectPool<T>& pool)
{
	for (auto obj : pool.GetUseList())
	{
		RemoveGo(obj);
	}
	pool.Clear();
}
