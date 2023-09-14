#pragma once
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include <iomanip>
#include<fstream>

using namespace std;
void inicialization_of_the_matrix(double** a, double* b, int n, int p);
void output_of_the_matrix(double** a, double* b, int n);
void output_of_the_answer(double* x, int n);
double check_the_answer(double* x, double** a, double* b, int n);
int method_gaussa_1(double** a, double* b, double* x, int n);
//int method_gaussa_2(double** a, double* b, double* x, int n);
void transposition(double** p, int n);
void write_data_to_file(double** a, double* b, int n);