#pragma once
#include <iostream>
//#include<iomanip>
#include<cmath>
#include<stdlib.h>
//#include"complex.h"
using namespace std;

class complex {
private:
	double re, im;
public:
	complex summ(complex y);
	double get_re();
	void set_re(double c);
	double get_im();
	void set_im(double c);
	double modul();
	//	complex multiplication(complex y);
	void multiplication(complex y);
	complex operator/(complex y);
	void operator/=(complex x);
	complex operator+(complex x);
	void operator+=(complex x);
	complex operator*(complex x);
	void operator*=(complex x);
	complex operator-(complex x);
	void operator-=(complex x);
	void print();
	//summa 
	complex operator=(int t) { if (t == 1) { re = 0; im = 0; return*this; } }
	complex operator +(double y);
	friend complex operator +(double y, complex x); //has access to the private variables
	void operator +=(double y);
	friend ostream& operator <<(ostream& os, complex x);
	friend istream& operator >>(istream& os, complex& x);
	complex(double _re, double _im);
	complex() { re = 0; im = 0; };//default
};
