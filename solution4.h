#pragma once
#include <string>

class Node {
public:
    char character;
    Node* next = nullptr;
    Node(char c) : character(c), next(nullptr) {}
};

class SLL {
private:
    Node* head {nullptr}, *tail {nullptr};
    int length = 0;
public:
    SLL() = default;
    void insert(std::string s);
    std::string upholdChallenge(std::string s, int value);
    void destruct();
};