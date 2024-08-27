#include "../dxlib_ext/dxlib_ext.h"
#include "PLAYER.h"


void PLAYER::init() {

	life_stock = 5;  //�v���C���[�c�@
	life = true;  //�v���C���[�������Ă��邩

	player_hit_sound = LoadSoundMem("sound/player_hit.mp3");

	bullet_count = 0;  //�e���ˊԊu

	//�e�@�摜�ǂݍ���
	int temp_z = LoadGraph("graphics/shot_z.png");
	int temp_x = LoadGraph("graphics/shot_x.png");
	int temp_c = LoadGraph("graphics/shot_c.png");
	int w, h;
	GetGraphSize(temp_z, &w, &h); // temp�̉摜��w�ɕ��Ah�ɍ���������
	GetGraphSize(temp_x, &w, &h);
	GetGraphSize(temp_c, &w, &h);

	for (int i = 0; i < 20; ++i) {
		bullet_z[i].flag = false;
		bullet_z[i].gh = temp_z;
		bullet_z[i].width = w;
		bullet_z[i].height = h;
		bullet_z[i].shot_sound = LoadSoundMem("sound/shot1.mp3");
	}

	for (int i = 0; i < 20; ++i) {
		bullet_x[i].flag = false;
		bullet_x[i].gh = temp_x;
		bullet_x[i].width = w;
		bullet_x[i].height = h;
		bullet_x[i].shot_sound = LoadSoundMem("sound/shot2.mp3");
	}

	for (int i = 0; i < 20; ++i) {
		bullet_c[i].flag = false;
		bullet_c[i].gh = temp_c;
		bullet_c[i].width = w;
		bullet_c[i].height = h;
		bullet_c[i].shot_sound = LoadSoundMem("sound/shot3.mp3");
	}
}

//�v���C���[�@�e�@�摜�ǂݍ���
void PLAYER::graph() {

	//�v���C���[�摜�ǂݍ���
	gpc_hdl = LoadGraph("graphics/majo_back.png");
	GetGraphSize(gpc_hdl, &width, &height);
}

void PLAYER::move() {
	
	//�v���C���[����
	if (tnl::Input::IsKeyDown(eKeys::KB_UP)) {
		pos.y -= 10;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_DOWN)) {
		pos.y += 10;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
		pos.x += 10;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
		pos.x -= 10;
	}
}

void PLAYER::draw() {

	// �e�̉摜�\��
	for (int i = 0; i < 20; ++i) {
		if (bullet_z[i].flag) {
			DrawGraph(bullet_z[i].x, bullet_z[i].y, bullet_z[i].gh, true);
		}
	}

	for (int i = 0; i < 20; ++i) {
		if (bullet_x[i].flag) {
			DrawGraph(bullet_x[i].x, bullet_x[i].y, bullet_x[i].gh, true);
		}
	}

	for (int i = 0; i < 20; ++i) {
		if (bullet_c[i].flag) {
			DrawGraph(bullet_c[i].x, bullet_c[i].y, bullet_c[i].gh, true);
		}
	}

	//�v���C���[�̉摜�\��
	DrawRotaGraph(pos.x, pos.y, 2, 0, gpc_hdl, true);
	if (pos.x <= 335) {
		pos.x = 335;
	}
	if (pos.x >= 920) {
		pos.x = 920;
	}
	if (pos.y <= 55) {
		pos.y = 55;
	}
	if (pos.y >= 680) {
		pos.y = 680;
	}
}

void PLAYER::hit_precess() {

	life_stock - 1;
}

void PLAYER::lifeflag() {

	if (life_stock <= 0) {
		life = false;
	}
}

void PLAYER::shot_z() {
	// �ez�̐���
	if (tnl::Input::IsKeyDown(eKeys::KB_Z) && bullet_count > 20) {
		for (int i = 0; i < 20; ++i) {
			if (bullet_z[i].flag == false) {
				bullet_z[i].flag = true;
				bullet_z[i].x = pos.x - 17;
				bullet_z[i].y = pos.y;
				ChangeVolumeSoundMem(80, bullet_z[i].shot_sound);
				PlaySoundMem(bullet_z[i].shot_sound, DX_PLAYTYPE_BACK);
				bullet_count = 0;
				break;
			}
		}
	}
	bullet_count++;

	// ���������ez�̈ړ�
	for (int i = 0; i < 20; ++i) {
		if (bullet_z[i].flag) {
			bullet_z[i].y -= SHOT_SPEED;

			if (bullet_z[i].y < -10) {
				bullet_z[i].flag = false;
			}
		}
	}
}

void PLAYER::shot_x() {
	// �ex�̐���
	if (tnl::Input::IsKeyDown(eKeys::KB_X) && bullet_count > 20) {
		for (int i = 0; i < 20; ++i) {
			if (bullet_x[i].flag == false) {
				bullet_x[i].flag = true;
				bullet_x[i].x = pos.x - 17;
				bullet_x[i].y = pos.y;
				ChangeVolumeSoundMem(80, bullet_x[i].shot_sound);
				PlaySoundMem(bullet_x[i].shot_sound, DX_PLAYTYPE_BACK);
				bullet_count = 0;
				break;
			}
		}
	}
	bullet_count++;

	// ���������ex�̈ړ�
	for (int i = 0; i < 20; ++i) {
		if (bullet_x[i].flag) {
			bullet_x[i].y -= SHOT_SPEED;

			if (bullet_x[i].y < -10) {
				bullet_x[i].flag = false;
			}
		}
	}
}

void PLAYER::shot_c() {
	// �ec�̐���
	if (tnl::Input::IsKeyDown(eKeys::KB_C) && bullet_count > 20) {
		for (int i = 0; i < 20; ++i) {
			if (bullet_c[i].flag == false) {
				bullet_c[i].flag = true;
				bullet_c[i].x = pos.x - 17;
				bullet_c[i].y = pos.y;
				ChangeVolumeSoundMem(80, bullet_c[i].shot_sound);
				PlaySoundMem(bullet_c[i].shot_sound, DX_PLAYTYPE_BACK);
				bullet_count = 0;
				break;
			}
		}
	}
	bullet_count++;

	// ���������ec�̈ړ�
	for (int i = 0; i < 20; ++i) {
		if (bullet_c[i].flag) {
			bullet_c[i].y -= SHOT_SPEED;

			if (bullet_c[i].y < -10) {
				bullet_c[i].flag = false;
			}
		}
	}
}