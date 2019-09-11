#include "Electro.h"
#include <iostream>
using namespace std;
Electro::Electro() : Trains()
{
	waypointTime = 0;
}

Electro::Electro(const Electro& obj) : Trains(obj)
{
	this->waypointTime = obj.waypointTime;
}

Electro::Electro(string nameItem, string typeItem, int costItem, int countItem, int lifeTime, int wpTime) : Trains(nameItem, typeItem, costItem, countItem, lifeTime)
{
	this->waypointTime = wpTime;
}

Electro::~Electro() = default;
void Electro::setData()
{
	Trains::setData();
	cout << "Введите время между остановками: ";
	cin >> this->waypointTime;
}

void Electro::showHeader()
{
	cout << "|---------------------------------------СПИСОК--------------------------------------|" << endl;
	Trains::showHeader();
	cout << setw(24) << "Время между остановками" << "|" << endl;
	cout << "|-----------------------------------------------------------------------------------|" << endl;
}

void Electro::showData()
{
	Trains::showData();
	cout << setw(24) << left << waypointTime << "|" << endl;
}

void Electro::setOptional()
{
	Electro value;			//Буферный объект
	char decision = '1';
	while (decision == '1')
	{
		value.editData();	    //Метод редактирования данных
		cout << "Желаете продолжить?" << endl;
		cout << "1| Да" << endl;
		cout << "2| Нет" << endl;
		cout << "Ваше решение: ";
		cin >> decision;
		switch (decision)
		{
		case '1':
			break;
		case '2':
			decision = '2';
			break;
		default:
			cout << "[ОШИБКА] Неверное значение" << endl;
			cout << "Желаете продолжить?" << endl;
			cout << "1| Да" << endl;
			cout << "2| Нет" << endl;
			cout << "Ваше решение: ";
			cin >> decision;
			break;
		}
	}
	*this = value;
}

void Electro::editData()
{
	string temp;		//Переменная для проверки на буквы
	char decision;
	Trains::editData();	//Метод редактирования данных
	cout << "6| Время в пути" << endl;
	cout << "Ваше решение: ";
	cin >> decision;
	switch (decision)
	{
	case '1':
		cout << "Введите название: ";
		cin >> this->nameItem;
		break;
	case '2':
		cout << "Введите количество мест: ";
		cin >> this->seats;
		break;
	case '3':
		cout << "Введите цену: ";
		cin >> temp;
		if (isFigure(temp))
		{
			this->price = stoi(temp);
		}
		else {
			cout << "[ОШИБКА] Присутствуют запрещенные символы" << endl;
		}
		break;
	case '4':
		cout << "Введите дату: ";
		cin >> temp;
		if (isFigure(temp))
		{
			this->date = stoi(temp);
		}
		else {
			cout << "[ОШИБКА] Присутствуют запрещенные символы" << endl;
		}
		break;
	case '5':
		cout << "Введите время в пути: " << endl;
		cin >> hours;
		if (isFigure(temp))
		{
			this->hours = stoi(temp);
		}
		else {
			
			cout << "[ОШИБКА] Присутствуют запрещенные символы" << endl;
			
		}
		break;
	case '6':
		cout << "Введите время между остановками: ";
		cin >> temp;
		if (isFigure(temp))
		{
			this->waypointTime = stoi(temp);
		}
		else {
			cout << "[ОШИБКА] Присутствуют запрещенные символы" << endl;
		}
		break;
	default:
		cout << "[ОШИБКА] Такого пункта меню не существует" << endl;
		break;
	}
}

void Electro::showLabel()						//Вывод полей класса
{
	Trains::showLabel();
	cout << "6| Время в пути" << endl;
}

Electro Electro::operator=(const Electro& obj)
{
	this->Trains::operator=(obj);
	this->waypointTime = obj.waypointTime;
	return *this;
}

bool Electro::operator==(const Electro& obj)
{
	bool flag = this->Trains::operator==(obj);
	if (obj.waypointTime != NULL && flag != false)
	{
		if (this->waypointTime == obj.waypointTime)
		{
			flag = true;
		}
		else { return false; }
	}
	return flag;
}

ostream& operator<<(ostream& sout, Electro& obj)
{
	sout << dynamic_cast<Trains&>(obj);						//Приведение к типу 
	sout << setw(24) << obj.waypointTime << "|" << endl;
	return sout;
}

istream& operator >> (istream& sin, Electro& obj)
{
	sin >> dynamic_cast<Trains&>(obj);	   //Приведение к типу 
	cout << "Введите время между остановками: ";
	sin >> obj.waypointTime;
	return sin;
}
ofstream& operator<<(ofstream& fout, Electro& obj)
{
	fout << dynamic_cast<Trains&>(obj);		//Приведение к типу 
	fout << obj.waypointTime << "\n";
	return fout;
}

ifstream& operator >> (ifstream& fin, Electro& obj)
{
	fin >> dynamic_cast<Trains&>(obj);//Приведение к типу 
	fin >> obj.waypointTime;
	return fin;
}

bool compareWpTime(const Electro* obj, const Electro* obj2, int trigger)
{
	switch (trigger)													//Выбор как сравнивать
	{
	case 1:
		return obj->waypointTime < obj2->waypointTime; //По возрастанию
		break;
	case 2:
		return obj->waypointTime > obj2->waypointTime; //По убыванию
		break;
	}
	return false;
}
