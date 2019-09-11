#pragma once
#include <cassert>
#include <iostream>

template<typename T>
class Queue
{
private:
	T* queuePtr;     // ��������� �� �������
	const int size;  // ������������ ���������� ��������� � �������
	int begin,       // ������ �������
		end;         // ����� �������
	int elemCT;      // ������� ���������
public:
	Queue(int = 10);          // ����������� �� ���������
	Queue(const Queue<T>&); // ����������� �����������
	~Queue();                // ����������

	void enqueue(const T&); // �������� ������� � �������
	T dequeue(); // ������� ������� �� �������
	void printQueue();
};

// ���������� ������� ������� ������ Queue

// ����������� �� ���������
template<typename T>
Queue<T>::Queue(int sizeQueue) :
	size(sizeQueue), // ������������� ���������
	begin(0), end(0), elemCT(0)
{
	// �������������� ������� ������� ��� ��������� ����� � ������ �������
	queuePtr = new T[size + 1];
}

// ����������� �����
template<typename T>
Queue<T>::Queue(const Queue& otherQueue) :
	size(otherQueue.size), begin(otherQueue.begin),
	end(otherQueue.end), elemCT(otherQueue.elemCT),
	queuePtr(new T[size + 1])
{
	for (int ix = 0; ix < size; ix++)
		queuePtr[ix] = otherQueue.queuePtr[ix]; // �������� �������
}

// ���������� ������ Queue
template<typename T>
Queue<T>::~Queue()
{
	delete[] queuePtr;
}

// ������� ���������� �������� � �������
template<typename T>
void Queue<T>::enqueue(const T& newElem)
{
	// ���������, ���� �� ��������� ����� � �������
	assert(elemCT < size);

	// ������� �������� ����������� � 0 �������
	queuePtr[end++] = newElem;

	elemCT++;

	// �������� ��������� ���������� �������
	if (end > size)
		end -= size + 1; // ���������� end �� ������ �������
}

// ������� �������� �������� �� �������
template<typename T>
T Queue<T>::dequeue()
{
	// ���������, ���� �� � ������� ��������
	assert(elemCT > 0);

	T returnValue = queuePtr[begin++];
	elemCT--;

	// �������� ��������� ���������� �������
	if (begin > size)
		begin -= size + 1; // ���������� begin �� ������ �������

	return returnValue;
}

template<typename T>
void Queue<T>::printQueue()
{
	std::cout << "�������: ";

	if (end == 0 && begin == 0)
		std::cout << " ������\n";
	else
	{
		for (int ix = end; ix >= begin; ix--)
			std::cout << queuePtr[ix] << " ";
		std::cout << endl;
	}
}
