#include "OperandStack.h"

//입력으로부터 후위 표기 수식을 읽어 계산하는 함수
double calPostfixExpr(FILE* fp = stdin) {
	char c;
	OperandStack st;

	while ((c = getc(fp)) != '\n') { //'\n' 입력 전까지
		if (c == '+' || c == '-' || c == '*' || c == '/') { //연산자이면
			double val2 = st.pop();
			double val1 = st.pop();
			switch (c) {
			case '+':st.push(val1 + val2); break;
			case '-':st.push(val1 - val2); break;
			case '*':st.push(val1 * val2); break;
			case '/':st.push(val1 / val2); break;
			}
		}
		else if (c >= '0' && c <= '9') { //피연산자(숫자)의 시작이면
			ungetc(c, fp); //문자를 입력 버퍼에 돌려주고
			double val;
			fscanf_s(fp, "%lf", &val); //double로 다시 읽음
			st.push(val); //읽은 값을 스택에 저장
		}
	}
	return (st.pop());
}
//주 함수
void main() {
	printf("수식 입력 (Postfix)=");
	double res = calPostfixExpr(); //PostFix수식 계산
	printf("계산 결과 =>%f\n", res); //결과를 화면에 출력
}