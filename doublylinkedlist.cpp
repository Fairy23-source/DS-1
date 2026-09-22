#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

node *first = NULL;

node* create_node(int x)
{
    node *temp;
    temp = (node*)malloc(sizeof(node));

    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

void insert_first(int x)
{
    node *temp = create_node(x);

    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

void insert_last(int x)
{
    node *temp = create_node(x);

    if (first == NULL)
    {
        first = temp;
        return;
    }

    node *p = first;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = temp;
    temp->prev = p;
}

void insert_position(int x, int pos)
{
    if (pos == 1)
    {
        insert_first(x);
        return;
    }

    node *p = first;

    for (int i = 1; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    node *temp = create_node(x);

    temp->next = p->next;
    temp->prev = p;

    if (p->next != NULL)
    {
        p->next->prev = temp;
    }

    p->next = temp;
}

void delete_first()
{
    if (first == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    node *temp = first;
    first = first->next;

    if (first != NULL)
    {
        first->prev = NULL;
    }

    free(temp);
}

void delete_last()
{
    if (first == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    node *p = first;

    while (p->next != NULL)
    {
        p = p->next;
    }

    if (p->prev != NULL)
    {
        p->prev->next = NULL;
    }
    else
    {
        first = NULL;
    }

    free(p);
}

void delete_position(int pos)
{
    if (first == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (pos == 1)
    {
        delete_first();
        return;
    }

    node *p = first;

    for (int i = 1; i < pos && p != NULL; i++)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    p->prev->next = p->next;

    if (p->next != NULL)
    {
        p->next->prev = p->prev;
    }

    free(p);
}

void display()
{
    if (first == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    node *p = first;

    cout << "List: ";

    while (p != NULL)
    {
        cout << p->data << " <-> ";
        p = p->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    int choice, x, pos;

    do
    {
        cout << "\n--- Doubly Linked List ---\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                insert_first(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                insert_last(x);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> x;
                cout << "Enter position: ";
                cin >> pos;
                insert_position(x, pos);
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_last();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                delete_position(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}
