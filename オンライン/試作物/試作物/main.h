#pragma once
#include "DxLib.h"
#include <list>
#include <memory>

using namespace std;

#define WIDTH  1000
#define HEIGHT 1000

//ID�̑���
#define PLAYER_BULLET 10
#define ENEMY_BULLET 20
#define BOSS_BULLET 30

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

	int ID{ -1 };//�I�u�W�F�N�g��ID
	virtual int Action(list<unique_ptr<Bace>>& bace) = 0;//����
	virtual void Draw() = 0;//�`��
};
