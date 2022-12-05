#pragma once

#include <vector>

#include "Bomb.h"

class BombIterator
{
private:
	const std::vector<DynamicObject*>& bombs;
	int64_t curentIndex;
	DynamicObject* ptr;
public:
	void reset();
	bool operator==(const BombIterator) const;
	bool operator!=(const BombIterator) const;
	BombIterator operator++();
	BombIterator operator--();
	DynamicObject* operator*();
	BombIterator begin();
	BombIterator end();
	BombIterator(const std::vector<DynamicObject*>& b) :bombs(b), curentIndex(-1), ptr(nullptr) { ++(*this); };
};

