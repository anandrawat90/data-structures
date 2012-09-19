#include <iostream>
#define NIL 0

using namespace std;

template <class T>
class cirqa
{
    public:
        cirqa(int x)
	{
	    f=0;
	    r=0;
	    N=x;
	    queue=new T[N];
	    cout<<"A queue has been created!"<<endl;
	}
        ~cirqa()
	{
	    delete[] queue;
	    cout<<"The queue has been deleted!"<<endl;
	}

        bool isEmpty()
	{
	    if (f==r)
	    return true;
	    else
	    return false;
	}

        int size()
	{
		if(f>r)
			return (N-f+r);
	    	else
			return(r-f);
	}
        T frontEle()
	{
	    if(isEmpty())
	    return NIL;
	    else
	    return queue[f];

	}

        T dequeue()
	{
	    if(isEmpty())
	    {
	    	cout<<"The queue is empty"<<endl;
	    	return NIL;
	    }
	    else
	    {
		int ele=queue[f];
		f=((f+1)%N);
		return ele;
	    }
	}

	T firstele()
	{
		if(isEmpty())
		{
			cout<<"The Queue is empty"<<endl;
			return NIL;
		}
		else
		{
			return queue[f];
		}
	}

        bool enqueue(T ele)
	{
	    if(size()==N-1)
	    {
		cout<<"The queue is full"<<endl;
		return false;
	    }
	    else
	    {
		queue[r]=ele;
		r=((r+1)%N);
		return true;
	    }
	}

        void printQ()
	{
		cout<<"The queue is:"<<endl;
		int i=f;
		if(r>f)
		for(;r>i;i++)
		{
			cout<<queue[i]<<endl;
		}
		else
		for(;r!=i;i=(i+1)%N)
		{
		    cout<<queue[i]<<endl;
		}
	}
    protected:
    private:
    int N;
    T *queue;
    int f;
    int r;
};


int main()
{

//------------------------------------------------------circular queue using arrays
    int n,c;
    char e;// element changes with the value of the template
    cout<<"Enter the size of the queue: ";
	cin>>n;
	cirqa <char> que(n+1);// the extra space since N%N=0 and 0%N=0
	while(1)
	{
		cout<<"1.EnQ 2.DeQ 3.PrintQ 4.SizeofQ 5.First Element 6.Exit: ";
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
				cout<<"The first element to popped is: "<<que.firstele()<<endl;
				break;
			case 6:
				return 0;
				break;
			default:
				cout<<"enter again"<<endl;
		}

	}
	return 0;
}
