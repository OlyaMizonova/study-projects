#include"complexxx.h"

double complex::get_re() {
	return re;
}

double complex::get_im() {
	return im;
}

void complex::set_re(double c) {
	re = c;
}

void complex::set_im(double c) {
	im = c;
}

double complex::modul() {
	double m = sqrt(re * re + im * im);
	return m;
}

complex complex::summ(complex y) {
	complex z;
	z.re = re + y.re;
	z.im = im + y.im;
	return z;
}

void complex::multiplication(complex y) {
	double rre = re, imm = im;
	rre = re * y.re - im * y.im;
	imm = re * y.im + im * y.re;
	re = rre;
	im = imm;
}

complex complex::operator+(complex x) {
	complex z;
	z.re = re + x.re;
	z.im = im + x.im;
	return z;
}

void complex::operator+=(complex x) {
	re = re + x.re;
	im = im + x.im;
}

complex complex::operator*(complex x) {
	complex z;
	z.re = re * x.re - im * x.im;
	z.im = re * x.im + im * x.re;
	return z;
}

void complex::operator*=(complex x) {
	double rre, imm;
	rre = re * x.re - im * x.im;
	imm = re * x.im + im * x.re;
	re = rre; im = imm;
}

complex complex::operator-(complex x) {
	complex z;
	z.re = re - x.re;
	z.im = im - x.im;
	return z;
}

void complex::operator-=(complex x) {
	re = re - x.re;
	im = im - x.im;
}

complex complex::operator/(complex x) {
	complex a, res, proiz, y;
	double summ = x.re * x.re + x.im * x.im;
	y.re = re;
	y.im = im;
	if (x.re == 0 && x.im == 0) {
		complex c(INFINITY, INFINITY);
		return c;
	}
	a.re = x.re;
	a.im = -x.im;
	proiz = y * a;
	res.re = proiz.re / summ;
	res.im = proiz.im / summ;
	return res;
}

void complex::operator/=(complex x) {
	complex sopr, res, proiz, y;
	double summ = x.re * x.re + x.im * x.im;
	y.re = re;
	y.im = im;
	if (x.re == 0 && x.im == 0) {
		re = INFINITY;
		im = INFINITY;
		return;
		//complex c(INFINITY, INFINITY);
		//return c;
	}
	sopr.re = x.re;
	sopr.im = -x.im;
	proiz = y * sopr;
	res.re = proiz.re / summ;
	res.im = proiz.im / summ;
	re = res.re; im = res.im;
	//return res;
}

void complex::print() {
	cout << re << " + " << im << "i";
}

complex::complex(double _re, double _im) {
	re = _re;
	im = _im;
}

complex complex::operator+(double x) {
	complex z;
	z.re = re + x;
	z.im = im;
	return z;
}

complex summary(double a, complex x) {
	complex z;
	z = x + a;
	return z;
}

complex operator+(double a, complex x) {
	complex z;
	z.re = x.re + a;
	z.im = x.im;
	return z;
}

ostream& operator <<(ostream& os, complex x) {
	os << x.re << " + " << x.im << 'i';
	return os;
}

istream& operator >>(istream& is, complex& x) {
	is >> x.re >> x.im;
	return is;
}

void complex::operator +=(double y) {
	re += y;
}