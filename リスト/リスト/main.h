#pragma once
#include "DxLib.h"
#include <list>
#include <memory>

using namespace std;

#define WIDTH 800
#define HEIGHT 600

struct Pos//�ʒu
{
	float x;
	float y;
};

//�ړ��x�N�g��
struct Vec
{
	float x;
	float y;
};

//�x�[�X�N���X
class Bace {
private:
public:
	int ID{ -1 };//�I�u�W�F�N�g��ID
	virtual int Action(list<unique_ptr<Bace>> &bace)=0;

	//virtual int Action(list<Bace*>* bace) = 0;//����
	virtual void Draw() = 0;//�`��
};