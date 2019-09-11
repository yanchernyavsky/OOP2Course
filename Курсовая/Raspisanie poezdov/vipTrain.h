#pragma once
#include "Item.h"

class vipTrain : public Item
{
protected:
	string vipCount;               //���������� ���� � VIP �������
public:
	vipTrain();                      //����������� ��� ����������
	vipTrain(const vipTrain&);     //����������� �����������
	vipTrain(string, string, int, int, string);               //����������� � �����������
	~vipTrain();                 //����������
	void setData();                //�����, ������������ ������ ���� ��������
	void showData();               //�����, ��������� ������ ���� ��������
	void showLabel();              //�����, ��������� ���� ��������
	//void setOptional();            //����� ���������� ������������ ������
	friend ostream& operator<<(ostream&, vipTrain&);                 //���������� ������
	friend istream& operator >> (istream&, vipTrain&);               //���������� �����
	friend ofstream& operator<<(ofstream&, vipTrain&);               //���������� ������
	friend ifstream& operator >> (ifstream&, vipTrain&);            //���������� �����
	vipTrain operator=(const vipTrain&);              //���������� ��������� ������������
	bool operator==(const vipTrain&);                  //���������� ��������� ���������
	friend bool compareVipSeat(const vipTrain*,const  vipTrain*, int);               //�����, ������������ ���� vipCount
	void showHeader();             //�����, ��������� ��������� ���� ��������
	void editData();               //�����, ���������� ������ ���� ��������
};
