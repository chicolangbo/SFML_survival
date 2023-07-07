#pragma once
#include "Singleton.h"

enum class Axis
{
	Horizontal,
	Vertical,
};

struct AxisInfo
{
	Axis axis;
	std::list<int> positivies;
	std::list<int> negatives;

	float sensi = 3.f; // 이 값이 크면 빠르게 변화
	float value = 0.f; // -1.0~1.0 사잇값
};


class InputMgr : public Singleton<InputMgr>
{
	friend Singleton<InputMgr>;

protected:
	InputMgr();
	virtual ~InputMgr() override = default;

	std::list<int> downList;
	std::list<int> upList;
	std::list<int> ingList;

	sf::Vector2f mousePos;

	std::map<Axis, AxisInfo> axisInfoMap;

public:
	void Update(float dt);
	void UpdateEvent(const sf::Event& ev);

	// Keyboard
	bool GetKeyDown(sf::Keyboard::Key key);
	bool GetKey(sf::Keyboard::Key key);
	bool GetKeyUp(sf::Keyboard::Key key);

	// Mouse
	const sf::Vector2f& GetMousePos();
	bool GetMouseButtonDown(sf::Mouse::Button button);
	bool GetMouseButton(sf::Mouse::Button button);
	bool GetMouseButtonUp(sf::Mouse::Button button);

	// Axis
	float GetAxis(Axis axis);
	float GetAxisRaw(Axis axis);
};

#define INPUT_MGR (InputMgr::Instance())
