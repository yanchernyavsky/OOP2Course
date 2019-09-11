#pragma once
#include "Item.h"

class carryWeight : public Item
{
protected:
	int amountLoaded;                  //���������� ������� � ������
public:
	carryWeight();               //����������� ��� ����������
	carryWeight(const carryWeight&);                             //����������� �����������
	carryWeight(string, string, int, int, int);               //����������� � �����������
	~carryWeight() = default;            //����������
	void setData();                    //�����, ������������ ������ ���� ��������
	void showData();                   //�����, ��������� ������ ���� ��������
	void showLabel();                  //�����, ��������� ���� ��������
	void setOptional();                //����� ���������� ������������ ������
	friend ostream& operator<<(ostream&, carryWeight&);                 //���������� ������
	friend istream& operator >> (istream&, carryWeight&);               //���������� �����
	friend ofstream& operator<<(ofstream&, carryWeight&);               //���������� ������
	friend ifstream& operator >> (ifstream&, carryWeight&);             //���������� �����
	carryWeight operator=(const carryWeight&);             //���������� ��������� ������������
	bool operator==(const carryWeight&);                  //���������� ��������� ���������
	friend bool compareTimeStorage(const carryWeight*, const carryWeight*, int);             //�����, ������������ ���� amountLoaded
	void showHeader();               //�����, ��������� ��������� ���� ��������
	void editData();                 //�����, ���������� ������ ���� ��������
};