#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info  info;
};
void Input(Elem*& first, Elem*& last, Info value) {
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

Info Delete(Elem*& first, Elem*& last) {
	Elem* tmp = first->link;
	Info value = first->info;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	return value;
}

int Count(Elem* elem) {
	int count = 0;
	while (elem != NULL)
	{
		if (elem->info % 2 != 0) {
			count++;
		}
		elem = elem->link;
	}
	return count;
}

int main()
{
	Elem  *first = NULL, *last = NULL;
	int n = 12;
	for (int i = 0; i < n; i++) {
		Input(first, last, i);
	}
	int count = Count(first);
	cout << "count = " << count << endl;

	for (int i = 0; i < n; i++)
	{
		cout<<Delete(first, last)<<" ";
	}

	return 0;
}