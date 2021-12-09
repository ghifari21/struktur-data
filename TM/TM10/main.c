#include "header.h"

int main()
{
    graph G;
    char c;
    scanf(" %c", &c);

    // buat graf dan node
    createEmpty(&G);
    addNode('1', &G);
    addNode('2', &G);
    addNode('3', &G);
    addNode('4', &G);
    addNode('5', &G);
    addNode('6', &G);
    addNode('7', &G);
    addNode('8', &G);

    // membuat jalur graf
    node *begin = findNode('1', G);
    node *end = findNode('2', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 1);
    }
    
    end = findNode('3', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 1);
    }

    begin = findNode('8', G);
    end = findNode('1', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 1);
    }

    end = findNode('4', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 1);
    }

    end = findNode('6', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 1);
    }

    begin = findNode('4', G);
    end = findNode('5', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 1);
    }

    begin = findNode('6', G);
    end = findNode('7', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 1);
    }

    begin = findNode('7', G);
    end = findNode('5', G);
    if (begin != NULL && end != NULL)
    {
        addPath(begin, end, 1);
    }

    // output   
    printGraph(G);
    printf("===========\n");

    // delete node
    delNode(c, &G);

    // output setelah node didelete
    printGraph(G);

    return 0;
}
