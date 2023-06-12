#include <iostream> 

using namespace std; 

void func( string str, int len )
{
    if( !len )
    {
        cout << str << endl;
        return;
    }
    func( str + '0', len - 1 );
    func( str + '1', len - 1 );
}
 
int main()
{
    int n;
    cin >> n;
 
    func( "", n );
    return 0;
}