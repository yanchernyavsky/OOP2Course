#include "vipTrain.h"

vipTrain::vipTrain() : Item()
{
	vipCount = "0";
}
vipTrain::vipTrain(const vipTrain& other) : Item(other)
{
	vipCount = other.vipCount;
}
vipTrain::vipTrain(string path, string seats, int price, int date, string vipCount) : Item(path, seats, price, date)
{
	this->vipCount = vipCount;
}
vipTrain::~vipTrain() = default;

void vipTrain::setData()
{
	Item::setData();

	while (true) 
	{
		cout << "������� ���������� ��� ����: "; cin >> vipCount;
		if (!isFigure(vipCount))
		{
			cout << "[������] ������� ����������� �������" << endl;
			continue;
		}
		else
			break;
	}
}

void vipTrain::showData()
{
	Item::showData();
	cout << setw(10) << vipCount << "|";
}

void vipTrain::showHeader()
{
	Item::showHeader();
	cout << setw(10) << "��� �����" << "|";
}

void vipTrain::showLabel()
{
	Item::showLabel();
	cout << "5| ��� �����" << endl;
}

void vipTrain::editData()
{
	Item::editData();
	cout << "5| ��� �����" << endl;
}

ostream& operator<<(ostream& sout, vipTrain& obj)
{
	sout << "|" << setw(21) << left << obj.nameItem << "|" << setw(16) << obj.seats << "|" << setw(6) << obj.price << "|" << setw(7) << obj.date << "|" << setw(10) << obj.vipCount << "|";
	return sout;
}

istream& operator >> (istream& sin, vipTrain& obj)
{
	string temp;
	cout << "������� �����������: ";
	sin >> obj.nameItem;
	cout << "������� �-�� ����: ";
	sin >> obj.seats;
	cout << "������� ����: ";
	sin >> temp;
	while (!isFigure(temp))
	{
		cout << "[������] ������� ����������� �������" << endl;
		cout << "������� ���: ";
		cin >> temp;
	}
	obj.price = stoi(temp);
	cout << "������� �������: ";
	sin >> temp;
	while (!isFigure(temp))
	{
		cout << "[������] ������� ����������� �������" << endl;
		cout << "������� �������: ";
		cin >> temp;
	}
	obj.date = stoi(temp);

	cout << "������� ���������� ��� ����: ";
	sin >> temp;
	while (!isFigure(temp))
	{
		cout << "[������] ������� ����������� �������" << endl;
		cout << "������� ���������� ��� ����: ";
		cin >> temp;
	}
	obj.vipCount = temp;
	return sin;
}

ofstream& operator<<(ofstream& fout, vipTrain& obj)
{
	fout << obj.nameItem << " " << obj.seats << " " << obj.price << " " << obj.date << " " << obj.vipCount;
	return fout;
}

ifstream& operator >> (ifstream& fin, vipTrain& obj)
{
	fin >> obj.nameItem;
	fin >> obj.seats;
	fin >> obj.price;
	fin >> obj.date;
	fin >> obj.vipCount;
	return fin;
}

vipTrain vipTrain::operator=(const vipTrain& obj)
{
	this->nameItem = obj.nameItem;
	this->seats = obj.seats;
	this->price = obj.price;
	this->date = obj.date;
	this->vipCount = obj.vipCount;
	return *this;
}

bool vipTrain::operator==(const vipTrain& obj)
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
	if (obj.vipCount != "")
	{
		if (this->vipCount == obj.vipCount)
		{
			flag = true;
		}
		else { return false; }
	}
	return flag;
}

bool compareVipSeat(const vipTrain* obj, const  vipTrain* obj2, int trigger)
{
	switch (trigger)
	{
	case 1:
		return stoi(obj->vipCount) < stoi(obj2->vipCount);
		break;
	case 2:
		return stoi(obj->vipCount) > stoi(obj2->vipCount);
		break;
	}
	return false;
}