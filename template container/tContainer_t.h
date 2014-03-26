#ifndef TCONTAINER_T_H
#define TCONTAINER_T_H

#include <vector>
#include <list>
#include <iostream>

using namespace std;


template<class T, class CONT >
class tContainer_t{

private:
	CONT container;
	std::vector<int> vec;			//for debugging 
	std::list<int>	 lst;			//for debugging

	//container iterators
	typedef typename CONT::const_iterator const_iter_t;
	typedef typename CONT::iterator iter_t;

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


	inline int	numOfElements()			const;
	bool		isempty()				const;
	T*			getFirst()				const;
	T*			getLast()				const;
	T*			find(const T& value)	const;
	void		print()					const;			//for debugging
	inline void	insert(T * const &   lmnt);
	void		remove(const T& value);
	void		removeAll();

};


#endif