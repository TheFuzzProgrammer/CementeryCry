#pragma once
#include "CDObject.h"

class Player : public CDObject {
public:
	Player() {
		x = y = 50;
		dx = dy = 0;
		width = height = 50;
	}

	void Move(Graphics^ g) {
		if (x + dx >= 0 && ((x + width) + dx) <= g->VisibleClipBounds.Width) {
			x += dx;
		}

		if (y + dy >= 0 && ((y + height) + dy) <= g->VisibleClipBounds.Height) {
			y += dy;
		}

	}

	void Show(Graphics^ g) {
		g->FillRectangle(Brushes::Blue, GetArea());
	}



};