#pragma once
#include "Item.h"

class carryWood : public Item
{
protected:
	int amountLenght;                  //Общая длина вагонов
public:
	carryWood();               //Конструктор без параметров
	carryWood(const carryWood&);                             //Конструктор копирования
	carryWood(string, string, int, int, int);               //Конструктор с параметрами
	~carryWood() = default;              //Деструктор
	void setData();                    //Метод, определяющий данные поля элемента
	void showData();                   //Метод, выводящий данные поля элемента
	void showLabel();                  //Метод, выводящий поля элемента
	void setOptional();                //Метод заполнения определенных данных
	friend ostream& operator<<(ostream&, carryWood&);                 //Перегрузка вывода
	friend istream& operator >> (istream&, carryWood&);               //Перегрузка ввода
	friend ofstream& operator<<(ofstream&, carryWood&);               //Перегрузка вывода
	friend ifstream& operator >> (ifstream&, carryWood&);             //Перегрузка ввода
	carryWood operator=(const carryWood&);             //Перегрузка оператора присваивания
	bool operator==(const carryWood&);                  //Перегрузка оператора сравнения
	friend bool compareLong(const carryWood*, const carryWood*, int);             //Метод, сравнивающий поле amountLenght
	void showHeader();               //Метод, выводящий заголовки поля элемента
	void editData();                 //Метод, изменяющий данные поля элемента
};