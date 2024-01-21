#include <iostream>

struct ListNode
{
    ListNode(int value) : _value(value){};
    int _value;
    struct ListNode *_next = nullptr;
    struct ListNode *_prev = nullptr;
};

void CreateList(ListNode *head, int length)
{
    ListNode* current = head;

    while (length > 0)
    {
        --length;
        ListNode* new_node = new ListNode(length);
        new_node->_prev = current;
        current->_next = new_node;
        current = new_node;
    }
}

void TraverseList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << "prev: " << current->_prev << "; Value: " << current->_value << "; next: " << current->_next <<std::endl;
        current = current->_next;
    }
}

int main()
{
    const int length = 5;
    ListNode *head = new ListNode(length);
    CreateList(head, length);
    TraverseList(head);
    return 0;
}