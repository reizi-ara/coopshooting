#pragma once
#include "char.h"

//コンストラクタ
Player::Player() {
	img = LoadGraph("image\\Player11.png");

	ID = 0;

	ShotFlag = true;

	pos.x = 1.0f;
	pos.y = 1.0f;
}

//処理
int Player::Action(list<Bace*>* bace) {


	//キー入力
	if (CheckHitKey(KEY_INPUT_UP))vec.y = -4.0f;
	if (CheckHitKey(KEY_INPUT_DOWN))vec.y = 4.0f;
	if (CheckHitKey(KEY_INPUT_DOWN) == false && CheckHitKey(KEY_INPUT_UP) == false)
		vec.y = 0.0f;
	if (CheckHitKey(KEY_INPUT_LEFT))vec.x = -4.0f;
	if (CheckHitKey(KEY_INPUT_RIGHT))vec.x = 4.0f;
	if (CheckHitKey(KEY_INPUT_RIGHT) == false && CheckHitKey(KEY_INPUT_LEFT) == false)
		vec.x = 0.0f;


	/*
	for (auto i = bace->begin(); i != bace->end(); i++)
	{
		if ((*i)->ID == 20) {
			((Bullet*)(*i))->pos.x;//エネミーのX座標が取れる
			((Bullet*)(*i))->pos.y;//エネミーのy座標が取れる
		}
	}*/

	//移動ベクトルを加算
	pos.x += vec.x;
	pos.y += vec.y;

	if (pos.x < 0.0f)
	{
		pos.x = 0.0f;
	}

	if (pos.x > 736.0f)
	{
		pos.x = 736.0f;
	}

	if (pos.y < 0.0f)
	{
		pos.y = 0.0f;
	}

	if (pos.y > 536.0f)
	{
		pos.y = 536.0f;
	}

	if (CheckHitKey(KEY_INPUT_Z) == true && ShotFlag == true)
	{
		auto b = (Bace*)new Bullet(pos.x + 20, pos.y, PLAYER_BULLET);
		bace->push_back(b);
		ShotFlag = false;
	}
	else if (CheckHitKey(KEY_INPUT_Z) == false)
	{
		ShotFlag = true;
	}


	return 0;
}

//描画
void Player::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}