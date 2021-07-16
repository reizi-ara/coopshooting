#pragma once
#include "char.h"

//コンストラクタ
boss::boss(float _x, float _y, int _id) {

	img = LoadGraph("image\\boss.png");

	pos.x = _x;
	pos.y = _y;

	vec.x = 4.0f;
	vec.y = 0.0f;


	ID = _id;

	e_hit = 0;
}

//処理
int boss::Action(list<unique_ptr<Bace>>& bace) {



	//移動ベクトルを加算
	pos.x += vec.x;
	pos.y += vec.y;

	//画面の端に来たら、移動ベクトルを逆にする
	if (pos.x < 0 || pos.x>WIDTH - 256.0f) vec.x = -vec.x;
	if (pos.y < 0 || pos.y>HEIGHT - 64.0f) vec.y = -vec.y;

	time++;

	if (time == 180)
	{
		/*auto e = (unique_ptr<Bace>)new Bullet(pos.x + 120, pos.y + 280, 0, 4.0f);
		bace.emplace_back(move(e));*/
	}

	if (time > 181)
	{
		time = 0;
	}

	//hpが0の場合、敵を消す
	if (hp <= 0)
	{
		ID = -999;
	}
	return 0;
}

//描画
void boss::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}