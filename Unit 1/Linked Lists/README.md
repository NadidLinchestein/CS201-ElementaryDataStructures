### Linked Lists in C++

#### Introduction to Linked Lists

A **Linked List** is a linear data structure where elements, known as nodes, are linked using pointers. Unlike arrays, linked lists do not require a contiguous block of memory and can dynamically grow or shrink in size. Each node in a linked list contains two components:

1. **Data**: The actual value stored in the node.
2. **Pointer**: A reference to the next node in the sequence.

Types of Linked Lists:

1. **Singly Linked List**: Nodes are linked in one direction, from head to tail.
2. **Doubly Linked List**: Nodes contain references to both the previous and next nodes.
3. **Circular Linked List**: The last node points back to the first node, forming a circle.

Advantages of Linked Lists:

- Dynamic size adjustment.
- Efficient insertions and deletions compared to arrays.
- No need for pre-allocation of memory.

Disadvantages of Linked Lists:

- Higher memory usage due to pointers.
- Sequential access makes operations like searching slower than arrays.
- Complex implementation compared to arrays.

---

#### Singly Linked List (SLL)

A **Singly Linked List** is the simplest form of linked list where each node contains data and a pointer to the next node. The last node’s pointer is set to `nullptr`, indicating the end of the list.

##### Node Structure

```cpp
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
```

##### Key Operations

1. **Insertion**:

   - At the beginning:
     ```cpp
     void insertAtHead(Node*& head, int value) {
         Node* newNode = new Node(value);
         newNode->next = head;
         head = newNode;
     }
     ```
   - At the end:
     ```cpp
     void insertAtTail(Node*& head, int value) {
         Node* newNode = new Node(value);
         if (!head) {
             head = newNode;
             return;
         }
         Node* temp = head;
         while (temp->next) temp = temp->next;
         temp->next = newNode;
     }
     ```

2. **Deletion**:

   - By value:
     ```cpp
     void deleteByValue(Node*& head, int value) {
         if (!head) return;
         if (head->data == value) {
             Node* temp = head;
             head = head->next;
             delete temp;
             return;
         }
         Node* temp = head;
         while (temp->next && temp->next->data != value) {
             temp = temp->next;
         }
         if (temp->next) {
             Node* nodeToDelete = temp->next;
             temp->next = temp->next->next;
             delete nodeToDelete;
         }
     }
     ```

3. **Traversal**:

   ```cpp
   void printList(Node* head) {
       while (head) {
           std::cout << head->data << " -> ";
           head = head->next;
       }
       std::cout << "nullptr\n";
   }
   ```

4. **Search**:
   ```cpp
   bool search(Node* head, int value) {
       while (head) {
           if (head->data == value) return true;
           head = head->next;
       }
       return false;
   }
   ```

---

#### Doubly Linked List (DLL)

A **Doubly Linked List** contains nodes with pointers to both the previous and the next nodes, allowing traversal in both directions. The first node’s previous pointer and the last node’s next pointer are set to `nullptr`.

##### Node Structure

```cpp
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};
```

##### Key Operations

1. **Insertion**:

   - At the beginning:
     ```cpp
     void insertAtHead(Node*& head, int value) {
         Node* newNode = new Node(value);
         if (head) {
             newNode->next = head;
             head->prev = newNode;
         }
         head = newNode;
     }
     ```
   - At the end:
     ```cpp
     void insertAtTail(Node*& head, int value) {
         Node* newNode = new Node(value);
         if (!head) {
             head = newNode;
             return;
         }
         Node* temp = head;
         while (temp->next) temp = temp->next;
         temp->next = newNode;
         newNode->prev = temp;
     }
     ```

2. **Deletion**:

   - By value:
     ```cpp
     void deleteByValue(Node*& head, int value) {
         if (!head) return;
         if (head->data == value) {
             Node* temp = head;
             head = head->next;
             if (head) head->prev = nullptr;
             delete temp;
             return;
         }
         Node* temp = head;
         while (temp && temp->data != value) {
             temp = temp->next;
         }
         if (temp) {
             temp->prev->next = temp->next;
             if (temp->next) temp->next->prev = temp->prev;
             delete temp;
         }
     }
     ```

3. **Traversal**:

   - Forward:
     ```cpp
     void printList(Node* head) {
         while (head) {
             std::cout << head->data << " <-> ";
             head = head->next;
         }
         std::cout << "nullptr\n";
     }
     ```
   - Backward:
     ```cpp
     void printReverse(Node* tail) {
         while (tail) {
             std::cout << tail->data << " <-> ";
             tail = tail->prev;
         }
         std::cout << "nullptr\n";
     }
     ```

4. **Search**:
   ```cpp
   bool search(Node* head, int value) {
       while (head) {
           if (head->data == value) return true;
           head = head->next;
       }
       return false;
   }
   ```

---

#### Comparison of SLL and DLL

| Feature             | Singly Linked List      | Doubly Linked List       |
| ------------------- | ----------------------- | ------------------------ |
| Memory Usage        | Less (one pointer/node) | More (two pointers/node) |
| Traversal Direction | Forward only            | Forward and backward     |
| Insertion/Deletion  | Faster for single links | Slower but bidirectional |
| Complexity          | Easier to implement     | More complex structure   |

---

### Conclusion

Linked Lists are powerful data structures that provide flexibility in memory management and dynamic sizing. Singly Linked Lists are suitable for simple tasks where one-direction traversal suffices, while Doubly Linked Lists offer enhanced functionality for more complex scenarios requiring bidirectional traversal. Choosing the right type depends on the specific requirements of your application.
