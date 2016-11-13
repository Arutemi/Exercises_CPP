#include <iostream>



//функция принимает параметр-функцию. Обрати внимание, указываются только типы, без конкретных имен
int cyclic_sum(int i, int j, int calc(int, int)) {
	int sum1 = 0;
	for (int k = i; k != 10 * i; ++k) {
		sum1 += calc(i, j);
	}
	return sum1;
}
// Эта функция вызывает другую функцию по имени и передает ей принятый параметр-функцию. Обрати внимание на синтаксис, 
//в списке аргументов у параметра-функции нет имен, лишь типы. В исполняемом коде функция-параметр передается другой функции тоже без параметров
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