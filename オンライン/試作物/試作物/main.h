#pragma once
#include "DxLib.h"
#include <list>

using namespace std;

#define WIDTH  800
#define HEIGHT 600

#define PLAYER_BULLET 10
#define ENEMY_BULLET 20

struct  Pos
{
	float x;
	float y;
};//位置

struct  Vec
{
	float x;
	float y;

};//移動ベクトル

//ベースクラス
class Bace
{
private:
public:
	Vec pos;
	int ID{ -1 };//オブジェクトのID
	virtual int Action(list<Bace*>* bace) = 0;//処理
	virtual void Draw() = 0;//描画
};

