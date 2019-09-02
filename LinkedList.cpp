#include <iostream>

struct Node {
    int key;
    Node* next;

    Node(const int key=0) {
        this->key = key;
    }
};

class LinkedList{
public:
    LinkedList() {
        head = new Node();
        head->next = head;
    }

    void insert(const int key) {
        auto tmp = new Node(key);
        tmp->next = head->next;
        head->next = tmp;
    }

    void append(const int key) {
        auto new_node = new Node(key), i = head;
        while(i->next != head) {
            i = i->next;
        }
        i->next = new_node;
        new_node->next = head;
    }

    void remove(const int key) {
        for(auto i = head->next, j = head; i != head; i=i->next) {
            if(i->key == key) {
                j->next = i->next;
                delete i;
                continue;
            }
            j = j->next;
        }
    }

    void peek() {
        std::cout << "head-> ";
        for(Node* i = head->next; i != head; i=i->next) {
            std::cout << i->key << " ";
        } std::cout << "\n";
    }

private:
    Node* head;
};

int main() {
    auto myList = new LinkedList();
    for(int i=0; i < 100; ++i) {
        if(i%2 != 0) {
            myList->append(i-1);
            continue;
        }
        myList->append(i);
    }

    myList->remove(98);
    myList->peek();

    delete myList;
    return 0;
}
