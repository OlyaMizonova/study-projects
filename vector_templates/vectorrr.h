#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include"exceptionnn.h"

using namespace std;

template<class Type>
class Vector {
private:
	int N;
	Type* arr;
public:
	Vector(int N_ = 10);
	Vector(const Vector<Type>& from_where);
	~Vector() { delete[]arr; }
	Vector<Type> operator+(const Vector<Type>& b);
	Vector<Type> operator-(const Vector<Type>& b);
	Vector<Type>& operator+=(const Vector<Type>& b);
	Vector<Type>& operator-=(const Vector<Type>& b);
	Vector<Type>& operator =(const Vector<Type>& b);
	Type& operator[](int pos);
	Type operator*(const Vector<Type>& b);
	bool operator==(const Vector<Type>& b);
	bool operator!=(const Vector<Type>& b);
	void ins(int pos, Type el);
	void del(int pos);
	int get_n() { return N; }
	template<class T>
	friend ostream& operator <<(ostream& os, const Vector<T>& x);
	template<class T>
	friend istream& operator >>(istream& is, Vector<T>& x);
};

template<class Type>
Vector<Type>::Vector(int N_) {
	if (N_ < 0) {
		//Exception e(__FILE__, __FUNCTION__, __LINE__, "Wrong size");
		throw 1;
	}
	N = N_;
	arr = new Type[N_];
	for (int i = 0; i < N_; i++) {
		arr[i] = 0;
	}
}

template<class Type>
Vector<Type>::Vector(const Vector<Type>& from_where) {
	if (&from_where == this)
		return;
	N = from_where.N;
	arr = new Type[N];
	for (int i = 0; i < N; i++) {
		arr[i] = from_where.arr[i];
	}
}

template <class Type>
Vector<Type>& Vector<Type>::operator = (const Vector<Type>& b) { // type vector for multiple assigment
	if (this == &b)
		return *this;

	if (N != b.N) {
		delete[]arr;
		N = b.N;
		arr = new Type[N];
	}
	for (int i = 0; i < N; i++) {
		arr[i] = b.arr[i];
	}
	return *this;
}

template<class Type>
Vector<Type> Vector<Type>::operator+(const Vector<Type>& b) {
	if (N != b.N) {
		Exception e(__FILE__, __FUNCTION__, __LINE__, "Operands have different size");
		throw e;
	}
	Vector<Type> ans(N);
	for (int i = 0; i < N; i++) {
		ans.arr[i] = arr[i] + b.arr[i];
	}
	return ans;
}

template<class Type>
Vector<Type> Vector<Type> :: operator-(const Vector<Type>& b) {
	if (N != b.N) {
		Exception e(__FILE__, __FUNCTION__, __LINE__, "Operands have different size");
		throw e;
	}
	Vector<Type> ans(N);
	for (int i = 0; i < N; i++) {
		ans.arr[i] = arr[i] - b.arr[i];
	}
	return ans;
}

template<class Type>
Vector<Type>& Vector<Type> :: operator+=(const Vector<Type>& b) {
	if (N != b.N) {
		throw (__FILE__, __FUNCTION__, __LINE__, "Operands have different size");
	}
	for (int i = 0; i < N; i++) {
		arr[i] += b.arr[i];
	}
	return *this;
}

template<class Type>
Vector<Type>& Vector<Type> :: operator-=(const Vector<Type>& b) {
	if (N != b.N) {
		throw (__FILE__, __FUNCTION__, __LINE__, "Operands have different size");
	}
	for (int i = 0; i < N; i++) {
		arr[i] -= b.arr[i];
	}
	return *this;
}

template<class Type>
Type& Vector<Type>::operator[](int pos) {
	if (pos < 0 || pos >= N) {
		throw (__FILE__, __FUNCTION__, __LINE__, "Wrong position");
	}
	return arr[pos];
}

template<class Type>
void Vector<Type>::ins(int pos, Type el) {
	if (pos > N || pos < 0) {

		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Wrong position");
	}
	Type* _arr;
	_arr = new Type[N];
	for (int i = 0; i < N; i++) {
		_arr[i] = arr[i];
	}
	N++;
	delete[]arr;
	arr = new Type[N];
	for (int i = 0; i < pos; i++) {
		arr[i] = _arr[i];
	}
	arr[pos] = el;
	for (int i = pos + 1; i < N; i++) {
		arr[i] = _arr[i - 1];
	}
	delete[]_arr;
}

template<class Type>
void Vector<Type>::del(int pos) {
	if (pos < 0 || pos >= N) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Wrong position");
	}
	Type* _arr;
	_arr = new Type[N - 1];
	for (int i = 0; i < pos; i++) {
		_arr[i] = arr[i];
	}
	for (int i = pos + 1; i < N; i++) {
		_arr[i - 1] = arr[i];
	}
	delete[]arr;
	N--;
	arr = new Type[N];
	for (int i = 0; i < N; i++) {
		arr[i] = _arr[i];
	}
	delete[]_arr;
}

template<class Type>
Type Vector<Type>::operator*(const Vector<Type>& x) {
	if (N != x.N) {
		Exception e(__FILE__, __FUNCTION__, __LINE__, "Operands have different size");
		throw e;
	}
	Type res = 0;
	for (int i = 0; i < N; i++) {
		res += arr[i] * x.arr[i];
	}
	return res;
}

template<class Type>
bool Vector<Type>::operator==(const Vector<Type>& b) {
	if (N != b.N) {
		return false;
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] != b.arr[i]) {
			return false;
		}
	}
	return true;
}

template<class Type>
bool Vector<Type>::operator!=(const Vector<Type>& b) {
	if (N != b.N) {
		return true;
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] != b.arr[i]) {
			return true;
		}
	}
	return false;
}

template<class Type>
ostream& operator <<(ostream& os, const Vector<Type>& x) {
	os << "(";
	for (int i = 0; i < x.N - 1; i++) {
		os << x.arr[i] << ", ";
	}
	os << x.arr[x.N - 1] << ")";
	return os;
}

template<class Type>
istream& operator >>(istream& is, Vector<Type>& x) {
	for (int i = 0; i < x.N; i++) {
		is >> x.arr[i];
	}
	return is;
}