//Use Double Pointer (Node **head): This approach follows the simple C rule:
//if you want to modify local variable of one function
//inside another function, pass pointer to that variable.
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
};
Node *getnode(int item)
{
	Node *x;
	x = (Node *)malloc(sizeof(Node));
	if (x == NULL)
	{
		cout << "Memory Unavailable";
		exit(0);
	}
	x->data = item;
	x->next = NULL;
	return x;
}

void printList(Node *n)
{
	// if (n == NULL)
	// 	cout << "List is Empty";
	// return;
	while (n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

void InsertAtBegin(Node **head, int new_data) //Receives pointer to head pointer (**head)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head);
	*head = new_node;
}

void InsertAtEnd(Node **head, int new_item)
{
	Node *new_node = new Node();
	new_node->data = new_item;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	Node *cur = *head;
	while (cur->next != NULL)
	{
		cur = cur->next;
		// Traverse till the last element in the linked list
	}
	// comes out when cur is in last Node in linked list
	cur->next = new_node;
	return;
}

void InsertAfterANode(Node *pre, int item)
{
	if (pre == NULL)
	{
		cout << "previous node cannot be empty";
	}
	Node *new_node = new Node();
	new_node->data = item;
	new_node->next = pre->next;
	pre->next = new_node;
}

void deletion(Node **head, int key)
{
	Node *cur = *head;
	Node *pre;

	//If head (first) node is to be deleted
	if (cur != NULL && cur->data == key)
	{
		*head = NULL;
		free(cur);
		return;
	}

	// Traverse Until the key element is found in the list
	// pre->next will be used to unlink the Node
	while (cur != NULL && cur->data != key)
	{
		pre = cur;
		cur = cur->next;
	}
}

int main()
{
	// Node * refers to pointer pointing to the Node type
	// Three Node pointers are assigned to NULL
	Node *head = NULL;
	Node *second = NULL;
	Node *third = NULL;

	//Here the Nodes are assigned with memory
	// By using new Node() memory of int + Node * is assigned to Node pointers
	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	InsertAtBegin(&head, 0);
	InsertAtEnd(&head, 6);
	InsertAfterANode(third, 5);
	InsertAfterANode(third, 4);
	printList(head);
	// Printing only the end element, need to debug
	return 0;
}
