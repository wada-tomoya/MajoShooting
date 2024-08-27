#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "PLAYER.h"
#include "SCENE_TITLE.h"
#include "SCENE_PLAY.h"
#include "ENEMY.h"
#include "SCENE_RESULT.h"

SCENE_TITLE scti;
SCENE_PLAY scpl;
SCENE_RESULT scre;

float scene_swith_time = 0;  //enter�������ăV�[�����؂�ւ�鎞��
bool scene_swith_flag = false;  //�V�[���؂�ւ��t���O

enum {
	SCENE_ID_TITLE,  //�^�C�g���V�[��
	SCENE_ID_PLAY,  //�v���C�V�[��
	SCENE_ID_RESULT  //���U���g�V�[��
};
int g_scene_id = SCENE_ID_TITLE;

//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart(){

	scti.graph();  //�^�C�g���w�i�摜�ǂݍ���
	scti.sound_load();  //�^�C�g�����ǂݍ���

	PLAYER graph();  //�v���C���[�@�e�@�摜�ǂݍ���

	playscene_init();  //SCENE_PLAY�i�v���C��ʁ@�G�l�~�[ �v���C���[�j�̏�����
	scpl.sound_load();  //�v���C��� �� �ǂݍ���
	scpl.graph();  //�v���C�w�i��ʌĂяo��

	scre.sound_load();  //���U���g��ʁ@���@�Ăяo��
}

//------------------------------------------------------------------------------------------------------------
// �^�C�g���V�[�����t���[�����s����܂�
void sceneTitle(float delta_time) {

	if (CheckSoundMem(scti.snd_bgm_hdl) == 0) {
		scti.sound_bgm_play();  //���@BGM�Đ�
	}

	title_reset();  //�^�C�g���ɖ߂����������l�ɖ߂��i�j

	scti.graph_draw();  //�^�C�g���w�i�`��
	scti.string();  //�^�C�g������
	scti.menu(delta_time);  //�^�C�g�����j���[

	//enter������
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		scti.sound_se_play();  //���@SE�Đ�
		scti.TITLE_MENU_FLASHINTIME = 0.25f;  //�Q�[���X�^�[�g�{�^���_�ő��xUP
		scene_swith_flag = true;  //�V�[���؂�ւ��t���O
	}
	if (scene_swith_flag) {
		scene_swith_time += delta_time;
	}
	//1�b�o�߂����
	if (scene_swith_time >= 1.0) {
		g_scene_id = SCENE_ID_PLAY;  //�V�[�����؂�ւ��
		scene_swith_time = 0;
		scene_swith_flag = false;
		scti.TITLE_MENU_FLASHINTIME = 0.5f;  //�Q�[���X�^�[�g�{�^���_�ő��x�����ɖ߂�
		scti.sound_bgm_stop();  //BGM���~�߂�
	}
 }

// �v���C�V�[�����t���[�����s����܂�
void scenePlay(float delta_time) {

	scpl.draw();  //�v���C��ʔw�i

	if (CheckSoundMem(scpl.snd_bgm_hdl) == 0) {
		scpl.sound_bgm_play();  //BGM�Đ�
	}

	Hitcheck_enemy_bullet();
	Hitcheck_enemy_player();
	Gane_play_main(delta_time);

	Gameover();
	if (gameover_flag == true) {

		g_scene_id = SCENE_ID_RESULT;
		scpl.sound_bgm_stop();
	}
}

void sceneResult(float delta_time) {

	if (CheckSoundMem(scre.snd_bgm_hdl) == 0) {
		scre.sound_bgm_play();  //���U���g��ʁ@BGM�@�Đ�
	}

	scre.gameover_draw();
	scre.score_draw();
	scre.menu_draw(delta_time);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		g_scene_id = SCENE_ID_TITLE;
		scre.sound_bgm_stop();
	}
}

//���t���[�����s����܂�
void gameMain(float delta_time) {

	//scene�̐؂�ւ�
	switch (g_scene_id) {
	case SCENE_ID_TITLE:
		sceneTitle(delta_time);
		break;
	case SCENE_ID_PLAY:
		scenePlay(delta_time);
		break;
	case SCENE_ID_RESULT:
		sceneResult(delta_time);
		break;
	}
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {

}