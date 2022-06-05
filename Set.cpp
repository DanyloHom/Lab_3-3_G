#include "Set.h"
#include <iostream>

using namespace std;

Set::Set()
{
	setFirst(0);
	setSecond(0);
}

Set::Set(const Set& s)
{
	setFirst(s.getFirst());
	setSecond(s.getSecond());
}

Set::Set(unsigned long l, unsigned long r)
{
	setFirst(l);
	setSecond(r);
}


Set& Set::operator=(const Set& s)
{
	setFirst(s.getFirst());
	setSecond(s.getSecond());

	return *this;
}

Set& Set::operator=(const BitString& b)
{
	setFirst(b.getFirst());
	setSecond(b.getSecond());

	return *this;

}


void Set::Exclude(int pos)
{
	if (pos <= 32)
		setFirst(getFirst() & ~(~(~0 << 1) << pos));
	if (pos > 32 && pos <= 64)
		setSecond(getSecond() & ~(~(~0 << 1) << pos));
	else cout << "wrong argument" << endl;
}

void Set::Include(int pos)
{
	if (pos <= 32)
		setFirst(getFirst() | ~(~0 << 1) << pos);
	if (pos > 32 && pos <= 64)
		setSecond(getSecond() | ~(~0 << 1) << pos);
	else cout << "wrong argument" << endl;
}

int Set::Count()
{
	int count = 0;
	unsigned long l = getFirst();
	unsigned long r = getSecond();

	while (l) {             //poky l ne stane 0
		count += l & 1;		//dodayemo do count kzhnu odynychku
		l >>= 1;			//rozglyadaemo nastypnyi bit
	}

	while (r) {				//poky r ne stane 0
		count += r & 1;		//dodayemo do count kzhnu odynychku
		r >>= 1;			//rozglyadaemo nastypnyi bit
	}

	return count;
}



Set Union(Set l, Set r)
{
	Set A;
	A = Or(l, r);

	return A;
}


Set Intersection(Set l, Set r)
{
	Set A;
	A = And(l, r);

	return A;
}

Set Substraction(Set l, Set r)
{
	Set A;
	A = XOr(l, r);

	return A;

}