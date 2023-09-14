#pragma once
#pragma once
#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace System::Drawing;

class Figure {
protected:
	int x, y; 
public:
	Figure(int x_, int y_) { x = x_; y = y_; }
	Figure() { x = 0; y = 0; }
	int get_x() const{
		return x;
	}
	int get_y() const{
		return y;
	}
	void set_x(int x_) {
		x = x_;
	}
	void set_y(int y_) {
		y = y_;
	}
	virtual int area() const = 0;
	virtual int perimeter()const = 0;
	virtual void print() = 0;
	virtual void show(Graphics^ gr) = 0;
	virtual void hide(Graphics^ gr) = 0;
	void move(Graphics^ gr, int dx, int dy) {
		hide(gr);
		x += dx; y += dy;
		show(gr);
	};
	virtual int get_right_x()const = 0;
	virtual int get_left_x()const = 0;
	virtual int get_up_y()const = 0;
	virtual int get_down_y()const = 0;
	void operator =(const Figure& t) {
		x = t.x;
		y = t.y;
	}
};

class tRectangle : public Figure {
protected:
	int width, hight;
public:
	tRectangle(int w_, int h_, int x_, int y_) :Figure(x_, y_) {
		width = w_, hight = h_;
	}
	tRectangle() :Figure() {
		width = 1, hight = 1;
	}
	int area()const override {
		return width * hight;
	}
	int perimeter() const override {
		return 2 * (width + hight);
	}
	int get_w() const{
		return width;
	}
	int get_h() const{
		return hight;
	}
	void set_a(const int a_) {
		width = a_;
	}
	void set_b(const int b_) {
		hight = b_;
	}
	void print() {
		std::cout << "Rectangle\nwidth: " << get_w() << "\nhight: " << get_h() << "\nArea: " << area() << "\nPerimeter: " << perimeter() << "\n";
	}
	int get_right_x()const override { return x + width; };
	int get_left_x()const override { return x; };
	int get_up_y()const override { return y; };
	int get_down_y()const override { return y + hight; };
	void show(Graphics^ gr)override {
		Brush^ brush = gcnew SolidBrush(Color::FromArgb(3, 252, 227));
		gr->FillRectangle(brush, x, y, width, hight);
	};
	void hide(Graphics^ gr) override {
		Brush^ brush = gcnew SolidBrush(Color::White);
		gr->FillRectangle(brush, x, y, width, hight);
	};
	//a = c + d
	void operator =(const tRectangle& t) {
		set_x(t.get_x());
		set_y(t.get_y());
		width = t.width;
		hight = t.hight;
	}
};

class Square : public tRectangle {
public:
	Square(int a_, int x_, int y_) :tRectangle(a_, a_, x_, y_) {}
	void print() {
		std::cout << "Square\n" << "Side a: " <<
			get_w() << "\nArea: " << area() << "\nperimeter: " << perimeter() << "\n";
	}
};

class Ellipse : public Figure {
protected: int r1, r2;
public:
	void operator =(const Ellipse& t) {
		set_x(t.get_x());
		set_y(t.get_y());
		r1 = t.r1;
		r2 = t.r2;
	}
	Ellipse() {
		r1 = 0; r2 = 0;
	}
	Ellipse(int a_, int b_, int x_, int y_) :Figure(x_, y_) {
		r1 = a_; r2 = b_;
	}
	int get_r1() {
		return r1;
	}
	int get_r2() {
		return r2;
	}
	void set_r1(const int a_) {
		r1 = a_;
	}
	void set_r2(const int b_) {
		r2 = b_;
	}
	int area()const override {
		return int(M_PI * r1 * r2);
	}
	int perimeter() const override {
		return 4 * ((int(M_PI) * r1 * r2) + (r1 - r2)) / (r1 + r2);
	}
	void print() {
		std::cout << "Ellipse\nradius 1: " << get_r1() << "\nradius 2: " << get_r2() << "\nArea: " << area() << "\nPerimeter: " << perimeter() << "\n";
	}
	int get_right_x() const override { return x + r1; };
	int get_left_x() const override { return x - r1; };
	int get_up_y() const override { return y - r2; };
	int get_down_y() const override { return y + r2; };
	void show(Graphics^ gr) { 
		Brush^ brush = gcnew SolidBrush(Color::FromArgb(66, 3, 87));
		gr->FillEllipse(brush, x - r1, y - r2, 2 * r1, 2 * r2); 
	};
	void hide(Graphics^ gr) { 
		Brush^ brush = gcnew SolidBrush(Color::White);
		gr->FillEllipse(brush, x - r1, y - r2, 2 * r1, 2 * r2); 
	};
};

class Circle : public Ellipse {
public:
	Circle() :Ellipse() {};
	Circle(int a_, int x_, int y_) : Ellipse(a_, a_, x_, y_) {};
	void set_r(int r_) { r1 = r_; r2 = r_; }
	void print() {
		std::cout << "Circle\nRadius: " << get_r1() << "\nArea: " << area() << "\nPerimeter: " << perimeter() << "\n";
	}
};

class Triangle : public Figure {
protected:
	int a, b, c;
public:
	Triangle(int a_, int b_, int c_, int x_, int y_) :Figure(x_, y_) {
		a = a_; b = b_; c = c_;
	}
	int get_a() {
		return a;
	}
	int get_b() {
		return b;
	}
	int get_c() {
		return c;
	}
	void set_a(const int a_) {
		a = a_;
	}
	void set_b(const int b_) {
		b = b_;
	}
	void set_c(const int c_) {
		c = c_;
	}
	int perimetr() {
		return a + b + c;
	}
	int area() {
		int p = (a + b + c) / 2;
		int s = int(sqrt(p * (p - a) * (p - b) * (p - c)));
		return s;
	}
	void print() {
		std::cout << "Triangle" << "Side a: " <<
			get_a() << "\nSide b: " << get_b() << "\nSide ñ: " << get_c() << "\nArea: " << area() << "\nPerimeter: " << perimeter() << "\n";
	}
};

class Rectangular :public Triangle {
public:
	Rectangular(int a_, int b_, int c_, int x_, int y_) :Triangle(a_, a_, c_, x_, y_) { }
	void print() {
		std::cout << "Rectangular" << "\nSide a: " << get_a() << "\nSide b: " << get_b() << "\nSide ñ: " << get_c() << "\nArea: " << area() << "\nPerimeter: " << perimeter() << "\n";
	}
};

class Isosceles :public Triangle {
public:
	Isosceles(int a_, int b_, int c_, int x_, int y_) :Triangle(a_, a_, a_, x_, y_) {}
	void print() {
		std::cout << "Isosceles" << "\nSide a: " << get_a() << "\nSide b: " << get_b() << "\nSide ñ: " << get_c() << "\nArea: " << area() << "\nPerimeter: " << perimeter() << "\n";
	}
};
