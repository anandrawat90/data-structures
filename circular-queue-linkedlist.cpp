#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int val;
    struct Node *ptr;
};

class cirql
{
    public:
        cirql(int);
        ~cirql();
        bool isfull();
        bool isEmpty();
        int size();
        int frontEle();
        int dequeue();
        bool enqueue(int);
        void printQ();
    protected:
    private:
    int N,size_q;
    Node *front,*rear;
};

cirql::cirql(int x)
{
    //ctor
    N=x;
    size_q=0;
    Node *temp;
    front=new Node;
    rear=new Node;
    if(N==0)
    {
        cout<<"Size of the queue can not be 0"<<endl;
        exit(0);
    }
    else
    temp=new Node;
    front=temp;
    rear=front;

    for(int i=0;i<N;i++)
    {
        Node *temp2=new Node;
        temp->ptr=temp2;
        temp=temp2;
    }
    temp->ptr=rear;
}

cirql::~cirql()
{
    //dtor
    Node *temp;
    for(int i=0;i<N;i++)
    {
	temp=rear;
        rear=temp->ptr;
        delete temp;
    }
    delete rear;
    cout<<"The memory has been freed"<<endl;
}

bool cirql::isEmpty()
{
    if(size_q==0)
    {
        cout<<"The Queue is empty!"<<endl;
        return true;
    }
    else
    return false;
}

int cirql::size()
{
    return size_q;
}

int cirql::frontEle()
{
    return (!isEmpty())?rear->val: 0;
}

int cirql::dequeue()
{
    int ele;
    if(size_q==1)
        {
            size_q--;
            ele=rear->val;
            rear=front;
        }
    else if(!isEmpty())
    {
        size_q--;
        ele=rear->val;
        rear=rear->ptr;
    }
    else
    ele=0;
    return ele;
}

bool cirql::enqueue(int ele)
{
    if(isfull())
    {
        cout<<"The queue is full please delete some elements!"<<endl;
        return false;
    }
    else if(front->ptr!=rear)
    {
        front->val=ele;
        front=front->ptr;
    }
    else
    front->val=ele;
    size_q++;
    return true;
}
bool cirql::isfull()
{
    return (size_q==N)? true: false;
}
void cirql::printQ()
{
    if(!isEmpty())
    {
        cout<<"The queue is:\n";
        Node *temp=new Node;
        temp=rear;
        while(temp->ptr!=front->ptr)
        {
            cout<<"\t\t"<<temp->val<<endl;
            temp=temp->ptr;
        }
    }
}


int main()
{


	int S;
	int c;
	int e;
	cout<<"Enter the number of nodes to present in queue: "<<endl;
	cin>>S;
	cirql que(S);
	while(1)
	{
		cout<<"1.EnQ 2.deQ 3.PrintQ 4.SizeofQ 5.First Element 6. Exit: ";
		cin>>c;
		switch(c)
		{
			case 1:
				cin>>e;
				if(que.enqueue(e))
				{
				    cout<<"The element has been pushed into the queue"<<endl;
				}
				break;
			case 2:
				cout<<"The element popped is : "<<que.dequeue()<<endl;
				break;
			case 3:
				que.printQ();
				break;
			case 4:
				cout<<que.size()<<endl;
				break;
			case 5:
				cout<<"The first element to be popped out is "<<que.frontEle()<<endl;
				break;
			case 6:
				return 0;	
    			default:
				cout<<"enter again"<<endl;
		}

	}
    return 0;
}

