#include "stdafx.h"
#include "SpriteEffect.h"
#include "SceneMgr.h"

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
	UINT8 a = ((duration - timer) / duration) * 255; // 선형보간
	sprite.setColor({ 255,255,255, a });

	if (timer > duration) // 핏자국 없어지는 타이밍
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
