#pragma once
#include "Trains.h"

class Diesel : public Trains
{
protected:
	string addStops;               //���������� ��������� �� ���� ���������� (��� �����������, ������������ �� �������������� ���������)
public:
	Diesel();                          //����������� ��� ����������
	Diesel(const Diesel&);          //����������� �����������
	Diesel(string, string, int, int, int, string);               //����������� � �����������
	~Diesel();                 //����������
	void setData();               //�����, ������������ ������ ���� ��������
	void showData();              //�����, ��������� ������ ���� ��������
	void setOptional();           //����� ���������� ������������ ������
	void editData();              //�����, ���������� ������ ���� ��������
	void showLabel();             //�����, ������������ ���� ��������
	friend ostream& operator<<(ostream&, Diesel&);                 //���������� ������
	friend istream& operator >> (istream&, Diesel&);               //���������� �����
	friend ofstream& operator<<(ofstream&, Diesel&);               //���������� ������
	friend ifstream& operator >> (ifstream&, Diesel&);             //���������� �����
	Diesel operator=(const Diesel&);           //���������� ��������� ������������ ��������
	bool operator==(const Diesel&);               //���������� ��������� c��������
	void showHeader();                               //�����, ��������� ��������� ���� ��������
	friend bool compareStops(const Diesel*, const Diesel*, int);               //�����, ������������ ���� additionalStops
};