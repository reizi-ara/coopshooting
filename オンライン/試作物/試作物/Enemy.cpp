#pragma once
#include "char.h"

//コンストラクタ
Enemy::Enemy(float _x, float _y,int _id, float _vx, float _vy) {

	img = LoadGraph("image\\Player2.png");

	pos.x = _x;
	pos.y = _y;

	vec.x = _vx;
	vec.y = _vy;

	ID = _id;


	e_hit = 0;
}

//処理
int Enemy::Action(list<unique_ptr<Bace>>& bace) {

	float r = 0.0f;
	r = vec.x * vec.x + vec.y * vec.y;
	r = sqrt(r);

	if (r == 0.0f)
	{
		;
	}
	else
	{
		vec.x = 2.0f / r * vec.x;
		vec.y = 2.0f / r * vec.y;
	}

	//移動ベクトルを加算
	pos.x += vec.x;
	pos.y += vec.y;

	//画面の端に来たら、移動ベクトルを逆にする
	if (pos.x < 0 || pos.x>WIDTH - 64.0f) vec.x = -vec.x;
	if (pos.y < 0 || pos.y>HEIGHT - 64.0f) vec.y = -vec.y;

	time++;

	if (time == 300)
	{
		auto d = (unique_ptr<Bace>)new Bullet(pos.x + 20, pos.y + 60, 0, 4.0f);
		bace.emplace_back(move(d));
	}

	if (time > 301)
	{
		time = 0;
	}

	if (hp <= 0)
	{
		ID = -999;
	}
	return 0;
}

//描画
void Enemy::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}