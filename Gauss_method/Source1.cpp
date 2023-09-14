#include"Header.h"

using namespace std;

void write_data_to_file(double**a, double* b, int n) {
	ofstream fs;
	fs.open("D:/study/forcpp/informatics/yaziki_i_metodi/data.txt");
	fs << n << ' ';
	if (n <= 4) {
		cout << "Enter the lines of the matrix: \n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				fs << a[i][j]<<' ';
			}
		}
		cout << "Please, enter the right column\n";
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			fs << b[i]<<' ';
		}
	}
	else {
		srand((unsigned int)time(NULL));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int t = rand();
				int k = (t % 2 == 0) + (-1) * (t % 2 == 1);
				a[i][j] = rand() / (1.4) * k;
				fs << a[i][j]<<' ';
			}
		}
	}
	fs.close();
}

void inicialization_of_the_matrix(double** a, double* b, int n, int p) {
		if (n <= 4) {
			if (p == 1) {
				cout << "Enter the lines of the matrix: \n";
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						cin >> a[i][j];
					}
				}
				cout << "Please, enter the right column\n";
				for (int i = 0; i < n; i++) {
					cin >> b[i];
				}
			}
			else {
				ifstream fs;
				fs.open("D:/study/forcpp/informatics/yaziki_i_metodi/data.txt");
				int t; fs >> t;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						fs >> a[i][j];
					}
				}
				for (int i = 0; i < n; i++) {
					fs >> b[i];
				}
				fs.close();
			}
		}
		else {
			srand((unsigned int)time(NULL));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int t = rand();
					int k = (t % 2 == 0) + (-1) * (t % 2 == 1);
					a[i][j] = rand() / (1.4) * k;
				}
			}
			for (int i = 0; i < n; i++) {
				int t = rand();
				int k = (t % 2 == 0) + (-1) * (t % 2 == 1);
				b[i] = rand() / (1.3) * k;
			}
		}
}

void output_of_the_matrix(double** a, double* b, int n) {
	if (n > 9) {
		cout << "The system has a big size, do you want to output the matrix? (yes/no)"<<endl;
		string s;
		cin >> s;
		if (s == "no") {
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "|";
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '|' << b[i]<<'|' << "\n";
	}
	cout << "\n\n";
}

void output_of_the_answer(double* x, int n) {
	for (int i = 0; i < n; i++) {
		cout << "x [" << i + 1 << "] = " << x[i] << endl;
	}
}

double check_the_answer (double* x, double** a, double* b, int n) {
	double s, maxdiff = 0;
	for (int i = 0; i < n; i++) {
		s = 0;
		for (int j = 0; j < n; j++) {
			s += (a[i][j] * x[j]);
		}
		s = fabs(s - b[i]);
		//diff = fabs(s - b[i]);
		if (maxdiff < s) {
			maxdiff = s;
		}
	}
	return maxdiff;
}

int method_gaussa_1(double** a, double* b, double* x, int n) {
	for (int j = 0; j < n - 1; j++) {
		for (int i = j + 1; i < n; i++) {
			double alf = (a[i][j]) / (a[j][j]);
			if (alf > 1000000000000000000) {
				return 0;
			}
			for (int k = j; k < n; k++) {
				a[i][k] -= (alf * a[j][k]);
			}
			b[i] -= (alf * b[j]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		double s = 0;
		for (int j = i + 1; j < n; j++) {
			s = s + a[i][j] * x[j];
		}
		x[i] = (b[i] - s) / a[i][i];
	}
	return 1;
}

//int method_gaussa_2(double** a, double* b, double* x, int n) {
//	for (int j = 0; j < n - 1; j++) {
//		for (int i = j + 1; i < n; i++) {
//			double max_el = 0;
//			double* index;
//			for (int k = i; k < n; k++) {
//				if (abs(a[k][i]) > max_el) {
//					max_el = abs(a[k][i]);
//					index = a[k];
//				}
//			}
//			if (max_el) {
//				swap(index, a[j]);
//			}
//			else {
//				return 0;
//			}
//			double alf = (a[j][i]) / (a[j][j]);
//			for (int k = j; k < n; k++) {
//				a[i][k] -= (alf * a[j][k]);
//			}
//			b[i] -= (alf * b[j]);
//		}
//	}
//	for (int i = n - 1; i >= 0; i--) {
//		double s = 0;
//		for (int j = i + 1; j < n; j++) {
//			s += a[i][j] * x[j];
//		}
//		x[i] = (b[i] - s) / a[i][i];
//	}
//	return 1;
//}

void transposition(double** p, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			swap(p[i][j], p[j][i]);
		}
	}
}

//cout.precision(ex);
//cout<<fixed();
//scientific
//defaultfloat
//setw()