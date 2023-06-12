#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	// массив строк
	string* s = new string[n];
	for ( int i = 0; i < n; i++ )
   	cin >> s[i];
 
       // вывод инициализированного массива
	cout << "Initial array:" << endl;
	for ( int i = 0; i < n-1; i++ )
   	cout << s[i] << ", ";
	cout << s[n-1] << endl;
 
       // определяем кол-во фаз
	int m = s[0].size();
	// 10 векторов - корзины
	vector<vector<string>>bucket(10);
 
       // начало основного алгоритма
       // цикл по количеству фаз
	for ( int f = 1; f <= m; f++ ) {
	    // цикл по количеству строк
   	    for ( int i = 0; i < n; i++ ) {
   	    	// вытаскиваем цифру нужного разряда
   	        // (определяем номер корзины)
       	int c = 0;
       	stringstream ss(s[i].substr(m-f, 1));
       	ss >> c;
       	// добавляем число s[i] в корзину по номеру c
       	bucket[c].push_back(s[i]);
   	     }
 
  	// выводим состояние корзин на фазе f
   	cout <<  "**********"  << endl;
   	cout << "Phase "<< f << endl;
   	for ( int i = 0; i < 10; i++ ) {
       	cout << "Bucket " << i << ": ";  
       	//проверка на пустую корзину
       	if ( bucket[i].empty() )
           		cout << "empty";
       	else {
       	    int size = bucket[i].size();
           	for(unsigned int j = 0; j < size-1; j++)
             	cout << bucket[i][j] << ", ";
            cout << bucket[i][size-1];  //вывод последнего
       	}
       	cout << endl;
   	}
 
  	// вытаскиваем отсортированные по c числа из корзин
  	// обратно в массив (перезаписываем массив строк s)
   	int count = 0;
   	for ( int i = 0; i < 10; i++ ) {
       	for ( unsigned int j = 0; j < bucket[i].size(); j++ ) {
           		s[count] = bucket[i][j];
           		count++;
       	}
       	// очищаем корзину
       	bucket[i].clear();
   	}
   }
 
   // вывод отсортированного массива
   cout << "**********" << endl;
   cout << "Sorted array:" << endl;
   for ( int i = 0; i < n-1; i++ )
   	cout << s[i] << ", ";
   cout << s[n-1] << endl;
 
   delete[] s;
   return 0;
}

