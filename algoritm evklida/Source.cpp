#include<stdio.h>
int main() {
	int a, b;
	printf("Enter numbers: ");
	scanf_s("%i%i", &a, &b);
	if (a != 0 && b != 0) {
		while ((a != 0) && (b != 0)&&(a!=b)) {
			if (a > b) a = a - b;
			if (a < b) b = b - a;
		}
	}
	else {
		printf("Wrong input");
	}
	printf("nod = %i", a);
}