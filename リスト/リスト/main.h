#pragma once
#include "DxLib.h"
#include <list>
#include <memory>

using namespace std;

#define WIDTH 800
#define HEIGHT 600

struct Pos//位置
{
	float x;
	float y;
};

//移動ベクトル
struct Vec
{
	float x;
	float y;
};

//ベースクラス
class Bace {
private:
public:
	int ID{ -1 };//オブジェクトのID
	virtual int Action(list<unique_ptr<Bace>> &bace)=0;

	//virtual int Action(list<Bace*>* bace) = 0;//処理
	virtual void Draw() = 0;//描画
};