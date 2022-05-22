#pragma once
#include "CDObject.h"

class Obstacle: public CDObject {


public: Obstacle() {
		x = rand() % 500;
		y = rand() % 500;
		width = height = rand() % 25 + 25;
	}

};

class Obstacles {
private:
	vector<Obstacle*> obstacles;
public:

	Obstacles(int n) {
		for (int i = 0; i <= n; i++) {
			obstacles.push_back(new Obstacle);
		}
	}

	~Obstacles() {
		for each (Obstacle * o in obstacles) {
			delete o;
		}
	}

	void Move(Graphics^ g){
		for (Obstacle* o : obstacles) {
			o->Move(g);
		}
	}

	void Show(Graphics^ g) {
		for (Obstacle* o : obstacles) {
			o->Show(g);
		}
	}

};