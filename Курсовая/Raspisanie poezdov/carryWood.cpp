#include "carryWood.h"

carryWood::carryWood() : Item()
{
	amountLenght = 0;
}
carryWood::carryWood(const carryWood& other) : Item(other)
{
	amountLenght = other.amountLenght;
}
carryWood::carryWood(string nameItem, string typeItem, int costItem, int countItem, int amount) : Item(nameItem, typeItem, costItem, countItem)
{
	amountLenght = amount;
}
void carryWood::setData()
{
	Item::setData();
	cout << "������� ���������� ������� � ������: ";
	cin >> this->amountLenght;
}
void carryWood::showHeader()
{
	cout << "|---------------------------------------������--------------------------------------|" << endl;
	Item::showHeader();
	cout << setw(14) << "����� �������" << "|" << endl;
	cout << "|-----------------------------------------------------------------------------------|" << endl;
}
void carryWood::showData()
{
	Item::showData();
	cout << setw(14) << left << amountLenght << "|" << endl;
}
void carryWood::showLabel()						//����� ����� ������
{
	Item::showLabel();
	cout << "5| ����� �������" << endl;
}

void carryWood::editData()
{
	string temp;		//���������� ��� �������� �� �����
	char decision;
	Item::editData();	//����� �������������� ������
	cout << "5| ����� �������" << endl;
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
		cout << "������� ����� ����� �������: ";
		cin >> temp;
		if (isFigure(temp))
		{
			this->amountLenght = stoi(temp);
		}
		else
			cout << "[������] ������������ ����������� �������" << endl;
		break;
	default:
		cout << "[������] ������ ������ ���� �� ����������" << endl;
		break;
	}
}

void carryWood::setOptional()
{
	carryWood value;			//�������� ������
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

carryWood carryWood::operator=(const carryWood& obj)
{
	this->Item::operator=(obj);
	this->amountLenght = obj.amountLenght;
	return *this;
}

bool carryWood::operator==(const carryWood& obj)
{
	bool flag = this->Item::operator==(obj);
	if (obj.amountLenght != NULL && flag != false)
	{
		if (this->amountLenght == obj.amountLenght)
		{
			flag = true;
		}
		else { return false; }
	}
	return flag;
}

ostream& operator<<(ostream& sout, carryWood& obj)
{
	sout << dynamic_cast<Item&>(obj);						//���������� � ���� 
	sout << setw(14) << obj.amountLenght << "|" << endl;
	return sout;
}

istream& operator >> (istream& sin, carryWood& obj)
{
	sin >> dynamic_cast<carryWood&>(obj);	   //���������� � ���� 
	cout << "������� ����� ����� �������: ";
	sin >> obj.amountLenght;
	return sin;
}
ofstream& operator<<(ofstream& fout, carryWood& obj)
{
	fout << dynamic_cast<Item&>(obj);		//���������� � ���� 
	fout << obj.amountLenght << "\n";
	return fout;
}

ifstream& operator >> (ifstream& fin, carryWood& obj)
{
	fin >> dynamic_cast<Item&>(obj);//���������� � ���� 
	fin >> obj.amountLenght;
	return fin;
}

bool compareLong(const carryWood* obj, const carryWood* obj2, int trigger)
{
	switch (trigger)													//����� ��� ����������
	{
	case 1:
		return obj->amountLenght < obj2->amountLenght; //�� �����������
		break;
	case 2:
		return obj->amountLenght > obj2->amountLenght; //�� ��������
		break;
	}
	return false;
}