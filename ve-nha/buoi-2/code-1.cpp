#include <iostream>
using namespace std;

typedef int Item;

struct Node
{
    Item data;
    Node *pNext;
};

class SList
{
private:
    Node *head;
    Node *tail;
    long size;

public:
    SList();
    ~SList();
    Node *getHead();
    Node *getTail();
    long getSize();
    Node *createNode(const Item &v);
    void addFirst(const Item &v);
    void addLast(const Item &v);
    void insertAfter(Node *p, const Item &v);
    void insertBefore(Node *p, const Item &v);
    void findBefore(Node *p); // chua lam
    void removeFirst();
    void removeLast();
    void remove(Node *p);
    void traverse();
};

int main()
{
    SList list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    list.traverse();
    cout << list.getSize() << endl;
    list.remove(list.getHead()->pNext->pNext);
    list.traverse();
    cout << list.getSize() << endl;

    return 0;
}

SList::SList()
{
    head = tail = NULL;
    size = 0;
}

SList ::~SList()
{
    Node *temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->pNext;
        delete temp;
    }
    size = 0;
}

Node *SList::getHead()
{
    return head;
}

Node *SList::getTail()
{
    return tail;
}

long SList::getSize()
{
    return size;
}

Node *SList::createNode(const Item &v)
{
    Node *n = new Node();
    n->data = v;
    n->pNext = NULL;
    return n;
}

void SList::addFirst(const Item &v)
{
    Node *p = createNode(v);
    if (size == 0)
        head = tail = p;
    else
    {
        p->pNext = head;
        head = p;
    }
    size++;
}

void SList::addLast(const Item &v)
{
    Node *p = createNode(v);
    if (size == 0)
        head = tail = p;
    else
    {
        tail->pNext = p;
        tail = p;
    }
    size++;
}

void SList::insertAfter(Node *p, const Item &v)
{
    Node *q = createNode(v);
    if (p == NULL)
        return;
    else if (p == tail)
        addLast(v);
    else
    {
        q->pNext = p->pNext;
        p->pNext = q;
    }
    size++;
}

void SList::findBefore(Node *p)
{
}

void SList::insertBefore(Node *p, const Item &v)
{
    Node *q = createNode(v);
    if (p == NULL)
        return;
    else if (p == head)
    {
        addFirst(v);
        size++;
    }
    else
    {
        for (Node *t = head; t != NULL; t = t->pNext)
        {
            if (t->pNext == p)
            {
                q->pNext = t->pNext;
                t->pNext = q;
                size++;
                return;
            }
        }
    }
}

void SList::removeFirst()
{
    if (size == 0)
        cout << "\nError when using removeFirst()\a" << endl;
    else
    {
        Node *temp = head;
        if (size == 1)
            head = tail = NULL;
        else
            head = head->pNext;
        delete temp;
        size--;
    }
}

void SList::removeLast()
{
    if (size == 0)
        return;
    {
        for (Node *t = head; t != NULL; t = t->pNext)
        {
            if (t->pNext == tail)
            {
                delete tail;
                t->pNext = NULL;
                tail = t;
                size--;
                return;
            }
        }
    }
}

void SList::remove(Node *p)
{
    if (p == head)
        removeFirst();
    else if (p == tail)
        removeLast();
    else
    {
        Node *prev;
        for (Node *t = head; t != NULL; t = t->pNext)
        {
            if (t == p)
            {
                prev->pNext = t->pNext;
                delete t;
                size--;
                return;
            }
            prev = t;
        }
    }
}

void SList::traverse()
{
    for (Node *t = head; t != NULL; t = t->pNext)
        cout << t->data << " ";
    cout << endl;
}