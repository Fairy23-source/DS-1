#include<iostream>
using namespace std;
#define max 5
int queue [max];
int front=-1;
int rear=-1;
void enqueue(int value)
{
    if (rear == max - 1)
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        cout << value << " inserted into queue." << endl;
    }
}
void dequeue()
{
    if(front== -1 || front > rear)
    {
        cout<<"queue is empty"<<endl;
    }
       else
    {
        cout << queue[front] << " deleted from queue." << endl;
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}
void display()
{
    if (front == -1)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
}
int main()
{
    int choice, value;

    while (true)
    {
        cout << "\n--- Queue Operations ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
