#include "tContainer_t.h"

 //---------------------------------------------------------------print
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

//------------------------------------------------------------copy CTOR
template<class T, class CONT >
tContainer_t<T, CONT> ::tContainer_t(const tContainer_t & other)	 {
	this->container.insert(this->container.begin(),
		other.container.cbegin(), other.container.cend());
}

//----------------------------------------------------------operator []
template<class T, class CONT>
T* tContainer_t<T, CONT>::operator[](const int& index){

	if (index<0 || index>this->numOfElements() - 1)
		return 0;

	const_iter_t it = this->container.begin();
	advance(it, index);

	return *it;
}

//-----------------------------------------------------------operator+=
template<class T, class CONT>
void tContainer_t<T, CONT>::operator+=(tContainer_t<T, CONT>& rhs){
	container.insert(container.end(), rhs.container.begin(), rhs.container.end());
	rhs.removeAll();
}

//------------------------------------------------------------operator=
template<class T, class CONT >
tContainer_t<T, CONT>&  tContainer_t<T, CONT>:: operator = (const tContainer_t& rhs){
	this->removeAll();
	this->container.insert(this->container.begin(), rhs.container.cbegin(), rhs.container.cend());
	return *this;
}

//------------------------------------------------------------removeAll
template<class T, class CONT>
void tContainer_t<T, CONT>::removeAll(){
	int size = numOfElements();
	for (int i = 0; i < size; i++)
		container.pop_back();
}

//-------------------------------------------------------get_const_iter
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
	return find_if(container.begin(), container.end(), Pred<T>(value));
}

//-----------------------------------------------------------------find
template<class T, class CONT>
T*	tContainer_t<T, CONT>::find(const T& value)const{
	const_iter_t position = get_const_iter(value);
	return position == container.cend() ? 0 : *position;
}

//---------------------------------------------------------------remove
template<class T, class CONT>
void  tContainer_t<T, CONT>::remove(const T& value){
	const_iter_t position = get_const_iter(value);
	if (position != container.cend())
		container.erase(position);
}