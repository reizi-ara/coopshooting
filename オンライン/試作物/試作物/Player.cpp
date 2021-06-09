#pragma once
#include "char.h"

//コンストラクタ
Player::Player() {
	img = LoadGraph("image\\kurumi(64).jpg");

	ID = 0;
}

//処理
int Player::Action(list<unique_ptr<Bace>>& bace) {
	//キー入力
	Vec v{ 0.0f,0.0f };
	if (CheckHitKey(KEY_INPUT_UP))v.y = -4.0f;
	if (CheckHitKey(KEY_INPUT_DOWN))v.y = 4.0f;
	if (CheckHitKey(KEY_INPUT_LEFT))v.x = -4.0f;
	if (CheckHitKey(KEY_INPUT_RIGHT))v.x = 4.0f;

	

	//移動ベクトルを加算
	pos.x += v.x;
	pos.y += v.y;

	return 0;
}

//描画
void Player::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}