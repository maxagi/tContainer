#include "tContainer_t.cpp"

using namespace std;
int main(){

	int i = 5;
	int* iptr = new int(9);
	int* iptr2 = new int(11);
	int* iptr3 = new int(13);



	tContainer_t<int, vector<int*> > vctContainer;
	vctContainer.insert(iptr);
	vctContainer.insert(iptr2);
	vctContainer.insert(iptr3);
	vctContainer.print();
	cout << vctContainer.find(i) << endl;
	vctContainer.remove(11);
	vctContainer.print();



	cout << endl;

	tContainer_t<int, list<int*> > lstContainer;
	lstContainer.insert(iptr);
	lstContainer.insert(iptr2);
	lstContainer.insert(iptr3);
	
	lstContainer.print();
	cout << lstContainer.find(i) << endl;
	lstContainer.remove(9);
	lstContainer.print();


	int x;
	cin >> x;

}