// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node* new_node = new Node(new_data, new_data1);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
       printf("%d %d ", temp->coeff, temp->pow);
       temp  = temp->next;
    }
}

Node* addPolynomial(Node *p1, Node *p2);


void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}
 

/* Driver program to test above function*/

 // } Driver Code Ends
/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};
*/

class Solution{
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node* addPolynomial(Node *p1, Node *p2)
    {
        Node *head = NULL, *rear = NULL;
        while(p1 && p2)
        {
            Node *p = new Node(0,0);
            if(head == NULL){
                head = rear = p;
            }
            else{
                rear -> next = p;
                rear = p;
                //rear->next NULL;
            }
            if(p1->pow == p2->pow){
                p ->pow = p1->pow;
                p->coeff = p1->coeff + p2->coeff;
                
                p1 = p1->next;
                p2 = p2->next;
            }
            else if(p1->pow >p2->pow){
                p->pow = p1->pow;
                p->coeff = p1->coeff;
                
                p1 = p1->next;
            }
            else{
                p->pow = p2->pow;
                p->coeff = p2->coeff;
                
                p2 = p2->next;
            }
            //p->next = NULL;
            // p1 = p1->next;
            // p2 = p2 ->next;
        }
        while(p1!=NULL)
        {
            
            Node * p = new Node(0,0);
            rear ->next = p;
            rear = p;
            
            p->coeff = p1 ->coeff;
            p->pow = p1 -> pow;
            
            //p -> next =NULL;
            p1 = p1->next;
        }
        while(p2!=NULL)
        {
            cout<<1;
            Node * p = new Node(0,0);
            rear ->next = p;
            rear = p;
            
            p->coeff = p2 ->coeff;
            p->pow = p2 -> pow;
            
            p2 = p2->next;
        }
        
        return head;
    }
};





// { Driver Code Starts.
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }
        
         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }
        Solution obj;
        Node *sum = obj.addPolynomial(poly1,poly2);
        for(Node* ptr=sum ; ptr ; ptr=ptr->next  )
        {
            // printing polynomial
            cout<< ptr->coeff << "x^" << ptr->pow;
            if(ptr->next) cout<<" + ";
        }
        cout<<endl;
       
    }

}
  // } Driver Code Ends