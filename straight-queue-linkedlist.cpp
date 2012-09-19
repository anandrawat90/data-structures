#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int val;
    struct Node *ptr;
};

class sinql
{
    public:
        sinql();
        ~sinql();
        bool isEmpty();
        int size();
        int frontEle();
        int dequeue();
        bool enqueue(int);
        void printQ();
    protected:
    private:
    int N;
    Node *front,*rear;
};

sinql::sinql()
{
    N=0;
    front=new Node;
    rear=new Node;
    front=NULL;
    rear=front;

}


sinql::~sinql()
{
	Node *temp;
	for(int i=0;i<N-1;i++)
	{
	temp=rear;
	rear=rear->ptr;
	delete temp;
	}
delete rear;
}


bool sinql::isEmpty()
{
    if(N==0)
    {
        cout<<"The Queue is empty!"<<endl;
        return true;
    }
    else
    return false;
}

int sinql::size()
{
    return N;
}

int sinql::frontEle()
{
    if(!isEmpty())
    return front->val;
    else
    return 0;
}

int sinql::dequeue()
{
    int ele;
    if(N==1)
        {
            N--;
            ele=front->val;
            front=NULL;
            rear=front;
        }
    else if(!isEmpty())
    {
        N--;
        Node *temp=new Node;
        temp=rear;
        while (temp->ptr!=front)
        temp=temp->ptr;
        ele=front->val;
        front=temp;
        temp->ptr=NULL;
    }
    else
    ele=0;
    return ele;
}

bool sinql::enqueue(int ele)
{
    Node *temp=new Node;
    temp->val=ele;
    if(rear==NULL)
    {
        temp->ptr=NULL;
        front=temp;
    }
    else
    temp->ptr=rear;
    rear=temp;
    N++;
    return true;
}

void sinql::printQ()
{
    if(!isEmpty())
    {
        cout<<"the queue is:\n";
        Node *temp=new Node;
        temp=rear;
        while(temp->ptr!=NULL)
        {
            cout<<"\t\t"<<temp->val<<endl;
            temp=temp->ptr;
        }
        cout<<"\t\t"<<temp->val<<endl;
    }
}

int main()
{

	int c;
	int e;
	sinql que;
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

