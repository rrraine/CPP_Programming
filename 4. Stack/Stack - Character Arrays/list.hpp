// TODO change this to handle char elements

class List {
    public:
    virtual void add(char c) = 0;
    virtual char get(int pos) = 0;
    virtual int remove(int num) = 0;
    virtual void print() = 0;
};