#include"vectorrr.h"
#include"exceptionnn.h"
Exception::Exception(const char* _file, const char* _function, int _line, const char* _description) {
	int n = strlen(_file);
	file = new char[n + 1];
	n = strlen(_function);
	function = new char[n + 1];
	n = strlen(_description);
	description = new char[n + 1];
	line = _line;
	strcpy(file, _file);
	strcpy(function, _function);
	strcpy(description, _description);
}

Exception::Exception(const Exception& x) {
	int n = strlen(x.file);
	file = new char[n + 1];
	n = strlen(x.function);
	function = new char[n + 1];
	n = strlen(x.description);
	description = new char[n + 1];
	line = x.line;
	strcpy(file, x.file);
	strcpy(function, x.function);
	strcpy(description, x.description);
}
ostream& operator <<(ostream& os, const Exception& x) {
	os << "This exception has been throwed in the file " << x.file << " in the line " << x.line << "\n" << x.description;
	return os;
}