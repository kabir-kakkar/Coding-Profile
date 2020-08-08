// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class _stack{

    stack<int> s;
    int minEle;

    public :
        int getMin();
        int pop();
        void push(int);
};

int main()
{
    freopen("input.txt", "r", stdin);

   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{
    if (s.empty())
        return -1;
    else
        return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if (s.empty()) {
        return -1;
    } else {
         int t = s.top();
         s.pop();

        if (t < minEle) {
            int temp = minEle;
            // in opposite to 2*x - m = t
            // where x is current min and m is prev minEle
            // therefore to get previous minEle, m after removing the current minEle
            // We apply the formula m = 2*x - t and get the previous minELe
            minEle = 2*minEle - t;
            return temp;
        } else {
            return t;
        }
    }
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if (s.empty()) {
        minEle = x;
        s.push(x);
        return;
    } else {
             if (x < minEle) {
            // We do this 2*x < minEle Always

            // We push it down as this element instead of x, as
            // if the top element which is going to be the minimum element is popped
            // we can retrieve the next minEle in an instant
            // without needing to scan the whole stack for a minEle
            s.push (2*x - minEle);

            // We then make the minEle as x, as it will be needed in the getMin() function
            minEle = x;
            } else {
                // if x >= minEle, we just simply push x
                s.push(x);
            }
    }
}
