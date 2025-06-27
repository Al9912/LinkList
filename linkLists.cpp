#include <iostream>
#include "linkLists.h"

using namespace std;

linkLists::linkLists(/* args */)
{
    head = nullptr;
}

linkLists::~linkLists()
{
    listNode *nodePtr; // To traverse the list
    listNode *nextNode; // A new node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
    head = nullptr;
}

void linkLists::appendNode (double num)
{
	listNode *newNode; // To point to a new node
	listNode *nodePtr; // To move through the list

	// Allocate a new node and store num there.
	newNode = new listNode;
	newNode-> value = num;
	newNode->next = nullptr;

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
    {
		head = newNode;
    }
	else // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		
		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}

void linkLists::insertNode(double num)
{
    listNode *newNode; // A new node
    listNode *nodePtr; // To traverse the list
    listNode *previousNode = nullptr; // The previous node

    // Allocate a new node and store num there.
    newNode = new listNode;
    newNode->value = num;

    // If there are no nodes in the list 
    // make newNode the first node
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else // Otherwise, insert newNode
    {
        // Position nodePtr at the head of list.
        nodePtr = head;

        // Initialize previousNode to nullptr. 
        previousNode = nullptr;

        // Skip all nodes whose value is less than num.
        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr; 
            nodePtr = nodePtr->next;
        }

        // If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else // Otherwise insert after the previous node.
        {
            previousNode->next = newNode; 
            newNode->next = nodePtr;
        }
    }
}

void linkLists::deleteNode(double num)
{
    listNode *nodePtr; // To traverse the list
    listNode *previousNode = nullptr; // The previous node

    // If the list is empty, do nothing.
    if (!head)
    {
        return;
    }
    // Determine if the first node is the one.
    else if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Skip all nodes whose value member is not equal to num.
        while (nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        // If nodePtr is not at the end of the list, link the previous node
        // after nodePtr, then delete nodePtr.
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

void linkLists::reverse()
{
    listNode *nextNode; // Next
    listNode *currNode; // Current
    listNode *previousNode = nullptr; // The previous node

    // If there are no nodes in the list 
    // make newNode the first node
    if (!head)
    {
        head = currNode;
        currNode->next = nullptr;
    }
    else // Otherwise, insert currNode
    {
        // Position currNode at the head of list.
        currNode = head;

        // Initialize previousNode to nullptr. 
        previousNode = nullptr;

        while (currNode != nullptr)
        {
            nextNode = currNode->next;
            currNode->next = previousNode;

            previousNode = currNode;
            currNode = nextNode;
        }
        head = previousNode;
    }
}

void linkLists::displayList()
{
    listNode *nodePtr = head; // To traverse the list

    cout << "|\t";
    if (nodePtr == nullptr)
    {
        cout << "Error: The list is blank. Please insert something.\t|" << endl;
    }
    

    while (nodePtr != nullptr)
    {
        cout << nodePtr->value << "\t|\t";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

bool linkLists::isMember(double num)
{
    listNode *nodePtr = head; // To traverse the list

    cout << "|\t";
    if (nodePtr == nullptr)
    {
        cout << "Error: The list is blank. Please insert something.\t|" << endl;
        return false;
    }

    while (nodePtr != nullptr)
    {
        if (nodePtr ->value == num)
        {
            return true;
        }
        else
        {
            nodePtr = nodePtr->next;
        }
    }
    // If tere is nothing.
    return false;
}