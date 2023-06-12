#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string text, edit_text, s;
	int size, k, max;

	ifstream file("input.txt", ios::in);

	while (!file.eof())
	{
		getline(file, s);
		text += s;
	}

	for (int i = 0; i < text.length(); i++)
		if (text[i] == '\n') text.erase(text.begin() + i);

	size = text.size();

	for (int i = 0; i < size; i++)
		if (text[i] == ' ')
		{
			text.erase(text.begin() + i);
			size--;
			i--;
		}


	for (int i = 0; i < size; i++)
		for (int j = size - 1; j > i; j--)
			if ((int)text[j] < (int)text[j - 1]) swap(text[j], text[j - 1]);

	int* mas = new int[size];
	int i = 0, p = 0;

	while (i < size)
	{
		k = 0;
		for (int j = i; j <= size; j++)
		{
			if ((int)text[i] == (int)text[j]) k++;
			else
			{
				mas[p] = k;
				i = j;
				break;
			}
		}
		p++;
	}

	char prev = text[0];
	edit_text += text[0];
	for (int i = 1; i < size; i++)
		if (text[i] != prev)
		{
			prev = text[i];
			edit_text += text[i];
		}

	max = mas[0];
	for (i = 1; i < p; i++)
		if (mas[i] > max) max = mas[i];
	while (max > 0)
	{
		for (i = 0; i < p; i++)
		{
			if (mas[i] >= max) cout << "#";
			else cout << " ";
		}
		max--;
		cout << endl;
	}
	cout << edit_text << endl;

	delete[] mas;

	file.close();
	return 0;
}