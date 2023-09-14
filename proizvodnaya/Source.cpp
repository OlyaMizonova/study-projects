#include"Header.h"
/* общее задание такое:
–азработать класс –асчет производных.
 ласс должен позвол€ть вычисл€ть приближенное значение первой производной от произвольной
функции одной переменной, заданной в виде функции €зыка C++. ѕроизводную нужно вычислить,
использу€ формулу по двум и по трем точкам.
 ласс должен содержать необходимые служебные методы (конструкторы, деструктор и пр.).
 ласс должен предоставл€ть следующие операции: 1) задать текущую функцию, 2) задать левую и
правую границы, 3) узнать левую и правую границы, 4) задать количество разбиений отрезка 5)
выбрать метод вычислени€ производной, 6) вычислить значение производной выбранным методом,
7) вывести результат вычислени€ в виде таблицы на экран и в файл
*/

void main() {
	int u = 0, q = 0;
	Derivative obj;
	try {
		while (q != 9) {	
			cout << "choose the command:\n";
			cout << "1.choose the function\n2.enter left and right borders\n";
			cout << "3.get left and right borders\n4.enter number of intervals\n";
			cout << "5.chose method of calculating\n6.calculate derivative\n";
			cout << "7.display result to the screen\n8.write result to the file\n9.exit\n";
			cin >> q;	
			switch (q) {
			case 1: {
				system("cls");
				cout << "choose the function:\n";
				cout << "1.f(x) = e^x\n2.f(x) = sin(x)\n3.f(x) = cos(x)\n4.f(x) = ln(x)\n5.Exit\n";
				cin >> u;
				switch (u) {
				case 1:
				{
					system("cls");
					obj.set_func(exp);
					break;
				}
				case 2:
				{
					system("cls");
					obj.set_func(sin);
					break;
				}
				case 3:
				{
					system("cls");
					obj.set_func(cos);
					break;
				}
				case 4:
				{
					system("cls");
					obj.set_func(log);
					break;
				}
				case 5:
				{
					break;
				}
				default: {cout << "wrong command\n"; break; }
				}
				break;
			}
			case 2: {
				system("cls");
				cout << "enter left and right borders:\n";
				double l, r;
				cin >> l >> r;
				obj.set_left(l);
				obj.set_right(r);
				break;
			}
			case 3: {
				system("cls");
				cout << "left border is " << obj.get_left() << "\nright border is " << obj.get_right()<<"\n";
				break;
			}
			case 4: {
				system("cls");
				int n;
				cout << "enter amount of intervals:\n";
				cin >> n;
				obj.set_N(n);
				break;
			}
			case 5: {
				system("cls");
				double t;
				cout << "choose method of calculating: ";
				cout << "enter 1 if you want to calculate delivate with one point\n";
				cout<<"and 2 if you want to do what with two points : \n";
				cin >> t;
				if (t == 1||t == 2) {
					obj.set_type(t);
				}
				else {
					cout << "wrong type\n";
				}
				break;
			}
			case 6: {
				system("cls");
				obj.calculate_del();
				break;
			}
			case 7: {
				system("cls");
				cout << obj;
				break;
			}
			case 8: {
				system("cls");
				ofstream fs;
				fs.open("D:/study/forcpp/informatics/yaziki_i_metodi/cpp/deliv.txt");
				fs << obj;
				fs.close();
				break;
			}
			case 9: {
				break;
			}
			default: {
				cout << "wrong command\n";
			}
			}
		}
	}
	catch (Exception i) {
		cout << i;
	}
	catch (...) {
		cout << "something wrong";
	}
}
