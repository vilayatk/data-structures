#include <iostream>

struct ListNode
{
    ListNode(int value = 0) : _value(value){};
    int _value;
    struct ListNode *next = nullptr;
};

void TraverseList(ListNode *head)
{
    auto current = head;
    while (true)
    {
        std::cout << "value: " << current->_value << "; at: " << current << "; next:" << current->next << std::endl;
        current = current->next;
        if (current == head)
            break;
    }
    std::cout << std::endl
              << std::endl
              << std::endl;
}

void CreateList(ListNode *head, int count)
{
    auto current = head;
    while (count > 0)
    {
        current->next = new ListNode(--count);
        current = current->next;
    }
    current->next = head;
}

int main()
{
    const int length = 6;

    auto head = new ListNode(length);
    CreateList(head, length);
    TraverseList(head);

    return 0;
}