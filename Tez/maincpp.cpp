#include <iostream>



//������� ��������� ��������-�������. ������ ��������, ����������� ������ ����, ��� ���������� ����
int cyclic_sum(int i, int j, int calc(int, int)) {
	int sum1 = 0;
	for (int k = i; k != 10 * i; ++k) {
		sum1 += calc(i, j);
	}
	return sum1;
}
// ��� ������� �������� ������ ������� �� ����� � �������� �� �������� ��������-�������. ������ �������� �� ���������, 
//� ������ ���������� � ���������-������� ��� ����, ���� ����. � ����������� ���� �������-�������� ���������� ������ ������� ���� ��� ����������
int func1(int rem, int num1, int num2, int calc(int, int)) {
	int c = rem + cyclic_sum(num1, num2, calc);
	return c;
}

int sum(int i, int j) {
	return i + j;
}

int mult_product(int i, int j) {
	return i * j;
}

int main() {
	const int base = 100;
	const int x = 7, y = 14;

	std::cout << cyclic_sum(x, y, mult_product) << std::endl;
	std::cout << cyclic_sum(x, y, sum) << std::endl;
	std::cout << func1(base, x, y, mult_product) << std::endl;
	std::cout << func1(base, x, y, sum) << std::endl;
	system("pause");
	return 0;

}