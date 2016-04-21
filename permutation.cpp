#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using  namespace std;

void swap(char *x,char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
static int cont;
void permu(char *s,int i,int n)
{
    int j;
    if(i==n){
        cont++;
        printf("%s\n",s);
    }
    else{
        for(j=i;j<=n;j++){
            swap((s+i),(s+j));
            permu(s,i+1,n);
            swap((s+i),(s+j));
        }
    }

}


int main()
{
    char str[100];
    gets(str);
    int len = strlen(str);
    permu(str,0,len-1);
    cout<<cont<<endl;
    return 0;
}
