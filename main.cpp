#include <iostream>
#include <sstream>

using namespace std;

struct node_t 
{
	int value;
	node_t * next;
};


void output(node_t * head) 
{
	node_t * time;
	time = head;
	while (time != nullptr) {
		cout << "+---+" << "    ";
		time = time->next;
	}
	time = head;
	cout << endl;
	while (time != nullptr) {
		cout << "| " << time->value << " |";
		time = time->next;
		if (time != nullptr) {
			cout << "--->";
		}
	}
	time = head;
	cout << endl;
	while (time != nullptr) {
		cout << "+---+" << "    ";
		time = time->next;
	}
	cout << endl;
}

void add(node_t * & head)
{
	string string;
	getline(cin, string);
	istringstream stream(string);
	int value;
	stream >> value;
	node_t * time = new node_t;
	time -> value = value;
	time -> next = nullptr;
	if (head == nullptr)
	{
		head = time;
	}
	else
	{
		node_t * last = head;
		while (last -> next)
		{
			last = last -> next;
		}
		last -> next = time;
	}
}

void sub(node_t * &  head) 
{
	node_t * time = new node_t;
	time = head -> next;
	delete head;
	head = time;
}

void rev(node_t * & head)
{
	node_t * new_head = nullptr;

	for (node_t * node = head; node; )
	{
		node_t * node_next = node -> next;
		node -> next = new_head;
		new_head = node;
		node = node_next;
	}
	head = new_head;
}


int main()
{
	node_t * head = new node_t;
	head = nullptr;
	char op;
	while (cin >> op)
	{
		if (op == 'q')
		{
			break;
		}
		if (op == '+')
		{
			add(head);
		}
		if (op == '-')
		{
			sub(head);
		}
		if (op == '/')
		{
			rev(head);
		}
		if (op == '=')
		{
			output(head);
		}
	}
	return 0;
}
