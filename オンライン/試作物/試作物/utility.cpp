#include "utility.h"
#include <list>
#include "main.h"
#include "char.h"

float x, y;

float PosXSave(list<unique_ptr<Bace>>& bace)
{
	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		x= ((Enemy*)(*i).get())->pos.x;
		return x;
	}
}

float PosYSave(list<unique_ptr<Bace>>& bace)
{
	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		y= ((Enemy*)(*i).get())->pos.y;
		return y;
	}
}