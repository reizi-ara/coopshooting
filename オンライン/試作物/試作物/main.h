#pragma once
#include "DxLib.h"
#include <list>
#include <memory>

using namespace std;

#define WIDTH  1000
#define HEIGHT 1000

//IDの代わり
#define PLAYER_BULLET 10
#define ENEMY_BULLET 20
#define BOSS_BULLET 30

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

	int ID{ -1 };//オブジェクトのID
	virtual int Action(list<unique_ptr<Bace>>& bace) = 0;//処理
	virtual void Draw() = 0;//描画
};
