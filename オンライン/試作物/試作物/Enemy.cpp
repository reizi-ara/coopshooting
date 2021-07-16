#pragma once
#include "char.h"

//コンストラクタ
Enemy::Enemy(float _x, float _y,int _id, float _vx, float _vy,float speed) {

	img = LoadGraph("image\\Player2.png");

	pos.x = _x;
	pos.y = _y;

	vec.x = _vx;
	vec.y = _vy;

	ID = _id;

	e_speed = speed;


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
		vec.x = vec.x / r * e_speed;
		vec.y = vec.y / r * e_speed;
	}

	//移動ベクトルを加算
	pos.x += vec.x;
	pos.y += vec.y;

	//画面の端に来たら、移動ベクトルを逆にする
<<<<<<< Updated upstream
	if (pos.x < 32.0f || pos.x - 32.0f>WIDTH - 64.0f) vec.x = -vec.x;
	if (pos.y < 0 || pos.y >HEIGHT - 64.0f) vec.y = -vec.y;
=======
	if (pos.x < 0 || pos.x>WIDTH - 64.0f) 
		vec.x *= -1;
	if (pos.y < 0 || pos.y>HEIGHT - 64.0f) ID = -999;
>>>>>>> Stashed changes

	time++;

	if (time == 300)
	{
<<<<<<< Updated upstream
		/*auto d = (unique_ptr<Bace>)new Bullet(pos.x + 20, pos.y + 60, 0, 4.0f);
		bace.emplace_back(move(d));*/
=======
	/*	auto d = (unique_ptr<Bace>)new Bullet(pos.x + 20, pos.y + 60, 0, 4.0f);
		bace.emplace_back(move(d));
>>>>>>> Stashed changes

		auto u = (unique_ptr<Bace>)new ShotGunEnemy(pos.x - 10, pos.y + 20, 60, 4.0f);
		bace.emplace_back(move(u));

		auto y = (unique_ptr<Bace>)new ShotGunEnemy(pos.x - 10, pos.y + 20, 90, 4.0f);
		bace.emplace_back(move(y));

<<<<<<< Updated upstream
		auto p = (unique_ptr<Bace>)new ShotGunEnemy(pos.x - 10, pos.y + 20, 120, 4.0f);
		bace.emplace_back(move(p));
=======
		auto p = (unique_ptr<Bace>)new ShotGunEnemy(pos.x + 20, pos.y + 60, 90, 4.0f);
		bace.emplace_back(move(p));*/
>>>>>>> Stashed changes
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
	DrawRotaGraph(pos.x, pos.y+32.0f, 1.0f, 0.0f, img, TRUE, 0, true);
}