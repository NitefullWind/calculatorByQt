#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
class stack{
public:
    stack();
    bool empty() const;
    bool full() const;
    void getTop(char &s) const;
    void getTop(double&n) const;
    void push(const char s);
    void push(const double n);
    void pop();
private:
    int count;
    char str[200];
    double num[200];
};
#endif //STACK_H_INCLUDED
