/*
 * Item7.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: shashi
 */
#include "MyClass.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <exception>
#include <algorithm>
using std::cout;
using std::endl;

void MyDerivedClass::memberFunc()
{
	cout<<getClassName()<<endl;
	MyClass* classPointer1=new MyDerivedClass("kumar");
	MyClass* classPointer2=new MyDerivedClass("HN");
	std::list<MyClass*> pointerList;
	std::vector<MyDerivedClass> classVector;
	classVector.push_back(MyDerivedClass("A"));
	classVector.push_back(MyDerivedClass("B"));
	classVector.push_back(MyDerivedClass("C"));
	classVector.push_back(MyDerivedClass("D"));
	classVector.push_back(MyDerivedClass("E"));
	classVector.push_back(MyDerivedClass("F"));
	classVector.push_back(MyDerivedClass("G"));
	classVector.erase(my_remove_if(classVector.begin(),classVector.end(),BadPredicate()),classVector.end());
	cout<<"Vector size::"<<classVector.size()<<endl;
	pointerList.push_back(classPointer1);
	pointerList.push_back(classPointer2);
	/*throw 100;
	std::list<MyClass*>::iterator iter=pointerList.begin();
	std::list<MyClass*>::iterator iterEnd=pointerList.end();
	for(;iter!=iterEnd;++iter)
		delete *iter;*/
	std::equal(pointerList.begin(),pointerList.end(),pointerList.begin(),CompareMyClass<MyDerivedClass>());
	std::for_each(pointerList.begin(),pointerList.end(),DeleteObject<MyClass>());


}

MyClass::~MyClass(){}

MyDerivedClass::~MyDerivedClass()
{
	cout<<"Destroying MyDerived class"<<endl;
}
int main()
{
	MyClass* classPointer=new MyDerivedClass("Shashi");
	classPointer->memberFunc();
	delete classPointer;
}

