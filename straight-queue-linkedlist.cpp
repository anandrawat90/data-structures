#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
struct Node
{
    T val;
    Node<T> *ptr;
};

template<class T>
class sinql
{
    public:
        sinql();
        ~sinql();
        bool isEmpty();
        int size();
        T frontEle();
        T dequeue();
        bool enqueue(int);
        void printQ();
    protected:
    private:
    int N;
    Node<T> *front,*rear;
};

template<class T>
sinql<T>::sinql()
{
    N=0;
    front=new Node<T>;
    rear=new Node<T>;
    front=NULL;
    rear=front;

}

template<class T>
sinql<T>::~sinql()
{
	Node<T> *temp;
	for(int i=0;i<N-1;i++)
	{
	temp=rear;
	rear=rear->ptr;
	delete temp;
	}
delete rear;
}

template<class T>
bool sinql<T>::isEmpty()
{
    if(N==0)
    {
        cout<<"The Queue is empty!"<<endl;
        return true;
    }
    else
    return false;
}

template<class T>
int sinql<T>::size()
{
    return N;
}

template<class T>
T sinql<T>::frontEle()
{
    if(!isEmpty())
    return front->val;
    else
    return 0;
}

template<class T>
T sinql<T>::dequeue()
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
        Node<T> *temp=new Node<T>;
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

template<class T>
bool sinql<T>::enqueue(int ele)
{
    Node<T> *temp=new Node<T>;
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

template<class T>
void sinql<T>::printQ()
{
    if(!isEmpty())
    {
        cout<<"the queue is:\n";
        Node<T> *temp=new Node<T>;
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
	int e;//Change the type to fit to your requirement
	sinql<int> que;//Change <int> to the same type as variable 'e'
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

