#include "BombIterator.h"

void BombIterator::reset(){
	ptr = nullptr;
	curentIndex = -1;
}

BombIterator BombIterator::operator++() {
	
	if (curentIndex == -1)
		curentIndex = 0;
	

	for (; curentIndex < bombs.size(); curentIndex++)
	{
		if (dynamic_cast<Bomb*>(bombs[curentIndex]) != nullptr) {
			ptr = bombs[curentIndex];
			break;
		}
	}

	if (curentIndex == bombs.size())
		reset();
	else
		curentIndex++;
	
	return *this;
}

BombIterator BombIterator::operator--(){
	if (curentIndex == -1)
		return *this;

	for (;curentIndex >= 0; curentIndex--) {
		if (dynamic_cast<Bomb*>(bombs[curentIndex]) != nullptr) {
			ptr = bombs[curentIndex];
			break;
		}
	}
	if (curentIndex == -1)
		reset();
	else
		curentIndex--;
	return *this;
		
}

bool BombIterator::operator==(const BombIterator b) const {
	return (this->ptr == b.ptr);
}

bool BombIterator::operator!=(const BombIterator b) const {
	return (this->ptr != b.ptr);
}

DynamicObject* BombIterator::operator*(){
	return ptr;
}

BombIterator BombIterator::begin(){ 
	BombIterator it(this->bombs);
	return it;
}

BombIterator BombIterator::end(){
	BombIterator it(this->bombs);
	it.reset();
	return it;
}