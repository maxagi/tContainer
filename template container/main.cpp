#include "tContainer_t.cpp"

using namespace std;
int main(){

	int i = 5;
	int* iptr = new int(9);
	int* iptr2 = new int(11);

	tContainer_t<int, vector<int*> > vctContainer;
	vctContainer.insert(iptr);
	vctContainer.insert(iptr2);
	vctContainer.print();


	tContainer_t<int, list<int*> > lstContainer;
	lstContainer.insert(iptr);
	lstContainer.insert(iptr2);
	lstContainer.print();

	int x;
	cin >> x;

}