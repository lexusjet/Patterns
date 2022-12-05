#include "TankAdaptee.h"

#include "MyTools.h"
#include "GameObject.h"

#include <iostream>
#include <stdint.h>
#include <windows.h>

void __fastcall GotoXY(double x, double y)
{
	const COORD cc = { short(x), short(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cc);
}

void TankAdaptee::Paint() const
{
	MyTools::SetColor(MyTools::CC_Brown);
	GotoXY(x, y - 3);
	std::cout << "    #####";
	GotoXY(x - 2, y - 2);
	std::cout << "#######   #";
	GotoXY(x, y - 1);
	std::cout << "    #####";
	GotoXY(x, y);
	std::cout << " ###########";
}

bool TankAdaptee::isInRange(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}