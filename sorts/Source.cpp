#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include<alg.h>

int* create_and_inicialize_arr(int n) { 
	//(int *n)
	//scanf_s("%i",n);
	int* p;
	p = (int*)malloc(n * sizeof(int));//*n
	if (n <= 10) {//*n
		printf("Введите массив: \n");
		for (int i = 0; i < n; i++) { //*n
			scanf_s("%i", &p[i]);
		}
	}
	else {
		srand((unsigned int)time(NULL));
		for (int i = 0; i < n; i++) { //*n
			int r = 1 * (i % 2 == 0) + (-1) * (i % 2 != 0);
			p[i] = rand()%101*r;//или без %101, если нужно изменить диапазон
		}
	}
	return p;
}

void output_of_the_array(int *p, int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", p[i]);
	}
	printf("\n");
}

void swap(int* a, int* b) {
	int c;
	c = *a; *a = *b; *b = c;
}

int line_search(int* p, int n, int x, int *comp) { 
	for (int i = 0; i < n; i++) {
		(*comp)++;
		if (p[i] == x) {
			return i;
		}
	}
	return -1;
}

int binary_search(int* p, int n, int x,int *comp) {
	int l = 0, r = n - 1, pos = -1;
	while (l <= r) {
		int c = (l + r) / 2;
		if (p[c] == x) {
			(*comp)++;
			pos = c;
			break;
		}
		if (p[c] > x) {
			(*comp)++;
			r = c - 1;
		}
		else {
			(*comp)++;
			l = c + 1;
		}
	}
	return pos;
}

int binary_search_position(int* p, int n, int x,int*comp) {
	int l = 0, r = n - 1, c;
	(*comp)++;
	if (x > p[n - 1]) {
		return n;
	}
	else if (x < p[0]) {
		return 0;
	}
	while (r - l > 1) {
		c = (l + r) / 2;
		(*comp)++;
		if (p[c] > x) {
			r = c - 1;
		}
		else {
			l = c + 1;
		}
	}
	(*comp)++;
	if (r == l) {
		(*comp)++;
		if (x < p[r]) {
			return r;
		}
		else {
			return r + 1;
		}
	}
	else if (r - l == 1) {
		(*comp)++;
		if (x < p[l]) {
			return l;
		}
		else if (x > p[l] && x < p[r]) {
			return r;
		}
		else {
			return r + 1;
		}
	}
}

void sort_bubble(int *p, int n) {
	double sp_t = 0.0;
	int comp=0, sw=0;
	clock_t begin = clock();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			comp += 1;
			if (p[i] > p[j]) {
				swap(&p[i], &p[j]);
				sw += 1;
			}
		}
	}
	clock_t end = clock();
	sp_t= (double)(end - begin) / CLOCKS_PER_SEC;
	if (n <= 30){ output_of_the_array(p, n); }
	printf("Количество сравнений равно %i\nКоличество обменов равно %i\nВремя выполнения в секундах равно %f\n",comp,sw,sp_t);
}

void sort_with_insertation(int* p, int n) {
	int comp = 0,sw=1;
	double sp_t = 0.0;
	clock_t begin = clock();
	for (int i = 1; i < n; i++) {
		int pos = i;
		for (int j = 0; j < i; j++) {
			comp++;
			if (p[i] <= p[j]) {
				pos = j;
				break;
			}
		}
		int q = p[i];
		for (int j = i; j > pos; j--) {
			p[j] = p[j - 1];
			sw++;
		}
		p[pos] = q;
	}
	clock_t end = clock();
	sp_t = (double)(end - begin) / CLOCKS_PER_SEC;
	if (n <= 30) { output_of_the_array(p, n); }
	printf("Количество сравнений равно %i\nКоличество обменов равно %i\nВремя выполнения в секундах равно %f\n", comp, sw, sp_t);
}

