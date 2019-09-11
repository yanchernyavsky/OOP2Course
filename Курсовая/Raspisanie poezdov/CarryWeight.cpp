#include "carryWeight.h"

carryWeight::carryWeight() : Item()
{
	amountLoaded = 0;
}
carryWeight::carryWeight(const carryWeight& other) : Item(other)
{
	amountLoaded = other.amountLoaded;
}
carryWeight::carryWeight(string nameItem, string typeItem, int costItem, int countItem, int amount) : Item(nameItem, typeItem, costItem, countItem)
{
	amountLoaded = amount;
}
void carryWeight::setData()
{
	Item::setData();

	cout << "������� ���������� ������� � ������: ";
	cin >> this->amountLoaded;
}
void carryWeight::showHeader()
{
	cout << "|---------------------------------------������--------------------------------------|" << endl;
	Item::showHeader();
	cout << setw(17) << "������� � ������" << "|" << endl;
	cout << "|-----------------------------------------------------------------------------------|" << endl;
}
void carryWeight::showData()
{
	Item::showData();
	cout << setw(17) << left << amountLoaded << "|" << endl;
}
void carryWeight::showLabel()						//����� ����� ������
{
	Item::showLabel();
	cout << "5| ������� � ������" << endl;
}

void carryWeight::editData()
{
	string temp;		//���������� ��� �������� �� �����
	char decision;
	Item::editData();	//����� �������������� ������
	cout << "5| ����� � ����" << endl;
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
		cout << "������� ���������� ������� � ������: ";
		cin >> temp;
		if (isFigure(temp))
		{
			this->amountLoaded = stoi(temp);
		}
		else
			cout << "[������] ������������ ����������� �������" << endl;
		break;
	default:
		cout << "[������] ������ ������ ���� �� ����������" << endl;
		break;
	}
}

void carryWeight::setOptional()
{
	carryWeight value;			//�������� ������
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

carryWeight carryWeight::operator=(const carryWeight& obj)
{
	this->Item::operator=(obj);
	this->amountLoaded = obj.amountLoaded;
	return *this;
}

bool carryWeight::operator==(const carryWeight& obj)
{
	bool flag = this->Item::operator==(obj);
	if (obj.amountLoaded != NULL && flag != false)
	{
		if (this->amountLoaded == obj.amountLoaded)
		{
			flag = true;
		}
		else { return false; }
	}
	return flag;
}

ostream& operator<<(ostream& sout, carryWeight& obj)
{
	sout << dynamic_cast<Item&>(obj);						//���������� � ���� 
	sout << setw(24) << obj.amountLoaded << "|" << endl;
	return sout;
}

istream& operator >> (istream& sin, carryWeight& obj)
{
	sin >> dynamic_cast<carryWeight&>(obj);	   //���������� � ���� 
	cout << "������� ���������� ������� � ������: ";
	sin >> obj.amountLoaded;
	return sin;
}
ofstream& operator<<(ofstream& fout, carryWeight& obj)
{
	fout << dynamic_cast<Item&>(obj);		//���������� � ���� 
	fout << obj.amountLoaded << "\n";
	return fout;
}

ifstream& operator >> (ifstream& fin, carryWeight& obj)
{
	fin >> dynamic_cast<Item&>(obj);//���������� � ���� 
	fin >> obj.amountLoaded;
	return fin;
}

bool compareTimeStorage(const carryWeight* obj, const carryWeight* obj2, int trigger)
{
	switch (trigger)													//����� ��� ����������
	{
	case 1:
		return obj->amountLoaded < obj2->amountLoaded; //�� �����������
		break;
	case 2:
		return obj->amountLoaded > obj2->amountLoaded; //�� ��������
		break;
	}
	return false;
}