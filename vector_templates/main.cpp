#include"vectorrr.h"
#include"rationalll.h"
#include"complexxx.h"
void main() {
	int n_a, n_b;
	cout << "Enter size of vector a, b\n";
	cin >> n_a >> n_b;
	Vector<double> a(n_a), b(n_b);
	try {
		Vector<double> c(n_a);
		cout << "Enter elements of a:\n";
		cin >>	a;
		cout << "Enter elements of b:\n";
		cin >> b;
		cout << "a = " << a << "\n";
		cout << "b = " << b << "\n";
		c = a + b;
		cout << " c = a + b\n c = " << c << "\n";
		c = a - b;
		cout << " c = a - b\n c = " << c << "\n";		
		c = a;
		c += b;
		cout << "a +=b; a = " << c << "\n";
		c = a;
		c -= b;
		cout << "a -=b; a = " << c << "\n";
		if (a.get_n() == b.get_n()) {
			cout << "(a, b) = " << a * b << "\n";
		}
		cout << "enter position and element what you want to add to a:";
		int pos;
		double el;
		cin >> pos >> el;
		a.ins(pos, el);
		cout << "a = " << a << endl;
		cout << "enter position what you want to delete element from b:";
		cin >> pos;
		b.del(pos);
		cout << "b = " << b << endl;
	}
	catch (Exception i) {
		cout << i;
	}
	catch (...) {
		cout << "oh no";
	}
}