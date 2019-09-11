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
	cout << "Введите количество вагонов с грузом: ";
	cin >> this->amountLenght;
}
void carryWood::showHeader()
{
	cout << "|---------------------------------------СПИСОК--------------------------------------|" << endl;
	Item::showHeader();
	cout << setw(14) << "Длина вагонов" << "|" << endl;
	cout << "|-----------------------------------------------------------------------------------|" << endl;
}
void carryWood::showData()
{
	Item::showData();
	cout << setw(14) << left << amountLenght << "|" << endl;
}
void carryWood::showLabel()						//Вывод полей класса
{
	Item::showLabel();
	cout << "5| Длина вагонов" << endl;
}

void carryWood::editData()
{
	string temp;		//Переменная для проверки на буквы
	char decision;
	Item::editData();	//Метод редактирования данных
	cout << "5| Длина вагонов" << endl;
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
		cout << "Введите общую длину вагонов: ";
		cin >> temp;
		if (isFigure(temp))
		{
			this->amountLenght = stoi(temp);
		}
		else
			cout << "[ОШИБКА] Присутствуют запрещенные символы" << endl;
		break;
	default:
		cout << "[ОШИБКА] Такого пункта меню не существует" << endl;
		break;
	}
}

void carryWood::setOptional()
{
	carryWood value;			//Буферный объект
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
	sout << dynamic_cast<Item&>(obj);						//Приведение к типу 
	sout << setw(14) << obj.amountLenght << "|" << endl;
	return sout;
}

istream& operator >> (istream& sin, carryWood& obj)
{
	sin >> dynamic_cast<carryWood&>(obj);	   //Приведение к типу 
	cout << "Введите общую длину вагонов: ";
	sin >> obj.amountLenght;
	return sin;
}
ofstream& operator<<(ofstream& fout, carryWood& obj)
{
	fout << dynamic_cast<Item&>(obj);		//Приведение к типу 
	fout << obj.amountLenght << "\n";
	return fout;
}

ifstream& operator >> (ifstream& fin, carryWood& obj)
{
	fin >> dynamic_cast<Item&>(obj);//Приведение к типу 
	fin >> obj.amountLenght;
	return fin;
}

bool compareLong(const carryWood* obj, const carryWood* obj2, int trigger)
{
	switch (trigger)													//Выбор как сравнивать
	{
	case 1:
		return obj->amountLenght < obj2->amountLenght; //По возрастанию
		break;
	case 2:
		return obj->amountLenght > obj2->amountLenght; //По убыванию
		break;
	}
	return false;
}