#pragma once
#include "imports.h"

class CDObject {

protected:
	//position
	int x, y;
	//speed
	int dx, dy;
	//size
	int width, height;

public:
	CDObject() {
		x = y = 0;
		dx = dy = 0;
		width = height = 0;
	}

	~CDObject() {

	}
	void SetDX(int x) {
		this->dx = x;
	}

	void SetDY(int y) {
		this->dy = y;
	}
	
	Rectangle GetArea() {
		return Rectangle(x, y, width, height);
	}

	Rectangle GetNextArea() {
		return Rectangle(x + dx, y + dy, width, height);
	}

	virtual void Move(Graphics^ graohics) {
		x += dx;
		y += dy;
	}

	virtual void Show(Graphics^ graphics) {
		graphics->FillRectangle(Brushes::Black, this->GetArea());
	}


};