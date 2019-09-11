#pragma once
#include "header.h"

class Item
{
protected:
	string nameItem;                      //Направление
	string seats;                      //Свободные места
	int price;                         //Стоимость билета
	int date;                        //Дата отправления
public:
	Item();                               //Конструктор без параметров
	Item(const Item&);                    //Конструктор копирования
	Item(string, string, int, int);       //Конструтор с параметрами
	~Item();                              //Деструктор
	void setData();                       //Метод, определяющий поля элемента
	void showData();                      //Метод, выводящий данные полей элемента
	void editData();                      //Метод, изменяющий данные полей элемента
	void showLabel();                     //Метод, выводящий полей элемента
	virtual string getName();                         //Метод, возвращающий nameItem
	virtual string getType();                         //Метод, возвращающий typeItem
	friend ostream& operator<<(ostream&, Item&);            //Перегрузка вывода
	friend istream& operator >> (istream&, Item&);          //Перегрузка ввода
	friend ofstream& operator<<(ofstream&, Item&);           //Перегрузка вывода
	friend ifstream& operator >> (ifstream&, Item&);         //Перегрузка ввода
	Item operator=(const Item&);                  //Перегрузка оператора присваивания
	bool operator==(const Item&);                //Перегрузка оператора сравнения
	void showHeader();               //Метод, показывающий заголовки элемента
	friend bool compareName(const Item*, const  Item*, int);
	friend bool compareType(const Item*, const  Item*, int);
	friend bool comparePrice(const Item*, const  Item*, int);
	friend bool compareDate(const Item*, const  Item*, int);
};