#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string>

using namespace std;

struct Node
{
	Node(string data)
	{
		x = data;
		next = NULL;
		prev = NULL;
	}
	string x;
	Node *prev, *next;
};

class TwoList
{
	Node *root, *last;
public:
	TwoList()
	{
		root = NULL;
		last = NULL;
	}
	~TwoList()
	{
		while (root != NULL && last != NULL)
		{
			Node *tmp = root->next;
			delete root;
			root = tmp;
		}
	}
	void Add(string data);
	void Show();
};

void TwoList::Add(string data)
{
	if (root == NULL)
	{
		root = new Node(data);
		last = root;
		Show();
		return;
	}
	/*Node *tmp = new Node(data);
	tmp->prev = last;
	last->next = tmp;
	last = tmp;
	Show();*/

	Node *tmp = new Node(data);
	Node *r = root;
	while (r != NULL)
	{
		if (data.compare(r->x) <= 0)
		{
			if (r == root)
			{
				tmp->next = r;
				tmp->prev = NULL;
				r->prev = tmp;
				root = tmp;	
				Show();
				break;
			}
			r->prev->next = tmp;
			tmp->next = r;
			tmp->prev = r->prev;
			r->prev = tmp;
			Show();
			break;
		}
		if (r == last)
		{
			tmp->prev = last;
			last->next = tmp;
			last = tmp;
			Show();
			break;
		}
		r = r->next;
	}
}

void TwoList::Show()
{
	Node *tmp = root;
	while (tmp != NULL)
	{
		cout << tmp->x << endl;
		tmp = tmp->next;
	}
}


class WorkTwoList
{
public:
	WorkTwoList()
	{
		string Text = "битва автобус авто";

		istringstream iss(Text);
		string data;

		TwoList *TW = new TwoList;
		while (getline(iss, data, ' '))
		{
			TW->Add(data);
			//cout << data << endl;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	WorkTwoList* WTL = new WorkTwoList;
	system("Pause");
	return 0;
}