void sort_with_sellection(int* a, int n) {
	int sw = 0, comp = 0;
	double sp_t = 0.0;
	clock_t begin = clock();
	for (int i = 0; i < n; i++) {
		int pos = i;
		int min_a = a[i];
		for (int j = i; j < n; j++) {
			comp++;
			if (a[j] < min_a) {
				pos = j;
				min_a = a[j];
			}
		}
		sw++;
		swap(&a[i], &a[pos]);
	}
	clock_t end = clock();
	sp_t = (double)(end - begin) / CLOCKS_PER_SEC;
	if (n <= 30) { output_of_the_array(a, n); }
	printf("Количество сравнений равно %i\nКоличество обменов равно %i\nВремя выполнения в секундах равно %f\n", comp, sw, sp_t);
}

void count_sort(int* p, int n) {
	double sp_t = 0.0;
	int mini = p[0], maxi = p[0];
	for (int i = 1; i < n; i++) {
		if (p[i] > maxi) {
			maxi = p[i];
		}
		if (p[i] < mini) {
			mini = p[i];
		}
	}
	int new_n = maxi - mini + 1;
	int* count = (int*)malloc(new_n * sizeof(int));
	clock_t begin = clock();
	for (int i = 0; i < new_n; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		count[p[i] - mini]++;
	}
	int k = 0;
	for (int i = 0; i < new_n; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				p[k] = i + mini; k++;
			}
		}
	}
	clock_t end = clock();
	sp_t = (long double)(end - begin) / CLOCKS_PER_SEC;
	free(count);
	if (n <= 30) { output_of_the_array(p, n); }
	printf("Время выполнения в секундах равно %f\n", sp_t);
}

void quick_sort(int* p, int first, int last, int *sw, int *comp) {
	int mid;
	int f = first, l = last;
	mid = p[(f + l) / 2];
	while (f<l){
		while (p[f] < mid) { f++; (* comp)++; }
		while (p[l] > mid) { l--; (* comp)++; }
		if (f <= l) {
			(* sw)++;
			swap(&p[f], &p[l]);
			f++;
			l--;
		}
	}
	if (first < l) { quick_sort(p, first, l, sw, comp); }
	if (f < last) { quick_sort(p, f, last, sw, comp); }
}

