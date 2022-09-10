#include <iostream>
using namespace std;

typedef int Item;

struct Node
{
    Item data;
    Node *pNext;
};

struct SList
{
    Node *head;
    Node *tail;
    long size;

    SList();
    ~SList();

    // Methods
    Node *createNode(const Item &v);
    void addFirst(const Item &v);
    void addLast(const Item &v);
    void insertAfter(Node *p, const Item &v);
    void insertBefore(Node *p, const Item &v);
    void findBefore(Node *p); // chua lam
    void removeFirst();
    void remove(Node *p);
    void removeLast();
};

int main()
{
    SList list;
    list.removeFirst();
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
        for (Node *t = head; t = t->pNext; t != NULL)
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

void SList::remove(Node *p)
{
    if (p == head)
        removeFirst();
    else
    {
    }
}

void SList::removeLast()
{
    if (size == 0)
        return;
    {
    }
}
