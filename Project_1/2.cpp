#include<iostream>
using namespace std;
int main() {
    int num=0, t=0, d=1;
    cout<<"Enter count:"<<endl;
    cout<<"==> ";
    cin>>num;
    while(num)
    {
        t +=(num%2)*d;
        //cout<<t;
        num=num/2;
        d=d*10; // razryad
    }
    cout<<t;
  //  cout<<num;
    cout<<endl;
    system("pause");
    return 0;
}