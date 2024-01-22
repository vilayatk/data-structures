#include <iostream>

struct ListNode
{
    ListNode(int value) : _value(value){};
    int _value;
    struct ListNode *next = nullptr;
    struct ListNode *prev = nullptr;
};

void CreateList(ListNode *head, int length)
{
    ListNode* current = head;

    while (length > 0)
    {
        --length;
        ListNode* new_node = new ListNode(length);
        new_node->prev = current;
        current->next = new_node;
        current = new_node;
    }
}

void TraverseList(ListNode *head)
{
    if (head == nullptr) {
        std::cout << "Is null";
        return;
    }
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << "prev: " << current->prev << "; Value: " << current->_value << "; next: " << current->next <<std::endl;
        current = current->next;
    }
    std::cout << std::endl << std::endl;
}

void InsertNodeAt(ListNode*& head, int position, int value)
{
    ListNode* new_node = new ListNode(value);
    if (position == 0)
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }
    ListNode* current = head;
    int counter = 0;

    while (counter < position && current->next != nullptr) {
        current = current->next;
        counter++;
    }
    if (counter == position) {
        new_node->prev = current->prev;
        new_node->next = current;

        current->prev->next = new_node;
        current->prev = new_node;
    } else {
        new_node->prev = current;
        current->next = new_node;
    }
}

void DeleteNodeAt(ListNode*& head, int position)
{
    if (position == 0)
    {
        auto delete_node = head;
        head = head->next;
        head->prev = nullptr;
        delete delete_node;
        return;
    }

    ListNode* current = head;
    int counter = 0;
    while (counter < position)
    {
        current = current->next;
        counter++;
    }
    if (position == counter)
    {
        auto delete_node = current;
        if (current->next != nullptr) // except for last node
        {
            current->next->prev = current->prev;
        }
        current->prev->next = current->next;
        delete delete_node;
    }
}

void DeleteList(ListNode*& head)
{
    ListNode* current = head;

    while (current != nullptr)
    {
        auto next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}
int main()
{
    const int length = 5;
    ListNode *head = new ListNode(length);
    CreateList(head, length);
    DeleteList(head);
    TraverseList(head);
    return 0;
}