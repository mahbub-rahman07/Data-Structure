#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstdlib>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node node;

struct node
{
    int info;
    struct node *next;
};
struct node *Start = NULL;

struct node* Create()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    return n;
}
void InsertNode()
{
    struct node *temp,*t;
    temp = Create();
    printf("Enter a number : ");
    cin>>temp->info;
    temp->next=NULL;
    if(Start==NULL)
        Start = temp;
    else{
        t = Start;
        while(t->next!=NULL)
            t=t->next;
        t->next = temp;
    }
}
void DeleteFirstNode()
{
    if(Start==NULL){printf("List is empty\n");system("pause");}
    else{
    struct node *r;
    r = Start;
    Start = Start->next;
    free(r);
    cout<<"Node successfully deleted :)\n"<<endl;
        system("pause");
    }

}

void DeleteLastNode()
{
    if(Start==NULL){printf("List is empty\n");system("pause");}
    else{
    struct node *r,*t;
    r = t = Start;

    while(r->next != NULL){
        t = r;
        r = r->next;
    }
    if(Start ->next == NULL){
        r = Start;
        Start = Start->next;
    }
    else{
        t->next = NULL;
    }
    free(r);
    cout<<"Node successfully deleted :)\n"<<endl;
        system("pause");
    }

}


void View()
{
    struct node *t;
    t = Start;
    while(t!=NULL){
        printf("%d\n",t->info);
        t = t->next;
    }
    system("pause");
}
bool Search(int data)
{
    if(Start == NULL)
        return 0;
    else{
        node *t;
        t = Start;
        while(t != NULL){
            if(t->info == data){
                return 1;
            }
            t = t->next;
        }
        return 0;
    }
}

void DeleteElement()
{
    int data;
    cout<<"Enter the Element ";
    cin>>data;
    node *t,*r;

    t = Start;
    r = t;
    if(Start == NULL)
        return ;
    if(Start->info == data){
        t = Start;
        Start = Start->next;
        free(t);
        cout<<"Element successfully deleted :)\n"<<endl;
        system("pause");
    }
    else if(Search(data)){
        while( t->info != data ){
            r = t;
            t = t->next;
        }

        r->next = t->next;
        free(t);
        cout<<"Element successfully deleted :)\n"<<endl;
        system("pause");
    }
    else{
        cout<<"Element not exist"<<endl;
        system("pause");
    }
}

void reverse_print()
{
    stack < int > S;
    if(Start == NULL){
        return ;
    }
    node *t;
    t = Start;
    while(t != NULL){
        S.push(t->info);
        t = t->next;
    }
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    cout<<endl;
    system("pause");
}
void Sort()
{
    node *t,*r;

    for(t = Start ; t != NULL ; t = t->next){

        for(r = t->next ; r != NULL ; r = r->next){

            if(t->info > r->info){

                t->info ^= r->info;
                r->info ^= t->info;
                t->info ^= r->info;
            }
        }
    }
}

void Manu()
{
    int ch;
    start:
    system("cls");
    cout<<"\n     (1)for Insert a Node\n     (2)for View\n     (3)for Delete First Node\n     (4)for Delete Last Node\n     (5)for Delete Element\n     (6)for Reverse print\n     (7)for Sort Element\n     (8)for Exit\n"<<endl;
    cin>>ch;
    switch(ch){
        case 1: InsertNode();goto start;
                break;
        case 2: View();goto start;
                break;
        case 3: DeleteFirstNode();goto start;
                break;
        case 4: DeleteLastNode();goto start;
                break;
        case 5: DeleteElement();goto start;
                break;
        case 6: reverse_print();goto start;
                break;
        case 7: Sort();goto start;
                break;

        case 8:exit(1);
        default:cout<<"Invalid"<<endl;

    }
}
int main()
{
    Manu();

    return 0;
}
