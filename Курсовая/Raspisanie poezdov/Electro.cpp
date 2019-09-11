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
	cout << "������� ����� ����� �����������: ";
	cin >> this->waypointTime;
}

void Electro::showHeader()
{
	cout << "|---------------------------------------������--------------------------------------|" << endl;
	Trains::showHeader();
	cout << setw(24) << "����� ����� �����������" << "|" << endl;
	cout << "|-----------------------------------------------------------------------------------|" << endl;
}

void Electro::showData()
{
	Trains::showData();
	cout << setw(24) << left << waypointTime << "|" << endl;
}

void Electro::setOptional()
{
	Electro value;			//�������� ������
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

void Electro::editData()
{
	string temp;		//���������� ��� �������� �� �����
	char decision;
	Trains::editData();	//����� �������������� ������
	cout << "6| ����� � ����" << endl;
	cout << "���� �������: ";
	cin >> decision;
	switch (decision)
	{
	case '1':
		cout << "������� ��������: ";
		cin >> this->nameItem;
		break;
	case '2':
		cout << "������� ���������� ����: ";
		cin >> this->seats;
		break;
	case '3':
		cout << "������� ����: ";
		cin >> temp;
		if (isFigure(temp))
		{
			this->price = stoi(temp);
		}
		else {
			cout << "[������] ������������ ����������� �������" << endl;
		}
		break;
	case '4':
		cout << "������� ����: ";
		cin >> temp;
		if (isFigure(temp))
		{
			this->date = stoi(temp);
		}
		else {
			cout << "[������] ������������ ����������� �������" << endl;
		}
		break;
	case '5':
		cout << "������� ����� � ����: " << endl;
		cin >> hours;
		if (isFigure(temp))
		{
			this->hours = stoi(temp);
		}
		else {
			
			cout << "[������] ������������ ����������� �������" << endl;
			
		}
		break;
	case '6':
		cout << "������� ����� ����� �����������: ";
		cin >> temp;
		if (isFigure(temp))
		{
			this->waypointTime = stoi(temp);
		}
		else {
			cout << "[������] ������������ ����������� �������" << endl;
		}
		break;
	default:
		cout << "[������] ������ ������ ���� �� ����������" << endl;
		break;
	}
}

void Electro::showLabel()						//����� ����� ������
{
	Trains::showLabel();
	cout << "6| ����� � ����" << endl;
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
	sout << dynamic_cast<Trains&>(obj);						//���������� � ���� 
	sout << setw(24) << obj.waypointTime << "|" << endl;
	return sout;
}

istream& operator >> (istream& sin, Electro& obj)
{
	sin >> dynamic_cast<Trains&>(obj);	   //���������� � ���� 
	cout << "������� ����� ����� �����������: ";
	sin >> obj.waypointTime;
	return sin;
}
ofstream& operator<<(ofstream& fout, Electro& obj)
{
	fout << dynamic_cast<Trains&>(obj);		//���������� � ���� 
	fout << obj.waypointTime << "\n";
	return fout;
}

ifstream& operator >> (ifstream& fin, Electro& obj)
{
	fin >> dynamic_cast<Trains&>(obj);//���������� � ���� 
	fin >> obj.waypointTime;
	return fin;
}

bool compareWpTime(const Electro* obj, const Electro* obj2, int trigger)
{
	switch (trigger)													//����� ��� ����������
	{
	case 1:
		return obj->waypointTime < obj2->waypointTime; //�� �����������
		break;
	case 2:
		return obj->waypointTime > obj2->waypointTime; //�� ��������
		break;
	}
	return false;
}
