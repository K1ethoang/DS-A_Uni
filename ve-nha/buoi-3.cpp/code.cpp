#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int day, month, year;
    Date();
    bool operator==(const Date &_date);
};

struct Student
{
    int ID;
    string fullName;
    Date dayOfBirth;
    float GPA;
    string grade;
    string major;
    Student();
};
typedef Student Item;

struct Node
{
    Item data;
    Node *next;
    Node();
    Node(const Item &val);
};

class Students
{
private:
    Node *head;
    Node *tail;
    long size;

public:
    Students();
    ~Students();
    Node *getHead();
    Node *getTail();
    // 1
    void insert(const Item &val);
    // 2
    Item findByID(const int &_ID);
    // 3
    Item findByFullName(const string &_fullName);
    // 4
    Item findByDayOfBirth(const Date &_dayOfBirth);
    // 5
    Students findByMajor(const string &_major);
    // 6
    Students findByGrade(const string &_grade);
    // 7
    Students findStudentsWithHighestGPA();
    // 8
    Students findStudentsWithGPABelow4();
    // 9
    void sortByMajor();
    void countNumberOfStudentEachMajor();
    // 10
    void deleteDuplicate();
};

int main()
{
    return 0;
}

// Date
Date::Date()
{
    day = month = year = 0;
}

bool Date::operator==(const Date &_date)
{
    if (day == _date.day && month == _date.month && year == _date.year)
        return 1;
    return 0;
}

// Student
Student::Student()
{
    ID = -1;
    fullName = "UNKNOWN";
    dayOfBirth;
    GPA = -1;
    grade = "EMPTY";
    major = "EMPTY";
}

Node::Node(const Item &val)
{
    data = val;
    next = NULL;
}

Students::Students()
{
    head = tail = NULL;
    size = 0;
}

Students::~Students() {}

void Students::insert(const Item &val)
{
    Node *n = new Node(val);
    if (size == 0)
        head = tail = n;
    else
    {
        tail->next = n;
        tail = n;
    }
    size++;
}

Node *Students::getHead()
{
    return head;
}

Node *Students::getTail()
{
    return tail;
}

Item Students::findByID(const int &_ID)
{
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.ID == _ID)
            return t->data;
    }
    return Item();
}

Item Students::findByFullName(const string &_fullName)
{
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.fullName.compare(_fullName) == 0)
            return t->data;
    }
    return Item();
}

Item Students::findByDayOfBirth(const Date &_dayOfBirth)
{
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.dayOfBirth == _dayOfBirth)
            return t->data;
    }
    return Item();
}

Students Students::findByMajor(const string &_major)
{
    Students list;
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.major.compare(_major) == 0)
            list.insert(t->data);
    }
    return list;
}

Students Students::findByGrade(const string &_grade)
{
    Students list;
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.major.compare(_grade) == 0)
            list.insert(t->data);
    }
    return list;
}

Students Students::findStudentsWithHighestGPA()
{
    Students list;
    float highestGPA = head->data.GPA;
    for (Node *t = head->next; t != NULL; t = t->next)
    {
        if (t->data.GPA > highestGPA)
            highestGPA = t->data.GPA;
    }
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.GPA == highestGPA)
            list.insert(t->data);
    }
    return list;
}

Students Students::findStudentsWithGPABelow4()
{
    Students list;
    for (Node *t = head; t != NULL; t = t->next)
    {
        if (t->data.GPA < 4)
            list.insert(t->data);
    }
    return list;
}

void swap(Item &x, Item &y) // hàm ngoài
{
    Item t = x;
    x = y;
    y = t;
}

void Students::sortByMajor()
{
    for (Node *i = head; i->next != tail; i = i->next)
    {
        Node *minIndex = i;
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (minIndex->data.major.compare(j->data.major) > 0)
                minIndex = j;
        }
        if (minIndex != i)
            swap(i->data, minIndex->data);
    }
}

void Students::countNumberOfStudentEachMajor()
{
    int count = 0;
    sortByMajor();
    for (Node *i = head; i != NULL; i = i->next)
    {
        count++;
        if (i->next->data.major.compare(i->data.major) != 0)
        {
            cout << i->data.major << " : " << count;
            count = 0;
        }
    }
}

void Students::deleteDuplicate()
{
    for (Node *i = head; i->next != tail; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
        }
    }
}
