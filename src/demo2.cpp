#include <set>
#include <iostream>

int main(int argc, char const *argv[])
{
	std::set<int> v;
	v.insert(1);
	v.insert(2);

	for (std::set<int>::reverse_iterator i = v.begin(); i != v.end(); ++i)
	{
		std::cout<<*i<<std::endl;
	}
	return 0;
}