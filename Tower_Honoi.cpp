#include<iostream>
using namespace std;
void TOH(int n,char b,char a,char e)
{
    if(n>=1){
        TOH(n-1,b,e,a);
        cout<<b<<" to "<<e<<endl;
        TOH(n-1,a,b,e);
    }
}


int main()
{
    TOH(3,'A','B','C');

    return 0;
}
