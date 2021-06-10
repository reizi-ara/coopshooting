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
};//�ʒu

struct  Vec
{
	float x;
	float y;

};//�ړ��x�N�g��

//�x�[�X�N���X
class Bace
{
private:
public:
	Vec pos;
	int ID{ -1 };//�I�u�W�F�N�g��ID
	virtual int Action(list<Bace*>* bace) = 0;//����
	virtual void Draw() = 0;//�`��
};

