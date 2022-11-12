#include <iostream>
using namespace std;

// with linked list
class queue2
{
public:
    int data;
    queue2 *next;
    queue2(int val)
    {
        data = val;
        next = NULL;
    }
    void linked_push(queue2 *&node, int element)
    {
        queue2 *n = new queue2(element);
        if (node == NULL)
        {
            node = n;
            return;
        }
        queue2 *p = node;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
    }
    void linked_pop(queue2 *&node)
    {
        if (node == NULL)
        {
            cout << "the queue is allready empty" << endl;
            return;
        }
        queue2 *p = node;
        node = p->next;
        free(p);
    }
    void display(queue2 *node)
    {
        queue2 *p = node;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};
//  bool empty(){
//     if(front==NULL){
//         cout<<"no element in queue"<<endl;
//         return 1;
//     }
//     return 0;
//  }
// };
//  void print_queue(queue1*top){
//     while(top!=NULL){
//         cout<<top->data<<" ";
//         top=top->next;
//     }
//     cout<<endl;
//  }
int main()
{
    queue2 *head = NULL;
    head->linked_push(head, 10);
    head->linked_push(head, 20);
    head->linked_push(head, 30);
    head->linked_push(head, 40);
    cout << "the queeue is" << endl;
    head->display(head);
    head->linked_pop(head);
    head->linked_pop(head);
    cout << " after poping the queeue is" << endl;
    head->display(head);
    return 0;
}