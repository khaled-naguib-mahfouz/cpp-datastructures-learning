#include <iostream>

using namespace std;
class Stack {
int tos;
int arr[5];
public:
    Stack(){tos=-1;}
    void push(int element)
    {
        if(tos>=4)
        {
            cout<<"the stack is full \n";
        }
        else{
                tos++;
            arr[tos]=element;
        }
    }
    void pop(int &y)
    {
        if(tos<0)
        {
            cout<< "the stack is empty";
        }
        else{
            y=arr[tos];
            tos--;

        }
    }
    void getTos(int &x)
    {

         if(tos<0)
        {
            cout<< "the stack is empty";
        }
        else{
            x=arr[tos];
            cout<<x;
    }}
    void print(){
    for(int i=tos; i>=0; i--){
        cout<< arr[i]<<"\n";

    }

     }


};

int main()
{
    Stack s;
    s.push(50);
        s.push(50);
    s.push(60);
    s.push(40);
    s.push(80);
    int y=0;
s.pop(y);
s.getTos(y);
s.print();
   return 0;
}
