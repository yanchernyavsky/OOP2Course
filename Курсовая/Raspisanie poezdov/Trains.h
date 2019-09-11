#pragma once
#include "Item.h"

class Trains : public Item
{
protected:
	int hours;                          //Время отправления
public:
	Trains();                             //Конструктор без параметров
	Trains(const Trains&);              //Конструктор копирования
	Trains(string, string, int, int, int);    //Конструктор с параметрами
	~Trains();                            //Деструктор
	void setData();                         //Метод, определяющий поля элемента
	void showData();                        //Метод, выводящий данные поля элемента
	void editData();                        //Метод, изменяющий данные поля элемента
	void showLabel();                       //Метод, выводящий поля элемента
	friend ostream& operator<<(ostream&, Trains&);  //Перегрузка оператора вывода
	friend istream& operator >> (istream&, Trains&); //Перегразка оператора ввода
	Trains operator=(const Trains&);  //Перегрузка оператора присваивания
	bool operator==(const Trains&);      //Перегрузка оператора сравнения
	friend ofstream& operator<<(ofstream&, Trains&);//Перегрузка оператора вывода
	friend ifstream& operator >> (ifstream&, Trains&); //Перегрузка оператора ввода
	void showHeader();          //Метод, выводящий заголовки элемента
	friend bool compareTime(const Trains*, const Trains*, int);      //Метод, сравнивающий поле hours
};