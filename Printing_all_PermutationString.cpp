#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include<bitset>
using namespace std;
void bin(int n,char* A)
{
    if(n<1){
        cout<<endl<<A;
    }
    else{
        A[n-1]='0';
        bin(n-1,A);
        A[n-1] = '1';
        bin(n-1,A);
    }
}


int main()
{
    char A[11];
    int n;
    cin>>n;
    A[n]='\0';
    bin(n,A);

    return 0;
}
