#pragma once 
#include <iostream> 

using namespace std;

class Queue {

private:

	int* data;

	int capacity;

	int first;

	int last;

	int size;

public:

	Queue();

	void push(int value);

	int pop()throw(int);

	friend ostream& operator << (ostream& out, const Queue& q);

	friend istream& operator >> (istream& in, Queue& q);

	int* begin();

	int* end();

	~Queue() {

		delete[]data;

	};

};



Queue::Queue() {

	data = new int[10];

	capacity = 10;

	first = 0;

	last = 0;

	size = 0;

}



void Queue::push(int value) {

	if (last == capacity) {

		int* tmp = new int[capacity * 2];

		for (int i = 0; i < capacity; i++) {

			tmp[i] = data[i];

		}

		capacity *= 2;

		delete[] data;

		data = tmp;

	}

	data[last] = value;

	last++;

	size++;

}



int Queue::pop()throw(int) {

	if (size == 0) {

		throw(1);

	}

	int result = data[first];

	first++;

	size--;

	return result;

}



ostream& operator <<(ostream& out, const Queue& q) {

	for (int i = q.first; i < q.last; i++) {

		cout << q.data[i] << " ";

	}

	return out;

}



istream& operator >>(istream& in, Queue& q) {

	int value;

	in >> value;

	q.push(value);

	return in;

}



int* Queue::begin() {

	return data + first;

}



int* Queue::end() {

	return data + last;

}



template<typename Q>

void ShowQueue(Q& q) {

	for (int* iter = q.begin(); iter < q.end(); iter++) {

		cout << (*iter) << " ";

	}

	cout << endl;

}



template<typename Q>

void InputQueue(Q& q) {

	cout << "Input value: ";

	int value;

	cin >> value;

	q.push(value);

}



int main() {

	Queue q1;

	q1.push(38);

	cout << "push(38): " << q1 << endl;

	q1.push(-25);

	cout << "push(-25): " << q1 << endl;

	int k = q1.pop();

	cout << "pop(): value: " << k << ", queue: " << q1 << endl;

	q1.push(10);

	cout << "push(10): " << q1 << endl;

	q1.push(3);

	cout << "push(3): " << q1 << endl;

	int m = q1.pop();

	cout << "pop(): value: " << m << ", queue: " << q1 << endl;

	cout << "Input value: ";

	cin >> q1;

	cout << "queue: " << q1 << endl;

	ShowQueue<Queue>(q1);

	InputQueue<Queue>(q1);

	ShowQueue<Queue>(q1);



	return 0;

}