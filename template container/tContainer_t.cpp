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



template<class Type>
class Pred{
private:
	Type value;
public:
	Pred(Type _value) :value(_value){}
	bool operator()(Type* lmnt){
		return *lmnt == value;
	}
};


template<class T, class CONT>
typename CONT::const_iterator  tContainer_t<T, CONT >  ::get_const_iter(const T& value)const {
	return find_if(container.begin(), --container.end(), Pred<T>(value));
}
