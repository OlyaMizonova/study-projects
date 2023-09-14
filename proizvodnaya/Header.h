#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<Windows.h> 
#include<fstream> 
#include<limits>
using namespace std;

class Exception {
private:
	char* file;//в любом случае это имя файла
	char* function;//имя функции
	int line;//номер строки
	char* description;//ну и описание
public:
	Exception(const char* file_, const char* function_, int line_, const char* description_);
	Exception(const Exception& x);
	~Exception() { delete[]file; delete[]function; delete[]description; }
	friend ostream& operator <<(ostream& os, const Exception& x);
};

class Derivative {
public:
	Derivative() { F = nullptr; Points = nullptr; Dels = nullptr; Left = numeric_limits<double>::quiet_NaN(); Right = numeric_limits<double>::quiet_NaN(); M = 1; Type = 0; }
	Derivative(double(*F_)(double), double Left_, double Right_, int N_);
	Derivative(const Derivative& r);
	~Derivative();
	void calculate_del();

	void set_type(int t) { Type = t; }
	void set_func(double(*F_)(double));
	void set_left(double l);
	void set_right(double r);
	void set_N(int _N);

	double get_left() { return Left; }
	double get_right() { return Right; }
	friend ostream& operator <<(ostream& os, const Derivative& r);
private:
	double(*F)(double);//это функция встроенная от которой буду производные брать
	double Left, Right;//границы
	int M;//количество точек где ищу производные
	const double H = 0.0000000001; //какая то фиксированная точность
	double* Points; //это точки где я буду искать производные
	double* Dels; //сами производные
	int Type;
	void recalculate_points();
	void check_params()const;
	void check_borders()const;
	void check_N(int N_)const;
	void resize_points(int M_);
	void count_1();
	void count_2();
};