#include "../dxlib_ext/dxlib_ext.h"
#include "SCENE_PLAY.h"
#include "ENEMY.h"
#include "PLAYER.h"

PLAYER chpl;
ENEMY_1 chen1[ENEMY_MAX_NUM];
ENEMY_2 chen2[ENEMY2_MAX_NUM];
ENEMY_3 chen3[ENEMY3_MAX_NUM];

float time_count;
int min;
int sec;

//���ڂ���
int enemy_num;  //�G 1 �o����
int enemy_spown_count;  //�G 1 �o���J�E���g
int enemy_count;  //�G 1 �o���Ԋu

//�ق�
int enemy2_num;  //�G 2 �o����
int enemy2_spown_count;  //�G 2 �o���J�E���g
int enemy2_count;  //�G 2 �o���Ԋu

//���΂�
int enemy3_num;  //�G 3 �o����
int enemy3_spown_count;  //�G 3 �o���J�E���g
int enemy3_count;  //�G 3 �o���Ԋu

bool gameover_flag;  //�Q�[���I�[�o�[�t���O

int score;  //�X�R�A
//---------------------------------------------------------------------------------------------------------------------
//�w�i�摜�ǂݍ���
void SCENE_PLAY::graph() {

	g_gpc_play_back = LoadGraph("graphics/unnamed.jpg");
}
//�w�i�摜�\��
void SCENE_PLAY::draw() {

	DrawRotaGraph(630, 350, 2, 0, g_gpc_play_back, false);
}
//�v���C�V�[���@���@�ǂݍ���
void SCENE_PLAY::sound_load() {

	snd_bgm_hdl = LoadSoundMem("sound/play_bgm4.mp3");
}
//�v���C�V�[���@BGM�@�Đ�
void SCENE_PLAY::sound_bgm_play() {

	ChangeVolumeSoundMem(50, snd_bgm_hdl);
	PlaySoundMem(snd_bgm_hdl, DX_PLAYTYPE_LOOP, true);
}
//�v���C�V�[���@BGM�@��~
void SCENE_PLAY::sound_bgm_stop() {

	StopSoundMem(snd_bgm_hdl);
}

//�v���C���[�A�e�ϐ�������
void playscene_init() {

	//���ڂ���
	enemy_num = 7;  //�G 1 �o����
	enemy_spown_count = 0;  //�G 1 �o���J�E���g
	enemy_count = 120;  //�G 1 �o���Ԋu

	//�ق�
	enemy2_num = 7;  //�G 2 �o����
	enemy2_spown_count = 0;  //�G 2 �o���J�E���g
	enemy2_count = 120;  //�G 2 �o���Ԋu

	//���΂�
	enemy3_num = 7;  //�G 3 �o����
	enemy3_spown_count = 0;  //�G 3 �o���J�E���g
	enemy3_count = 120;  //�G 3 �o���Ԋu

	//�Q�[���^�C�}�[
	time_count = 60 * 10;
	min = 0;
	sec = 0;

	//�X�R�A
	score = 0;

	//�Q�[���I�[�o�[�t���O
	gameover_flag = false;

	//�v���C���[�ϐ�������
	chpl.init();
	chpl.graph();

	//�G�l�~�[�ϐ�������
	for (int i = 0; i < ENEMY_MAX_NUM; ++i) {
		chen1[i].init1();
	}
	for (int i = 0; i < ENEMY2_MAX_NUM; ++i) {
		chen2[i].init2();
	}
	for (int i = 0; i < ENEMY2_MAX_NUM; ++i) {
		chen3[i].init3();
	}
	//�G�l�~�[�@�摜�@���@�ǂݍ���
	for (int i = 0; i < ENEMY_MAX_NUM; ++i) {
		chen1[i].Graph();
		chen1[i].sound_load();
	}
	for (int i = 0; i < ENEMY2_MAX_NUM; ++i) {
		chen2[i].Graph2();
		chen2[i].sound_load();
	}
	for (int i = 0; i < ENEMY3_MAX_NUM; ++i) {
		chen3[i].Graph3();
		chen3[i].sound_load();
	}
}

