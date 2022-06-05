#pragma once
#include "BitString.h"

class Set :
	public BitString
{
public:
	Set();
	Set(const Set& s);
	Set(unsigned long l, unsigned long r);

	Set& operator=(const Set& s);
	Set& operator=(const BitString& b);


	void Exclude(int pos);
	void Include(int pos);
	int Count();
	friend Set Union(Set l, Set r); //obyednannya
	friend Set Intersection(Set l, Set r); //peretyn
	friend Set Substraction(Set l, Set r); //riznycya
};