#pragma once
using namespace std;
#include"vectorrr.h"
class Exception {
private:
	char* file;
	char* function;
	int line;
	char* description;
public:
	Exception(const char* _file, const char* _function, int _line, const char* _description);
	Exception(const Exception& x);
	~Exception() { delete[]file; delete[]function; delete[]description; }
	friend ostream& operator <<(ostream& os, const Exception& x);
};
