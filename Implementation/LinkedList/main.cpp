#include <iostream>
#include <string>
#include <memory>

template<typename T>
struct Node
{
	Node(T val)
	{
		value = val;
		next = nullptr;
	}
	T value;
	std::shared_ptr<Node> next;
};

template<typename T>
void AddNode(std::shared_ptr<Node<T>> head, const T value)
{
	auto temp = head;

	while (true)
	{
		if (temp->next == nullptr)
		{
			temp->next.reset(new Node<T>(value));
			break;
		}
		temp = temp->next;
	}
}

template<typename T>
void PrintList(std::shared_ptr<Node<T>> head)
{
	auto temp = head;
	std::cout << "{ ";
	while (temp != nullptr)
	{
		std::cout << temp->value << ", ";
		temp = temp->next;
	}
	std::cout << "}";
}

template<typename T>
void ReverseList(std::shared_ptr<Node<T>> head)
{
	auto temp = head;
	std::cout << "{ ";
	while (temp != nullptr)
	{
		std::cout << temp->value << ", ";
		temp = temp->next;
	}
	std::cout << "}";
}



int main()
{
	auto head = std::make_shared<Node<std::string>>("1");

	AddNode(head, std::string("2df"));
	AddNode(head, std::string("3f"));
	AddNode(head, std::string("4f"));
	AddNode(head, std::string("5f"));

	PrintList(head);
}