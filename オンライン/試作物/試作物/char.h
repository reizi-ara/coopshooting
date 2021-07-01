#pragma once
#include "main.h"

//プレイヤー
class Player :public Bace
{
private:
	bool ShotFlag = false;
	bool Shot_Flag = false;

	//レーザー弾丸を3発でリロードは十秒
	int lb = 3;

	int time = 0;

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
	Enemy(float _x, float _y,int _id);

	int hp = 10;//hpの値
	int time = 0;//時間で弾を管理する用

	bool e_hit;

	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};

//弾
class Bullet :public Bace
{
private:
	float x = 0;
	float y = 0;

	//エネミーの座標を保存する用
	float ex = 0;
	float ey = 0;

	Vec v = { 0.0f,0.0f };

	bool b_hit = false;

	int Hit_id = 0;

public:
	int img{ 0 };//画像
	int img1{ 0 };
	Pos pos{ 250.0f,0.0f };//位置
	Vec vec{ 0.0f,0.0f };//移動ベクトル

	bool flag = true;
	//当たり判定用
	int hit = -1;

	bool hit_bullet() { return b_hit; }
	//コンストラクタ
	Bullet(float _x, float _y, int _ID,float _vy);

	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};

//弾
class LaserBullet :public Bace
{
private:
	float x = 0;
	float y = 0;

	//エネミーの座標を保存する用
	float ex = 0;
	float ey = 0;

	Vec v = { 0.0f,0.0f };

	bool b_hit = false;



public:
	int img{ 0 };//画像
	Pos pos{ 250.0f,0.0f };//位置
	Vec vec{ 0.0f,0.0f };//移動ベクトル

	bool flag = true;
	//当たり判定用
	int hit = 0;

	bool hit_bullet() { return b_hit; }
	//コンストラクタ
	LaserBullet(float _x, float _y, int _ID);

	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};