#include "Item.h"

Item::Item()
{
	nameItem = "";
	seats = "";
	price = NULL;
	date = NULL;
}

Item::Item(const Item& obj)
{
	this->nameItem = obj.nameItem;
	this->seats = obj.seats;
	this->price = obj.price;
	this->date = obj.date;
}

Item::Item(string nameItem, string typeItem, int costItem, int countItem)
{
	this->nameItem = nameItem;
	this->seats = typeItem;
	this->price = costItem;
	this->date = countItem;
}

Item::~Item() = default;

void Item::setData()
{
	string temp;
	cout << "Введите пункт назначения: ";
	cin >> nameItem;
	cout << "Введите количество мест: ";
	cin >> seats;
	cout << "Введите цену за билет: ";
	cin >> temp;
	while (!isFigure(temp))
	{
		cout << "[ОШИБКА] Имеются запрещенные символы" << endl;
		cout << "Введите цену за билет: ";
		cin >> temp;
	}
	this->price = stoi(temp);
	cout << "Введите дату поездки: ";
	cin >> temp;
	while (!isFigure(temp))
	{
		cout << "[ОШИБКА] Имеются запрещенные символы" << endl;
		cout << "Введите время отправления: ";
		cin >> temp;
	}
	this->date = stoi(temp);
}

void Item::showHeader()
{
	cout << "|" << setw(21) << left << "Направление" << "|" << setw(16) << "Свободные места" << "|" << setw(6) << "Цена" << "|" << setw(7) << "Дата" << "|";
}

void Item::showData()
{
	cout << "|" << setw(21) << left << nameItem << "|" << setw(16) << seats << "|" << setw(6) << price << "|" << setw(7) << date << "|";
}

void Item::editData()
{
	cout << "1| Направление" << endl;
	cout << "2| Свободные места" << endl;
	cout << "3| Цена" << endl;
	cout << "4| Дата" << endl;
}

void Item::showLabel()
{
	cout << "1| Направление" << endl;
	cout << "2| Свободные места" << endl;
	cout << "3| Цена" << endl;
	cout << "4| Дата" << endl;
}

Item Item::operator=(const Item& obj)
{
	this->nameItem = obj.nameItem;
	this->seats = obj.seats;
	this->price = obj.price;
	this->date = obj.date;
	return *this;
}
bool Item::operator==(const Item& obj)
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
	return flag;
}
bool compareName(const Item* obj, const Item* obj2, int trigger)
{
	switch (trigger)
	{
	case 1:
		return obj->nameItem < obj2->nameItem;
		break;
	case 2:
		return obj->nameItem > obj2->nameItem;
		break;
	}
	return false;
}
bool compareType(const Item* obj, const  Item* obj2, int trigger)
{
	switch (trigger)
	{
	case 1:
		return obj->seats < obj2->seats;
		break;
	case 2:
		return obj->seats > obj2->seats;
		break;
	}
	return false;
}

bool comparePrice(const Item* obj, const  Item* obj2, int trigger)
{
	switch (trigger)
	{
	case 1:
		return obj->price < obj2->price;
		break;
	case 2:
		return obj->price > obj2->price;
		break;
	}
	return false;
}

bool compareDate(const Item* obj, const  Item* obj2, int trigger)
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

ostream& operator<<(ostream& sout, Item& obj)
{
	sout << "|" << setw(21) << left << obj.nameItem << "|" << setw(16) << obj.seats << "|" << setw(6) << obj.price << "|" << setw(7) << obj.date << "|";
	return sout;
}

istream& operator >> (istream& sin, Item& obj)
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
	return sin;
}

ofstream& operator<<(ofstream& fout, Item& obj)
{
	fout << obj.nameItem << " " << obj.seats << " " << obj.price << " " << obj.date << " ";
	return fout;
}

ifstream& operator >> (ifstream& fin, Item& obj)
{
	fin >> obj.nameItem;
	fin >> obj.seats;
	fin >> obj.price;
	fin >> obj.date;
	return fin;
}

string Item::getName()
{
	return this->nameItem;
}
string Item::getType()
{
	return this->seats;
}