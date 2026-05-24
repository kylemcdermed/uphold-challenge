#include <string>
#include "solution4.h"

using namespace std;

void SLL::insert(string s) {
    for (int i = 0; i < s.size(); ++i) {
        Node* newNode = new Node(s[i]);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
}

string SLL::upholdChallenge(string s, int value) {
    insert(s);

    int count = 0;
    Node* fast = head, *prev = nullptr;

    while (fast != nullptr) {
        if (isdigit(fast->character)) {
            count++;
            fast = fast->next;
        } else {
            if (count > 0) {
                int numberOfZeros = value - count;
                while (numberOfZeros > 0) {
                    Node* newNode = new Node('0');
                    length++;
                    if (prev == nullptr) {
                        newNode->next = head;
                        head = newNode;
                    } else {
                        newNode->next = prev->next;
                        prev->next = newNode;
                    }
                    prev = newNode;
                    numberOfZeros--;
                }
                count = 0;
                prev = fast;
                fast = fast->next;
            } else {
                prev = fast;
                fast = fast->next;
            }
        }
    }

    if (count > 0) {
        int numberOfZeros = value - count;
        while (numberOfZeros > 0) {
            Node* newNode = new Node('0');
            length++;
            if (prev == nullptr) {
                newNode->next = head;
                head = newNode;
            } else {
                newNode->next = prev->next;
                prev->next = newNode;
            }
            prev = newNode;
            numberOfZeros--;
        }
    }

    string result = "";
    Node* temp = head;
    while (temp != nullptr) {
        result += temp->character;
        temp = temp->next;
    }

    destruct();
    return result;
}

void SLL::destruct() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
        --length;
    }
    tail = nullptr;
}