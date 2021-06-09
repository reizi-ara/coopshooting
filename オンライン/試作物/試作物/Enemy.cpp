#pragma once
#include "char.h"

//コンストラクタ
Enemy::Enemy(float _x,float _y) {
	img = LoadGraph("image\\ai(64).jpg");
	vec.x = 4.0f + _x;
	vec.y = 3.0f + _y;

	ID = 1;
}

//処理
int Enemy::Action(list<unique_ptr<Bace>>& bace) {

	//移動ベクトルを加算
	pos.x += vec.x;
	pos.y += vec.y;

	//画面の端に来たら、移動ベクトルを逆にする
	if (pos.x < 0 || pos.x>736.0f)vec.x = -vec.x;
	if (pos.y < 0 || pos.y>546.0f)vec.y = -vec.y;

	return 0;
}

//描画
void Enemy::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}