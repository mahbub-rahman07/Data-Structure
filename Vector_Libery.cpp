#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <list>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

// Lamda function : in c++3
class Less{
public:
	bool operator()(int x){
		return (x>10);
	}
};

class Mx{
	public:
		bool operator()(int x,int y){
			return (x>10 && y<90);
		}
	};

// in c++11 lamda function [],(int x){return x<10;}
int main() 
{
	/*** Vector ***/
	
	vector<int> vec;
	vec.push_back(9);
	vec.push_back(69);
	vec.push_back(69);
	vec.push_back(45);
	vec.push_back(87);
	vec.push_back(90);
	
	
/** Count Function **/	
	int n = count(vec.begin(), vec.end(), 90);	
	int m = count_if(vec.begin()+1, vec.end()-1, Less()
	);
	cout<<"Count Number Of same Element : "<<n<<" conditional : "<<m<<endl;
	
/** Min & Max Function **/
	
	pair<vector<int>::iterator , vector<int>::iterator > pit;
	vector<int>::iterator it; // we need ierator as our vector type
	
	it = max_element(vec.begin(), vec.end());
	cout<<"max element is : "<<(*it)<<endl;
	
	pit = minmax_element(vec.begin(), vec.end(),Mx());
	cout<<"max element and min (x>10 &y<90) : "<<(*pit.second)<<" "<<(*pit.first)<<endl;
	
	it = min_element(vec.begin(), vec.end());
	cout<<"min element : "<<(*it)<<endl;
	
/** Linear Search **/
	it = find(vec.begin(), vec.end(), 87);
	int pos = find(vec.begin(), vec.end(), 87)-vec.begin();
	// if pos > vec.size() not found other wise pos = index of 87
	cout<<"found item "<<(*it)<<endl;
	
//	it = find_if(vec.begin(), vec.end(), [](int x){ return x>80 ;});
//	it = find_if_not(vec.begin(), vec.end(), [](int x){ return x>80 ;});
	vector<int >sub;
	sub.push_back(45);
	sub.push_back(87);
	sub.push_back(90);
	
	it = search(vec.begin(), vec.end(), sub.begin(), sub.end());
	cout<<"Sub vec : "<<(*it)<<endl;
	
//	it = search_end(vec.begin(), vec.end(), sub.begin(), sub.end());
	
	it = search_n(vec.begin(),vec.end() , 2, 69);
	cout<<"Found perticular item : "<<(*it)<<endl;
	
/** sort **/
	bool is = is_sorted(vec.begin(), vec.end());
	cout<<"List is sorte ? "<<(is == 0 ? "No":"Yes")<<endl;
	it = is_sorted_until(vec.begin(), vec.end());
	cout<<"item is not sorted "<<(*it)<<endl;
	
	
/**  Copy  */

	vector<int>vec2(3,0);
	
	copy(sub.begin(),// source 
	 sub.end(),// unti
	 vec2.begin()); // desination
	//copy_if(source, untill, dest, condition);
	//copy_n(source, items No,destination);
	for(x : vec2){ cout<<x<<" ";} cout<<" copy"<<endl; // print 

/**   Renove */
		
		remove(vec2.begin(),vec2.end() ,45);
		for(x : vec2){ cout<<x<<" ";} cout<<" removed"<<endl;


/**  Replace */

	replace_if(vec2.begin(),//source 
	vec2.end(),//untill
	Less(), // condition
	10		//  new value 
	);
	for(x : vec2){ cout<<x<<" ";} cout<<" replace"<<endl;

/**   Unique Not very succesive :( */
	unique(vec.begin(),vec.end());
	
	unique(vec.begin(),vec.end(),less<int>());
	for(x : vec){ cout<<x<<" ";} cout<<" Uniqued"<<endl;

/*** rotate **/
	rotate(vec.begin(),vec.begin()+(n- (roatetime % n)),// from
	vec.end());						// to
	for(x : vec){ cout<<x<<" ";} cout<<" Rotated"<<endl;
	
/*        random    **/
	random_shuffle(vec.begin(),vec.end());
	for(x : vec){ cout<<x<<" ";} cout<<" Random"<<endl;
/*				lowerBound and Upper Bound  */	
cout << vec[lower_bound(all(vec),lower)-vec.begin()]<<endl;
	
	return 0;
}