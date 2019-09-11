#pragma once
#include "Trains.h"

class Electro : public Trains
{
protected:
	int waypointTime;                            //����� ����� �����������
public:
	Electro();                              //����������� ��� ����������
	Electro(const Electro&);           //����������� �����������
	Electro(string, string, int, int, int, int);         //����������� � �����������
	~Electro();                                               //����������
	void setData();                //�����, ������������ ���� ��������
	void showData();               //�����, ��������� ������ ���� ��������
	void showLabel();              //�����, ��������� ���� ��������
	void setOptional();
	friend ostream& operator<<(ostream&, Electro&);               //���������� ������
	friend istream& operator >> (istream&, Electro&);             //���������� �����
	friend ofstream& operator<<(ofstream&, Electro&);             //���������� ������
	friend ifstream& operator >> (ifstream&, Electro&);           //���������� �����
	Electro operator=(const Electro&);           //���������� ��������� ������������
	bool operator==(const Electro&);             //���������� ��������� ���������
	friend bool compareWpTime(const Electro*, const Electro*, int);               //�����, ������������ ���� waypointTime
	void showHeader();               //�����, ������������ ��������� ��������
	void editData();                 //�����, ���������� ������ ���� ��������
};