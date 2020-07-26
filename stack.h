#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

/*!
 * \brief The NodeOfStack struct
 */
struct NodeOfStack
{
    /*!
     * \brief NodeOfStack
     */
    NodeOfStack()
    {
        next = nullptr;
        this->data = "";
    }
    /*!
     * \brief NodeOfStack
     * \param data
     */
    NodeOfStack(const std::string& data)
    {
        this->data = data;
        next = nullptr;
    }

    std::string data = "";
    struct NodeOfStack* next = nullptr;
};

/*!
 * \brief The Stack class
 */
class Stack
{
public:
    /*!
     * \brief Stack
     */
    Stack(){}
    
    ~Stack();
    /*!
     * \brief insertNode
     * \param data
     * \return
     */
    NodeOfStack* insertNode(const std::string& data);

    /*!
     * \brief removeNode
     * \return
     */
    struct NodeOfStack* removeNode();

    /*!
     * \brief topNode
     * \return
     */
    struct NodeOfStack* topNode();

    /*!
     * \brief getElementsAsVector
     * \return
     */
    std::vector<std::string> getElementsAsVector();

private:
    NodeOfStack* head = nullptr;
};

#endif // STACK_H
