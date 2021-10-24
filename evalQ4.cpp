#include "bits/stdc++.h"
using namespace std;

class node
{
public:
	string data;
	node* next;
	node* child;
	int stock;
	node()
	{
		next = NULL;
		child = NULL;
	}
	node(string s, int n)
	{
		data = s;
		stock = n;
		next = NULL;
		child = NULL;
	}
};

bool isPresent(node* head, string s)
{
	if(head == NULL)
	{
		return false;
	}
	node* temp = head;
	while(temp != NULL && temp -> data != s)
	{
		temp = temp -> next;
	}
	if(temp == NULL)
	{
		return false;
	}
	return true;
}

bool isThere(node* head, string s)
{
	if(s.length() == 2)
	{
		return isPresent(head, s);
	}
	else if(s.length() == 4)
	{
		string ab = s.substr(0, 2);
		string cd = s.substr(2, 2);
		bool p1 = isPresent(head, ab);
		if(p1)
		{
			node* temp = head;
			while(temp -> data != ab)
			{
				temp = temp -> next;
			}
			return isPresent(temp -> child, cd);
		}
		return false;
	}
	else if(s.length() == 6)
	{
		string ab = s.substr(0, 2);
		string cd = s.substr(2, 2);
		string ef = s.substr(4, 2);
		bool p1 = isPresent(head, ab);
		if(p1)
		{
			node* temp1 = head;
			while(temp1 -> data != ab)
			{
				temp1 = temp1 -> next;
			}
			bool p2 = isPresent(temp1 -> child, cd);
			if(p2)
			{
				node* temp2 = temp1 -> child;
				while(temp2 -> data != cd)
				{
					temp2 = temp2 -> next;
				}
				return isPresent(temp2 -> child, ef);
			}
			return false;
		}
		return false;
	}
	return false;
}

int findLength(node* head)
{
	int len = 0;
	while(head != NULL)
	{
		len++;
		head = head -> next;
	}
	return len;
}

node* getNode(node*& head, int pos)
{
	node* temp = head;
	while(pos--)
	{
		temp = temp -> next;
	}
	return temp;
}

void insertAtTail(node*& head, string s, int n)
{
	node* new_node = new node(s, n);
	if(head == NULL)
	{
		head = new_node;
	}
	else
	{
		node* temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = new_node;
	}
}

void deleteNode(node*& head, string s)
{
	if(head -> data == s)
	{
		node* temp = head;
		head = head -> next;
		delete temp;
	}
	else
	{
		node* curr = head -> next;
		node* prev = head;
		while(curr -> data != s)
		{
			curr = curr -> next;
			prev = prev -> next;
		}
		prev -> next = curr -> next;
		delete curr;
	}
}

void updateNode(node*& head, string s, int n)
{
	node* temp = head;
	while(temp -> data != s)
	{
		temp = temp -> next;
	}
	temp -> stock = temp -> stock + n;
	if(temp -> stock == 0)
	{
		deleteNode(head, temp -> data);
	}
}

void insertMainProduct(node*& head, string ab, int n)
{
	if(!isPresent(head, ab))
	{
		insertAtTail(head, ab, n);
	}
	else
	{
		updateNode(head, ab, n);
	}
}

void insertSubCategory(node*& head, string ab, string cd, int n)
{
	node* temp = head;
	while(temp -> data != ab)
	{
		temp = temp -> next;
	}
	if(!isPresent(temp -> child, cd))
	{
		insertAtTail(temp -> child, cd, n);
	}
	else
	{
		updateNode(temp -> child, cd, n);
	}
}

void insertSubSubCategory(node*& head, string ab, string cd, string ef, int n)
{
	node* temp1 = head;
	while(temp1 -> data != ab)
	{
		temp1 = temp1 -> next;
	}
	node* temp2 = temp1 -> child;
	while(temp2 -> data != cd)
	{
		temp2 = temp2 -> next;
	}
	if(!isPresent(temp2 -> child, ef))
	{
		insertAtTail(temp2 -> child, ef, n);
	}
	else
	{
		updateNode(temp2 -> child, ef, n);
	}
}

int findMainStock(node*& head, string ab)
{
	node* temp = head;
	while(temp -> data != ab)
	{
		temp = temp -> next;
	}
	return temp -> stock;
}

