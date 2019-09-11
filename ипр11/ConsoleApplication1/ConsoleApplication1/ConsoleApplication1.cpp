// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "queue.h" // подключаем шаблон класса

using namespace std;



int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	Queue<char> myQueue(14); // объект класса очередь

	myQueue.printQueue(); // вывод очереди

	int ct = 1;
	char ch;

	// добавление элементов в очередь
	while (ct++ < 14)
	{
		cin >> ch;
		myQueue.enqueue(ch);
	}

	myQueue.printQueue(); // вывод очереди

	// удаление элемента из очереди
	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.dequeue();

	myQueue.printQueue(); // вывод очереди

	cout << "\n\nСработал конструктор копирования:\n";
	Queue<char> newQueue(myQueue);

	newQueue.printQueue(); // вывод очереди

	return 0;
}
