/*
    C++ Circular Linked List:

    Insertion – At beginning and end.
    Deletion – Removes a node by value.
    Search – Checks if a value exists.
    Print – Displays the list.
    Count Nodes – Returns total nodes.
    Clear List – Deletes all nodes.
    Destructor – Frees memory automatically. 
*/

#include <iostream>
using namespace std;

// Node structure for a circular linked list
struct Node {
    int data;   // Data part of the node
    Node* next; // Pointer to the next node
    
    // Constructor for easy initialization
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head; // Head pointer to the first node

public:
    // Constructor initializes an empty list
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        // If the list is empty, new node becomes the head and points to itself
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) { // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode; // Link last node to new node
            newNode->next = head; // New node points back to head
        }
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) { // Traverse to the last node
                temp = temp->next;
            }
            newNode->next = head; // New node points to old head
            temp->next = newNode; // Last node points to new node
            head = newNode;       // Update head pointer
        }
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        Node* temp = head;
        Node* prev = nullptr;
        
        // If head node holds the value to be deleted
        if (head->data == value) {
            if (head->next == head) { // Only one node in the list
                delete head;
                head = nullptr;
                return;
            }
            
            while (temp->next != head) { // Find last node
                temp = temp->next;
            }
            temp->next = head->next; // Last node points to second node
            delete head;
            head = temp->next; // Update head
            return;
        }
        
        // Search for the node to be deleted
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != value);
        
        // If value not found, exit
        if (temp == head) {
            cout << "Node not found!\n";
            return;
        }
        
        prev->next = temp->next;
        delete temp;
    }

    // Function to search for a value in the list
    bool search(int value) {
        if (head == nullptr) return false;
        
        Node* temp = head;
        do {
            if (temp->data == value) return true;
            temp = temp->next;
        } while (temp != head);
        
        return false;
    }

    // Function to print the list
    void printList() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
    
    // Function to count the number of nodes in the list
    int countNodes() {
        if (head == nullptr) return 0;
        
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        
        return count;
    }
    
    // Function to clear the entire list
    void clearList() {
        if (head == nullptr) return;
        
        Node* temp = head;
        while (head->next != head) {
            Node* nextNode = head->next;
            temp->next = nextNode->next;
            delete nextNode;
        }
        delete head;
        head = nullptr;
    }
    
    // Destructor to free allocated memory when object is destroyed
    ~CircularLinkedList() {
        clearList(); // Ensure all nodes are deleted
    }
};

// Main function to test the circular linked list features
int main() {
    CircularLinkedList cll;
    
    // Inserting values at the end of the list
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtBeginning(5);
    
    // Displaying the list
    cout << "Circular Linked List: ";
    cll.printList();
    
    // Searching for a value
    cout << "Searching for 20: " << (cll.search(20) ? "Found" : "Not Found") << "\n";
    cout << "Searching for 100: " << (cll.search(100) ? "Found" : "Not Found") << "\n";
    
    // Counting nodes
    cout << "Total nodes in list: " << cll.countNodes() << "\n";
    
    // Deleting a node
    cll.deleteNode(20);
    cout << "Circular Linked List after deleting 20: ";
    cll.printList();
    
    // Clearing the entire list
    cll.clearList();
    cout << "Circular Linked List after clearing: ";
    cll.printList();
    
    return 0;
}