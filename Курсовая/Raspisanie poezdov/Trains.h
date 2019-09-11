#pragma once
#include "Item.h"

class Trains : public Item
{
protected:
	int hours;                          //����� �����������
public:
	Trains();                             //����������� ��� ����������
	Trains(const Trains&);              //����������� �����������
	Trains(string, string, int, int, int);    //����������� � �����������
	~Trains();                            //����������
	void setData();                         //�����, ������������ ���� ��������
	void showData();                        //�����, ��������� ������ ���� ��������
	void editData();                        //�����, ���������� ������ ���� ��������
	void showLabel();                       //�����, ��������� ���� ��������
	friend ostream& operator<<(ostream&, Trains&);  //���������� ��������� ������
	friend istream& operator >> (istream&, Trains&); //���������� ��������� �����
	Trains operator=(const Trains&);  //���������� ��������� ������������
	bool operator==(const Trains&);      //���������� ��������� ���������
	friend ofstream& operator<<(ofstream&, Trains&);//���������� ��������� ������
	friend ifstream& operator >> (ifstream&, Trains&); //���������� ��������� �����
	void showHeader();          //�����, ��������� ��������� ��������
	friend bool compareTime(const Trains*, const Trains*, int);      //�����, ������������ ���� hours
};