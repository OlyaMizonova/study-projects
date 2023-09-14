#pragma once
#include"Header.h"
class Train {
private:
	tRectangle vagon;
	Circle wheel_1, wheel_2;
public:
	Train() {
		tRectangle rect;
		Circle w1, w2;
		vagon = rect;
		wheel_1 = w1;
		wheel_2 = w2;
	}
	Train(tRectangle rect, Circle w1, Circle w2) {
		vagon = rect;
		wheel_1 = w1;
		wheel_2 = w2;
	}
	void operator =(const Train& t) {
		if (&t == this) {
			return;
		}
		wheel_1 = t.wheel_1;
		wheel_2 = t.wheel_2;
		vagon = t.vagon;
	}
	Train(const Train& t) {
		if (&t == this) {
			return;
		}
		wheel_1 = t.wheel_1;
		wheel_2 = t.wheel_2;
		vagon = t.vagon;
	}
	int get_right_x(){ 
		return vagon.get_right_x();
	}
	int get_left_x() {
		return vagon.get_left_x();
	}
	int get_down_y() {
		return wheel_1.get_down_y();
	}
	void show(Graphics^ gr) {
		vagon.show(gr);
		wheel_1.show(gr);
		wheel_2.show(gr);
	}
	void hide(Graphics^ gr) {
		wheel_1.hide(gr);
		wheel_2.hide(gr);
		vagon.hide(gr);
	};
	void move(Graphics^ gr, int dx, int dy) {
		vagon.hide(gr);
		wheel_2.hide(gr);
		wheel_1.hide(gr);
		vagon.set_x(vagon.get_x() + dx);
		wheel_1.set_x(wheel_1.get_x() + dx);
		wheel_2.set_x(wheel_2.get_x() + dx);
		vagon.set_y(vagon.get_y() + dy);
		wheel_1.set_y(wheel_1.get_y() + dy);
		wheel_2.set_y(wheel_2.get_y() + dy);
		vagon.show(gr);
		wheel_1.show(gr);
		wheel_2.show(gr);
		/*vagon.move(gr, dx, dy);
		wheel_1.move(gr, dx, dy);
		wheel_2.move(gr, dx, dy);*/
	}
};

class Train_1 {
private:
	Figure* tr[3];
	//tRectangle vagon;
	//Circle wheel_1, wheel_2;
public:
	Train_1() {
		/*tRectangle rect;
		Circle w1, w2;*/
		tr[0] = (new tRectangle());
		tr[1] = (new Circle());
		tr[2] = (new Circle());
		/*tr[0] = reinterpret_cast<Figure*>(&rect);
		tr[1] = reinterpret_cast<Figure*>(&w1);
		tr[2] = reinterpret_cast<Figure*>(&w2);*/
	}
	Train_1(const tRectangle &rect, const Circle& w1, const Circle& w2) {
		tr[0] = new tRectangle();
		tr[1] = new Circle();
		tr[2] = new Circle();
		*(static_cast<tRectangle*>(tr[0])) = rect;
		*(static_cast<Circle*>(tr[1])) = w1;
		*(static_cast<Circle*>(tr[2])) = w2;
	}
	Train_1(const Train_1 &t) {
		if (&t == this) {
			return;
		}
		//for (int i = 0; i < 3; i++) {
		//	tr[i] = t.tr[i];
		//}
		*(static_cast<Circle*>(tr[1])) = *(static_cast<Circle*>(t.tr[1]));
		*(static_cast<Circle*>(tr[2])) = *(static_cast<Circle*>(t.tr[2]));
		*(static_cast<tRectangle*>(tr[0])) = *(static_cast<tRectangle*>(t.tr[0]));
	}
	~Train_1() {
		for (int i = 0; i < 3; i++) {
			delete tr[i];
		}
	}
	void operator =(const Train_1 &t){
		if (&t == this) {
			return;
		}
		*(static_cast<Circle*>(tr[1])) = *(static_cast<Circle*>(t.tr[1]));
		*(static_cast<Circle*>(tr[2])) = *(static_cast<Circle*>(t.tr[2]));
		*(static_cast<tRectangle*>(tr[0])) = *(static_cast<tRectangle*>(t.tr[0]));
	}
	int get_right_x() {
		return tr[0]->get_right_x();
	}
	int get_left_x() {
		return tr[0]->get_left_x();
	}
	int get_down_y() {
		return tr[1]->get_down_y();
	}
	void show(Graphics^ gr) {
		tr[0]->show(gr);
		tr[1]->show(gr);
		tr[2]->show(gr);
	}
	void hide(Graphics^ gr) {
		tr[1]->hide(gr);
		tr[2]->hide(gr);
		tr[0]->hide(gr);
	};
	void move(Graphics^ gr, int dx, int dy) {
		tr[0]->hide(gr);
		tr[1]->hide(gr);
		tr[2]->hide(gr);
		tr[0]->set_x(tr[0]->get_x() + dx);
		tr[1]->set_x(tr[1]->get_x() + dx);
		tr[2]->set_x(tr[2]->get_x() + dx);
		tr[0]->set_y(tr[0]->get_y() + dy);
		tr[1]->set_y(tr[1]->get_y() + dy);
		tr[2]->set_y(tr[2]->get_y() + dy);
		tr[0]->show(gr);
		tr[1]->show(gr);
		tr[2]->show(gr);
		/*vagon.move(gr, dx, dy);
		wheel_1.move(gr, dx, dy);
		wheel_2.move(gr, dx, dy);*/
	}
};