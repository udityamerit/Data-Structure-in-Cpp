#include<bits/stdc++.h>
using namespace std;

void lastinsert(int);

struct node{
        int data;
        struct node *next;

};
struct node *head, *temp;

void lastinsert(int item){
        struct node *ptr = (struct node*)malloc(sizeof(struct node));

        if (ptr == NULL){
                cout<<"Overflow";
        }
        else{
                ptr->data = item;
                if (head==NULL){
                        ptr->next = NULL;
                        head = ptr;
                        cout<<"Node inserted";
                }
                else{
                        temp = head;
                        while(temp->next!= NULL){
                                temp = temp-> next;
                        }
                        temp->next = ptr;
                        ptr->next = NULL;
                        cout<<"Node inserted";
                }
        }        

}

int main(){
        int choice, item;
        do
        {
                cout<<"Enter the item which you want to insert";
                cin>>item;
                lastinsert(item);
                cout<<"press 0 to insert more";
                cin>>choice;
        } while (choice ==0);

        return 0;
        
}