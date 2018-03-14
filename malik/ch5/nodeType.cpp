#ifndef H_NodeType
#define H_NodeType

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

#endif