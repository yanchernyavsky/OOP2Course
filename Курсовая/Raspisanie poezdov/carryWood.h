#pragma once
#include "Item.h"

class carryWood : public Item
{
protected:
	int amountLenght;                  //����� ����� �������
public:
	carryWood();               //����������� ��� ����������
	carryWood(const carryWood&);                             //����������� �����������
	carryWood(string, string, int, int, int);               //����������� � �����������
	~carryWood() = default;              //����������
	void setData();                    //�����, ������������ ������ ���� ��������
	void showData();                   //�����, ��������� ������ ���� ��������
	void showLabel();                  //�����, ��������� ���� ��������
	void setOptional();                //����� ���������� ������������ ������
	friend ostream& operator<<(ostream&, carryWood&);                 //���������� ������
	friend istream& operator >> (istream&, carryWood&);               //���������� �����
	friend ofstream& operator<<(ofstream&, carryWood&);               //���������� ������
	friend ifstream& operator >> (ifstream&, carryWood&);             //���������� �����
	carryWood operator=(const carryWood&);             //���������� ��������� ������������
	bool operator==(const carryWood&);                  //���������� ��������� ���������
	friend bool compareLong(const carryWood*, const carryWood*, int);             //�����, ������������ ���� amountLenght
	void showHeader();               //�����, ��������� ��������� ���� ��������
	void editData();                 //�����, ���������� ������ ���� ��������
};