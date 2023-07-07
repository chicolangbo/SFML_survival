#pragma once

#define _USE_MATH_DEFINES


enum class Origins
{
	TL,
	TC,
	TR,
	ML,
	MC,
	MR,
	BL,
	BC,
	BR,
	CUSTOM,
};

enum class ResourceTypes
{
	Texture,
	Font,
	SoundBuffer,
};

enum class SceneId
{
	None = -1,
	Dev1,
	Count,
};

