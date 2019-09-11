#pragma once
#include "vipTrain.h"

class exhTrain : public vipTrain
{
protected:
	string descExh;               //описание выставки
public:
	exhTrain();                              //Конструктор без параметров
	exhTrain(const exhTrain&);            //Конструктор копирования
	exhTrain(string, string, int, int, string, string);          //Конструктор с параметрами
	~exhTrain();               //Деструктор
	void setData();               //Метод, изменяющий данные поля элемента
	void showData();              //Метод, выводящий данные поля элемента
	void showLabel();             //Метод, выводязий поля элемента
	void setOptional();           //Метод заполнения определенных данных
	friend ostream& operator<<(ostream&, exhTrain&);                 //Перегрузка вывода
	friend istream& operator >> (istream&, exhTrain&);               //Перегрузка ввода 
	friend ofstream& operator<<(ofstream&, exhTrain&);               //Перегрузка вывода 
	friend ifstream& operator >> (ifstream&, exhTrain&);             //Перегрузка ввода
	exhTrain operator=(const exhTrain&);                    //Перегрузка оператора присваивания 
	bool operator==(const exhTrain&);                       //Перегрузка оператора сравнения
	friend bool comparedescExh(const exhTrain*, const exhTrain*, int);     //Метод, сравнивающий поле descExh
	void showHeader();             //Метод, выводящий заголовки поля элемента
	void editData();               //Метод, изменяющий данные поля элемента
};