#include <iostream>
#include <string>
using namespace std;

struct Item
{
    char c;
    int ASCII;
};

struct Node
{
    Item data;
    Node *next;

    Node()
    {
        data.c = ' ';
        data.ASCII = -1;
        next = NULL;
    }

    Node(const char &value)
    {
        data.c = value;
        data.ASCII = value;
        next = NULL;
    }
};

class SList
{
private:
    Node *head;
    Node *tail;

public:
    SList();
    void addLast(const char &value);
    void input(const string &value);
    void outputByChar();
    void outputByASCII();
};

int main()
{
    string name;
    SList nameList;
    cout << "\nNhap ho ten: ";
    fflush(stdin);
    getline(cin, name);
    nameList.input(name);
    cout << "\n\tXuat theo ky tu\n";
    nameList.outputByChar();
    cout << "\n\tXuat theo ASCII\n";
    nameList.outputByASCII();
    return 0;
}

SList::SList()
{
    head = tail = nullptr;
}

void SList::addLast(const char &value)
{
    Node *n = new Node(value);
    if (head == NULL)
        head = tail = n;
    else
    {
        tail->next = n;
        tail = n;
    }
}

void SList::input(const string &value)
{
    for (int i = 0; i < value.size(); i++)
    {
        addLast(value[i]);
    }
}

void SList::outputByChar()
{
    for (Node *t = head; t != NULL; t = t->next)
        cout << t->data.c;
    cout << endl;
}

void SList::outputByASCII()
{
    for (Node *t = head; t != NULL; t = t->next)
        cout << t->data.ASCII << " ";
    cout << endl;
}