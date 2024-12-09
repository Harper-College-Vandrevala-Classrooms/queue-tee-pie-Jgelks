#include <iostream>
#include <string>
#include <array>
using namespace std;

class Cutie
{
public:
    virtual string description() const = 0;
    virtual int cuteness_rating() const = 0;
    virtual ~Cutie() {}
};

class QueueTees
{
private:
    static const int MAX_SIZE = 5;
    array<Cutie *, MAX_SIZE> queue;
    int front;
    int back;
    int current_size;

public:
    QueueTees() : front(0), back(0), current_size(0)
    {
        queue.fill(nullptr);
    }

    void enqueue(Cutie *cutie)
    {
        if (current_size >= MAX_SIZE)
        {
            cout << "Queue is full! Cannot enqueue." << endl;
            return;
        }
        queue[back] = cutie;
        back = (back + 1) % MAX_SIZE;
        ++current_size;
        cout << "Enqueued: " << cutie->description() << endl;
    }

    Cutie *dequeue()
    {
        if (current_size == 0)
        {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return nullptr;
        }
        Cutie *cutie = queue[front];
        cout << "Dequeued: " << cutie->description() << endl;
        queue[front] = nullptr;
        front = (front + 1) % MAX_SIZE;
        --current_size;
        return cutie;
    }

    int size() const
    {
        return current_size;
    }
};

class Puppy : public Cutie
{
public:
    string description() const override
    {
        return "A dog, but smaller";
    }

    int cuteness_rating() const override
    {
        return 11;
    }
};

class Kitty : public Cutie
{
public:
    string description() const override
    {
        return "A cat, but smaller";
    }

    int cuteness_rating() const override
    {
        return 10;
    }
};

class Joey : public Cutie
{
public:
    string description() const override
    {
        return "A kangaroo, but smaller";
    }

    int cuteness_rating() const override
    {
        return 9;
    }
};

int main()
{

    Puppy puppy;
    Kitty kitty;
    Joey joey;
    Kitty kitten;
    Joey joseph;
    Joey extra;

    QueueTees queue;
    // prove the queue is 0 before adding anything
    cout << "Initial queue size: " << queue.size() << endl;

    queue.enqueue(&puppy);
    queue.enqueue(&kitty);
    queue.enqueue(&joey);
    queue.enqueue(&kitten);
    queue.enqueue(&joseph);
    queue.enqueue(&extra);

    // prove the queue is 5 after adding 5 items
    cout << "Queue size after enqueueing: " << queue.size() << endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    // prove the queue is 0 after removing all 5 items
    cout << "Queue size after dequeueing: " << queue.size() << endl;

    // prove you cannot remove an item if there is none
    // and a message will display
    queue.dequeue();

    return 0;
}