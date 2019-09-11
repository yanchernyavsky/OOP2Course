#pragma once
#include "exhTrain.h"
#include "Electro.h"
#include "Diesel.h"
#include "header.h"
#include "carryWeight.h"
#include "vipTrain.h"
#include "Item.h"
#include "carryWood.h"
#include "Trains.h"
#include "SpeedTrain.h"

template<class Type>
struct Line
{
	Type obj;                 //Элемент
	Line<Type>* next;         //Указатель на следующий элемент
	Line<Type>* prev;         //Указатель на предыдующий элемент
};

template<class Type>
class List
{
private:
	Line<Type>* begin;               //Указатель на начало списка
	Line<Type>* end;                 //Указатель на конец списка
	int count;                       //Количество элементов
public:
	List();	                   //Конструктор без параметров
	void push(const Type&);          //Добавить элемент в начало
	void pushBack(const Type&);      //Добавить элемент в конец
	Type dellOne();		      //Удалить элемент с начала
	Type dellOneBack();              //Удалить элемент с конца
	void dellAll();                  //Удалить все элементы
	int getCount();                  //Метод, возвращающий поле count
	Type dellPoint(Line<Type>*);     //Удаление заданного элемента
	void show();			      //Метод, выводящий все элемента списка с начала
	void showBack();                 //Метод, выводящий все элемента списка с конца
	Line<Type>* operator [] (int);   //Перегрузка оператора []
	void readFile(string);           //Чтение данных из файла
	void writeFile(string);          //Запись данных в файл
	bool isEmpty();		      //Метод, проверяющий список на пустоту
	void search(const Type&);        //Поиск элемента по названию
	void sort(int, bool(*Compare)(Type*, Type*, int));   //Сортировка по всем полям
	~List();                          //Деструктор
};