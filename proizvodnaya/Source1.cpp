#include"Header.h"
Derivative::Derivative(double(*F_)(double), double Left_, double Right_, int N_) {
	check_N(N_);
	F = F_;
	Left = Left_;
	Right = Right_;
	M = N_- 1;
	Points = new double[M];
	Dels = new double[M];
	for (int i = 0; i < M; i++) {
		Dels[i] = 0;
		Points[i] = 0;
	}
}

Derivative::Derivative(const Derivative& r) {
	F = r.F;
	Left = r.Left;
	Right = r.Right;
	M = r.M;
	Points = new double[M];
	Dels = new double[M];
	for (int i = 0; i < M; i++) {
		Points[i] = r.Points[i];
		Dels[i] = r.Dels[i];
	}
}

Derivative::~Derivative() {
	delete[]Points;
	delete[]Dels;
}

void Derivative::calculate_del() {
	if (M <= 0) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Wrong number of points\n");
	}
	check_borders();
	check_params();
	recalculate_points();
	if (Type == 1) { 
		count_1(); 
	} 
	else if(Type==2) {
		count_2(); 
	} 
	else {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Wrong calculation type\n");
	}
}

void Derivative::set_func(double(*F_)(double)) {
	F = F_;
}

void Derivative::set_left(double l) { /* не уверена на 100 что всегда будет такое работать, но вроде бы все нормально, как и в нижнем методе */
	Left = l;
}

void Derivative::set_right(double r) {
	Right = r;
}

void Derivative::set_N(int N_) {
	check_N(N_);
	resize_points(N_- 1);
}

ostream& operator <<(ostream& os, const Derivative& r) {
	os << "_________________\n";
	os << "x        |" << "f'(x)     |\n";
	for (int i = 0; i < r.M; i++) {
		os << r.Points[i] << "        |" << r.Dels[i] << "     |\n";
	}
	os << "_________________\n";
	return os;
}

void Derivative::recalculate_points() {
	if (Points != nullptr) {
		double step = (Right - Left) / (M + 1);
		if (step < H) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Intervals are too small\n");
		}
		Points[0] = Left + step;
		for (int i = 1; i < M; i++) {
			Points[i] = Points[i - 1] + step;
		}
	}
}

void Derivative::check_borders() const {
	if (isnan(Right) || isnan(Left)) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "One or both borders are not defined\n");
	}
	if (Right <= Left) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Wrong borders\n");
	}
}

void Derivative::check_params() const {
	if (F == log) {
		if (Left <= 0) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Log is not define there\n");
		}
	}
}

void Derivative::check_N(int N_) const {
	if (N_ < 2) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Wrong amount of intervals");
	}
}

void Derivative::resize_points(int M_) {
	if (M != M_) {
		if (Points != nullptr) {
			delete[]Points; delete[]Dels;
		}
		M = M_;
		Points = new double[M];
		Dels = new double[M]; /*ну тут просто перевыделяю память*/
	}
}

void Derivative::count_1() {
	for (int i = 0; i < M; i++) {
		Dels[i] = (F(Points[i] + H) - F(Points[i])) / H;
	}
}

void Derivative::count_2() {
	for (int i = 0; i < M; i++) {
		Dels[i] = (F(Points[i] + H) - F(Points[i] - H)) / (2 * H);
	}
}
	
Exception::Exception(const char* file_, const char* function_, int line_, const char* description_) {
	int n = strlen(file_);
	file = new char[n + 1];
	n = strlen(function_);
	function = new char[n + 1];
	n = strlen(description_);
	description = new char[n + 1];
	line = line_;
	strcpy(file, file_);
	strcpy(function, function_);
	strcpy(description, description_);
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


