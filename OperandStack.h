#include <cstdio>
#include <cstdlib>
#define MAX_STACK_SIZE 100
inline void error(const char* message) {
    printf("%s\n", message);
    exit(1);
}

class OperandStack {
    double data[MAX_STACK_SIZE]; //요소의 배열
    int top; //요소의 개수
public:
    OperandStack() { top = -1; } //스택 생성자
    ~OperandStack() {} //스택 소멸자
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE - 1; }
    void push(double e) { //맨 위에 항목 삽입
        if (isFull()) error("스택 포화 에러");
        data[++top] = e;
    }
    double pop() { //맨 위의 요소를 삭제하고 반환
        if (isEmpty()) error("스택 공백 에러");
        return data[top--];
    }
};