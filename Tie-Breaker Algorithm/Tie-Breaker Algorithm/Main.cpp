#include <iostream>
#include <thread>
void CS1();
void CS2();
bool in1 = false, in2 = false;

int main()
{
	std::thread t1(CS1);
	std::thread t2(CS2);

	t1.join();
	t2.join();
}

void CS1()
{
	while (true)
	{
		in1 = true;
		while (!in2)
		{
		}
		std::cout << "CS1" << std::endl;
		in1 = false;
	}
}

void CS2()
{
	while (true)
	{
		in2 = true;
		while (!in1)
		{
		}
		std::cout << "CS2" << std::endl;
		in2 = false;
	}
}