# cpp-digraph
Cpp - DiGraph Depth First Serch Impl 

Compilation : clang++ *.cc -std=c++17

Usage :

     Stack my_stack;

    // edges initialization
    edge_t *D = (edge_t(*)) new edge_t;
    D->size = 0;
    D->data = 10;

    edge_t *G = (edge_t(*)) new edge_t;
    G->size = 0;
    G->data = 100;

    edge_t *F = (edge_t(*)) new edge_t;
    F->size = 0;
    F->data = 23;

    edge_t *C = (edge_t(*)) new edge_t + sizeof(link_t);
    C->size = 1;
    C->data = 20;

    edge_t *B = (edge_t(*)) new edge_t + (sizeof(link_t) * 2);
    B->size = 2;
    B->data = 30;

    edge_t *A = (edge_t(*)) new edge_t + (sizeof(link_t) * 3);
    A->size = 3;
    A->data = 40;

    // links initialization
    link_t c_to_d = {.from_edge = C, .to_edge = D, .link_name = "c to d link"};
    link_t b_to_g = {.from_edge = B, .to_edge = G, .link_name = "b to g link"};
    link_t b_to_c = {.from_edge = B, .to_edge = C, .link_name = "b to c link"};
    link_t a_to_c = {.from_edge = A, .to_edge = C, .link_name = "a to c link"};
    link_t a_to_b = {.from_edge = A, .to_edge = B, .link_name = "a to b link"};
    link_t a_to_f = {.from_edge = A, .to_edge = F, .link_name = "a to f link"};

    // linking
    C->links[0] = c_to_d;

    B->links[0] = b_to_c;
    B->links[1] = b_to_g;

    A->links[0] = a_to_c;
    A->links[1] = a_to_b;
    A->links[2] = a_to_f;

    std::optional<edge_t(*)> start_edge = std::make_optional<edge_t(*)>(A);
    bool res = my_stack.find_item(start_edge, 23);
    std::cout << "Res : " << res << std::endl;
    res = my_stack.find_item(start_edge, 21);
    std::cout << "Res : " << res << std::endl;
