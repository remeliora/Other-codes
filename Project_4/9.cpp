#include <iostream>
using namespace std;
int a[10000],b[10000],i,q;
int main()
{
    int n;
    cin>>n;
     for(int i=0; i<n; i++)
       cin>>a[i]>>b[i];
     for(int j=0; j<n-1; j++)
     for(int i=0; i<n-1; i++)
       if(b[i]<b[i+1] || b[i]==b[i+1] && a[i]>a[i+1]){
          q =a[i];
           a[i]=a[i+1];
           a[i+1]=q;
           q=b[i];
           b[i]=b[i+1];
           b[i+1]=q; 
 }
    for(int i=0; i<n; i++)
         cout<<a[i]<<' '<<b[i]<<endl;
    return 0; 
}