void title_reset() {

	//���ڂ���
	enemy_num = 7;  //�G 1 �o����
	enemy_spown_count = 0;  //�G 1 �o���J�E���g
	enemy_count = 120;  //�G 1 �o���Ԋu

	//�ق�
	enemy2_num = 7;  //�G 2 �o����
	enemy2_spown_count = 0;  //�G 2 �o���J�E���g
	enemy2_count = 120;  //�G 2 �o���Ԋu

	//���΂�
	enemy3_num = 7;  //�G 3 �o����
	enemy3_spown_count = 0;  //�G 3 �o���J�E���g
	enemy3_count = 120;  //�G 3 �o���Ԋu

	//�Q�[���^�C�}�[
	time_count = 60 * 10;
	min = 0;
	sec = 0;

	//�X�R�A
	score = 0;

	//�Q�[���I�[�o�[�t���O
	gameover_flag = false;

	//�v���C���[�ϐ�������
	chpl.pos = { 645, 685, 0 };
	chpl.life_stock = 5;
	chpl.life = true;
	//�e�ϐ�������
	for (int i = 0; i < 20; ++i) {
		chpl.bullet_z[i].flag = false;
		chpl.bullet_x[i].flag = false;
		chpl.bullet_c[i].flag = false;
	}

	//�G�l�~�[�ϐ�������
	for (int i = 0; i < ENEMY_MAX_NUM; ++i) {
		chen1[i].init1();
	}
	for (int i = 0; i < ENEMY2_MAX_NUM; ++i) {
		chen2[i].init2();
	}
	for (int i = 0; i < ENEMY2_MAX_NUM; ++i) {
		chen3[i].init3();
	}
}

void Gane_play_main(float delta_time) {

	//�o�ߎ��ԁ@�\��
	time_count -= delta_time;
	min = (int)time_count / 60;
	sec = (int)time_count % 60;
	SetFontSize(70);
	DrawStringEx(50, 20, -1, "%d : %d", min, sec);

	//�v���C���[�c�@�@�\��
	DrawStringEx(1050, 500, -1, "%d", chpl.life_stock);

	//�X�R�A�\��
	SetFontSize(50);
	DrawStringEx(1000, 10, -1, "�X�R�A");

	DrawStringEx(1000, 60, -1, "%d", score);

	//�G�L���� 1 �����@���ڂ���
	enemy_spown_count++;
	for (int i = 0; i < enemy_num; ++i) {
		if (enemy_spown_count % enemy_count == 0) {
			if (chen1[i].flag == false) {
				chen1[i].flag = true;
				chen1[i].Enemy();

				break;
			}
		}
	}
	
	//�G�L���� 1 �摜�\��
	for (int i = 0; i < enemy_num; ++i) {
		if (chen1[i].flag) {
			chen1[i].Draw();
		}
	}
	//�G�L���� 1 �ړ�
	for (int i = 0; i < enemy_num; ++i) {
		if (chen1[i].flag && chen1[i].aiko_flag == false) {
			chen1[i].Move();
		}
		if (chen1[i].flag && chen1[i].aiko_flag == true) {
			chen1[i].aiko_stop_time();
		}
	}

	//�G�L���� 2 �����@�ق�
	enemy2_spown_count++;
	for (int i = 0; i < enemy2_num; ++i) {
		if (enemy2_spown_count % enemy2_count == 0 && enemy2_spown_count >= 0) {
			if (chen2[i].flag2 == false) {
				chen2[i].flag2 = true;
				chen2[i].Enemy2();
				break;
			}
		}
	}
	//�G�L���� 2 �摜�\��
	for (int i = 0; i < enemy2_num; ++i) {
		if (chen2[i].flag2) {
			chen2[i].Draw2();
		}
	}
	//�G�L���� 2 �ړ�
	for (int i = 0; i < enemy2_num; ++i) {
		if (chen2[i].flag2 && chen2[i].aiko_flag == false) {
			chen2[i].Move2();
		}
		if (chen2[i].flag2 && chen2[i].aiko_flag == true) {
			chen2[i].aiko_stop_time();
		}
	}

	//�G�L���� 3 �����@���΂�
	enemy3_spown_count++;
	for (int i = 0; i < enemy3_num; ++i) {
		if (enemy3_spown_count % enemy3_count == 0 && enemy3_spown_count >= 0) {
			if (chen3[i].flag3 == false) {
				chen3[i].flag3 = true;
				chen3[i].Enemy3();
				break;
			}	
		}
	}
	//�G�L���� 3 �摜�\��
	for (int i = 0; i < enemy3_num; ++i) {
		if (chen3[i].flag3) {
			chen3[i].Draw3();
		}
	}
	//�G�L���� 3 �ړ�
	for (int i = 0; i < enemy3_num; ++i) {
		if (chen3[i].flag3 && chen3[i].aiko_flag == false) {
			chen3[i].Move3();
		}
		if (chen3[i].flag3 && chen3[i].aiko_flag == true) {
			chen3[i].aiko_stop_time();
		}
	}

	//�v���C���[�A�e
	chpl.shot_z();  //�e���̔��ˏ��������s
	chpl.shot_x();  //�e���̔��ˏ��������s
	chpl.shot_c();  //�e���̔��ˏ��������s
	chpl.move();  //�v���C���[�ړ�
	chpl.draw();  //�v���C���[�摜�\��
}

