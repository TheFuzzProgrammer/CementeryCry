#pragma once
#include "Player.h"
#include "Obstacles.h"

class Game {
private:
	Player* player;
	Obstacles* obstacles;
public:
	Game(int n) {
		player = new Player();
		obstacles = new Obstacles(n);
	}
	~Game() {
		delete player, obstacles;

	}

	void PlayerMovement(bool b, Keys k, int s) {
		if (b == true) {
			if (k == Keys::W) {
				player->SetDY(-s);
			}
			else if (k == Keys::S) {
				player->SetDY(s);
			}
			else if (k == Keys::A) {
				player->SetDX(-s);
			}
			else if (k == Keys::D) {
				player->SetDX(s);
			}
		}
		else {
			if (k == Keys::W) {
				player->SetDY(0);
			}
			else if (k == Keys::S) {
				player->SetDY(0);
			}
			else if (k == Keys::A) {
				player->SetDX(0);
			}
			else if (k == Keys::D) {
				player->SetDX(0);
			}
		}
	}

	void Move(Graphics^ g) {
		player->Move(g);
		obstacles->Move(g);
	}
	void Show(Graphics^ g) {
		player->Show(g);
		obstacles->Show(g);
	}

};