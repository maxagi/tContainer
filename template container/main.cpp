#include "tContainer_t.cpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

#define max 1
using namespace std;

//Type of container & content
//Note: should be replaced before running the main according to the needs
typedef int T;
typedef deque<T *> CONT;

//Members
int continerNumber, index;
T* result;
tContainer_t <T, CONT> container1, container2;
list<T *> values1, values2;


//Methods decelerations
void GetContainerNumber();
tContainer_t<T, CONT>& GetContainer();
list<T *> &GetValuesList(int i);


int main(int argc, int **argv){
#ifndef husam
	int i = 13;
	int* iptr = new int(9);
	int* iptr2 = new int(11);
	int* iptr3 = new int(13);



	tContainer_t<int, vector<int*> > vctContainer;
	vctContainer.insert(iptr);
	vctContainer.insert(iptr2);
	vctContainer.insert(iptr3);
	vctContainer.print();

	tContainer_t<int, vector<int*> > vctContainer2 = vctContainer;

	vctContainer2.print();
	tContainer_t<int, vector<int*> > vctContainer3;

	vctContainer3.insert(iptr2);
	vctContainer3 = vctContainer;
	vctContainer3.print();

	vctContainer3 += vctContainer2;
	vctContainer3.print();

	vctContainer2.insert(iptr2);
	vctContainer2.print();


	int x;
	cin >> x;

#endif

#ifdef husam

	char answer;
	T *v;
	T value;
	bool cont = true;
	int i;

	while (cont)
	{
		cout << "*** Enter your choise: ****" << endl
			<< "1- is Empty?" << endl
			<< "2 - return number of elements in container" << endl
			<< "3 - insert a new element at end of container" << endl
			<< "4 - return first element in container" << endl
			<< "5 - return last element in container" << endl
			<< "6 - find specific element by value" << endl
			<< "7 - remove specific element" << endl
			<< " 8 - remove all elements" << endl
			<< "9 - operator[]" << endl
			<< "10 - merger of 2 containers" << endl
			<< "11 - exit" << endl;

		cin >> i;

		cout << endl;

		switch (i)
		{
			//is Empty?
		case 1:
			cout << "container 1 is " << (container1.isempty() ? "empty" : "not empty") << endl
				<< "container 2 is " << (container2.isempty() ? "empty" : "not empty") << endl
				<< endl;
			break;
			//number of elements in container
		case 2:
			cout << "container 1 has " << container1.numOfElements() << " elements" << endl
				<< "container 2 has " << container2.numOfElements() << " elements" << endl
				<< endl;
			break;
			//insert a new element at end of container
		case 3:
			GetContainerNumber();
			cout << "enter value: " << endl;
			v = new T;
			cin >> *v;

			GetContainer().insert(v);
			GetValuesList(continerNumber).push_back(v);

			break;
			//return first element in container
		case 4:
			GetContainerNumber();
			cout << "first element in container : " << *GetContainer().getFirst() << endl;
			break;
			//return last element in container
		case 5:
			GetContainerNumber();
			cout << "last element in container : " << *GetContainer().getLast() << endl;
			break;
			//find specific element by value
		case 6:
			GetContainerNumber();
			cout << "Enter value to find: " << endl;
			cin >> value;

			result = GetContainer().find(value);
			if (*result == value){
				cout << "Element found" << endl;
			}
			else{
				cout << "Element not found" << endl;
			}
			break;
			//remove specific element
		case 7:
			GetContainerNumber();
			cout << "Enter value to remove: " << endl;
			cin >> value;

			GetContainer().remove(value);
			cout << "Element removed" << endl;

			//Remove address in values vector in order to remove it
			GetValuesList(continerNumber).remove(result);
			delete result; //free memory
			break;

			//remove all
		case 8:
			GetContainerNumber();
			GetContainer().removeAll();
			//free memory of the values vector
			for (list<T *>::iterator it = GetValuesList(continerNumber).begin(); it != GetValuesList(continerNumber).end(); it++){
				delete *it;
			}
			//clear the value list
			GetValuesList(continerNumber).clear();
			break;
			//operator[]
		case 9:
			GetContainerNumber();
			cout << "Enter index: " << endl;
			cin >> index;
			cout << "Enter value: " << endl;
			cin >> value;

			if (index >= GetContainer().numOfElements()){
				cout << "error: illegal index" << endl;
				break;
			}

			*GetContainer()[index] = value;
			break;
			//merger of 2 containers
		case 10:
			//free memory of the container 2 values vector
			for (list<T *>::iterator it = GetValuesList(2).begin(); it != GetValuesList(2).end(); it++){
				GetValuesList(1).push_back(*it);
			}
			//free memory of the container 2 values vector
			GetValuesList(2).clear();
			//merge containers
			container1 += container2;
			cout << "container merged" << endl;
			break;
		case 11:
			//free the memory of the value vectors
			for (list<T *>::iterator it = GetValuesList(1).begin(); it != GetValuesList(1).end(); it++){
				v = *it;
				delete v;
			}
			for (list<T *>::iterator it = GetValuesList(2).begin(); it != GetValuesList(2).end(); it++){
				v = *it;
				delete v;
			}

			//delete elements of value vector
			values1.clear(); values2.clear();

			cout << "do you really want to exit? (y/n)" << endl;
			cin >> answer;
			if (answer == 'n'){
				break;
			}
			exit(1);
			break;
		}
	}
#endif // !1
	return 1;
}

//Method Implementations

void GetContainerNumber(){
	cout << "choose container 1 or 2: " << endl;
	cin >> continerNumber;
}

tContainer_t<T, CONT>& GetContainer()
{
	if (continerNumber == 2)
	{
		return container2;
	}
	else{
		return container1;
	}
}

list<T *> &GetValuesList(int i){

	if (i == 2){
		return values2;
	}
	else
		return values1;

}