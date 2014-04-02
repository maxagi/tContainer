#include "tContainer_t.cpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

//Type of container & content
//Note: should be replaced before running the main according to the needs
typedef int T;
typedef deque<T *> CONT;

int continerNumber;
tContainer_t <T, CONT> container1, container2;
list<T *> values1, values2;


//Methods decelerations
void getContainerNum();
tContainer_t<T, CONT>& GetContainer();
list<T *> &GetValuesList(int i);


int main(int argc, int **argv){
	char answer;
	T *v;
	T* result;
	T value;
	bool cont = true, found = true;
	int i, index;

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
			<< "8 - remove all elements" << endl
			<< "9 - operator[]" << endl
			<< "10 - merger of 2 containers" << endl
			<< "11 - operator =" << endl
			<< "12 - exit" << endl;

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
			getContainerNum();
			cout << "enter value: " << endl;
			v = new T;
			cin >> *v;

			GetContainer().insert(v);
			GetValuesList(continerNumber).push_back(v);

			break;
			//return first element in container
		case 4:
			getContainerNum();
			if (GetContainer().numOfElements() <= 0)
				cout << "error: container is empty!" << endl;
			else
				cout << "first element in container : " << *GetContainer().getFirst() << endl;
			break;
			//return last element in container
		case 5:
			getContainerNum();
			if (GetContainer().numOfElements() == 0)
				cout << "error: container is empty!" << endl;
			else
				cout << "last element in container : " << *GetContainer().getLast() << endl;
			break;
			//find specific element by value
		case 6:
			getContainerNum();
			cout << "Enter value to find: " << endl;
			cin >> value;

			found = GetContainer().find(value);
			if (found){
				cout << "Element found" << endl;
			}
			else{
				cout << "Element not found" << endl;
			}
			break;
			//remove specific element
		case 7:
			getContainerNum();

			cout << "Enter value to remove: " << endl;
			cin >> value;
			found = GetContainer().find(value);
			if (!found){
				cout << "error: Element not found" << endl;
			}
			else{
				GetContainer().remove(value);
				cout << "Element removed" << endl;
			}
			break;

			//remove all
		case 8:
			getContainerNum();
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
			getContainerNum();
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
			//operator =
		case 11:
			container1 = container2;
			break;
		case 12:
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
		default:
			cout << "Wrong choice" << endl;
			break;
		}
	}
	return 1;
}

//Method Implementations

void getContainerNum(){
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