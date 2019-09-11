#include <iostream>
#include <vector>

int main()
{
	std::vector<int> my_vector;
	std::vector<int>::iterator begin_iter;
	for (int i = 0; i < 10; i++)
	{
		my_vector.emplace_back(i * 3);
	}
	begin_iter = my_vector.begin();
	while (begin_iter != my_vector.end())
	{
		std::cout << *begin_iter << " ";
		begin_iter++;
	}
	begin_iter = my_vector.begin();
	std::reverse_iterator<std::vector<int>::iterator> end_iter = my_vector.rbegin();
	for (int i = 0; i < (my_vector.size()) / 2; i++)
	{
		auto temp = *begin_iter;
		*begin_iter = *end_iter;
		*end_iter = temp;
		begin_iter++;
		end_iter++;
	}
	std::cout << std::endl;
	begin_iter = my_vector.begin();
	while (begin_iter != my_vector.end())
	{
		std::cout << *begin_iter << " ";
		begin_iter++;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}