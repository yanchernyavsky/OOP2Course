#pragma once
#include "vipTrain.h"

class SpeedTrain : public vipTrain
{
protected:
	int maxSpeed;               //����������� ����������� ��������
public:
	SpeedTrain();                   //����������� ��� ����������
	SpeedTrain(const SpeedTrain&);										//����������� �����������
	SpeedTrain(string, string, int, int, string, int);               //����������� � �����������
	~SpeedTrain();                  //����������
	void setData();                 //�����, ������������ ������ ���� ��������
	void showLabel();               //�����, ��������� ���� ��������
	void showData();                //�����, ��������� ������ ���� ��������
	void setOptional();             //����� ���������� ������������ ������
	friend ostream& operator<<(ostream&, SpeedTrain&);                 //���������� ������
	friend istream& operator >> (istream&, SpeedTrain&);               //���������� �����
	friend ofstream& operator<<(ofstream&, SpeedTrain&);               //���������� ������
	friend ifstream& operator >> (ifstream&, SpeedTrain&);             //���������� �����
	SpeedTrain operator=(const SpeedTrain&);		 //���������� ��������� ������������
	bool operator==(const SpeedTrain&);      	   //���������� ��������� ���������
	void showHeader();               //�����, ��������� ��������� ���� ��������
	void editData();                 //�����, ���������� ������ ���� ��������
	friend bool compareTypeSpeed(const SpeedTrain*, const SpeedTrain*, int);               //�����, ������������ ���� maxSpeed
};