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

template<class T, class CONT>
T* tContainer_t<T, CONT>::operator[](const int& index){

	if (index<0 || index>this->numOfElements() - 1)
		return 0;

	const_iter_t it = this->container.begin();
	advance(it, index);

	return *it;
}



template<class T, class CONT>
void tContainer_t<T, CONT>::removeAll(){
	int size = numOfElements();
	for (int i = 0; i < size; i++)
		container.pop_back();
}



template<class T, class CONT>
inline int tContainer_t<T, CONT>::numOfElements()const {
	return container.size();
}