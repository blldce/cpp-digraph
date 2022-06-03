

#ifndef DIGRAPH_H
#define DIGRAPH_H 1

#include <optional>

typedef struct Edge edge_t;
typedef struct Link link_t;
typedef struct Node node_t;

struct Link
{
    const char(*link_name);
    edge_t(*from_edge); // Its optional, used for debugging information to where this link come from.
    edge_t(*to_edge);
};

struct Edge
{
    int data;
    int size;       // we dont want to use fixed size links, it can vary each node
    link_t links[]; // we dont want to use fixed size links, it can vary each node
};

struct Node
{
    node_t(*next_node);
    edge_t(*edge);
};

class Stack
{
private:
    int size;
    node_t(*base);

public:
    explicit Stack();
    void push_item(edge_t(*const));
    std::optional<edge_t(*)> pop_item();
    void print_items();
    bool find_item(std::optional<edge_t(*)>, int);
};

#endif
