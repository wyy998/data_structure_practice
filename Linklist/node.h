#ifndef _NODE
#define _NODE

class node
{
    private:
    node *next;
    int data;
    public:
    node(int d);
    node();
    ~node();
    void node_set(int d);
    int node_get();
    void node_set_next(node* p);
    node* node_get_next();
}
