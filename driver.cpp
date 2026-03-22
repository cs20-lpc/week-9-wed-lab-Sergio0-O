#include <iostream>
#include <string>
#include "ArrayQueue.hpp"
using namespace std;

template <typename T>
void printQueue(ArrayQueue<T> queueCopy) {
    cout << "Queue: ";

    if (queueCopy.isEmpty()) {
        cout << "empty";
    }
    else {
        while (!queueCopy.isEmpty()) {
            cout << queueCopy.front() << " ";
            queueCopy.dequeue();
        }
    }

    cout << endl;
}

int main() {
    try {
        cout << "Int queue test" << endl;
        ArrayQueue<int> numbers(5);

        cout << "Is empty? ";
        if (numbers.isEmpty()) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }

        numbers.enqueue(10);
        numbers.enqueue(20);
        numbers.enqueue(30);

        printQueue(numbers);

        cout << "Front: " << numbers.front() << endl;
        cout << "Back: " << numbers.back() << endl;
        cout << "Length: " << numbers.getLength() << endl;

        numbers.dequeue();
        cout << "After one dequeue:" << endl;
        printQueue(numbers);

        numbers.enqueue(40);
        numbers.enqueue(50);
        numbers.enqueue(60);

        cout << "After more enqueues:" << endl;
        printQueue(numbers);

        cout << "Is full? ";
        if (numbers.isFull()) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }

        cout << endl;
        cout << "Circular behavior test" << endl;

        numbers.dequeue();
        numbers.dequeue();
        numbers.enqueue(70);
        numbers.enqueue(80);

        printQueue(numbers);
        cout << "Front: " << numbers.front() << endl;
        cout << "Back: " << numbers.back() << endl;

        cout << endl;
        cout << "Copy constructor test" << endl;

        ArrayQueue<int> copyQueue(numbers);
        printQueue(copyQueue);

        cout << endl;
        cout << "Assignment operator test" << endl;

        ArrayQueue<int> otherQueue(3);
        otherQueue.enqueue(1);
        otherQueue.enqueue(2);
        otherQueue = numbers;

        printQueue(otherQueue);

        cout << endl;
        cout << "Clear test" << endl;

        numbers.clear();
        cout << "After clear:" << endl;
        printQueue(numbers);

        cout << "Is empty? ";
        if (numbers.isEmpty()) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }

        cout << endl;
        cout << "String queue test" << endl;

        ArrayQueue<string> fruits(4);
        fruits.enqueue("apple");
        fruits.enqueue("banana");
        fruits.enqueue("cherry");

        printQueue(fruits);
        cout << "Front: " << fruits.front() << endl;
        cout << "Back: " << fruits.back() << endl;

        cout << endl;
        cout << "Exception tests" << endl;

        ArrayQueue<int> testEmpty(2);

        try {
            cout << testEmpty.front() << endl;
        }
        catch (string error) {
            cout << error << endl;
        }

        try {
            testEmpty.dequeue();
        }
        catch (string error) {
            cout << error << endl;
        }

        try {
            ArrayQueue<int> smallQueue(2);
            smallQueue.enqueue(5);
            smallQueue.enqueue(6);
            smallQueue.enqueue(7);
        }
        catch (string error) {
            cout << error << endl;
        }

        try {
            ArrayQueue<int> badQueue(0);
        }
        catch (string error) {
            cout << error << endl;
        }
    }
    catch (string error) {
        cout << error << endl;
    }

    return 0;
}
