#pragma once
#include "main.h"

//プレイヤー
class Player :public Bace
{
private:
	bool ShotFlag = false;
public:
	int img{ 0 };//画像
	Pos pos{ 0.0f,0.0f };//位置
	Vec vec{ 0.0f,0.0f };//移動ベクトル
	//コンストラクタ
	Player();

	int Action(list<Bace*>* bace);
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

	int Action(list<Bace*>* bace);
	void Draw();
};

//弾
class Bullet :public Bace
{
private:
	int hit = 0;//当たり判定用
	float x = 0;
	float y = 0;

	//エネミーの座標を保存する用
	float ex = 0;
	float ey = 0;

	Vec v = { 0.0f,0.0f };



public:
	int img{ 0 };//画像
	Pos pos{ 0.0f,0.0f };//位置
	Vec vec{ 0.0f,0.0f };//移動ベクトル
	//コンストラクタ
	Bullet(float _x, float _y, int _ID);

	int Action(list<Bace*>* bace);
	void Draw();
};