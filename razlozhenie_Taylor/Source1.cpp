#include"Header.h"

int size_of_array(double a, double b, double step) {
	int k = 1;
	a += step;
	while (a<b) {
		k++;
		a += step;
	}
	return k+1;
}

void inicialize_array(our_func our, p_func p, double* x, double* our_f, double* f_x_vstr, double*dx_f, double a, int k, int n, double step, double *maxdx) {
	if (our == ln_y && a == 0) {
		printf("Вы пытаетесь найти значение натурального логарифма от нуля! Будьте внимательнее к области определения функции\n\n\n");
	}
	for (int i = 0; i < k; i++) {
		x[i] = a;
		a += step;
		our_f[i] = our(x[i], n);
		f_x_vstr[i] = p(x[i]);
		dx_f[i] = our_f[i] - f_x_vstr[i];
		if (dx_f[i] < 0) { dx_f[i] = -dx_f[i]; }
		if (x[i] == 0 && our == ln_y) {
			dx_f[i] = 0;
		}
		if (dx_f[i] > *maxdx) { *maxdx = dx_f[i]; }
	}
}

double exp_n(double x, int n) {
	double res = 0, a = 1;
	if (x > 6) {
		res = exp_n_for_big_x(x, n);
		return res;
	}
	res += a;
	for (int i = 1; i <= n; i++) {
		a *= (x / i);
		res += a;
	}
	return res;
}

double exp_n_for_big_x(double y, int n) {
	double k = 0;
	while (y - k * M_LN2 > 0) {
		k++;
	}
	double x = y - k * M_LN2;
	double ex_x = exp_n(x, n);
	double n2 = 1;
	for (int i = 1; i <= k; i++) {
		n2 *= 2;
	}
	double res = n2 * ex_x;
	return res;
}

void swap(double* a, double* b) {
	double c;
	c = *a; *a = *b; *b = c;
}

//sin(x)~0+x+0-x^3/3!+x^5/5!...+

double sin_x_n(double x, int n) {
	while (x > M_PI || x < -M_PI) {
		if (x > M_PI) {
			x -= 2 * M_PI;
		}
		else {
			x += 2 * M_PI;
		}
	}
	long double res = x, a = x;
	for (long int i = 3; i <= n; i += 2) {
		a *= (( - 1) * x * x) / ((i - 1) * i);
		res += a;
	}
	return res;
}


double cos_x_n(double x, int n) {
	while (x >  M_PI || x < -M_PI) {
		if (x >  M_PI) {
			x -= 2 * M_PI;
		}
		else {
			x += 2 * M_PI;
		}
	}
	long double res = 0, a = 1;
	res += a;
	for (long int i = 2; i <= n; i += 2) {
		a = a*(((-1) * (x * x)) / ((i - 1) * i));
		res += a;
	}
	return res;
}

double ln_y(double y, int n) {
	if (y > 0 && y <= 2) {
		double res = ln_y_0_2(y, n);
		return res;
	}
	else {
		double x = (y - 1) / (y + 1);
		double a = x;
		double res = a;
		for (int i = 3; i <= n; i += 2) {
			a *= x * x;
			res += (a  / i);
		}
		return res * 2;
	}
}


double ln_y_0_2(double y, int n) {
	double x = y - 1;
	double a = -1;
	double res = 0;
	for (int i = 1; i <= n; i++) {
		a *= (-1) * x;
		res += (a / i);
	}
	return res;
}
//cos(x)=1-x^2/2!+x^4/4!+...