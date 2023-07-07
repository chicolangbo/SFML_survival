#include "stdafx.h"
#include "SpriteEffect.h"
#include "SceneMgr.h"
#include "Utils.h"

SpriteEffect::SpriteEffect(const std::string& textureId, const std::string& n)
	: SpriteGo(textureId, n)
{
}

void SpriteEffect::Init()
{
	SpriteGo::Init();
	SetOrigin(Origins::MC);
}

void SpriteEffect::Reset()
{
	SpriteGo::Reset();
	timer = 0.f;
	sprite.setColor({ 255,255,255,255 });
}

void SpriteEffect::Update(float dt)
{
	timer += dt;

	// test code : ���� ����
	// UINT8 a = ((duration - timer) / duration) * 255;

	// test code : ���� ���� 
	// UINT8 a = Utils::Lerp(0, 255, (duration - timer) / duration);
	// sprite.setColor({ 255,255,255, a });

	// test code : ���� ����
	//sf::Color a = { 255,255,255,0 };
	//sf::Color b = sf::Color::White;
	//sf::Color color = Utils::Lerp(a, b, (duration - timer) / duration);
	//sprite.setColor(color);

	UINT8 a = Utils::Lerp(255, 0, (timer / duration));
	sprite.setColor({ 255,255,255,a });

	if (timer > duration) // ���ڱ� �������� Ÿ�̹�
	{

		if (pool != nullptr)
		{
			SCENE_MGR.GetCurrScene()->RemoveGo(this);
			pool->Return(this);
		}
		else
		{
			SetActive(false);
		}
	}
}
