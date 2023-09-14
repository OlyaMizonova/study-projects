#pragma once

#define _USE_MATH_DEFINES

#include<Windows.h>
#include<stdio.h>
#include<locale.h>
#include <math.h>
#include<malloc.h>

typedef double(*p_func)(double);
typedef double(*our_func)(double, int);

int size_of_array(double a, double b, double step);

void inicialize_array(our_func our, p_func p, double* x, double* our_f, double* f_x_vstr, double* dx_f, double a, int k, int n, double step, double* maxdx);

double exp_n(double x, int n);

double exp_n_for_big_x(double y, int n);

void swap(double* a, double* b);

double sin_x_n(double x, int n);

double cos_x_n(double x, int n);

double ln_y(double y, int n);

double ln_y_0_2(double y, int n);