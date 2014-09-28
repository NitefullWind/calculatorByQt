#include "stack.h"

stack::stack(){
    count = 0;
}

bool stack::empty() const{
    if(count==0) return true;
    return false;
}

bool stack::full() const{
    if(count==19) return true;
    return false;
}

void stack::getTop(char &s) const{
    s = str[count-1];
}

void stack::getTop(double &n) const{
    n = num[count-1];
}

void stack::push(const char s){
    if(full())	return;
    else
        str[count++] = s;
}

void stack::push(const double n){
    if(full())return;
    else
        num[count++] = n;
}

void stack::pop(){
    if(empty()) return;
    else count--;
}
