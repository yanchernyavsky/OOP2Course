#include "Interface.h"

template<class Type>
Interface<Type>::Interface() { }

template<class Type>
Interface<Type>::Interface(const Type& obj)
{
	this->obj = obj.obj;
}

template<class Type>
Interface<Type>::~Interface() = default;