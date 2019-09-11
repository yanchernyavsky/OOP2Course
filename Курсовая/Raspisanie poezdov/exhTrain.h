#pragma once
#include "vipTrain.h"

class exhTrain : public vipTrain
{
protected:
	string descExh;               //�������� ��������
public:
	exhTrain();                              //����������� ��� ����������
	exhTrain(const exhTrain&);            //����������� �����������
	exhTrain(string, string, int, int, string, string);          //����������� � �����������
	~exhTrain();               //����������
	void setData();               //�����, ���������� ������ ���� ��������
	void showData();              //�����, ��������� ������ ���� ��������
	void showLabel();             //�����, ��������� ���� ��������
	void setOptional();           //����� ���������� ������������ ������
	friend ostream& operator<<(ostream&, exhTrain&);                 //���������� ������
	friend istream& operator >> (istream&, exhTrain&);               //���������� ����� 
	friend ofstream& operator<<(ofstream&, exhTrain&);               //���������� ������ 
	friend ifstream& operator >> (ifstream&, exhTrain&);             //���������� �����
	exhTrain operator=(const exhTrain&);                    //���������� ��������� ������������ 
	bool operator==(const exhTrain&);                       //���������� ��������� ���������
	friend bool comparedescExh(const exhTrain*, const exhTrain*, int);     //�����, ������������ ���� descExh
	void showHeader();             //�����, ��������� ��������� ���� ��������
	void editData();               //�����, ���������� ������ ���� ��������
};