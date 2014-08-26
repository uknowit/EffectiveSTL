/*
 * MyClass.hpp
 *
 *  Created on: Aug 19, 2014
 *      Author: shashi
 */

#ifndef MYCLASS_HPP_
#define MYCLASS_HPP_
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <functional>
#include <iostream>
#include <algorithm>

class MyClass {
public:
	MyClass(std::string className):classInstanceName(className){}
	virtual ~MyClass()=0;
	virtual void memberFunc()=0;
	std::string getClassName()const {return classInstanceName;}
private:
	std::string classInstanceName;
};

class MyDerivedClass:public MyClass {
public:
	MyDerivedClass(std::string className):MyClass(className){}
	~MyDerivedClass();
	void memberFunc();

};

template<class T>  class DeleteObject: public std::unary_function<const T*,void>
{
public:
  void operator()(const T* ptr)const{ delete ptr;}
};

template<class T> class CompareMyClass: public std::binary_function<const MyClass*,class MyClass*,bool>
{
public:
	bool operator()(const MyClass* lhs,const MyClass* rhs) const
	{
		if(lhs->getClassName()== rhs->getClassName())
			return true;
		else
			return false;
	}
};

class BadPredicate:public std::unary_function<MyDerivedClass,bool> {
public:
	BadPredicate():timesCalled(0){}
	bool operator()(const MyDerivedClass&)
	{
		std::cout<<"Invoking bad predicate::"<<timesCalled<<std::endl;
		return ++timesCalled==3;
	}
private:
	size_t timesCalled;
};

template<typename FwdIterator,typename predicate> FwdIterator my_remove_if(FwdIterator begin,FwdIterator end,predicate p)
{
	begin=std::find_if(begin,end,p);
	if(begin==end)return begin;
	else
	{
		FwdIterator next=begin;
		return std::remove_copy_if(++next,end,begin,p);
	}
}
#endif /* MYCLASS_HPP_ */
