#include <iostream>
#include <Windows.h>
#include <ctime>
#include <queue>
using namespace std;

struct Elem
{
	Elem* link;
	int info;
};
void enqueue(Elem* &first, Elem* &last, int size, int min_value, int max_value)
{
	for (int i = 0; i < size; i++)
	{
		int ElemInfo = min_value + rand() % (max_value - min_value + 1);
		Elem* tmp = new Elem;
		tmp->info = ElemInfo;
		tmp->link = NULL;
		if (last != NULL)
		{
			last->link = tmp;
		}
		last = tmp;
			if (first == NULL)
			{
				first = tmp;
			}
		
	}
}
void Print(Elem* first)
{
	Elem* current = first;
	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->link;
	}
}
bool check_info(Elem* first)
{
	if (first == NULL)
	{
		return false;
	}
	Elem* previous = first;
	Elem* current = first->link;
	while (current != NULL)
	{
		if (previous->info == current->info)
		{
			return true;
		}
		previous = current;
		current = current->link;
	}
	return false;
}
int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	srand(time(NULL));
	Elem* first = NULL,
		* last = NULL;
	int size;
	cout << "����� ����� : "; cin >> size;
	int min_value = 0;
	int max_value = 10;
	enqueue(first, last, size, min_value, max_value);// create
	Print(first);
	cout << endl;
	if (check_info(first) == true)
	{
		cout << "� ������ � ����" << endl;
	}
	else
	{
		cout << "� ������ ���� ����" << endl;
	}
	return 0;


}