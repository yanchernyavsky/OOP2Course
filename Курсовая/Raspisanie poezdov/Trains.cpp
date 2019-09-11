#include "Trains.h"

Trains::Trains()
{
	hours = 0;
}
Trains::Trains(const Trains& other)
{
	hours = other.hours;
}
Trains::Trains(string nameItem, string typeItem, int costItem, int countItem, int hours) : Item(nameItem, typeItem, costItem, countItem)
{
	this->hours = hours;
}
Trains::~Trains() = default;
void Trains::setData()
{
	string temp;
	Item::setData();
	cin >> temp;
	while (!isFigure(temp))
	{
		cout << "[ОШИБКА] Имеются запрещенные символы" << endl;
		cout << "Введите время отправления: ";
		cin >> temp;
	}
	this->hours = stoi(temp);
}

void Trains::showHeader()
{
	Item::showHeader();
	cout << setw(18) << "Время отправления" << "|";
}
void Trains::showData()
{
	Item::showData();
	cout << setw(18) << hours << "|";
}

void Trains::editData()
{
	Item::editData();
	cout << "5| Время отправления" << endl;
}
void Trains::showLabel()
{
	Item::showLabel();
	cout << "5| Время отправления" << endl;

}

Trains Trains::operator=(const Trains& obj)
{
	this->nameItem = obj.nameItem;
	this->seats = obj.seats;
	this->price = obj.price;
	this->date = obj.date;
	this->hours = obj.hours;
	return *this;
}
bool Trains::operator==(const Trains& obj)
{
	bool flag = true;
	if (obj.nameItem != "")
	{
		if (this->nameItem == obj.nameItem)
		{
			flag = true;
		}
		else { return false; }
	}
	if (obj.seats != "")
	{
		if (this->seats == obj.seats)
		{
			flag = true;
		}
		else { return false; }
	}
	if (obj.price != NULL)
	{
		if (this->price == obj.price)
		{
			flag = true;
		}
		else { return false; }
	}
	if (obj.date != NULL)
	{
		if (this->date == obj.date)
		{
			flag = true;
		}
		else { return false; }
	}
	if (obj.hours != NULL)
	{
		if (this->hours == obj.hours)
		{
			flag = true;
		}
		else { return false; }
	}
	return flag;
}

ostream& operator<<(ostream& sout, Trains& obj)
{
	sout << "|" << setw(21) << left << obj.nameItem << "|" << setw(16) << obj.seats << "|" << setw(6) << obj.price << "|" << setw(7) << obj.date << "|" << setw(18) << obj.hours;
	return sout;
}
istream& operator >> (istream& sin, Trains& obj)
{
	string temp;
	cout << "Введите направление: ";
	sin >> obj.nameItem;
	cout << "Введите к-во мест: ";
	sin >> obj.seats;
	cout << "Введите цену: ";
	sin >> temp;
	while (!isFigure(temp))
	{
		cout << "[ОШИБКА] Имеются запрещенные символы" << endl;
		cout << "Введите год: ";
		cin >> temp;
	}
	obj.price = stoi(temp);
	cout << "Введите дату: ";
	sin >> temp;
	while (!isFigure(temp))
	{
		cout << "[ОШИБКА] Имеются запрещенные символы" << endl;
		cout << "Введите дату: ";
		cin >> temp;
	}
	obj.date = stoi(temp);
	cout << "Введите максимальную скорость: ";
	sin >> temp;
	while (!isFigure(temp))
	{
		cout << "[ОШИБКА] Имеются запрещенные символы" << endl;
		cout << "Введите максимальную скорость: ";
		cin >> temp;
	}
	obj.hours = stoi(temp);
	return sin;
}
ofstream& operator<<(ofstream& fout, Trains& obj)
{
	fout << obj.nameItem << " " << obj.seats << " " << obj.price << " " << obj.date << " " << obj.hours;
	return fout;
}
ifstream& operator >> (ifstream& fin, Trains& obj)
{
	fin >> obj.nameItem;
	fin >> obj.seats;
	fin >> obj.price;
	fin >> obj.date;
	fin >> obj.hours;
	return fin;
}

bool compareTime(const Trains* obj, const Trains* obj2, int trigger)
{
	switch (trigger)
	{
	case 1:
		return obj->date < obj2->date;
		break;
	case 2:
		return obj->date > obj2->date;
		break;
	}
	return false;
}