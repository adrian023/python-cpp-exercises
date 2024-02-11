#include <iostream>
#include <sstream>

using namespace std;

struct Node
{
    int values;
    Node* next;
};

Node* listReverse(Node* current, Node* prev)
{
    if (current == NULL)
        return prev;

    Node* nextNode = current->next;
    current->next = prev;

    return listReverse(nextNode, current);
}

Node* inputLinkedList()
{
    cout << "Input the values of the linked list and separate them with spaces: ";
    string input;
    getline(cin, input);
    istringstream iss(input);

    int values;
    Node* head = NULL;
    Node* prev = NULL;

    while (iss >> values)
    {
        Node* node = new Node();
        node->values = values;
        node->next = NULL;

        if (head == NULL)
        {
            head = node;
        }
        else
        {
            prev->next = node;
        }

        prev = node;
    }

    return head;
}

void outputLinkedList(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        cout << current->values << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node* head = inputLinkedList();
    cout << "Orig: ";
    outputLinkedList(head);
    head = listReverse(head, NULL);
    cout << "Reverse: ";
    outputLinkedList(head);

    return 0;
}

