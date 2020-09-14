#include <iostream>
#include <random>

int main()
{
	std::random_device rd;
	std::default_random_engine engine(rd());

	for (int i = 0; i < 100; ++i)
	{
		int a = engine() % 10, b = engine() % 10;

		std::cout << "a = " << a
		          << "\t b = " << b
		          << "\t a/b = " << a / b << std::endl;
	}
}
