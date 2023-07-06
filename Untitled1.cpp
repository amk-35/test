#include<iostream>
using namespace std;
struct node
{
    char name[20];
    int age;
    node *next;
};
void creation();
void display();
void deallocated();
void deletion();
node *head,*tail;
int main()
{
    creation();
    display();
    deletion();
    deallocated();
    display();

}

void creation()
{
    node *n;
    node *n2;
    head=NULL;
    tail=NULL;
    char ans='y';
    while(toupper(ans)=='Y')
    {
        n=new node;
        cout<<"Enter Name: ";
        gets(n->name);
        cout<<"Enter age: ";
        cin>>n->age;
        n->next=NULL;
        if(tail==NULL)
        {
            tail=n;
        }

        if(head!=NULL)
        {
            n->next=n2;
        }
        head=n;
        n2=n;
        cout<<"Do another(Y/N): ";
        cin>>ans;
        cin.ignore();
    }
}

void display()
{
    node *n;
    n=head;
    while(n!=NULL)
    {
    	cout<<n->name<<"\t"<<n->age<<"\n";
        n=n->next;
    }
}


void deallocated()
{
    node *n;
    n=head;
    while(n!=NULL)
    {
        delete n;
        n=n->next;
    }
}

void deletion()
{
    node *n;
    char sname[20];
    int found=0;
    cout<<"Enter Name to delete: ";
    gets(sname);
    n=head;
    if(strcmpi(sname,head->name)==0)
    {
        delete head;
        head=n->next;
    }
    else
    {
        while(n->next!=NULL && !found)
        {
            if(strcmpi(sname,(n->next)->name)==0)
            {
                if((n->next)->next==NULL)
                {
                    delete n->next;
                    n->next=NULL;
                }
                else
                {
                    delete n->next;
                    n->next=(n->next)->next;
                }
                found =1;
            }
            else
            {
                n=n->next;
            }
        }
    }
}