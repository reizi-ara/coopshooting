#pragma once
#include "main.h"

//プレイヤー
class Player :public Bace
{
private:
public:
	int img{ 0 };//画像
	Pos pos{ 0.0f,0.0f };//位置
	Vec vec{ 0.0f,0.0f };//移動ベクトル
	//コンストラクタ
	Player();

	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};

//敵
class Enemy :public Bace
{
private:
public:
	int img{ 0 };//画像
	Pos pos{ 0.0f,0.0f };//位置
	Vec vec{ 0.0f,0.0f };//移動ベクトル
	//コンストラクタ
	Enemy(float _x, float _y);

	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};