//Hey, can you make me a C++ file that is named 'memoryLeaks.cpp' and has at least 6 memory leaks?

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void createLeak1() {
    // Leak 1: Dynamic integer allocation without delete
    int* ptr = new int(5);
    std::cout << "Leak 1: Integer value " << *ptr << std::endl;
    // `delete ptr;` is missing here
}

void createLeak2() {
    // Leak 2: Array allocation without delete[]
    int* arr = new int[10];
    arr[0] = 10;
    std::cout << "Leak 2: Array value " << arr[0] << std::endl;
    // `delete[] arr;` is missing here
}

void createLeak3() {
    // Leak 3: Custom object allocation without delete
    Node* node = new Node(20);
    std::cout << "Leak 3: Node data " << node->data << std::endl;
    // `delete node;` is missing here
}

void createLeak4() {
    // Leak 4: Multiple allocations, only one is deleted
    int* a = new int(15);
    int* b = new int(25);
    std::cout << "Leak 4: Integer a = " << *a << ", b = " << *b << std::endl;
    delete a;  // Only one of them is deleted
    // `delete b;` is missing here
}

void createLeak5() {
    // Leak 5: Dynamically allocated linked list without deletion
    Node* head = new Node(30);
    head->next = new Node(40);
    head->next->next = new Node(50);
    std::cout << "Leak 5: Linked list created starting with " << head->data << std::endl;
    // Nodes are not deleted
}

void createLeak6() {
    // Leak 6: Unreleased allocation in a loop
    for (int i = 0; i < 3; ++i) {
        int* ptr = new int(i);
        std::cout << "Leak 6: Integer in loop " << *ptr << std::endl;
        // `delete ptr;` is missing here
    }
}

int main() {
    createLeak1();
    createLeak2();
    createLeak3();
    createLeak4();
    createLeak5();
    createLeak6();

    std::cout << "Program completed with intentional memory leaks." << std::endl;
    return 0;
}
