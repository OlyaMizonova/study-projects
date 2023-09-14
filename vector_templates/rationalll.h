#pragma once
#include<iostream>
using namespace std;
class Rational {
	int m, n;//m/n
	void sokr();
public:
	Rational(int m, int n);
	Rational() { m = 0; n = 1; }
	Rational operator=(int t);
	Rational operator+(Rational a);
	void operator+=(Rational x);
	Rational operator-(Rational a);
	void operator-=(Rational x);
	Rational operator*(Rational a);
	void operator*=(Rational x);
	Rational operator/(Rational a);
	void operator/=(Rational x);
	friend Rational operator +(int y, Rational x);
	void operator +=(int y);
	bool operator==(Rational x);
	bool operator>(Rational x);
	bool operator>=(Rational x);
	bool operator<(Rational x);
	bool operator<=(Rational x);
	friend ostream& operator <<(ostream& os, Rational x);
	friend istream& operator >>(istream& os, Rational& x);
};