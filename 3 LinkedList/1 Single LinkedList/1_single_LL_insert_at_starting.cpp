#include<bits/stdc++.h>
using namespace std;

// this code is used for the inserting the elements at the starting:

void beginsert(int);
struct node
{
        int data;
        struct node *next;
};
struct node *head;

void beginsert(int item){
        struct node *ptr = (struct node*)malloc(sizeof(struct node*));
        if (ptr == NULL){
                cout<<"Overflow\n";
        }
        else{
                ptr->data = item;
                ptr->next = head;
                head = ptr;
                cout<<"Node inserted\n";
        }
}

int main(){
        int choice, item;
        do{
                cout<<"Enter the item which you want to inser: ";
                cin>>item;
                beginsert(item);
                cout<<"Press 0 to insert more: ";
                cin>>choice;

        }while (choice==0);

        return 0;
}
