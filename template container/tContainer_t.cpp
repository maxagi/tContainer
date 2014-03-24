#include "tContainer_t.h"
#include "tContainer_base.cpp"

template<class T>
void tContainer_t<T, list<T*> >  ::print()const{
	cout << "this is a list container" << endl;
}


template<class T>
void tContainer_t<T, vector<T*> >  ::print()const{
	cout << "this is a vector  container" << endl;
}






