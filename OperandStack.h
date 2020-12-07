#include <cstdio>
#include <cstdlib>
#define MAX_STACK_SIZE 100
inline void error(const char* message) {
    printf("%s\n", message);
    exit(1);
}

class OperandStack {
    double data[MAX_STACK_SIZE]; //����� �迭
    int top; //����� ����
public:
    OperandStack() { top = -1; } //���� ������
    ~OperandStack() {} //���� �Ҹ���
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE - 1; }
    void push(double e) { //�� ���� �׸� ����
        if (isFull()) error("���� ��ȭ ����");
        data[++top] = e;
    }
    double pop() { //�� ���� ��Ҹ� �����ϰ� ��ȯ
        if (isEmpty()) error("���� ���� ����");
        return data[top--];
    }
};