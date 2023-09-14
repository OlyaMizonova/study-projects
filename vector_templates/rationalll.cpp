#include"rationalll.h"
int nod(int m, int n) {
	if (m == 0) {
		return 1;
	}
	while ((m != 0) && (n != 0) && (m != n)) {
		if (m > n) m = m - n;
		if (m < n) n = n - m;
	}
	return m;
}

void Rational::sokr() {
	int k = nod(abs(m), abs(n));
	m /= k;
	n /= k;
}

Rational::Rational(int a, int b) {
	m = a; n = b;
	/*this->*/sokr();
}

Rational Rational::operator+(Rational a) {
	Rational z;
	if (n == a.n) {
		z.n = n;
		z.m = m + a.m;
		z.sokr();
		return z;
	}
	z.m = m * a.n + n * a.m;
	z.n = n * a.n;
	z.sokr();
	return z;
}

void Rational::operator+=(Rational a) {
	Rational z;
	if (n == a.n) {
		z.n = n;
		z.m = m + a.m;
	}
	else {
		z.m = m * a.n + n * a.m;
		z.n = n * a.n;
	}
	z.sokr();
	m = z.m;
	n = z.n;
}

Rational Rational::operator-(Rational a) {
	Rational z;
	if (n == a.n) {
		z.n = n;
		z.m = m - a.m;
		z.sokr();
		return z;
	}
	z.m = m * a.n - n * a.m;
	z.n = n * a.n;
	z.sokr();
	return z;
}

void Rational::operator-=(Rational a) {
	Rational z;
	if (n == a.n) {
		z.n = n;
		z.m = m - a.m;
	}
	else {
		z.m = m * a.n - n * a.m;
		z.n = n * a.n;
	}
	z.sokr();
	m = z.m;
	n = z.n;
}

Rational Rational::operator*(Rational a) {
	Rational z;
	z.m = m * a.m;
	z.n = n * a.n;
	z.sokr();
	return z;
}

void Rational::operator*=(Rational a) {
	Rational z;
	z.m = m * a.m;
	z.n = n * a.n;
	z.sokr();
	n = z.n; m = z.m;
}

Rational Rational::operator/(Rational a) {
	Rational z;
	swap(a.m, a.n);
	z.m = m * a.m;
	z.n = n * a.n;
	z.sokr();
	return z;
}

void Rational::operator/=(Rational a) {
	Rational z;
	swap(a.m, a.n);
	z.m = m * a.m;
	z.n = n * a.n;
	z.sokr();
	n = z.n; m = z.m;
}

ostream& operator <<(ostream& os, Rational x) {
	x.sokr();
	if (x.m == 0) {
		os << 0;
		return os;
	}
	if (x.n == 1) {
		os << x.m;
		return os;
	}
	if (x.n == -1) {
		os << -x.m;
		return os;
	}
	os << x.m << "/" << x.n;
	return os;
}

istream& operator >>(istream& is, Rational& x) {
	//x.sokr();
	is >> x.m >> x.n;
	return is;
}

Rational operator+(int a, Rational x) {
	Rational z;
	z.m = x.m + a * x.n;
	z.n = x.n;
	z.sokr();
	return z;
}

void Rational:: operator +=(int y) {
	Rational z;
	z.m = m + y * n;
	z.n = n;
	z.sokr();
	m = z.m; n = z.n;
}

bool Rational::operator==(Rational x) {
	if (m == x.m && n == x.n) {
		return true;
	}
	return false;
}

bool Rational::operator<(Rational x) {
	Rational t;
	t.m = m * x.n - n * x.m;
	if (t.m < 0) {
		return true;
	}
	return false;
}

bool Rational::operator<=(Rational x) {
	Rational t;
	t.m = m * x.n - n * x.m;
	if (t.m <= 0) {
		return true;
	}
	return false;
}

bool Rational::operator>(Rational x) {
	Rational t;
	t.m = m * x.n - n * x.m;
	if (t.m > 0) {
		return true;
	}
	return false;
}

bool Rational::operator>=(Rational x) {
	Rational t;
	t.m = m * x.n - n * x.m;
	if (t.m >= 0) {
		return true;
	}
	return false;
}

Rational Rational::	operator=(int t) {
	if (t == 0) {
		m = 0;
		n = 1;
	}
	return *this;
}