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

class comp{
public:
	bool operator ()(char c){
		return (c <='i' && c >= 'a'); 
	}
};

int main() 
{
	// constractor
	string s1("hello",3); // s1:hel where 3 is size
	string s2(s1,2); // s2: llo where 2 is starting point
	string s3(s1,2,2); // s3: ll
	string s4(5,'a'); // s4: aaaaa
	//string s5('a','b','c'); // s5:"abc"
	
	// string copy 
	string s = "codeforces";
		
	string s2 = string(s.begin(),s.begin()+4); // code
	cout << s2 << endl;
	
	// split string into variable or vector
	string s = "split by space";
	sscanf(s.c_str(),"%c %d %d",&ch,&x,&y);	 
	
	vector<string> result;
	istringstream iss(s);
	for(string s; iss >> s; )
		result.push_back(s);
	
	// size 
	s1 = "Goodbye";
	s1.size(),s1.length(); // gives the size of string
	s1.capacity(); // currently allocated space
	s1.reserve(100); // 100 char are alocated
	s1.shrink_to_fit(); // shirnk the capacity
	s1.resize(9,'x'); // s1: Goodbyexxx
	s1.resize(3);//s1:Goo
	
	//Memeber Function 
	
	s1.at(2) = 'y';// s1: Goydbyexxx
	s1.front(); // 'G'
	s1.back(); // 'x'
	s1.push_back('k'); // s1: Goodbyexxxk
	s1.pop_back(); //// s1: Goodbyexxx
	s1.begin(); // s1[0]
	s1.end(); // s[12]
	
	// Ranged Access
	// assign , append , insert , replace
	s2 = "Things";
	s1.assign(s2, 2, 4); //s1: ings;
	s1.append("def"); // s1 : ingsdef
	s1.insert(0,"Th"); // s1: Thingsdef
	s1.insert(6,"abcd",3); // s1: Thingsabcdef
	
	s1 = "Goodoo";
	s2 = "odBye";
	s1.replace(2,5,s2,0,5); // s1 : GoodBye where 2 is starting point 5 char and 0 is s2 staring and 5 size  
	
	s1.erase(4,3);// s1 : Good
	
	s1.swap(s2); // s1 : obBye , s2: Good
	
	s1 = "Hello i am under cover under shadow";
	size_t found = s1.find("under"); // found == 11
 	found = s1.find("under" ,15); // found  = 23
	
	
	/// Non Memeber Function
	
	//getline(cin,s1,'.');
	
	//conversion
	/** num to string **/
	s1 = to_string(8); // s1 = "8";
	s1 = to_string(2.3e7); // s1 = "23000000.000000" (floot)
	s1 = to_string(0xa4); // s1 = "164"  (hexa)
	s1 = to_string(034); // s1 = "28"
	
	/**  string to number  */
	s1 = "190";
	int i = stoi(s1);
	s1 = "190 monkey";
	size_t pos;
	
	i = stoi(s1,&pos); // i == 190 and pos is the index number 3
	s1 = "a moneky";
	i = stoi(s1 , &pos , 16); // where 16 is hexa base
	
	
	// algorithm ////
	s1 = "life of pie is very intresting";
	int num = count(s1.begin() , s1.end() , 'i'); // num = 5
	
	num = count_if(s1.begin() , s1.end() , comp()); // comp() is a lamda function 
	
	s1 = "Goodness is better the beauty";
	string::iterator itr = search_n(s1.begin() , s1.begin()+20 , 2, 's'); // find 'ss' where 2 is indicate 2 ss 
	s1.erase(itr,itr+2); // remove ss from string
	s1.insert(itr,1,'s');
	s1.replace(itr,itr+3,3,'z'); // Goodnezzzs
	
	replace(s1.begin() ,s1.end() , 'z' ,' '); // Goodne   s better the beauty
	
	s1 = "abcdef";
	rotate(s1.begin() , s1.begin()+3 , s1.end() ); // s1 : "defabc"
	
	cout<<s1<<endl;
	
	
	return 0;
}