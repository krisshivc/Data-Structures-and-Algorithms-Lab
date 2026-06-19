#include <iostream>
using namespace std;

struct Coach
{
    int id;
    Coach* next;
};

Coach* head = nullptr;
int coachCount = 0;

void addCoach(int id)
{
    Coach* c = new Coach();
    c->id = id;
    c->next = nullptr;

    if (!head)
    {
        head = c;
        coachCount++;
        return;
    }

    Coach* t = head;
    while (t->next)
        t = t->next;

    t->next = c;
    coachCount++;
}

void removeLastCoach()
{
    if (!head)
    {
        cout << "Train is empty, no coach to remove\n";
        return;
    }

    if (!head->next)
    {
        delete head;
        head = nullptr;
        coachCount--;
        return;
    }

    Coach* t = head;
    while (t->next->next)
        t = t->next;

    delete t->next;
    t->next = nullptr;
    coachCount--;
}

void removeCoachById(int id)
{
    if (!head)
    {
        cout << "Train is empty\n";
        return;
    }

    if (head->id == id)
    {
        Coach* t = head;
        head = head->next;
        delete t;
        coachCount--;
        return;
    }

    Coach* t = head;
    while (t->next && t->next->id != id)
        t = t->next;

    if (!t->next)
    {
        cout << "Coach with id " << id << " not found\n";
        return;
    }

    Coach* toDelete = t->next;
    t->next = toDelete->next;
    delete toDelete;
    coachCount--;
}

void display()
{
    if (!head)
    {
        cout << "Train is empty\n";
        return;
    }

    Coach* t = head;
    while (t)
    {
        cout << "[Coach " << t->id << "]";
        if (t->next) cout << " -> ";
        t = t->next;
    }

    cout << "\n";
    cout << "Total coaches: " << coachCount << "\n";
}

int main()
{
    addCoach(1);
    addCoach(2);
    addCoach(3);
    addCoach(4);
    display();
    removeLastCoach();
    display();
    removeCoachById(2);
    display();
    removeCoachById(99); // not found
    return 0;
}
