#include <string>
#include <iostream>

inline void swap(std::string &, int, int);
void reverse(std::string &, int, int);

int main()
{
	std::string value = "0123456789";
	reverse(value, 6, 9);
	std::cout << value << std::endl;
	return 0;
}

inline void swap(std::string &value, int k, int l)
{
	char temp = value[k];
	value[k] = value[l];
	value[l] = temp;
}
void reverse(std::string &value, int k, int n)
{
	if(k >= n)
	{
		return;
	}
	swap(value, k, n);
	reverse(value, k + 1, n - 1);
}
