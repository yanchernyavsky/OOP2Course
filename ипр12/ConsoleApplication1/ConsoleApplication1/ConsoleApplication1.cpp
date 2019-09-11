#include "pch.h"
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

class OutRangeError {
public:
	OutRangeError(int idx) : index(idx) {}
	virtual ~OutRangeError() {}
	virtual string what() const {
		return "Ошибка индекса";
	}
	int getIndex() const { return index; }
private:
	int index;
};

class LowBoundError : public OutRangeError {
public:
	LowBoundError(int idx) : OutRangeError(idx) {}
	string what() const {
		return "Индекс меньше нижней границы";
	}
};

class UpBoundError : public OutRangeError {
public:
	UpBoundError(int idx) : OutRangeError(idx) {}
	string what() const {
		return "Индекс меньше верхней границы";
	}
};

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	int arr[] = { 1, 2, 10, 4, 5, 6, 7, 9, 10 };
	cout << "Введите индекс: ";
	int idx;
	cin >> idx;
	try {
		if (idx < 0)
			throw LowBoundError(idx);
		else if (idx >= sizeof(arr) / sizeof(int))
			throw  UpBoundError(idx);
		cout << "Ваше число -  " << arr[idx] << endl;
	}
	catch (const OutRangeError& err) {
		cerr << err.what() << "; индекс = " << err.getIndex() << endl;
		return 1;
	}

	return 0;
}
