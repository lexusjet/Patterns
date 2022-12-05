#pragma once

#include "DynamicObject.h"

#include "Bomb.h"

class BombDecorator: public DynamicObject{
private:
	Bomb bomb;

public:
	BombDecorator() {};
	void Move(uint16_t time) override;
	void Draw() const override;

	void SetPos(double nx, double ny);
	uint16_t GetWidth() const;
};

