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
class cirql
{
    public:
        cirql(int);
        ~cirql();
        bool isfull();
        bool isEmpty();
        int size();
        T frontEle();
        T dequeue();
        bool enqueue(T);
        void printQ();
    protected:
    private:
    int N,size_q;
    Node<T> *front,*rear;
};

template<class T>
cirql<T>::cirql(int x)
{
    //ctor
    N=x;
    size_q=0;
    Node<T> *temp;
    front=new Node<T>;
    rear=new Node<T>;
    if(N==0)
    {
        cout<<"Size of the queue can not be 0"<<endl;
        exit(0);
    }
    else
    temp=new Node<T>;
    front=temp;
    rear=front;

    for(int i=0;i<N;i++)
    {
        Node<T> *temp2=new Node<T>;
        temp->ptr=temp2;
        temp=temp2;
    }
    temp->ptr=rear;
}

template<class T>
cirql<T>::~cirql()
{
    //dtor
    Node<T> *temp;
    for(int i=0;i<N;i++)
    {
	temp=rear;
        rear=temp->ptr;
        delete temp;
    }
    delete rear;
    cout<<"The memory has been freed"<<endl;
}

template<class T>
bool cirql<T>::isEmpty()
{
    if(size_q==0)
    {
        cout<<"The Queue is empty!"<<endl;
        return true;
    }
    else
    return false;
}

template<class T>
int cirql<T>::size()
{
    return size_q;
}

template<class T>
T cirql<T>::frontEle()
{
    return (!isEmpty())?rear->val: 0;
}

template<class T>
T cirql<T>::dequeue()
{
    T ele;
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

template<class T>
bool cirql<T>::enqueue(T ele)
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

template<class T>
bool cirql<T>::isfull()
{
    return (size_q==N)? true: false;
}
template<class T>
void cirql<T>::printQ()
{
    if(!isEmpty())
    {
        cout<<"The queue is:\n";
        Node<T> *temp=new Node<T>;
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
	int e;//change the type of the varible to suit your purpose
	cout<<"Enter the number of nodes to present in queue: ";
	cin>>S;
	cirql<int> que(S);//<int> should be change accordingly
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