void merge(int* p, int left, int mid, int right, int* comp,int*sw) {
	int n = right - left + 1;
	int* w = (int*)malloc(n * sizeof(int));
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right) {
		(*comp)++;
		if (p[i] < p[j]) {
			w[k] = p[i];
			i++;
		}
		else {
			w[k] = p[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		while (j <= right) {
			w[k] = p[j];
			j++;
			k++;
		}
	}
	else {
		while (i <= mid) {
			w[k] = p[i];
			i++;
			k++;
		}
	}
	(*comp)++;
	k = 0;
	for (int q = left; q < right + 1; q++) {
		p[q] = w[k];
		k++;
		(*sw)++;
	}
	free(w);
}

void merge_sort(int* p, int left, int right, int* comp,int*sw) {
	if (left == right) {
		return;
	}
	int mid = (left + right) / 2;
	merge_sort(p, left, mid, comp,sw);
	merge_sort(p, mid + 1, right, comp,sw);
	merge(p, left, mid, right, comp,sw);
}

int main() {
	int z = 0, n; int *p,*w;
	setlocale(LC_CTYPE, "Russian");
	printf("Введите размер массива\n");
	scanf_s("%i", &n);
	p = (int*)malloc(n * sizeof(int));
	w = (int*)malloc(n * sizeof(int));
	printf("Меню\n1.Cоздать массив\n2.Вывести массив\n3.Сортировка пузырьком\n4.Сортировка выбором\n5.Сортировка вставкой\n6.Сортировка подсчетом\n7.Быстрая сортировка\n8.Сортировка слиянием\n9.Изменить размер массива\n10.Бинарный поиск\n11.Линейный поиск\n12.Выход\n");
	while(z!=12) {
		printf("Введите команду:\n");
		scanf_s("%i", &z);
		switch (z) {
		case 1: {
			p = create_and_inicialize_arr(n);
			for (int i = 0; i < n; i++) {
				w[i] = p[i];
			}
			break;
		}
		case 2:{ 
			output_of_the_array(p, n);
			break;
		}
		case 3: {
			sort_bubble(w, n);
			for (int i = 0; i < n; i++) {
				w[i] = p[i];
			}
			break;
		}
		case 4: {
			sort_with_sellection(w, n);
			for (int i = 0; i < n; i++) {
				w[i] = p[i];
			}
			break;
		}
		case 5: {
			sort_with_insertation(w, n);
			for (int i = 0; i < n; i++) {
				w[i] = p[i];
			}
			break;
		}
		case 6: {
			count_sort(w, n);
			for (int i = 0; i < n; i++) {
				w[i] = p[i];
			}
			break;
		}
		case 7: {
			double sp_t = 0.0;
			int comp = 0, sw = 0;
			clock_t begin = clock();
			quick_sort(w, 0, n-1, &sw, &comp);
			clock_t end = clock();
			sp_t = (long double)(end - begin) / CLOCKS_PER_SEC;
			if (n <= 30) { output_of_the_array(w, n); }
			printf("Количество сравнений равно %i\nКоличество обменов равно %i\nВремя выполнения в секундах равно %f\n", comp, sw, sp_t);
			for (int i = 0; i < n; i++) {
				w[i] = p[i];
			}
			break;
		}
		case 8: {
			double sp_t = 0.0;
			int comp = 0, sw = 0;
			clock_t begin = clock();
			merge_sort(w, 0, n - 1, &comp, &sw);
			clock_t end = clock();
			sp_t = (long double)(end - begin) / CLOCKS_PER_SEC;
			if (n <= 30) { output_of_the_array(w, n); }
			printf("Количество сравнений равно %i\nКоличество обменов равно %i\nВремя выполнения в секундах равно %f\n", comp, sw, sp_t);
			for (int i = 0; i < n; i++) {
				w[i] = p[i];
			}
			break;
		}
		case 9: {
			free(p);
			free(w);
			printf("Введите новый размер:\n");
			scanf_s("%i", &n);
			p = (int*)malloc(n * sizeof(int));
			w = (int*)malloc(n * sizeof(int));
			p = create_and_inicialize_arr(n);
			for (int i = 0; i < n; i++) {
				w[i] = p[i];
			}
			break;
		}
		case 10: {
			int x, comp=0, c1=0, s1=0;
			double sp_t = 0.0;
			merge_sort(w, 0, n - 1, &c1, &s1);
			printf("Введите число, которое хотите найти:\n");
			scanf_s("%i", &x);
			clock_t begin = clock();
			int t = binary_search(w, n, x,&comp);
			if (t>=0) {
				clock_t end = clock();
				sp_t = (long double)(end - begin) / CLOCKS_PER_SEC;
				printf("Такое число есть, оно находится на позиции %i, количество сравнений равно %i, время выполнения равно %f\n", t,comp,sp_t);
			}
			else {
				int t1 = binary_search_position(w, n, x, &comp);
				clock_t end = clock();
				sp_t = (long double)(end - begin) / CLOCKS_PER_SEC;
				printf("Такого числа нет, но его нужно было бы поставить на позицию %i, количество сравнений равно %i, время выполнения равно %f\n", t1,comp,sp_t);
			}
			for (int i = 0; i < n; i++) {
				w[i] = p[i];
			}
			break;
		}
		case 11: {
			int x;
			int comp=0;
			double sp_t = 0.0;
			printf("Введите число, которое хотите найти:\n");
			scanf_s("%i", &x);
			int t = line_search(w, n, x, &comp);
			if (t >= 0) {
				printf("Такое число есть, оно находится на позиции %i, количество сравнений равно %i, время выполнения равно %f\n", t, comp,sp_t);
			}
			else {
				printf("Такого числа нет, количество сравнений равно %i, время выполнения равно %f\n", comp,sp_t);
			}
			for (int i = 0; i < n; i++) {
				w[i] = p[i];
			}
			break;
		}
		case 12: {break; }
		default: printf("Нет такой операции\n");
			break;
		}
	}
	free(p);
	free(w);
}
