#pragma once
#include "char.h"
#include <math.h>

//コンストラクタ
ShotGunEnemy::ShotGunEnemy(float _x, float _y,float _r,float _speed) {

	img = LoadGraph("image\\EnemyBullet.png");

	pos.x = _x;
	pos.y = _y;

	r = _r;
	speed = _speed;

	ID = 2;

	px = 0;
	py = 0;
}

//当たり判定用関数
int ShotGunCheckHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
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
	int D2 = y2 + h2; // 下(上+縦幅)B

	if (D1 < U2) return 0;
	if (D2 < U1) return 0;

	// それ以外の場合は当たっている
	return 1;
}

//処理
int ShotGunEnemy::Action(list<unique_ptr<Bace>>& bace) 
{
	//速度
	v.y += 4.0f;

	v.x = cos(3.14f / 180.0f * r);
	v.y = sin(3.14f / 180.0f * r);



	//主人公の座標取得
	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if ((*i)->ID == 1) {
			px = ((Player*)(*i).get())->pos.x;//playerのX座標が取れる
			py = ((Player*)(*i).get())->pos.y;//player座標が取れる
		}
	}

	//移動ベクトルを加算
	pos.x += v.x*speed;
	pos.y += v.y*speed;
	
	//主人公に当たったらフラグをtrueにする
	if (ShotGunCheckHit(px, py, 64, 55, pos.x, pos.y, 24, 24) == 1)
	{
		b_hit = true;
	}
	else
		b_hit = false;

	//当たっていたら主人公にダメージを与えて、弾が消える
	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if (((Player*)(*i).get())->ID == 1)
		{
			if (b_hit == true)
			{
				ID = -999;
				((Player*)(*i).get())->hp -= 2;
			}
		}
	}

	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		;
	}
	//領域外の処理
	if (pos.x < -24.0f)
	{
		ID = -999;
	}

	if (pos.x > WIDTH - 24.0f)
	{
		ID = -999;
	}

	if (pos.y < -24.0f)
	{
		ID = -999;
	}

	if (pos.y > HEIGHT - 24.0f)
	{
		ID = -999;
	}

	return 0;
}

//描画
void ShotGunEnemy::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}