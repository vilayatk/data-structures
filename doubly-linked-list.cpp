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
    std::cout << std::endl << std::endl;
}

void InsertNodeAt(ListNode*& head, int position, int value)
{
    if (position == 0)
    {
        ListNode* new_node = new ListNode(value);
        new_node->_next = head;
        head->_prev = new_node;
        head = new_node;
        return;
    }
    ListNode* current = head;
    int counter = 0;

    while (counter < position) {
        current = current->_next;
        counter++;
    }
    if (counter == position) {
        ListNode* new_node = new ListNode(value);
        new_node->_prev = current->_prev;
        new_node->_next = current;

        current->_prev->_next = new_node;
        current->_prev = new_node;
    }
}

int main()
{
    const int length = 5;
    ListNode *head = new ListNode(length);
    CreateList(head, length);
    TraverseList(head);
    InsertNodeAt(head, 2, 500);
    TraverseList(head);
    return 0;
}