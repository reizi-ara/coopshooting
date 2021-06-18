#pragma once
#include "char.h"


LaserBullet::LaserBullet(float _x, float _y, int _ID)
{
	img = LoadGraph("image\\レーザー.png");

	pos.x = _x;
	pos.y = _y;

	ID = _ID;

	ex = 0;
	ey = 0;
}


//当たり判定用関数
int LaserCheckHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	int L1 = x1;      // 左
	int R1 = x1 + w1; // 右(左+横幅)
	int L2 = x2;      // 左
	int R2 = x2 + w2; // 右(左+横幅)

	if (R1 < L2) return 0;
	if (R2 < L1) return 0;

	int U1 = y1;      // 上
	int D1 = y1 + h1; // 下(上+縦幅)
	int U2 = y2;      // 上
	int D2 = y2 + h2; // 下(上+縦幅)

	if (D1 < U2) return 0;
	if (D2 < U1) return 0;

	// それ以外の場合は当たっている
	return 1;
}

int LaserBullet::Action(list<unique_ptr<Bace>>& bace)
{

	v.y = -4.0f;


	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if ((*i)->ID == 1) {
			ex = ((Enemy*)(*i).get())->pos.x;//エネミーのX座標が取れる
			ey = ((Enemy*)(*i).get())->pos.y;//エネミーのy座標が取れる
		}
	}


	pos.x += v.x;
	pos.y += v.y;

	if (LaserCheckHit(ex, ey, 64, 55, pos.x, pos.y, 22, 119) == 1)
	{
		b_hit = true;
	}
	else
		b_hit = false;

	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if (((Enemy*)(*i).get())->ID == 1)
		{
			if (b_hit == true)
			{
				ID = -999;
				//((Enemy*)(*i).get())->ID = -999;
				((Enemy*)(*i).get())->hp -= 5;
			}
		}
	}

	if (pos.x < 0.0f)
	{
		ID = -999;
	}

	if (pos.x > WIDTH - 22.0f)
	{
		ID = -999;
	}

	if (pos.y < -119.0f)
	{
		ID = -999;
	}

	if (pos.y > HEIGHT - 119.0f)
	{
		ID = -999;
	}

	return 0;
}

void LaserBullet::Draw()
{

	DrawGraphF(pos.x, pos.y, img, TRUE);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ex=%f:ey=%f", pos.x, pos.y);
}