#include "OperandStack.h"

//�Է����κ��� ���� ǥ�� ������ �о� ����ϴ� �Լ�
double calPostfixExpr(FILE* fp = stdin) {
	char c;
	OperandStack st;

	while ((c = getc(fp)) != '\n') { //'\n' �Է� ������
		if (c == '+' || c == '-' || c == '*' || c == '/') { //�������̸�
			double val2 = st.pop();
			double val1 = st.pop();
			switch (c) {
			case '+':st.push(val1 + val2); break;
			case '-':st.push(val1 - val2); break;
			case '*':st.push(val1 * val2); break;
			case '/':st.push(val1 / val2); break;
			}
		}
		else if (c >= '0' && c <= '9') { //�ǿ�����(����)�� �����̸�
			ungetc(c, fp); //���ڸ� �Է� ���ۿ� �����ְ�
			double val;
			fscanf_s(fp, "%lf", &val); //double�� �ٽ� ����
			st.push(val); //���� ���� ���ÿ� ����
		}
	}
	return (st.pop());
}
//�� �Լ�
void main() {
	printf("���� �Է� (Postfix)=");
	double res = calPostfixExpr(); //PostFix���� ���
	printf("��� ��� =>%f\n", res); //����� ȭ�鿡 ���
}