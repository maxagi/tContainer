#ifndef TCONTAINER_T_H
#define TCONTAINER_T_H

#include "tContainer_base.h"


using namespace std;


template<class T, class CONT >
class tContainer_t : public tContainer_base<T, CONT> {
	//nothing should be here 
};





//---------------specialization for vector & list ---------------/

template<class T>
class tContainer_t<T, vector<T*> > :public tContainer_base<T, vector<T*> >{
public:
	//default constructor 
	tContainer_t() :tContainer_base(){}

	//print
	void print()const;
};



template<class T>
class tContainer_t<T, list<T*> > :public tContainer_base<T, list<T*> >{
public:
	//default constructor 
	tContainer_t() :tContainer_base(){}

	//print
	void print()const;

};




#endif 