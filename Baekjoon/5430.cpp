#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define MAX_SIZE 100000

class Deque {
    typedef struct Node {
        int data;
        Node* left;
        Node* right;
    }Node;
    Node* head;
    Node* tail;
    int size;
    bool isReverse;
public:
    Deque()
        : head(nullptr), tail(nullptr), size(0), isReverse(false)
    {}

    Node* CreateNode(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return(size == 0);
    }

    void Push(int data) {
        Node* newNode = CreateNode(data);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            if (isReverse) {
                tail->left = newNode;
                tail = newNode;
            }
            else {
                tail->right = newNode;
                newNode->left = tail;
                tail = newNode;
                newNode->right = nullptr;
            }
        }
        ++size;
        return;
    }

    void Drop() {
        if (size == 0)
            return;

        Node* removeNode;
        removeNode = head;

        if (isReverse) {
            head = head->left;
            delete removeNode;
        }
        else {
            head = head->right;
            delete removeNode;
        }
        --size;
        return;
    }

    void Reverse() {
        Node* temp;
        temp = head;
        head = tail;
        tail = temp;

        isReverse = isReverse ? false : true;
        return;
    }

    void Print(bool& isError) {
        if (isError) {
            isError = false;
            cout << "error" << endl;
            return;
        }

        Node* current = head;
        cout << '[';
        if (size != 0) {
            for (int i = 0; i < size; i++) {
                if (i == 0)
                    cout << current->data;
                else
                    cout << ',' << current->data;

                if (isReverse)
                    current = current->left;
                else
                    current = current->right;
            }
        }
        cout << ']' << endl;
    }
};

int main()
{
    bool isError = false;
    int num_testCase;
    cin >> num_testCase;

    for (int i = 0; i < num_testCase; i++) {
        Deque dq;
        string function;
        int num;
        string arr;

        // input
        if (i == 0) {
            cin.ignore();
        }
        getline(cin, function, '\n');
        cin >> num;
        cin.ignore();
        getline(cin, arr, '\n');

        char ch;
        int intBuff = 0;
        stringstream ss(arr);
    
        while(ss >> ch) {
            if (isdigit(ch)) {
                ss.unget();
                ss >> intBuff;
                dq.Push(intBuff);
            }
        }

        for (int j = 0; j < function.length(); j++) {
            if (function[j] == 'D') {
                if (dq.getSize() == 0) {
                    isError = true;
                    break;
                }
                dq.Drop();
            }
            else if (function[j] == 'R') {
                dq.Reverse();
            }
        }

        dq.Print(isError);
    }
}
