#ifndef _STACK_
#define _STACK_

template <class T>
class Stack
{
  private:
    int len;
    // T s[1000];
    struct node
    {
        T val;
        struct node *next;
    } * base;

  public:
    Stack() : len(0), base(new node){};
    ~Stack(){};
    void push(T a)
    {
        node *new_val = new node;
        new_val->val = a;
        new_val->next = base;
        base = new_val;
        len++;
    };
    T pop()
    {
        len--;
        T p = base->val;
        base = base->next;
        return p;
    };
    T pop(T a)
    {
        a = pop();
        return a;
    };
    bool isEmpty() const
    {
        return len ? 1 : 0;
    };
    int length() const
    {
        return len;
    };
};

#endif //end of _STACK_