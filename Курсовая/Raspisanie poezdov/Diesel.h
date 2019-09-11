#pragma once
#include "Trains.h"

class Diesel : public Trains
{
protected:
	string addStops;               //Количество остановок по пути следования (для определения, пропускаются ли необязательные остановки)
public:
	Diesel();                          //Конструктор без параметров
	Diesel(const Diesel&);          //Конструктор копирования
	Diesel(string, string, int, int, int, string);               //Конструктор с параметрами
	~Diesel();                 //Деструктор
	void setData();               //Метод, определяющий данные поля элемента
	void showData();              //Метод, выводящий данные поля элемента
	void setOptional();           //Метод заполнения определенных данных
	void editData();              //Метод, изменяющий данные поля элемента
	void showLabel();             //Метод, показывающий поля элемента
	friend ostream& operator<<(ostream&, Diesel&);                 //Перегрузка вывода
	friend istream& operator >> (istream&, Diesel&);               //Перегрузка ввода
	friend ofstream& operator<<(ofstream&, Diesel&);               //Перегрузка вывода
	friend ifstream& operator >> (ifstream&, Diesel&);             //Перегрузка ввода
	Diesel operator=(const Diesel&);           //Перегрузка оператора присваивания элемента
	bool operator==(const Diesel&);               //Перегрузка оператора cравнения
	void showHeader();                               //Метод, выводящий заголовки поля элемента
	friend bool compareStops(const Diesel*, const Diesel*, int);               //Метод, сравнивающий поля additionalStops
};