//�����蔻��@�e�ƓG
void Hitcheck_enemy_bullet() {

	//�ez�Ƃ��ڂ���
	for (int i = 0; i < enemy_num; i++) {
		tnl::Vector3 enemy_kabocha_pos = { chen1[i].enemy_x, chen1[i].enemy_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_z_pos = { chpl.bullet_z[u].x + 17, chpl.bullet_z[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_z_pos, chpl.bullet_x[u].width / 2, enemy_kabocha_pos, chen1[i].enemy_w / 2)
				&& chpl.bullet_z[u].flag && chen1[i].flag) {

				chpl.bullet_z[u].flag = false;
				chen1[i].aiko_flag = true;
			}
		}
	}
	//�ex�Ƃ��ڂ���
	for (int i = 0; i < enemy_num; i++) {
		tnl::Vector3 enemy_kabocha_pos = { chen1[i].enemy_x, chen1[i].enemy_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_x_pos = { chpl.bullet_x[u].x + 17, chpl.bullet_x[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_x_pos, chpl.bullet_x[u].width / 2, enemy_kabocha_pos, chen1[i].enemy_w / 2)
				&& chpl.bullet_x[u].flag && chen1[i].flag) {

				chpl.bullet_x[u].flag = false;
			}
		}
	}
	//�ec�Ƃ��ڂ���
	for (int i = 0; i < enemy_num; i++) {
		tnl::Vector3 enemy_kabocha_pos = { chen1[i].enemy_x, chen1[i].enemy_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_c_pos = { chpl.bullet_c[u].x + 17, chpl.bullet_c[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_c_pos, chpl.bullet_c[u].width / 2, enemy_kabocha_pos, chen1[i].enemy_w / 2)
				&& chpl.bullet_c[u].flag && chen1[i].flag) {

				chen1[i].flag = false;
				chpl.bullet_c[u].flag = false;
				chen1[i].sound_play(); 
				score += 10;
			}
		}
	}

	//�ez�Ƃق�
	for (int i = 0; i < enemy2_num; i++) {
		tnl::Vector3 enemy_hone_pos = { chen2[i].enemy2_x, chen2[i].enemy2_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_z_pos = { chpl.bullet_z[u].x + 17, chpl.bullet_z[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_z_pos, chpl.bullet_x[u].width / 2, enemy_hone_pos, chen2[i].enemy2_w / 2)
				&& chpl.bullet_z[u].flag && chen2[i].flag2) {

				chen2[i].flag2 = false;
				chpl.bullet_z[u].flag = false;
				chen2[i].sound_play();
				score += 10;
			}
		}
	}
	//�ex�Ƃق�
	for (int i = 0; i < enemy2_num; i++) {
		tnl::Vector3 enemy_hone_pos = { chen2[i].enemy2_x, chen2[i].enemy2_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_x_pos = { chpl.bullet_x[u].x + 17, chpl.bullet_x[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_x_pos, chpl.bullet_x[u].width / 2, enemy_hone_pos, chen2[i].enemy2_w / 2)
				&& chpl.bullet_x[u].flag && chen2[i].flag2) {
				
				chpl.bullet_x[u].flag = false;
				chen2[i].aiko_flag = true;
			}
		}
	}
	//�ec�Ƃق�
	for (int i = 0; i < enemy2_num; i++) {
		tnl::Vector3 enemy_hone_pos = { chen2[i].enemy2_x, chen2[i].enemy2_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_c_pos = { chpl.bullet_c[u].x + 17, chpl.bullet_c[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_c_pos, chpl.bullet_c[u].width / 2, enemy_hone_pos, chen2[i].enemy2_w / 2)
				&& chpl.bullet_c[u].flag && chen2[i].flag2) {
				
				chpl.bullet_c[u].flag = false;
			}
		}
	}

	//�ez�Ƃ��΂�
	for (int i = 0; i < enemy3_num; i++) {
		tnl::Vector3 enemy_obake_pos = { chen3[i].enemy3_x, chen3[i].enemy3_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_z_pos = { chpl.bullet_z[u].x + 17, chpl.bullet_z[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_z_pos, chpl.bullet_x[u].width / 2, enemy_obake_pos, chen3[i].enemy3_w / 2)
				&& chpl.bullet_z[u].flag && chen3[i].flag3) {
				
				chpl.bullet_z[u].flag = false;
			}
		}
	}
	//�ex�Ƃ��΂�
	for (int i = 0; i < enemy3_num; i++) {
		tnl::Vector3 enemy_obake_pos = { chen3[i].enemy3_x, chen3[i].enemy3_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_x_pos = { chpl.bullet_x[u].x + 17, chpl.bullet_x[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_x_pos, chpl.bullet_x[u].width / 2, enemy_obake_pos, chen3[i].enemy3_w / 2)
				&& chpl.bullet_x[u].flag && chen3[i].flag3) {

				chpl.bullet_x[u].flag = false;
				chen3[i].flag3 = false;
				chen3[i].sound_play();
				score += 10;
			}
		}
	}
	//�ec�Ƃ��΂�
	for (int i = 0; i < enemy3_num; i++) {
		tnl::Vector3 enemy_obake_pos = { chen3[i].enemy3_x, chen3[i].enemy3_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_c_pos = { chpl.bullet_c[u].x + 17, chpl.bullet_c[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_c_pos, chpl.bullet_c[u].width / 2, enemy_obake_pos, chen3[i].enemy3_w / 2)
				&& chpl.bullet_c[u].flag && chen3[i].flag3) {
				
				chpl.bullet_c[u].flag = false;
				chen3[i].aiko_flag = true;
			}
		}
	}
}

