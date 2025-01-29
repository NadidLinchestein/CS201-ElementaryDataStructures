/*
    C++ Singly Linked List:
    
    Insertion – At the beginning and end.
    Deletion – Removes a node by value.
    Search – Checks if a value exists.
    Print – Displays the list.
    Count Nodes – Returns the total nodes.
    Clear List – Deletes all nodes.
    Destructor – Frees memory automatically.
*/

#include <iostream>
using namespace std;

// Node structure for a singly linked list
struct Node {
    int data;   // Data part of the node
    Node* next; // Pointer to the next node
    
    // Constructor for easy initialization
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head; // Head pointer to the first node

public:
    // Constructor initializes an empty list
    SinglyLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value); // Create a new node with given value
        
        // If the list is empty, new node becomes the head
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) { // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode; // Link last node to the new node
        }
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head; // New node points to old head
        head = newNode;       // Update head pointer
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;
        
        // If head node itself holds the value to be deleted
        if (temp != nullptr && temp->data == value) {
            head = temp->next; // Move head to next node
            delete temp;
            return;
        }
        
        // Search for the node to be deleted, keeping track of the previous node
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        
        // If value not found, exit
        if (temp == nullptr) {
            cout << "Node not found!\n";
            return;
        }
        
        // Unlink the node from the list
        prev->next = temp->next;
        delete temp;
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

    // Function to print the list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
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
        head = nullptr; // Reset head pointer
    }
    
    // Destructor to free allocated memory when object is destroyed
    ~SinglyLinkedList() {
        clearList(); // Ensure all nodes are deleted
    }
};

// Main function to test the linked list features
int main() {
    SinglyLinkedList sll;
    
    // Inserting values at the end of the list
    sll.insertAtEnd(10);
    sll.insertAtEnd(20);
    sll.insertAtEnd(30);
    sll.insertAtBeginning(5);
    
    // Displaying the list
    cout << "Linked List: ";
    sll.printList();
    
    // Searching for a value
    cout << "Searching for 20: " << (sll.search(20) ? "Found" : "Not Found") << "\n";
    cout << "Searching for 100: " << (sll.search(100) ? "Found" : "Not Found") << "\n";
    
    // Counting nodes
    cout << "Total nodes in list: " << sll.countNodes() << "\n";
    
    // Deleting a node
    sll.deleteNode(20);
    cout << "Linked List after deleting 20: ";
    sll.printList();
    
    // Clearing the entire list
    sll.clearList();
    cout << "Linked List after clearing: ";
    sll.printList();
    
    return 0;
}