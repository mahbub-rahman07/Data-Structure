#include <iostream>
#include <string>
#include <list>
using namespace std;
int main(int argc, char *argv[]) {
	
	list <int> mylist(5,0);// {0,0,0,0,0}
	
	list<int>::iterator it1 = mylist.begin();
	
	advance(it1,2); // jumping to index 2
	*it1 = 10;
	list<int>::iterator it;
	
	for(it=mylist.begin();it != mylist.end();it++){
		cout<<(*it)<<" ";
	}
	
	cout<<"\n--------Insert-------"<<endl;
	
	list<int>::iterator Insert = mylist.begin();
	advance(Insert, 3);
	mylist.insert(Insert,11);
	advance(Insert, 4);
	mylist.erase(Insert);
	
	//mylist.assign(2,15 ); {15,15 }
	/**
	mylist.push_front(25)
	mylist.pop_front();
	mylist.front();
	mylist.back();
	mylist.remove(2);
	mylist.unique();
	mylist.marge(list1);
	
	*/
	mylist.push_front(25);
	mylist.unique();
	for(it=mylist.begin();it != mylist.end();it++){
		cout<<(*it)<<" ";
	}
	
	return 0;
}