//�����蔻�� �v���C���[�ƓG
void Hitcheck_enemy_player() {
	//�v���C���[�Ƃ��ڂ���
	for (int i = 0; i < enemy_num; i++) {
		tnl::Vector3 enemy_kabocha_pos = { chen1[i].enemy_x, chen1[i].enemy_y, 0 };  //���ڂ�����W
		
		if (tnl::IsIntersectSphere(chpl.pos, chpl.width / 2, enemy_kabocha_pos, chen1[i].enemy_w / 2)
			&& chpl.life && chen1[i].flag) {

			chen1[i].flag = false;
			ChangeVolumeSoundMem(100, chpl.player_hit_sound);
			PlaySoundMem(chpl.player_hit_sound, DX_PLAYTYPE_BACK);
			chpl.life_stock -= 1;
		}
	}
	//�v���C���[�Ƃق�
	for (int i = 0; i < enemy2_num; i++) {
		tnl::Vector3 enemy_hone_pos = { chen2[i].enemy2_x, chen2[i].enemy2_y, 0 };

		if (tnl::IsIntersectSphere(chpl.pos, chpl.width / 2, enemy_hone_pos, chen2[i].enemy2_w / 2)
			&& chpl.life && chen2[i].flag2) {

			chen2[i].flag2 = false;
			ChangeVolumeSoundMem(100, chpl.player_hit_sound);
			PlaySoundMem(chpl.player_hit_sound, DX_PLAYTYPE_BACK);
			chpl.life_stock -= 1;
		}
	}
	//�v���C���[�Ƃ��΂�
	for (int i = 0; i < enemy3_num; i++) {
		tnl::Vector3 enemy_obake_pos{ chen3[i].enemy3_x, chen3[i].enemy3_y, 0 };

		if (tnl::IsIntersectSphere(chpl.pos, chpl.width / 2, enemy_obake_pos, chen3[i].enemy3_w / 2)
			&& chpl.life && chen3[i].flag3) {

			chen3[i].flag3 = false;
			ChangeVolumeSoundMem(100, chpl.player_hit_sound);
			PlaySoundMem(chpl.player_hit_sound, DX_PLAYTYPE_BACK);
			chpl.life_stock -= 1;
		}
	}
}

void Gameover() {

	chpl.lifeflag();
	if (time_count <= 0.0f || !chpl.life) {
		gameover_flag = true;
	}
}