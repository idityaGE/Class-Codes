#include<iostream>
using namespace std;
class Node{
  public:
  Node *prev;
  Node *next;
  int data;
  Node(int data){
    this->data = data;
    prev = NULL;
    next=NULL;
  }
};

int main(){
  int arr[4]={1,2,3,4};
  Node *head = NULL;
  Node *temp;
  Node * present = head;
  for(int i=0; i<4; i++)
  {
    if(head ==NULL){
      head = new Node(arr[i]);
    }
    else{
      temp = new Node(arr[i]);
      temp->prev = present;
      present->next = temp ;
      present = temp;


    }

  }
  temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }

}