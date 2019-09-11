#pragma once
#include "vipTrain.h"

class SpeedTrain : public vipTrain
{
protected:
	int maxSpeed;               //максимально развиваемая скорость
public:
	SpeedTrain();                   //Конструктор без параметров
	SpeedTrain(const SpeedTrain&);										//Конструктор копирования
	SpeedTrain(string, string, int, int, string, int);               //Конструктор с параметрами
	~SpeedTrain();                  //Десктрутор
	void setData();                 //Метод, определяющий данные поля элемента
	void showLabel();               //Метод, выводящий поля элемента
	void showData();                //Метод, выводящий данные поля элемента
	void setOptional();             //Метод заполнения определенных данных
	friend ostream& operator<<(ostream&, SpeedTrain&);                 //Перегрузка вывода
	friend istream& operator >> (istream&, SpeedTrain&);               //Перегрузка ввода
	friend ofstream& operator<<(ofstream&, SpeedTrain&);               //Перегрузка вывода
	friend ifstream& operator >> (ifstream&, SpeedTrain&);             //Перегрузка ввода
	SpeedTrain operator=(const SpeedTrain&);		 //Перегрузка оператора присваивания
	bool operator==(const SpeedTrain&);      	   //Перегрузка оператора сравнения
	void showHeader();               //Метод, выводящий заголовки поля элемента
	void editData();                 //Метод, изменяющий данные поля элемента
	friend bool compareTypeSpeed(const SpeedTrain*, const SpeedTrain*, int);               //Метод, сравнивающий поле maxSpeed
};