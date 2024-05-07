#include<iostream>
using namespace std;
class Stack{
private:
   
    int data[100];
    int top;

public:
    Stack() 
	{
       top = -1;
    }
    void push(int val) 
	{
        
        data[++top] = val;
    }
    void pop() 
	{
        --top;
    }
    
    void print() 
	{
        cout << "Stack elements: ";
        for (int i = top; i >= 0; --i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
class Queue {
private:
   
    int data[100];
    int front;
    int rear;

public:
    Queue() 
	{
       front = -1;
        rear = -1;
    }

    void enqueue(int val) 
	{
        if (front == -1) 
		{
            front = 0;
            rear = 0;
        } else 
		{
            rear = rear + 1 ;
        }
        data[rear] = val;
    }
    void dequeue() 
	{
        if (front == rear) 
		{
            front= -1;
            rear = -1;
        } else 
		{
            front = front + 1 ;
        }
    }
   
    void print() 
	{
        cout << "Queue elements: ";
        int i = front;
        while (i != rear) 
		{
            cout << data[i] << " ";
            i = (i + 1) ;
        }
        cout << data[rear] << endl;
    }
};

int main() {
    Stack myStack;
    Queue myQueue;

    int choice;
    int element;

    do {
        cout << "\nMain Menu:" << endl;
        cout << "1. Stack Operations" << endl;
        cout << "2. Queue Operations" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                int stackChoice;
                do {
                    cout << "\nStack Operations:" << endl;
                    cout << "1. Push" << endl;
                    cout << "2. Pop" << endl;
                    cout << "3. Print Stack" << endl;
                    cout << "4. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> stackChoice;

                    switch (stackChoice) 
					{
                        case 1:
                            cout << "Enter element to push: ";
                            cin >> element;
                            myStack.push(element);
                            break;
                        case 2:
                            myStack.pop();
                            break;
                        case 3:
                            myStack.print();
                            break;
                        case 4:
                            cout << "back to the main menu" << endl;
                            break;
                        default:
                            cout << "Invalid choice" << endl;
                            break;
                    }
                } while (stackChoice != 5);
                break;
            case 2:
                int queueChoice;
                do {
                    cout << "\nQueue Operations:" << endl;
                    cout << "1. Enqueue" << endl;
                    cout << "2. Dequeue" << endl;
                    cout << "3. Print Queue" << endl;
                    cout << "4. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> queueChoice;

                    switch (queueChoice) 
					{
                        case 1:
                            cout << "Enter element to enqueue: ";
                            cin >> element;
                            myQueue.enqueue(element);
                            break;
                        case 2:
                            myQueue.dequeue();
                            break;
                        case 3:
                            myQueue.print();
                            break;
                        case 4:
                            cout << "back to main menu" << endl;
                            break;
                        default:
                            cout << "Invalid choice" << endl;
                            break;
                    }
                } 
			while (queueChoice != 5);
                break;
            case 3:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
