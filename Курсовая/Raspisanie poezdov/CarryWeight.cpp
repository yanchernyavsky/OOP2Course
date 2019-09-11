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

	cout << "Введите количество вагонов с грузом: ";
	cin >> this->amountLoaded;
}
void carryWeight::showHeader()
{
	cout << "|---------------------------------------СПИСОК--------------------------------------|" << endl;
	Item::showHeader();
	cout << setw(17) << "Вагонов с грузом" << "|" << endl;
	cout << "|-----------------------------------------------------------------------------------|" << endl;
}
void carryWeight::showData()
{
	Item::showData();
	cout << setw(17) << left << amountLoaded << "|" << endl;
}
void carryWeight::showLabel()						//Вывод полей класса
{
	Item::showLabel();
	cout << "5| Вагонов с грузом" << endl;
}

void carryWeight::editData()
{
	string temp;		//Переменная для проверки на буквы
	char decision;
	Item::editData();	//Метод редактирования данных
	cout << "5| Время в пути" << endl;
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
		cout << "Введите количество вагонов с грузом: ";
		cin >> temp;
		if (isFigure(temp))
		{
			this->amountLoaded = stoi(temp);
		}
		else
			cout << "[ОШИБКА] Присутствуют запрещенные символы" << endl;
		break;
	default:
		cout << "[ОШИБКА] Такого пункта меню не существует" << endl;
		break;
	}
}

void carryWeight::setOptional()
{
	carryWeight value;			//Буферный объект
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
	sout << dynamic_cast<Item&>(obj);						//Приведение к типу 
	sout << setw(24) << obj.amountLoaded << "|" << endl;
	return sout;
}

istream& operator >> (istream& sin, carryWeight& obj)
{
	sin >> dynamic_cast<carryWeight&>(obj);	   //Приведение к типу 
	cout << "Введите количество вагонов с грузом: ";
	sin >> obj.amountLoaded;
	return sin;
}
ofstream& operator<<(ofstream& fout, carryWeight& obj)
{
	fout << dynamic_cast<Item&>(obj);		//Приведение к типу 
	fout << obj.amountLoaded << "\n";
	return fout;
}

ifstream& operator >> (ifstream& fin, carryWeight& obj)
{
	fin >> dynamic_cast<Item&>(obj);//Приведение к типу 
	fin >> obj.amountLoaded;
	return fin;
}

bool compareTimeStorage(const carryWeight* obj, const carryWeight* obj2, int trigger)
{
	switch (trigger)													//Выбор как сравнивать
	{
	case 1:
		return obj->amountLoaded < obj2->amountLoaded; //По возрастанию
		break;
	case 2:
		return obj->amountLoaded > obj2->amountLoaded; //По убыванию
		break;
	}
	return false;
}