#include"Header.h"

void main() {
	Rational *ar;
	ar = new Rational[3];
	
	Rational x, y, z;
	cout << "Enter nomirator and denomirator of x\n";
	cin >> x;
	cout << "Enter nomirator and denomirator of y\n";
	cin >> y;

	cout << "x = " << x << "\ny = " << y<<"\n";

	z = x + y;
	cout << "x + y = " << z << "\n";
	z = x;
	z += y;
	cout << "x += y; x = " << z << "\n";

	z = x - y;
	cout << "x - y = " << z << "\n";
	z = x;
	z -= y;
	cout << "x -= y; x = " << z << "\n";

	z = x * y;
	cout << "x * y = " << z << "\n";
	z = x;
	z *= y;
	cout << "x *= y; x = " << z << "\n";

	z = x / y;
	cout << "x / y = " << z << "\n";
	z = x;
	z /= y;
	cout << "x /= y; x = " << z << "\n";

	if (x > y) {
		cout << "x > y";
	}
	else if (x < y) {
		cout << "x < y";
	}
	else {
		cout << "x = y";
	}
}