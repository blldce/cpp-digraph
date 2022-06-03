

#include <iostream>
#include "digraph.h"

Stack::Stack() : base(nullptr), size(0)
{
}

void Stack::push_item(edge_t(*edge))
{
    node_t(*new_node) = (node_t(*)) new node_t;
    new_node->edge = edge;
    new_node->next_node = nullptr;
    if (this->size > 0)
        new_node->next_node = this->base;
    this->base = new_node;
    this->size++;
}

std::optional<edge_t(*)> Stack::pop_item()
{
    if (this->size == 0)
        return std::nullopt;

    if (this->base->edge == nullptr)
        return std::nullopt;

    std::optional<edge_t(*)> ret = std::make_optional<edge_t(*)>(this->base->edge);

    node_t(*old_node) = this->base;
    this->base = this->base->next_node;
    this->size--;
    delete old_node;

    return ret;
}

bool Stack::find_item(std::optional<edge_t(*)> edge_o, int target)
{
    if (!edge_o.has_value())
        return false;

    if (edge_o.value()->data == target)
        return true;

    int count = 0;
    while (count < edge_o.value()->size)
    {
        edge_t(*e) = edge_o.value()->links[count].to_edge;
        this->push_item(e);
        count++;
    }
    return this->find_item(this->pop_item(), target);
}

void Stack::print_items()
{
    if (this->size == 0)
        return;
    std::cout << "*********" << std::endl;

    node_t(*node_iter) = this->base;
    while (node_iter != nullptr)
    {
        std::cout << "Value : " << node_iter->edge->data << " -- Address : " << node_iter << " -- Next : " << node_iter->next_node << std::endl;
        node_iter = node_iter->next_node;
    }
    std::cout << "*********" << std::endl;
}