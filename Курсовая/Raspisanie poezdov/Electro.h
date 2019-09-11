#pragma once
#include "Trains.h"

class Electro : public Trains
{
protected:
	int waypointTime;                            //Время между остановками
public:
	Electro();                              //Конструктор без параметров
	Electro(const Electro&);           //Конструктор копирования
	Electro(string, string, int, int, int, int);         //Конструктор с параметрами
	~Electro();                                               //Деструктор
	void setData();                //Метод, определяющий поля элемента
	void showData();               //Метод, выводящий данные поля элемента
	void showLabel();              //Метод, выводящий поля элемента
	void setOptional();
	friend ostream& operator<<(ostream&, Electro&);               //Перегрузка вывода
	friend istream& operator >> (istream&, Electro&);             //Перегрузка ввода
	friend ofstream& operator<<(ofstream&, Electro&);             //Перегрузка вывода
	friend ifstream& operator >> (ifstream&, Electro&);           //Перегрузка ввода
	Electro operator=(const Electro&);           //Перегрузка оператора присваивания
	bool operator==(const Electro&);             //Перегрузка оператора сравнения
	friend bool compareWpTime(const Electro*, const Electro*, int);               //Метод, сравнивающий поле waypointTime
	void showHeader();               //Метод, показывающий заголовки элемента
	void editData();                 //Метод, изменяющий данные поля элемента
};