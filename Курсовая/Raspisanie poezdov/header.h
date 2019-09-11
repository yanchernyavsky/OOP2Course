#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;


bool isFigure(string text);
/*  Шаблонные функции приведения типа  */
template<class Type> bool compareName(Type* t1, Type* t2, int ord)
{
	return compareName(dynamic_cast<const Item*>(t1), dynamic_cast<const Item*>(t2), ord);
}
template<class Type> bool compareType(Type* t1, Type* t2, int ord)
{
	return compareType(dynamic_cast<const Item*>(t1), dynamic_cast<const Item*>(t2), ord);
}
template<class Type> bool comparePrice(Type* t1, Type* t2, int ord)
{
	return comparePrice(dynamic_cast<const Item*>(t1), dynamic_cast<const Item*>(t2), ord);
}
template<class Type> bool compareDate(Type* t1, Type* t2, int ord)
{
	return compareDate(dynamic_cast<const Item*>(t1), dynamic_cast<const Item*>(t2), ord);
}
template<class Type> bool compareTime(Type* t1, Type* t2, int ord)
{
	return compareTime(dynamic_cast<const Item*>(t1), dynamic_cast<const Item*>(t2), ord);
}
template<class Type> bool comparePoint(Type* t1, Type* t2, int ord)
{
	return comparePoint(dynamic_cast<const Trains*>(t1), dynamic_cast<const Trains*>(t2), ord);
}
template<class Type> bool compareavgTimePeriod(Type* t1, Type* t2, int ord)
{
	return compareavgTimePeriod(dynamic_cast<const Item*>(t1), dynamic_cast<const Item*>(t2), ord);
}
template<class Type> bool compareStops(Type* t1, Type* t2, int ord)
{
	return compareStops(dynamic_cast<Diesel*>(t1), dynamic_cast<Diesel*>(t2), ord);
}
template<class Type> bool compareVipSeats(Type* t1, Type* t2, int ord)
{
	return compareVipSeats(dynamic_cast<vipTrain*>(t1), dynamic_cast<vipTrain*>(t2), ord);
}
template<class Type> bool compareTheme(Type* t1, Type* t2, int ord)
{
	return compareTheme(dynamic_cast<exhTrain*>(t1), dynamic_cast<exhTrain*>(t2), ord);
}
template<class Type> bool compareStorage(Type* t1, Type* t2, int ord)
{
	return compareStorage(dynamic_cast<carryWeight*>(t1), dynamic_cast<carryWeight*>(t2), ord);
}
template<class Type> bool compareLenght(Type* t1, Type* t2, int ord)
{
	return compareLenght(dynamic_cast<carryWood*>(t1), dynamic_cast<carryWood*>(t2), ord);
}
template<class Type> bool compareTypeSpeed(Type* t1, Type* t2, int ord)
{
	return compareTypeSpeed(dynamic_cast<SpeedTrain*>(t1), dynamic_cast<SpeedTrain*>(t2), ord);
}