int findSubCategoryStock(node*& head, string ab, string cd)
{
	node* temp = head;
	while(temp -> data != ab)
	{
		temp = temp -> next;
	}
	temp = temp -> child;
	while(temp -> data != cd)
	{
		temp = temp -> next;
	}
	return temp -> stock;
}

int findSubSubCategoryStock(node*& head, string ab, string cd, string ef)
{
	node* temp = head;
	while(temp -> data != ab)
	{
		temp = temp -> next;
	}
	temp = temp -> child;
	while(temp -> data != cd)
	{
		temp = temp -> next;
	}
	temp = temp -> child;
	while(temp -> data != ef)
	{
		temp = temp -> next;
	}
	return temp -> stock;
}

void traverse(node* head, map <string, int>& prod_to_stock, vector <string>& prods)
{
	node* temp1 = head;
	while(temp1)
	{
		prod_to_stock[temp1 -> data] = temp1 -> stock;
		node* temp2 = temp1 -> child;
		while(temp2)
		{
			prod_to_stock[temp1 -> data + temp2 -> data] = temp2 -> stock;
			prods.push_back(temp1 -> data + temp2 -> data);
			temp2 = temp2 -> next;
		}
		temp1 = temp1 -> next;
	}
}

void merge(node*& head, int n, int m)
{
	node* a = getNode(head, n);
	node* b = getNode(head, m);
	if((a -> data)[0] != '0' || (b -> data)[0] != '0')
	{
		return;
	}
	string ab_new = (a -> data).substr(1, 1) + (b -> data).substr(1, 1);
	int stock_new = a -> stock + b -> stock;

	node* a_cat = a -> child;
	node* b_cat = b -> child;

	map <string, int> prod_to_stock;
	vector <string> prods;
	traverse(b_cat, prod_to_stock, prods);

	for(string x_data: prods)
	{
		int x_stock = prod_to_stock[x_data];
		string x_cd = x_data.substr(0, 2);
		string x_ef = x_data.substr(2, 2);
		insertSubCategory(head, a -> data, x_cd, x_stock);
		insertSubSubCategory(head, a -> data, x_cd, x_ef, x_stock);
	}

	sort(ab_new.begin(), ab_new.end());
	a -> data = ab_new;
	a -> stock = stock_new;
	deleteNode(head, b -> data);
}

void print(node* head)
{
	while(head)
	{
		string ab = head -> data;
		node* cat = head -> child;
		while(cat)
		{
			string cd = cat -> data;
			node* sub = cat -> child;
			while(sub)
			{
				cout << ab << cd << sub -> data << " " << sub -> stock << endl;
				sub = sub -> next;
			}
			cat = cat -> next;
		}
		head = head -> next;
	}
}

int main()
{
	int q;
	cin >> q;
	node* head = NULL;
	while(q--)
	{
		char op;
		cin >> op;
		if(op == 'I')
		{
			string s;
			int n;
			cin >> s >> n;
			string ab = s.substr(0, 2);
			string cd = s.substr(2, 2);
			string ef = s.substr(4, 2);
			if(n >= 0)
			{
				insertMainProduct(head, ab, n);
				insertSubCategory(head, ab, cd, n);
				insertSubSubCategory(head, ab, cd, ef, n);
			}
			else
			{
				insertSubSubCategory(head, ab, cd, ef, n);
				insertSubCategory(head, ab, cd, n);
				insertMainProduct(head, ab, n);
			}
		}

		else if(op == 'M')
		{
			int n, m;
			cin >> n >> m;
			n--;
			m--;
			int len = findLength(head);
			merge(head, n % len, m % len);
		}

		else if(op == 'S')
		{
			string s;
			cin >> s;
			if(!isThere(head, s))
			{
				cout << "";
			}
			else
			{
				int stock;
				if(s.length() == 2)
				{
					stock = findMainStock(head, s);
				}
				else if(s.length() == 4)
				{
					string ab = s.substr(0, 2);
					string cd = s.substr(2, 2);
					stock = findSubCategoryStock(head, ab, cd);
				}
				else if(s.length() == 6)
				{
					string ab = s.substr(0, 2);
					string cd = s.substr(2, 2);
					string ef = s.substr(4, 2);
					stock = findSubSubCategoryStock(head, ab, cd, ef);
				}
				cout << stock << endl;
			}
		}

		else if(op == 'P')
		{
			print(head);
		}
	}
}