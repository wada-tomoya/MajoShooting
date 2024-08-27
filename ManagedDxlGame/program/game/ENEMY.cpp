#include "../dxlib_ext/dxlib_ext.h"
#include "ENEMY.h"

//“GƒLƒƒƒ‰‚P@‚©‚Ú‚¿‚á
void ENEMY_1::init1() {

	speed = 1;

	life = 1;

	enemy_x = 645;
	enemy_y = -20;
	enemy_w = 60;  //“GƒLƒƒƒ‰•
	enemy_h = 60;  //“GƒLƒƒƒ‰‚‚³
	flag = false;
	aiko_flag = false;
	stop_time = 0;
}
void ENEMY_1::Graph() {

	ene_gpc_hdl = LoadGraph("graphics/kabocha1.png");
}
void ENEMY_1::sound_load() {

	death_sound = LoadSoundMem("sound/kabocha_death.mp3");
}
void ENEMY_1::Enemy() {

	if (flag) {
		enemy_x = GetRand(585) + 335;  //xoŒ»ˆÊ’uƒ‰ƒ“ƒ_ƒ€
		enemy_y = 20;
	}
}
void ENEMY_1::Draw() {

	DrawRotaGraph(enemy_x, enemy_y, 1, 0, ene_gpc_hdl, true);
}
void ENEMY_1::Move(){

	enemy_y += speed;
}
void ENEMY_1::sound_play() {

	ChangeVolumeSoundMem(50, death_sound);
	PlaySoundMem(death_sound, DX_PLAYTYPE_BACK);
}
void ENEMY_1::aiko_stop_time() {

	stop_time += 1;
	if (stop_time == 300) {
		aiko_flag = false;
		stop_time = 0;
	}
}

//“GƒLƒƒƒ‰‚Q@‚Ù‚Ë
void ENEMY_2::init2() {

	speed2 = 1;

	life2 = 1;

	enemy2_x = 645;
	enemy2_y = -20;
	enemy2_w = 60;  //“GƒLƒƒƒ‰•
	enemy2_h = 60;  //“GƒLƒƒƒ‰‚‚³
	flag2 = false;
	aiko_flag = false;
	stop_time = 0;
}
void ENEMY_2::Graph2() {

	ene_gpc_hdl2 = LoadGraph("graphics/hone1.png");
}
void ENEMY_2::sound_load() {

	death_sound = LoadSoundMem("sound/hone_death.mp3");
}
void ENEMY_2::Enemy2() {

	enemy2_x = GetRand(585) + 335;  //xoŒ»ˆÊ’uƒ‰ƒ“ƒ_ƒ€
	enemy2_y = -20;
}
void ENEMY_2::Draw2() {

	DrawRotaGraph(enemy2_x, enemy2_y, 1, 0, ene_gpc_hdl2, true);
}
void ENEMY_2::Move2() {

	enemy2_y += speed2;
}
void ENEMY_2::sound_play() {

	ChangeVolumeSoundMem(100, death_sound);
	PlaySoundMem(death_sound, DX_PLAYTYPE_BACK);
}
void ENEMY_2::aiko_stop_time() {

	stop_time += 1;
	if (stop_time == 300) {
		aiko_flag = false;
		stop_time = 0;
	}
}

//“GƒLƒƒƒ‰‚R@‚¨‚Î‚¯
void ENEMY_3::init3() {

	speed3 = 1;

	life3= 1;

	enemy3_x = 645;
	enemy3_y = -20;
	enemy3_w = 60;  //“GƒLƒƒƒ‰•
	enemy3_h = 60;  //“GƒLƒƒƒ‰‚‚³
	flag3 = false;
	aiko_flag = false;
	stop_time = 0;
}
void ENEMY_3::Graph3() {

	ene_gpc_hdl3 = LoadGraph("graphics/obake1.png");
}
void ENEMY_3::sound_load() {

	death_sound = LoadSoundMem("sound/obake_death.mp3");
}
void ENEMY_3::Enemy3() {

	enemy3_x = GetRand(585) + 335;  //xoŒ»ˆÊ’uƒ‰ƒ“ƒ_ƒ€
	enemy3_y = -20;
}
void ENEMY_3::Draw3() {

	DrawRotaGraph(enemy3_x, enemy3_y, 1, 0, ene_gpc_hdl3, true);
}
void ENEMY_3::Move3() {

	enemy3_y += speed3;

	if (enemy3_y > 750) {
		flag3 = false;
	}
}
void ENEMY_3::sound_play() {

	ChangeVolumeSoundMem(50, death_sound);
	PlaySoundMem(death_sound, DX_PLAYTYPE_BACK);
}
void ENEMY_3::aiko_stop_time() {

	stop_time += 1;
	if (stop_time == 300) {
		aiko_flag = false;
		stop_time = 0;
	}
}