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
	Type obj;                 //�������
	Line<Type>* next;         //��������� �� ��������� �������
	Line<Type>* prev;         //��������� �� ����������� �������
};

template<class Type>
class List
{
private:
	Line<Type>* begin;               //��������� �� ������ ������
	Line<Type>* end;                 //��������� �� ����� ������
	int count;                       //���������� ���������
public:
	List();	                   //����������� ��� ����������
	void push(const Type&);          //�������� ������� � ������
	void pushBack(const Type&);      //�������� ������� � �����
	Type dellOne();		      //������� ������� � ������
	Type dellOneBack();              //������� ������� � �����
	void dellAll();                  //������� ��� ��������
	int getCount();                  //�����, ������������ ���� count
	Type dellPoint(Line<Type>*);     //�������� ��������� ��������
	void show();			      //�����, ��������� ��� �������� ������ � ������
	void showBack();                 //�����, ��������� ��� �������� ������ � �����
	Line<Type>* operator [] (int);   //���������� ��������� []
	void readFile(string);           //������ ������ �� �����
	void writeFile(string);          //������ ������ � ����
	bool isEmpty();		      //�����, ����������� ������ �� �������
	void search(const Type&);        //����� �������� �� ��������
	void sort(int, bool(*Compare)(Type*, Type*, int));   //���������� �� ���� �����
	~List();                          //����������
};