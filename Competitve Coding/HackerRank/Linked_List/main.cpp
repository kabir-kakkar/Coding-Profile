#include <iostream>
#include <cstddef>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

    Node* insert(Node *head,int data)
      {
          Node* tmp = new Node(data);

          if (head == NULL) {
              head = tmp;
          } else {
              Node* start = head;
              while(start->next != NULL) {
                start = start->next;
              }
              start->next = tmp;
          }
          return head;
      }
      void display(Node *head)
      {
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
      }
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    //cin>>T;
    T = 4;
    while(T-->0){
        data = T;
        head=mylist.insert(head,data);
    }
	mylist.display(head);

}
