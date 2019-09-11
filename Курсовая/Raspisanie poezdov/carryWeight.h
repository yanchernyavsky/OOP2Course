#pragma once
#include "Item.h"

class carryWeight : public Item
{
protected:
	int amountLoaded;                  //количество вагонов с грузом
public:
	carryWeight();               //Конструктор без параметров
	carryWeight(const carryWeight&);                             //Конструктор копирования
	carryWeight(string, string, int, int, int);               //Конструктор с параметрами
	~carryWeight() = default;            //Деструктор
	void setData();                    //Метод, определяющий данные поля элемента
	void showData();                   //Метод, выводящий данные поля элемента
	void showLabel();                  //Метод, выводящий поля элемента
	void setOptional();                //Метод заполнения определенных данных
	friend ostream& operator<<(ostream&, carryWeight&);                 //Перегрузка вывода
	friend istream& operator >> (istream&, carryWeight&);               //Перегрузка ввода
	friend ofstream& operator<<(ofstream&, carryWeight&);               //Перегрузка вывода
	friend ifstream& operator >> (ifstream&, carryWeight&);             //Перегрузка ввода
	carryWeight operator=(const carryWeight&);             //Перегрузка оператора присваивания
	bool operator==(const carryWeight&);                  //Перегрузка оператора сравнения
	friend bool compareTimeStorage(const carryWeight*, const carryWeight*, int);             //Метод, сравнивающий поле amountLoaded
	void showHeader();               //Метод, выводящий заголовки поля элемента
	void editData();                 //Метод, изменяющий данные поля элемента
};