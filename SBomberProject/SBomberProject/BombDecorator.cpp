#include "BombDecorator.h"
#include "MyTools.h"

#include <iostream>

void BombDecorator::Move(uint16_t time) {
	bomb.Move(time);
}

void BombDecorator::Draw() const {
	bomb.Draw();
	// Некоторое изменение внешнего вида бомбы
	MyTools::GotoXY(bomb.GetX(), bomb.GetY() - 1);
	std::cout << "|";
}

void BombDecorator::SetPos(double nx, double ny) {
	bomb.SetPos(nx, ny); 
}

uint16_t BombDecorator::GetWidth() const {
	return bomb.GetWidth(); 
}
