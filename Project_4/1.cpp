#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	string* s = new string[n];
	for ( int i = 0; i < n; i++ )
   	cin >> s[i];
	cout << "Initial array:" << endl;
	for ( int i = 0; i < n-1; i++ )
   	cout << s[i] << ", ";
	cout << s[n-1] << endl;

	int m = s[0].size();
	vector<vector<string>>bucket(10);
	for ( int f = 1; f <= m; f++ ) {
   	    for ( int i = 0; i < n; i++ ) {
       	int c = 0;
       	stringstream ss(s[i].substr(m-f, 1));
       	ss >> c;
       	bucket[c].push_back(s[i]);
   	     }
   	cout <<  "**********"  << endl;
   	cout << "Phase "<< f << endl;
   	for ( int i = 0; i < 10; i++ ) {
       	cout << "Bucket " << i << ": ";  
       	if ( bucket[i].empty() )
           		cout << "empty";
       	else {
       	    int size = bucket[i].size();
           	for(unsigned int j = 0; j < size-1; j++)
             	cout << bucket[i][j] << ", ";
            cout << bucket[i][size-1];  
       	}
       	cout << endl;
   	}
   	int count = 0;
   	for ( int i = 0; i < 10; i++ ) {
       	for ( unsigned int j = 0; j < bucket[i].size(); j++ ) {
           		s[count] = bucket[i][j];
           		count++;
       	}
       	bucket[i].clear();
   	}
   }
   cout << "**********" << endl;
   cout << "Sorted array:" << endl;
   for ( int i = 0; i < n-1; i++ )
   	cout << s[i] << ", ";
   cout << s[n-1] << endl;
 
   delete[] s;
   return 0;
}
 