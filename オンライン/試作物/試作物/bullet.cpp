#pragma once
#include "char.h"
#include "utility.h"


Bullet::Bullet(float _x, float _y, int _ID)
{
	img = LoadGraph("image\\bullet.png");

	pos.x = _x;
	pos.y = _y;

	ID = _ID;

	ex = 0;
	ey = 0;
}


//当たり判定用関数
int CheckHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
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

int Bullet::Action(list<unique_ptr<Bace>>& bace)
{

	v.y = -4.0f;


	for (auto i = bace.begin(); i != bace.end(); i++)
	{
	
				if ((*i)->ID== 1) {

					ex = ((Enemy*)(*i).get())->pos.x;//PosXSave(bace);//エネミーのX座標が取れる
					ey = ((Enemy*)(*i).get())->pos.y;//PosYSave(bace);//エネミーのy座標が取れる
					if (CheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
					{
						b_hit = true;
						Hit_id = 1;
						break;
					}
					else
						b_hit = false;
				}

				else if ((*i)->ID == 2) {

					ex = ((Enemy*)(*i).get())->pos.x; //PosXSave(bace);//エネミーのX座標が取れる
					ey = ((Enemy*)(*i).get())->pos.y;//PosYSave(bace);//エネミーのy座標が取れる
					if (CheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
					{
						b_hit = true;
						Hit_id = 2;
						break;
					}
					else
						b_hit = false;
				}

				else if ((*i)->ID == 3) {

					ex = ((Enemy*)(*i).get())->pos.x; //PosXSave(bace);//エネミーのX座標が取れる
					ey = ((Enemy*)(*i).get())->pos.y;//PosYSave(bace);//エネミーのy座標が取れる
					if (CheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
					{
						b_hit = true;
						Hit_id = 3;
						break;
					}
					else
						b_hit = false;
				}

				else if ((*i)->ID == 4) {

					ex = ((Enemy*)(*i).get())->pos.x; //PosXSave(bace);//エネミーのX座標が取れる
					ey = ((Enemy*)(*i).get())->pos.y;//PosYSave(bace);//エネミーのy座標が取れる
					if (CheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
					{
						b_hit = true;
						Hit_id = 4;
						break;
					}
					else
						b_hit = false;
				}
	}



	pos.x += v.x;
	pos.y += v.y;

	/*if (CheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
	{
		b_hit = true;
	}
	else
		b_hit = false;*/

	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if (((Enemy*)(*i).get())->ID == Hit_id);
		{
			if (b_hit == true)
			{
				ID = -999;
				//((Enemy*)(*i).get())->ID = -999;
				if (Hit_id == 1)
				{
					if ((*i)->ID == 1) {
						((Enemy*)(*i).get())->hp -= 1;
					}
				}
				else if (Hit_id == 2)
				{
					if ((*i)->ID == 2) {
						((Enemy*)(*i).get())->hp -= 1;
					}
				}
				else if (Hit_id == 3)
				{
					if ((*i)->ID == 3) {
						((Enemy*)(*i).get())->hp -= 1;
					}
				}
				else if (Hit_id == 4)
				{
					if ((*i)->ID == 4) {
						((Enemy*)(*i).get())->hp -= 1;
					}
				}
			}
		}
	}
	

	if (pos.x < 0.0f)
	{
		ID = -999;
	}

	if (pos.x > WIDTH - 24.0f)
	{
		ID = -999;
	}

	if (pos.y < 0.0f)
	{
		ID = -999;
	}

	if (pos.y > HEIGHT - 24.0f)
	{
		ID = -999;
	}
	return 0;
}

void Bullet::Draw()
{

	DrawGraphF(pos.x, pos.y, img, TRUE);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ex=%f:ey=%f", pos.x, pos.y);
}