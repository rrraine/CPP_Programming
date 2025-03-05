class List {
    public:
    virtual void addFirst(int n) = 0;
    virtual void addLast(int n) = 0;
    virtual void removeFirst() = 0;
    virtual void removeLast() = 0;
    // virtual void insert(int) = 0;
    virtual int get(int pos) = 0;
    // virtual int remove(int num) = 0;
    virtual void print() = 0;
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    // virtual void addAt(int num, int pos) = 0;
    // virtual int removeAt(int pos) = 0;
};