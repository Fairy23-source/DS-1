#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* first = NULL;
void insertBeginning(int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;

    if (first == NULL) {
        first = newNode;
        newNode->next = first;
    }
    else {
        Node* temp = first;

        // Find last node
        while (temp->next != first)
         {
            temp = temp->next;
        }

        newNode->next = first;
        temp->next = newNode;
        first = newNode;
    }

    cout << "Node inserted at beginning.\n";
}



void insertEnd(int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;

    if (first == NULL) {
        first = newNode;
        newNode->next = first;
    }
    else {
        Node* temp = first;

        // Find last node
        while (temp->next != first)
         {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = first;
    }

    cout << "Node inserted at end.\n";
}


// i(c). Insert After Given Node
void insertAfter(int value, int given) 
{
    if (first == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = first;

    do {
        if (temp->data == given)
         {

            Node* newNode = (Node*)malloc(sizeof(Node));

            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;

            cout << "Node inserted after "
                 << given << ".\n";
            return;
        }

        temp = temp->next;

    } while (temp != first);

    cout << "Given node not found.\n";
}



void deleteFirst() 
{
    if (first == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = first;

   
    if (first->next == first) {
        first = NULL;
        free(temp);

        cout << "First node deleted.\n";
        return;
    }

    Node* last = first;

   
    while (last->next != first) {
        last = last->next;
    }

    first = first->next;
    last->next = first;

    free(temp);

    cout << "First node deleted.\n";
}



void deleteLast() 
{
    if (first == NULL) {
        cout << "List is empty.\n";
        return;
    }

   
    if (first->next == first) {
        free(first);
        first = NULL;

        cout << "Last node deleted.\n";
        return;
    }

    Node* temp = first;

    
    while (temp->next->next != first) {
        temp = temp->next;
    }

    Node* last = temp->next;

    temp->next = first;

    free(last);

    cout << "Last node deleted.\n";
}



void deleteAfter(int given) {
    if (first == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = first;

    do {
        if (temp->data == given) {

            Node* deleteNode = temp->next;

            // Only one node
            if (deleteNode == temp) {
                cout << "No node exists after given node.\n";
                return;
            }

            temp->next = deleteNode->next;

            free(deleteNode);

            cout << "Node after " << given
                 << " deleted.\n";
            return;
        }

        temp = temp->next;

    } while (temp != first);

    cout << "Given node not found.\n";
}



void display() {
    if (first == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = first;

    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != first);

    cout << endl;
}



int main() {
    int choice;
    int value;
    int given;

    do {
        cout << "\n===== SINGLY CIRCULAR LINKED LIST =====\n";

        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Given Node\n";
        cout << "4. Delete First Node\n";
        cout << "5. Delete Last Node\n";
        cout << "6. Delete Node After Given Node\n";
        cout << "7. Display All Nodes\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;

                cout << "Enter given node: ";
                cin >> given;

                insertAfter(value, given);
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                cout << "Enter given node: ";
                cin >> given;

                deleteAfter(given);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}
