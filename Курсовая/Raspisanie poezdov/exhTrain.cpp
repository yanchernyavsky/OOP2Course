#include "exhTrain.h"

exhTrain::exhTrain() : vipTrain::vipTrain()
{
	descExh = "";
}

exhTrain::exhTrain(const exhTrain& obj) : vipTrain(obj)
{
	this->descExh = obj.descExh;
}

exhTrain::exhTrain(string nameItem, string typeItem, int costItem, int countItem, string storageCondition, string typeMetal) : vipTrain(nameItem, typeItem, costItem, countItem, storageCondition)
{
	this->descExh = typeMetal;
}

exhTrain::~exhTrain() {}
void exhTrain::setData()
{
	vipTrain::setData();
	cout << "Введите описание выставки: ";
	cin >> this->descExh;
}

void exhTrain::showLabel()
{
	vipTrain::showLabel();
	cout << "6| Jписание выставки" << endl;
}

void exhTrain::showHeader()
{
	cout << "|------------------------------------------СПИСОК---------------------------------------|" << endl;
	vipTrain::showHeader();
	cout << setw(15) << "Основные события" << "|" << endl;
	cout << "|---------------------------------------------------------------------------------------|" << endl;
}

void exhTrain::showData()
{
	vipTrain::showData();
	cout << setw(15) << left << descExh << "|" << endl;
}

exhTrain exhTrain::operator=(const exhTrain& obj)
{
	vipTrain::operator=(obj);
	this->descExh = obj.descExh;
	return *this;
}

bool exhTrain::operator==(const exhTrain& obj)
{
	bool flag = this->vipTrain::operator==(obj);
	if (obj.descExh != "" && flag != false)
	{
		if (this->descExh == obj.descExh)
		{
			flag = true;
		}
		else { return false; }
	}
	return flag;
}

ostream& operator<<(ostream& sout, exhTrain& obj)
{
	sout << dynamic_cast<vipTrain&>(obj);
	sout << setw(15) << obj.descExh << "|" << endl;
	return sout;
}

istream& operator >> (istream& sin, exhTrain& obj)
{
	sin >> dynamic_cast<vipTrain&>(obj);
	cout << "Введите описание выставки: ";
	sin >> obj.descExh;
	return sin;
}
ofstream& operator<<(ofstream& fout, exhTrain& obj)
{
	fout << dynamic_cast<vipTrain&>(obj);
	fout << obj.descExh << "\n";
	return fout;
}

ifstream& operator >> (ifstream& fin, exhTrain& obj)
{
	fin >> dynamic_cast<vipTrain&>(obj);
	fin >> obj.descExh;
	return fin;
}

bool comparedescExh(const exhTrain* obj, const exhTrain* obj2, int trigger)
{
	switch (trigger)
	{
	case 1:
		return obj->descExh.length() < obj2->descExh.length();
		break;
	case 2:
		return obj->descExh.length() > obj2->descExh.length();
		break;
	}
	return false;
}
void exhTrain::editData()
{
	string temp;
	char decision;
	vipTrain::editData();
	cout << "6| Описание выставки" << endl;
	cout << "Ваше решение: ";
	cin >> decision;
	switch (decision)
	{
	case '1':
		cout << "Введите направление: ";
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
		cout << "Введите доп места: ";
		cin >> this->vipCount;
		break;
	case '6':
		cout << "Введите описание выставки: ";
		cin >> this->descExh;
		break;
	default:
		cout << "[ОШИБКА] Такого пункта меню не существует" << endl;
		break;
	}
}
void exhTrain::setOptional()
{
	exhTrain value;
	char decision = '1';
	while (decision == '1')
	{
		value.editData();
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
