#ifndef TCONTAINER_BASE_H
#define TCONTAINER_BASE_H

#include <vector>
#include <list>
#include <iostream>

using namespace std;


template<class T, class CONT >
class tContainer_base{

private:
	CONT container;
	std::vector<int> vec;			//for debugging 

protected:

	//default constructor			//don't allow users to instantiate base class objects
	tContainer_base() {}

public:

	//copy constructor
	tContainer_base(const tContainer_base & other);

	//operator = 
	tContainer_base& operator = (const tContainer_base& rhs);

	//operator [] 
	tContainer_base& operator[] (const int index);

	//operator +=
	tContainer_base operator+=(tContainer_base& rhs);


	int		numOfElements()			const;
	bool	isempty()				const;
	T*		getFirst()				const;
	T*		getLast()				const;
	T*		find(const T& value)	const;
	void	print()					const;			//for debugging
	void	insert(T const * lmnt);
	void	remove(const T& value);
	void	removeAll();

};


#endif