#include "SpeedTrain.h"

SpeedTrain::SpeedTrain() : vipTrain::vipTrain()
{
	maxSpeed = 0;
}

SpeedTrain::SpeedTrain(const SpeedTrain& obj) : vipTrain(obj)
{
	this->maxSpeed = obj.maxSpeed;
}

SpeedTrain::SpeedTrain(string nameItem, string typeItem, int costItem, int countItem, string storageCondition, int maxSpeed) : vipTrain(nameItem, typeItem, costItem, countItem, storageCondition)
{
	this->maxSpeed = maxSpeed;
}

SpeedTrain::~SpeedTrain() {}
void SpeedTrain::setData()
{
	vipTrain::setData();
	cout << "Введите максимальную скорость: ";
	cin >> this->maxSpeed;
}

void SpeedTrain::showLabel()
{
	vipTrain::showLabel();
	cout << "6| Максимальная скорость" << endl;
}

void SpeedTrain::showHeader()
{
	cout << "|------------------------------------------СПИСОК---------------------------------------|" << endl;
	vipTrain::showHeader();
	cout << setw(22) << "Максимальная скорость" << "|" << endl;
	cout << "|---------------------------------------------------------------------------------------|" << endl;
}

void SpeedTrain::showData()
{
	vipTrain::showData();
	cout << setw(22) << left << maxSpeed << "|" << endl;
}

SpeedTrain SpeedTrain::operator=(const SpeedTrain& obj)
{
	vipTrain::operator=(obj);
	this->maxSpeed = obj.maxSpeed;
	return *this;
}

bool SpeedTrain::operator==(const SpeedTrain& obj)
{
	bool flag = this->vipTrain::operator==(obj);
	if (obj.maxSpeed != 0 && flag != false)
	{
		if (this->maxSpeed == obj.maxSpeed)
		{
			flag = true;
		}
		else { return false; }
	}
	return flag;
}

ostream& operator<<(ostream& sout, SpeedTrain& obj)
{
	sout << dynamic_cast<vipTrain&>(obj);
	sout << setw(22) << obj.maxSpeed << "|" << endl;
	return sout;
}

istream& operator >> (istream& sin, SpeedTrain& obj)
{
	string temp;
	sin >> dynamic_cast<vipTrain&>(obj);
	cout << "Введите максимальную скорость: ";
	sin >> temp;
	while (isFigure(temp))
	{
		cout << "[ОШИБКА] Введены неверные символы!" << endl;
		cout << "Введите максимальную скорость: ";
		cin >> temp;
	}
	obj.maxSpeed = stoi(temp);
	return sin;
}
ofstream& operator<<(ofstream& fout, SpeedTrain& obj)
{
	fout << dynamic_cast<SpeedTrain&>(obj);
	fout << obj.maxSpeed << "\n";
	return fout;
}

ifstream& operator >> (ifstream& fin, SpeedTrain& obj)
{
	fin >> dynamic_cast<SpeedTrain&>(obj);
	fin >> obj.maxSpeed;
	return fin;
}

bool compareTypeSpeed(const SpeedTrain* obj, const SpeedTrain* obj2, int trigger)
{
	switch (trigger)
	{
	case 1:
		return obj->maxSpeed < obj2->maxSpeed;
		break;
	case 2:
		return obj->maxSpeed > obj2->maxSpeed;
		break;
	}
	return false;
}
void SpeedTrain::editData()
{
	string temp;
	char decision;
	vipTrain::editData();
	cout << "6| Максимальная скорость" << endl;
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
		cout << "Введите максимальную скорость: ";
		cin >> temp;
		if (isFigure(temp))
		{
			this->maxSpeed = stoi(temp);
		}
		else 
		{
			cout << "[ОШИБКА] Присутствуют запрещенные символы" << endl;
		}
		break;
	default:
		cout << "[ОШИБКА] Такого пункта меню не существует" << endl;
		break;
	}
}
void SpeedTrain::setOptional()
{
	SpeedTrain value;
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
