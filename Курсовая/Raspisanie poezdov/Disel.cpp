#include "Diesel.h"

Diesel::Diesel()
{
	addStops = "";
}
Diesel::Diesel(const Diesel& other)
{
	addStops = other.addStops;
}
Diesel::Diesel(string nameItem, string typeItem, int costItem, int countItem, int hours, string add) : Trains::Trains(nameItem, typeItem, costItem, countItem, hours)
{
	this->addStops = add;
}
Diesel::~Diesel() = default;
void Diesel::setData()
{
	string temp;
	Trains::setData();
	cout << "������� �������������� ���������: " << endl;
	cin >> temp;
	this->addStops = temp;
}

void Diesel::showHeader()
{
	cout << "|---------------------------------------������--------------------------------------|" << endl;
	Trains::showHeader();
	cout << setw(35) << "�������������� ���������" << "|" << endl;
	cout << "|-----------------------------------------------------------------------------------|" << endl;
}
void Diesel::showData()
{
	Trains::showData();
	cout << setw(35) << addStops << "|";
}

void Diesel::editData()
{
	Trains::editData();
	cout << "6| �������������� ���������" << endl;
}
void Diesel::showLabel()
{
	Trains::showLabel();
	cout << "6| �������������� ���������" << endl;

}

Diesel Diesel::operator=(const Diesel& obj)
{
	this->nameItem = obj.nameItem;
	this->seats = obj.seats;
	this->price = obj.price;
	this->date = obj.date;
	this->hours = obj.hours;
	this->addStops = obj.addStops;
	return *this;
}
bool Diesel::operator==(const Diesel& obj)
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
	if (obj.addStops != "")
	{
		if (this->addStops == obj.addStops)
		{
			flag = true;
		}
		else { return false; }
	}
	return flag;
}

ostream& operator<<(ostream& sout, Diesel& obj)
{
	sout << "|" << setw(21) << left << obj.nameItem << "|" << setw(16) << obj.seats << "|" << setw(6) << obj.price << "|" << setw(7) << obj.date << "|" << setw(18) << obj.hours << "|" << setw(35) << obj.addStops << "|";
	return sout;
}
istream& operator >> (istream& sin, Diesel& obj)
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
	cout << "������� ����: ";
	sin >> temp;
	while (!isFigure(temp))
	{
		cout << "[������] ������� ����������� �������" << endl;
		cout << "������� ����: ";
		cin >> temp;
	}
	obj.date = stoi(temp);

	cout << "������� ������������ ��������: ";
	sin >> temp;
	while (!isFigure(temp))
	{
		cout << "[������] ������� ����������� �������" << endl;
		cout << "������� ������������ ��������: ";
		cin >> temp;
	}
	obj.hours = stoi(temp);
	cout << "������� �������������� ���������" << endl;
	sin >> obj.addStops;
	return sin;
}
ofstream& operator<<(ofstream& fout, Diesel& obj)
{
	fout << obj.nameItem << " " << obj.seats << " " << obj.price << " " << obj.date << " " << obj.hours << " " << obj.addStops;
	return fout;
}
ifstream& operator >> (ifstream& fin, Diesel& obj)
{
	fin >> obj.nameItem;
	fin >> obj.seats;
	fin >> obj.price;
	fin >> obj.date;
	fin >> obj.hours;
	fin >> obj.addStops;
	return fin;
}

bool compareStops(const Diesel* obj, const Diesel* obj2, int trigger)
{
	switch (trigger)
	{
	case 1:
		return obj->addStops.length() < obj2->addStops.length();
		break;
	case 2:
		return obj->addStops.length() > obj2->addStops.length();
		break;
	}
	return false;
}

void Diesel::setOptional()
{
	Diesel value;			//�������� ������
	char decision = '1';
	while (decision == '1')
	{
		value.editData();	    //����� �������������� ������
		cout << "������� ����������?" << endl;
		cout << "1| ��" << endl;
		cout << "2| ���" << endl;
		cout << "���� �������: ";
		cin >> decision;
		switch (decision)
		{
		case '1':
			break;
		case '2':
			decision = '2';
			break;
		default:
			cout << "[������] �������� ��������" << endl;
			cout << "������� ����������?" << endl;
			cout << "1| ��" << endl;
			cout << "2| ���" << endl;
			cout << "���� �������: ";
			cin >> decision;
			break;
		}
	}
	*this = value;
}