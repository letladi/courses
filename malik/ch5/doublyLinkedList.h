template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *next;
    nodeType<Type> *back;
};

template <class Type>
class doublyLinkedList
{
public:
    const doublyLinkedList<Type>& operator=(const doublyLinkedList<Type>&);
    void initializeList();
    void isEmptyList() const;
    void destroy();
    void print() const;
    void reversePrint() const;
    int length() const;
    Type front() const;
    Type back() const;
    bool search(const Type& item) const;
    void insert(const Type& item) const;
    void deleteNode(const Type& item);
    doublyLinkedList();
    doublyLinkedList(const doublyLinkedList<Type>& other);
protected:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;
private:
    void copyList(const doublyLinkedList<Type>& other);
};