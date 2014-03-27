#ifndef TCONTAINER_T_H
#define TCONTAINER_T_H

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;


template<class T, class CONT >
class tContainer_t{

private:
	CONT container;
	std::vector<int> vec;			//for debugging 
	std::list<int>	 lst;			//for debugging

	//container iterator types
	typedef typename CONT::const_iterator const_iter_t;
	typedef typename CONT::iterator iter_t;

	const_iter_t get_const_iter(const T& value)const;

public:


	//default constructor			
	tContainer_t() {}

	//copy constructor
	tContainer_t(const tContainer_t & other);

	//operator = 
	tContainer_t& operator = (const tContainer_t& rhs);

	//operator []	,	retrieve functionality
	T* operator[] (const int& index);

	//operator +=
	tContainer_t& operator+=(tContainer_t& rhs);

	void		print()					const;	//for debugging
	inline int	numOfElements()			const{ return container.size(); }
	inline bool	isempty()				const{ return numOfElements() == 0 }
	inline T*	getFirst()				const{ return container.front(); }
	inline T*	getLast()				const{ return container.back(); }
	inline T*	find(const T& value)	const{ return *get_const_iter(value); }
	void		remove(const T& value)		 { container.erase(get_const_iter(value)); }
	inline void	insert(T * const &   lmnt)	 { container.push_back(lmnt); }
	void		removeAll();

};

#endif