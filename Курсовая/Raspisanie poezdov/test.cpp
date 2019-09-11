#include "interface.cpp"

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Interface<bool> design;
	design.mainMenu();
}