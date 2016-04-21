#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstdlib>

using namespace std;
typedef struct node node;

struct node
{
    int info;
    struct node *perv,*next;
};
struct node *start = NULL;
node *last = NULL;

node* Create()
{
    node *t;
    t = (node *)malloc(sizeof(node));

    return t;
}


void Insert()
{
    struct node *n;
    n = Create();
    cout<<"Enter a Number : ";
    cin>>n->info;
    n->perv = NULL;
    n->next = NULL;
    if(start==NULL)
        start= n;
    else{
    struct node *t;
    t = start;

    while(t->next != NULL)
        t = t->next;
        t->next = n;
        n->perv = t;
        n->next = NULL;
        last = n;
    }

}

void rev()
{
    if(start == NULL)
    {
        cout<<"List is empty"<<endl;
        system("pause");
    }
    else if(last == NULL)
    {
        cout<<start->info<<endl;
        system("pause");
    }
    else{

        for(node *t = last ; t!= NULL ;t = t->perv){
            cout<<t->info<<endl;
        }
        system("pause");

    }
}

void Delete()
{
    struct node *r;
    if(start==NULL){
        cout<<"List is empty"<<endl;system("pause");}
    else{
    r = start;
    start = start->next;
    start->perv = NULL;
    free(r);
    }
}
void DeleteLast()
{
    struct node *r;
    if(start==NULL){
        cout<<"List is empty"<<endl;system("pause"); return ;}
    else if(start->next == NULL){
    r = start;
    start = NULL;
    }
    else{
        r = last;
        last = last->perv;
        last->next = NULL;
    }
    free(r);

}

void Sort()
{
    node *t,*r;

    for(t = start ; t != NULL ; t = t->next){

        for(r = t->next ; r != NULL ; r = r->next){

            if(t->info > r->info){

                t->info ^= r->info;
                r->info ^= t->info;
                t->info ^= r->info;
            }
        }
    }
}

void Veiw()
{
   struct node *t;
    if(start==NULL){
        cout<<"List is empty"<<endl;system("pause");}
    else{
        t = start;
        while(t !=NULL){
            cout<<t->info<<endl;
            t = t->next;
        }
    }

    system("pause");
}

void DeleteElement()
{
    int data;
    cout<<"Enter the data : ";
    cin>>data;

    node *t,*r;

    t = r = start;
    if(start->info == data){
        t = start;
        start = start->next;
        free(t);
        return ;
    }

    while(t->info != data){
        r = t;
        t = t->next;
    }

    r ->next = t->next;

    free(t);

}

void Menu()
{
    int ch;
    start:
    system("cls");

    cout<<"\n     (1)for Insert a Node\n     (2)for View\n     (3)for Delete First Node\n     (4)for Delete Last Node\n     (5)for Delete Element\n     (6)for Reverse print\n     (7)for Sort Element\n     (8)for Exit\n"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: Insert();    goto start;break;
        case 2: Veiw();      goto start;break;
        case 3: Delete();    goto start;break;
        case 4: DeleteLast();goto start;break;
        case 5: DeleteElement();goto start;break;
        case 6: rev();       goto start;break;
        case 7: Sort();      goto start;break;
        case 8: exit(1);
        default:cout<<"Invalid"<<endl;goto start;
    }
}


int main()
{
    Menu();
    return 0;
}
