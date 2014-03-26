#include "tContainer_t.cpp"

using namespace std;
int main(){

	int i = 5;
	int* iptr = new int(9);

	tContainer_t<int, vector<int*> > vctContainer;

	vctContainer.print();


	tContainer_t<int, list<int*> > lstContainer;

	lstContainer.print();

	int x;
	cin >> x;

}