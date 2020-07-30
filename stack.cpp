#include "stack.h"
#include <stdlib.h>

StackDataStructure::~StackDataStructure()
{
    NodeOfStack* initialHead = head;
    if (initialHead != nullptr)
    {
        NodeOfStack* tmp = initialHead->next;
        delete initialHead;
        while (tmp != nullptr)
        {
            head = tmp->next;
            delete tmp;
            tmp = head;
        }
    }
}

NodeOfStack* StackDataStructure::insertNode(const std::string& data)
{
    struct NodeOfStack* tmp = new NodeOfStack(data);
    if (tmp == nullptr)
        throw std::invalid_argument("There is no memomy");
    tmp->next = nullptr;

    if (head == nullptr)
    {
        head = tmp;
    }
    else
    {
        tmp->next = head;
        head = tmp;
    }

    return tmp;
}

NodeOfStack *StackDataStructure::removeNode()
{
    if (head == nullptr)
    {
        return nullptr;
    }
    else
    {
        NodeOfStack* tmp = head;
        head = head->next;

        return tmp;
    }
}

NodeOfStack *StackDataStructure::topNode()
{
    return head;
}

std::vector<std::string> StackDataStructure::getElementsAsVector()
{
    std::vector<std::string> vec;
    NodeOfStack* tmp = head;
    while (tmp != nullptr)
    {
        vec.push_back(tmp->data);
        tmp = tmp->next;
    }

    return vec;
}
