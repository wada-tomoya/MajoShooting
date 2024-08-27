#pragma once
#include "ENEMY.h"
#include "PLAYER.h"

const int ENEMY_MAX_NUM = 10;  //�G 1 �o�������
const int ENEMY2_MAX_NUM = 10;  //�G 2 �o�������
const int ENEMY3_MAX_NUM = 10;  //�G 3 �o�������

//�Q�[���^�C�}�[
extern float time_count;
extern int min;
extern int sec;

//���ڂ���
extern int enemy_num;  //�G 1 �o����
extern int enemy_spown_count;  //�G 1 �o���J�E���g
extern int enemy_count;  //�G 1 �o���Ԋu

//�ق�
extern int enemy2_num;  //�G 2 �o����
extern int enemy2_spown_count;  //�G 2 �o���J�E���g
extern int enemy2_count;  //�G 2 �o���Ԋu

//���΂�
extern int enemy3_num;  //�G 3 �o����
extern int enemy3_spown_count;  //�G 3 �o���J�E���g
extern int enemy3_count;  //�G 3 �o���Ԋu

extern bool gameover_flag;  //�Q�[���I�[�o�[�t���O

extern int score;  //�X�R�A

class SCENE_PLAY {
public:
	int g_gpc_play_back; //�v���C��ʔw�i
	int snd_bgm_hdl;  //���@BGM

	void graph();
	void draw();

	void sound_load();  //���@�ǂݍ���
	void sound_bgm_play();  //BGM�Đ�
	void sound_bgm_stop();  //BGM��~
};

void playscene_init();
void title_reset();

void Hitcheck_enemy_bullet();
void Hitcheck_enemy_player();

void Gane_play_main(float delta_taime);  ////�G�L�����A�v���C���[�A�e �����E�\���E�ړ�
void Gameover();