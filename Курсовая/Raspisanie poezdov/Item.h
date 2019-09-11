#pragma once
#include "header.h"

class Item
{
protected:
	string nameItem;                      //�����������
	string seats;                      //��������� �����
	int price;                         //��������� ������
	int date;                        //���� �����������
public:
	Item();                               //����������� ��� ����������
	Item(const Item&);                    //����������� �����������
	Item(string, string, int, int);       //���������� � �����������
	~Item();                              //����������
	void setData();                       //�����, ������������ ���� ��������
	void showData();                      //�����, ��������� ������ ����� ��������
	void editData();                      //�����, ���������� ������ ����� ��������
	void showLabel();                     //�����, ��������� ����� ��������
	virtual string getName();                         //�����, ������������ nameItem
	virtual string getType();                         //�����, ������������ typeItem
	friend ostream& operator<<(ostream&, Item&);            //���������� ������
	friend istream& operator >> (istream&, Item&);          //���������� �����
	friend ofstream& operator<<(ofstream&, Item&);           //���������� ������
	friend ifstream& operator >> (ifstream&, Item&);         //���������� �����
	Item operator=(const Item&);                  //���������� ��������� ������������
	bool operator==(const Item&);                //���������� ��������� ���������
	void showHeader();               //�����, ������������ ��������� ��������
	friend bool compareName(const Item*, const  Item*, int);
	friend bool compareType(const Item*, const  Item*, int);
	friend bool comparePrice(const Item*, const  Item*, int);
	friend bool compareDate(const Item*, const  Item*, int);
};