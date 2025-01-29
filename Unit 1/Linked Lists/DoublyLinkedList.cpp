/*
    C++ doubly linked list:

    Insertion at both ends.
    Deletion of a node by value.
    Searching for a value.
    Forward & backward traversal.
    Proper memory management with a destructor.
*/

#include <iostream>
using namespace std;

// Node structure for a doubly linked list
struct Node {
    int data;   // Data part of the node
    Node* prev; // Pointer to the previous node
    Node* next; // Pointer to the next node
    
    // Constructor for easy initialization
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head; // Head pointer to the first node
    Node* tail; // Tail pointer to the last node

public:
    // Constructor initializes an empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value); // Create a new node with given value
        
        // If the list is empty, new node becomes both head and tail
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode; // Link last node's next to new node
            newNode->prev = tail; // Link new node's prev to last node
            tail = newNode;        // Update tail pointer
        }
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head; // New node points to old head
            head->prev = newNode; // Old head points back to new node
            head = newNode;       // Update head pointer
        }
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        Node* temp = head;
        
        // Search for the node with the given value
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }
        
        // If node not found, exit function
        if (temp == nullptr) {
            cout << "Node not found!\n";
            return;
        }
        
        // If node is the only node in the list
        if (head == tail) {
            delete temp;
            head = tail = nullptr;
        } 
        // If node is the head
        else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
            delete temp;
        } 
        // If node is the tail
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        } 
        // If node is in the middle
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    // Function to search for a value in the list
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true; // Value found in list
            }
            temp = temp->next;
        }
        return false; // Value not found
    }

    // Function to print the list in forward order
    void printForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Function to print the list in reverse order
    void printBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
    
    // Function to count the number of nodes in the list
    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    // Function to clear the entire list
    void clearList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = nullptr; // Reset head and tail
    }
    
    // Destructor to free allocated memory when object is destroyed
    ~DoublyLinkedList() {
        clearList(); // Ensure all nodes are deleted
    }
};

// Main function to test the linked list features
int main() {
    DoublyLinkedList dll;
    
    // Inserting values at the end of the list
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtBeginning(5);
    
    // Displaying the list
    cout << "Linked List (Forward): ";
    dll.printForward();
    cout << "Linked List (Backward): ";
    dll.printBackward();
    
    // Searching for a value
    cout << "Searching for 20: " << (dll.search(20) ? "Found" : "Not Found") << "\n";
    cout << "Searching for 100: " << (dll.search(100) ? "Found" : "Not Found") << "\n";
    
    // Counting nodes
    cout << "Total nodes in list: " << dll.countNodes() << "\n";
    
    // Deleting a node
    dll.deleteNode(20);
    cout << "Linked List after deleting 20 (Forward): ";
    dll.printForward();
    
    // Clearing the entire list
    dll.clearList();
    cout << "Linked List after clearing: ";
    dll.printForward();
    
    return 0;
}