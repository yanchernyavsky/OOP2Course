#pragma once
#include "Item.h"

class vipTrain : public Item
{
protected:
	string vipCount;               //количество мест в VIP вагонах
public:
	vipTrain();                      //Конструктор без параметров
	vipTrain(const vipTrain&);     //Конструктор копирования
	vipTrain(string, string, int, int, string);               //Конструктор с параметрами
	~vipTrain();                 //Деструктор
	void setData();                //Метод, определяющий данные поля элемента
	void showData();               //Метод, выводящий данные поля элемента
	void showLabel();              //Метод, выводящий поля элемента
	//void setOptional();            //Метод заполнения определенных данных
	friend ostream& operator<<(ostream&, vipTrain&);                 //Перегрузка вывода
	friend istream& operator >> (istream&, vipTrain&);               //Перегрузка ввода
	friend ofstream& operator<<(ofstream&, vipTrain&);               //Перегрузка вывода
	friend ifstream& operator >> (ifstream&, vipTrain&);            //Перегрузка ввода
	vipTrain operator=(const vipTrain&);              //Перегрузка оператора присваивания
	bool operator==(const vipTrain&);                  //Перегрузка оператора сравнения
	friend bool compareVipSeat(const vipTrain*,const  vipTrain*, int);               //Метод, сравнивающий поле vipCount
	void showHeader();             //Метод, выводящий заголовки поля элемента
	void editData();               //Метод, изменяющий данные поля элемента
};
