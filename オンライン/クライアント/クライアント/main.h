#pragma once
#include "DxLib.h"
#define MAX 4 //接続数
#define WIDTH 800 //windowサイズ　横
#define HEIGHT 600 //windowサイズ　縦

IPDATA IP_set();//IP入力

//スレッドナンバー
enum {
	T_A,
	T_B,
	T_C,
	T_D
};

//移動ベクトル
struct Vec {
	float x, y;
};

//位置情報
struct Point {
	float x, y;
};

//プレイヤークラス
class Data {
private:
public:
	char name[8]{ "null" };//名前
	Point pos{ 0.0f,0.0f };//位置
	int ID{ -1};//オブジェクト識別用
	IPDATA ip{ 0,0,0,0 };//IPアドレス保存用
	//コンストラクタ
	Data();
	Data(float _x, float _y, char* _name);
	//初期化メソッド
	void Data_Init();
};

//送受信データ用のクラス
class SendData {
private:
public:
	Data data[MAX];
};