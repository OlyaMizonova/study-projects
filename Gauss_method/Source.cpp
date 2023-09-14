#include"Header.h"

void main() {
	int n, z = 0;
	double** a, ** a_copy;
	double* b, * b_copy, * x;
	cout << "Enter the system's size:\n";
	cin >> n;
	system("cls");
	a = new double* [n];
	a_copy = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
		a_copy[i] = new double[n];
	}
	b = new double[n];
	b_copy = new double[n];
	x = new double[n];
	while (z != 9) {
		cout << "Menu\n";
		cout << "1.To change the size of the matrix\n2.To initialize the matrix\n";
		cout << "3.To solve the system of equations\n4.To check the answer\n5.To output the matrix\n6.To output the answer\n7.To transpose the matrix\n8.To enter numbers to the file\n9.Exit\n";
		cin >> z;
		switch (z) {
			case 1: {
				system("cls");
				int n_ol = n;
				cout << "Enter new size: \n";
				cin >> n;
				system("cls");
				for (int i = 0; i < n_ol; i++) {
					delete[] a[i];
					delete[] a_copy[i];
				}
				delete[]a;
				delete[]b;
				delete[]a_copy;
				delete[]b_copy;
				delete[]x;
				a = new double* [n];
				a_copy = new double* [n];
				for (int i = 0; i < n; i++) {
					a[i] = new double[n];
					a_copy[i] = new double[n];
				}
				x = new double[n];
				b = new double[n];
				b_copy = new double[n];
				break;
			}
			case 2: {
				system("cls");
				if (n < 5) {
					int y;
					cout << "If you want to enter numbers from the keyboard press 1, if you want\n to enter numbers from file press 2 (the different size is possible)\n";
					cin >> y;
					if (y == 1) {
						inicialization_of_the_matrix(a, b, n, 1);
					}
					else {
						ifstream fs;
						fs.open("D:/study/forcpp/informatics/yaziki_i_metodi/data.txt");
						int n_ol = n;
						fs >> n;
						fs.close();
						for (int i = 0; i < n_ol; i++) {
							delete[] a[i];
							delete[] a_copy[i];
						}
						delete[]a;
						delete[]b;
						delete[]a_copy;
						delete[]b_copy;
						delete[]x;
						a = new double* [n];
						a_copy = new double* [n];
						for (int i = 0; i < n; i++) {
							a[i] = new double[n];
							a_copy[i] = new double[n];
						}
						x = new double[n];
						b = new double[n];
						b_copy = new double[n];
						inicialization_of_the_matrix(a, b, n, 2);
					}
				}
				else {
					inicialization_of_the_matrix(a, b, n, 1);
				}
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						a_copy[i][j] = a[i][j];
					}
					b_copy[i] = b[i];
				}
				cout << "Matrix was inicialized\n";
				break;
			}
			case 3: {
				system("cls");
				int k = method_gaussa_1(a, b, x, n);
				if (k == 0) {
					cout << "The system is inconsistent" << endl;
				}
				break;
			}
			case 4: {
				system("cls");
				ios init(NULL);
				init.copyfmt(cout);
				double p;
				p = check_the_answer(x, a_copy, b_copy, n);
				cout << "The fault of the calculations is ";
				cout.precision(7);
				cout << scientific << p;
				cout << endl;
				cout.copyfmt(init);
				break;
			}
			case 5: {
				system("cls");
				output_of_the_matrix(a_copy, b_copy, n);
				break;
			}
			case 6: {
				system("cls");
				output_of_the_answer(x, n);
				break;
			}
			case 7: {
				system("cls");
				transposition(a, n);
				cout << "Matrix was transponated\n";
				break;
			}
			case 8: {
				system("cls");
				write_data_to_file(a, b, n);
				break;
			}
			case 9: {
				break;
			}
			default: {
				system("cls");
				cout << "Please, enter the correct command\n";
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[]a;
	delete[]b;
}