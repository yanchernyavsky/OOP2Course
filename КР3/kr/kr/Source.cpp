#include <iostream>
using namespace std;
template <class T>
class Circle
{
	struct Node
	{
		T data;
		Node* next;
	};
protected:
	Node* last; // ��������� �� ��������� �������
public:
	Circle();    // ����������� �� ���������
	Circle(T);  // ����������� � �����������
	Circle(const Circle&); // ����������� �����������
	~Circle();    // ����������
	void addItem(T);
	void print() const;
	void find(T) const;
};
template <class T>
Circle <T>::Circle() :last(NULL)
{
	// ������ �� �������� ���������
}
template <class T>
Circle<T>::Circle(T data)
{
	last = new Node;
	last->data = data;
	last->next = last;
}
template <class T>
Circle<T>::Circle(const Circle& circle)
{
	last = NULL;
	if (circle.last != NULL)
	{
		Node* cur = circle.last->next;
		while (cur != circle.last) // �������� �������� ���� �� ������ �� ����������
		{
			this->addItem(cur->data);
			cur = cur->next;
		}
		// ����������� ���������� ��������
		this->addItem(circle.last->data);
	}
}
template <class T>
Circle<T>::~Circle()
{
	Node* temp, *cur;
	// �������� ��������� � ������������ ��������
	if (last != NULL) // ���� ������ �������� ��������
	{
		cur = last->next;
		last->next = NULL;    // ��������� ������
		while (cur)
		{
			temp = cur;
			cur = cur->next;
			delete temp;
		}
	}
}
template <class T>
void Circle<T>::addItem(T data)
{
	// ���� ����������� ����� �������
	if (last == NULL)
	{
		last = new Node;
		last->next = last;
		last->data = data;
	}
	else // ���������� ������� � ����������� ���������
	{
		Node* oldLast = last;
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = last->next;
		last = newNode;
		oldLast->next = newNode;
	}
}
template <class T>
void Circle<T>::print() const
{
	if (last != NULL)    // ���� ������ �� ������
	{
		Node* cur = last->next;
		while (cur != last) // ������� �������� ���� �� ������ �� ����������
		{
			std::cout << cur->data << "  ";
			cur = cur->next;
		}
		// ����� ���������� ��������
		std::cout << last->data << endl;
	}
}
template <class T>
void Circle<T>::find(T pattern) const
{
	int c = 0;
	if (last != NULL)    // ���� ������ �� ������
	{
		Node* cur = last->next;
		while (cur != last) // ���������� �������� ���� �� ������ �� ����������
		{
			if (cur->data == pattern)
				std::cout << "���������� ������� � " << c << " �������� ������\n";
			cur = cur->next;
			c++;
		}
		// ��������� �������� �������
		if (last->data == pattern)
			std::cout << "���������� ������� � " << c << " �������� ������\n";
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Circle <int> c1;
	c1.addItem(15);
	c1.addItem(30);
	c1.addItem(15);
	c1.addItem(7);

	std::cout << "����� ��������� ������ c1: ";
	c1.print();
	// �������� ������� �2 � �������������� ������������ �����������
	Circle <int> c2 = c1;
	c2.addItem(99);
	c2.addItem(15);
	std::cout << "����� ��������� ������ c2: ";
	c2.print();
	std::cout << "����� ��������� ������ �2, ���������� ����� 15:\n";
	c2.find(15);
	system("pause");
	return 0;
}
