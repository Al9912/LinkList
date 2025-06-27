#ifndef H_linkLists
#define H_linkLists

class linkLists
{
    private:
        struct listNode
        {
            double value;
            listNode *next;
        };
        listNode *head;
    public:
        linkLists(/* args */);
        ~linkLists();
        void appendNode (double num);
        void insertNode(double num);
        void deleteNode(double num);
        void reverse();
        bool isMember(double num);
        void displayList();
};

#include "linkLists.cpp"

#endif