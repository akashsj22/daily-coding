#include <iostream>
#include <cctype>
#include <stack>

#define EOF -1

std::stack<int> s;

void push(int value) { 
    s.push(value); 
}

int pop(void) { 
    if (s.empty()) 
        return EOF; 
    int value = s.top(); 
    s.pop(); 
    return value; 
}

void flagError() { 
    std::cerr << "Error!" << std::endl; 
    exit(1); 
}

int main() {
    int c, m, n, r;
    while ((c = std::cin.get()) != EOF) {
        if (isdigit(c))
            push(c - '0');
        else if ((c == '+') || (c == '*')) {
            m = pop();
            n = pop();
            r = (c == '+') ? n + m : n * m;
            push(r);
        } else if (c != ' ')
            flagError();
    }
    std::cout << pop() << std::endl;
}
