#include <iostream>
#include <vector>

std::string string_of_binary(uint64_t input)
{
	char cstr[65];
	cstr[64] = '\0';
	for(uint64_t i = 0; i < 64; ++i)
	{
		
	}
	return std::string(cstr);
}

std::vector<uint64_t> bit_reverse_indexes_gen(uint64_t FFTpower)
{
	std::vector<uint64_t> result;
	uint64_t indexes_count = 2^FFTpower - 1;
	for(uint64_t index = 0; index < indexes_count; ++index)
	{
		uint64_t reversed_index = 0;
		for(uint8_t bit_number = 0; bit_number < FFTpower; ++bit_number)
		{
			reversed_index |= ((((1<<bit_number) & (index<<bit_number))) << (63 - bit_number));
		}
		std::cout << reversed_index << std::endl;
		std::cout << string_of_binary(reversed_index) << std::endl;
	}
	return result;
}

int main()
{
	std::cout << string_of_binary(static_cast<uint64_t>(1)) << std::endl;
	//std::cout << "hello" << std::endl;
	//bit_reverse_indexes_gen(1);
	return 0;
}
