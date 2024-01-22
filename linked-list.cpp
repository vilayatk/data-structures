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
        if (current == nullptr)
            break;

        std::cout << "value: " << current->_value << "; at: " << current << "; next:" << current->next << std::endl;
        current = current->next;
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
}

void InsertNodeAt(ListNode *&head, int value, int position)
{
    if (position == 0)
    {
        auto new_node = new ListNode(value);
        new_node->next = head;
        head = new_node;
    }

    auto node = head;
    int counter = 0;

    while (true)
    {
        if (counter == position)
        {
            auto old_reference = node->next;
            node->next = new ListNode(value);
            node->next->next = old_reference;
            break;
        }
        else if (node->next == nullptr)
        {
            node->next = new ListNode();
        }
        node = node->next;
        counter++;
    }
}

void DeleteNodeAt(ListNode *&head, int position)
{
    if (position == 0)
    {
        ListNode *delete_ptr = head;
        head = head->next;
        free(delete_ptr);
        return;
    }

    int counter = 0;
    auto node = head;
    while (counter < (position - 1) && node->next != nullptr)
    {
        node = node->next;
        counter++;
    }
    if (counter == (position - 1))
    {
        ListNode *delete_ptr = node->next;
        node->next = node->next->next;
        free(delete_ptr);
    }
    else
    {
        std::cout << "Cannot delete what does not exist!";
    }
}

void DeleteList(ListNode *&head)
{
    ListNode *node = head;

    while (node != nullptr)
    {
        auto next_node = node->next;
        free(node);
        node = next_node;
    }
    head = nullptr;
}

void ReverseList(ListNode*& head)
{
    ListNode* current = head;
    ListNode* previous = NULL;

    while(current != nullptr)
    {
        auto next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

int main()
{
    const int length = 6;

    auto head = new ListNode(length);
    CreateList(head, length);
    TraverseList(head);
    ReverseList(head);
    TraverseList(head);
    return 0;
}