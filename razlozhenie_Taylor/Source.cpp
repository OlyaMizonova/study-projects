#include"Header.h"


int main() {
	int z = 0, n = 0;
	double a = 0, b = 0, step=0;
	double* x, *our_f, *f_x_vstr,*dx_f;
	x = (double*)malloc(0 * sizeof(double));
	our_f = (double*)malloc(0 * sizeof(double));
	f_x_vstr = (double*)malloc(0 * sizeof(double));
	dx_f = (double*)malloc(0 * sizeof(double));
	setlocale(LC_CTYPE, "Russian");
	while (z != 7) {
		printf("Меню\n1.Ввести данные\n2.Выбрать функцию\n3.Изменить границы отрезка\n4.Изменить шаг вычисления значений\n5.Изменить точность (количество слагаемых в разложении Тейлора)\n6.Вывести текущие данные\n7.Выход\n");
		printf("Введите команду\n");
		scanf_s("%i", &z);
		switch (z) {
		case 1: {
			system("cls");
			printf("Введите границы отрезка\n");
			scanf_s("%lf",&a);
			scanf_s("%lf", &b);
			if (a > b ) {
				swap(&a, &b);
			}
			printf("Введите шаг вычисления значений\n");
			scanf_s("%lf",&step);
			printf("Введите точность (количество слагаемых в раложении Тейлора)\n");
			scanf_s("%i",&n);
			system("cls");
			break;
		}
		case 2: {
			int q = 0;
			system("cls");
			while (q != 5) {
				printf("1.f(x)=e^x\n2.f(x)=sin(x)\n3.f(x)=cos(x)\n4.f(x)=ln(x)\n5.Выход\n");
				scanf_s("%i", &q);
				switch (q) {
				case 1: {
					double maxdx = 0;
					system("cls");
					int k = size_of_array(a,b,step);
					free(dx_f);
					free(x);
					free(f_x_vstr);
					free(our_f);
					x = (double*)malloc(k * sizeof(double));
					our_f = (double*)malloc(k * sizeof(double));
					f_x_vstr = (double*)malloc(k * sizeof(double));
					dx_f = (double*)malloc(k * sizeof(double));
					inicialize_array (exp_n, exp, x, our_f, f_x_vstr, dx_f, a, k, n, step, &maxdx);
					printf("|x          |exp_n(x,n)  |exp(x)     |dx          |\n");
					for (int i = 0; i < k; i++) {
						printf("|%12.6f|%12.6f|%12.6f|%12.6f|\n", x[i], our_f[i], f_x_vstr[i],dx_f[i]);
					}
					printf("|max(dx)| = %lf\n\n", maxdx);
					break;
				}
				case 2: {
					double maxdx = 0;
					system("cls");
					free(dx_f);
					free(x);
					free(f_x_vstr);
					free(our_f);
					int k = size_of_array(a, b, step);
					x = (double*)malloc(k * sizeof(double));
					our_f = (double*)malloc(k * sizeof(double));
					f_x_vstr = (double*)malloc(k * sizeof(double));
					dx_f = (double*)malloc(k * sizeof(double));
					inicialize_array(sin_x_n, sin, x, our_f, f_x_vstr, dx_f, a, k, n, step, &maxdx);
					printf("|x          |sin_x_n(x,n) |sin(x)      |dx          |\n");
					for (int i = 0; i < k; i++) {
						printf("|%12.6f|%12.6f|%12.6f|%12.6f|\n", x[i], our_f[i], f_x_vstr[i], dx_f[i]);
					}
					printf("|max(dx)| = %lf\n\n", maxdx);
					break;
				}
				case 3: { 
					double maxdx = 0;
					system("cls");
					free(dx_f);
					free(x);
					free(f_x_vstr);
					free(our_f);
					int k = size_of_array(a, b, step);
					x = (double*)malloc(k * sizeof(double));
					our_f = (double*)malloc(k * sizeof(double));
					f_x_vstr = (double*)malloc(k * sizeof(double));
					dx_f = (double*)malloc(k * sizeof(double));
					inicialize_array(cos_x_n, cos, x, our_f, f_x_vstr, dx_f, a, k, n, step, &maxdx);
					printf("|x          |cos_x_n(x,n)  |cos(x)     |dx          |\n");
					for (int i = 0; i < k; i++) {
						printf("|%12.6f|%12.6f|%12.6f|%12.6f|\n", x[i], our_f[i], f_x_vstr[i], dx_f[i]);
					}
					printf("|max(dx)| = %lf\n\n", maxdx);
					break;
				}
				case 4: {
					double maxdx = 0;
					system("cls");
					free(dx_f);
					free(x);
					free(f_x_vstr);
					free(our_f);
					int k = size_of_array(a, b, step);
					x = (double*)malloc(k * sizeof(double));
					our_f = (double*)malloc(k * sizeof(double));
					f_x_vstr = (double*)malloc(k * sizeof(double));
					dx_f = (double*)malloc(k * sizeof(double));
					inicialize_array(ln_y, log, x, our_f, f_x_vstr, dx_f, a, k, n, step, &maxdx);
					printf("|x          |ln_y(x,n)  |ln(x)     |dx          |\n");
					for (int i = 0; i < k; i++) {
						printf("|%12.6f|%12.6f|%12.6f|%12.6f|\n", x[i], our_f[i], f_x_vstr[i], dx_f[i]);
					}
					printf("|max(dx)| = %lf\n\n", maxdx);
					break;
				}
				case 5: {
					break;
				}
				default:
					printf("Нет такой команды\n");
					break;
				}
			}
			system("cls");
			break;
		}
		case 3: {
			printf("Введите новые границы отрезка\n");
			scanf_s("%lf", &a);
			scanf_s("%lf", &b);
			system("cls");
			break;
		}
		case 4: {
			printf("Введите новый шаг вычисления значений\n");
			scanf_s("%lf", &step);
			system("cls");
			break;
		}
		case 5: {
			printf("Введите новую точность (количество слагаемых в раложении Тейлора)\n");
			scanf_s("%i", &n);
			system("cls");
			break;
		}
		case 6: {
			printf("Левая граница отрезка равна %lf\nПравая граница  равна %lf\nШаг вычисления значений равен %lf\nТочность (количество слагаемых в разложении Тейлора) равна %i\nНажмите 0 для возвращения к меню\n",a,b,step,n);
			int w = 1;
			while (w != 0) {
				scanf_s("%i", &w);
			}
			system("cls");
			break;
		}
		case 7: {break; }
		default:
			system("cls");
			printf("Нет такой команды\n");
			Sleep(1000);
			system("cls");
			break;
		}
	}
	free(dx_f);
	free(x);
	free(f_x_vstr);
	free(our_f);
}