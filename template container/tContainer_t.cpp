#include "tContainer_t.h"



template<class T, class CONT>
void tContainer_t<T, CONT >  ::print()const{
	T* ptr;
	const_iter_t it = container.cbegin();

	while (it != container.end()){
		ptr = *it++;
		cout << "[*" << ptr << "= " << *ptr << "]";
	}
	cout << endl;
}


template<class T, class CONT>
inline void tContainer_t<T, CONT >  ::insert(T * const &   lmnt){
	container.push_back(lmnt);
}
