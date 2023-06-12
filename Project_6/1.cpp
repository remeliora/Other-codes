#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
vector <int> graph(100);
bool used[100]; //массив пройденных вершин
int comp[100];  //массив компонент связности

void dfs(int v, int c_num) {    //c_num - номер текущей компоненты связности.
    used[v] = true;
    comp[v] = c_num;

    for (int &u: graph)     //находим непройденные вершины в векторе
        if (!used[u])       //если нашли
            dfs(u, c_num);  //рекурсия
}

int main() {
    int n; 
    ifstream in("input.txt"); 
    if ( !in.is_open() )    // если файл не открыт
		cout << "File doesnt open" << endl;   // сообщить об этом
	else {   
        in >> n;
		int a;
        while ( !in.eof() ) {   //считываем символ до конца файла
            in >> a;
            graph.push_back(a);   //добавляем в вектор
        }
    }
	in.close(); // закрываем файл
    
    int c_num = 1;  //Номер очередной компоненты

    for ( int i = 0; i < n; i++ ) {
        if ( !used[i] ) {       //если мы ещё не посетили эту вершину, обходя одну из предыдущих
            dfs( i, c_num );    //запускаем поиск
            c_num++;            //увеличиваем компоненту
        }
    }
 
    for ( int i = 0; i < n; i++ ) {
        cout << "Vertex " << i + 1 << " belongs to component " << comp[i] << endl;
    }
    cout << "K = " << c_num << endl;

    ofstream out("output.txt"); //вывод в файл
    out << "K = " << c_num; 
}