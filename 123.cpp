#include <iostream>
#include <fstream>
void dis()
{
	 std::ifstream f("temp_bill.txt");

    if (f.is_open())
        std::cout << f.rdbuf();
}
int main()
{
   dis();
}
