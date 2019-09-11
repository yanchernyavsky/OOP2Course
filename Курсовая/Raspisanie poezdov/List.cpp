#include "List.h"

template<class Type>
List<Type>::List()
{
	count = 0;
	begin = NULL;
	end = NULL;
}

template<class Type>
List<Type>::~List()
{
	Line<Type>* tmp = nullptr;
	if (begin != NULL)
	{
		while (begin != NULL)
		{
			tmp = begin->next;
			delete begin;
			begin = tmp;
		}
	}
}

template<class Type>
void List<Type>::push(const Type& obj)
{
	Line<Type>* temp = new Line<Type>;	//Выделение памяти для объекта
	temp->next = NULL;
	Line<Type>* current = nullptr;
	temp->obj = obj;
	count++;
	if (begin != NULL)
	{
		temp->prev = end;
		end->next = temp;
		end = temp;
		current = end;
	}
	else
	{
		temp->prev = NULL;
		begin = end = temp;
	}
}
template<class Type>
void List<Type>::pushBack(const Type& obj)
{
	Line<Type>* current = nullptr;
	Line<Type>* temp = new Line<Type>;
	temp->prev = NULL;
	current = NULL;
	temp->obj = obj;
	count++;
	if (begin != NULL)
	{
		begin->prev = temp;
		temp->next = begin;
		begin = temp;
		current = begin;
	}
	else
	{
		temp->next = NULL;
		begin = end = temp;
	}
}
template<class Type>
void List<Type>::show()
{
	Line<Type>* current = nullptr;
	current = end;
	cout << current->obj << endl;
	while (current->prev != NULL)
	{
		current = current->prev;
		cout << current->obj << endl;
	}
}
template<class Type>
void List<Type>::showBack()
{
	Line<Type>* current = nullptr;
	current = begin;
	cout << current->obj << endl;
	while (current->next != NULL)
	{
		current = current->next;
		cout << current->obj << endl;
	}
}
template<class Type>
Type List<Type>::dellPoint(Line<Type>* obj)
{
	count--;
	Line<Type>* temp, * tempn, data;
	if (obj == begin && obj != end) //Если удаляемый объект является началом списка
	{
		tempn = obj->next;
		tempn->prev = NULL;
		begin = tempn;
		data.obj = obj->obj;
		delete obj;
		return data.obj;
	}
	else if (obj == end && obj != begin)//Если удаляемый объект является концом списка
	{
		temp = obj->prev;
		temp->next = obj->next;
		end = temp;
		data.obj = obj->obj;
		delete obj;
		return data.obj;
	}
	else if (obj == end && obj == begin)   //Если объект является и концом и началом
	{
		temp = obj;
		data.obj = obj->obj;
		delete end;
		end = begin = NULL;
		return data.obj;
	}
	else
	{
		temp = obj->prev;
		tempn = obj->next;
		temp->next = tempn;
		tempn->prev = temp;
		data.obj = obj->obj;
		delete obj;
		return data.obj;
	}
}
template<class Type>
Type List<Type>::dellOne()
{
	if (end == begin)
	{
		count--;
		Line<Type> data;
		data.obj = end->obj;
		delete end;
		end = begin = NULL;
		return data.obj;
	}
	else {
		Line<Type>* current = nullptr;
		count--;
		Line<Type> data;
		current = end->prev;
		current->next = NULL;
		data.obj = end->obj;
		delete end;
		end = current;
		return data.obj;
	}
}
template<class Type>
Type List<Type>::dellOneBack()
{
	if (end == begin)
	{
		count--;
		Line<Type> data;
		data.obj = end->obj;
		delete end;
		end = begin = NULL;
		return data.obj;
	}
	else {
		Line<Type>* current = nullptr;
		Line<Type> data;
		count--;
		current = begin->next;
		current->prev = NULL;
		data.obj = end->obj;
		delete begin;
		begin = current;
		return data.obj;
	}
}
template<class Type>
bool List<Type>::isEmpty()
{
	if (begin != NULL)
	{
		return true;
	}
	else { return false; }
}
template<class Type>
void List<Type>::search(const Type& obj)
{
	int index = 0;
	Line<Type>* current = end;
	while (current != NULL)
	{
		if (current->obj == obj)
		{
			index++;
			if (index == 1)
			{
				current->obj.showHeader();
			}
			cout << current->obj;
		}
		current = current->prev;
	}
	if (index == 0)
	{
		cout << "[ОШИБКА] Элементы с таким именем не существуют" << endl;
	}
}
template<class Type>
Line<Type>* List<Type>::operator[] (int id)
{
	Line<Type>* current = nullptr;
	current = end;
	int index = 1;
	while (id != index)
	{
		if (current->prev != NULL)
		{
			current = current->prev;
		}
		index++;
	}
	return current;
}
template<class Type>
void List<Type>::readFile(string fileName)
{
	ifstream fin(fileName, ios::in);
	Type temp;
	while (fin >> temp)
	{
		this->push(temp);
	}
	fin.close();
}
template<class Type>
void List<Type>::writeFile(string fileName)
{
	ofstream fout(fileName, ios_base::trunc);
	Line<Type>* current = begin;
	while (current != NULL)
	{
		fout << current->obj;
		current = current->next;
	}
	fout.close();
}
template<class Type>
void List<Type>::sort(int trigger, bool(*Compare)(Type*, Type*, int))
{
	Line<Type>* current = end;
	Line<Type>* temp = nullptr;
	for (current; current != NULL; current = current->prev)
	{
		for (temp = end; temp != NULL; temp = temp->prev)
		{
			if ((*Compare)(&current->obj, &temp->obj, trigger))
			{
				swap(current->obj, temp->obj);
			}
		}
	}
}
template<class Type>
void List<Type>::dellAll()
{
	Line<Type>* tmp = nullptr;
	if (begin != NULL)
	{
		while (begin != NULL)
		{
			tmp = begin->next;
			delete begin;
			begin = tmp;
		}
	}
}
template<class Type>
int List<Type>::getCount()
{
	return this->count;
}
