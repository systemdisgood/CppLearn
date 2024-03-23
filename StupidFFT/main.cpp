#include <iostream>
#include <vector>

uint64_t uint64_t_pow(uint64_t base, uint8_t exponent)
{
	if(exponent == 0) return 1;
	else
	{
		uint64_t result = base;
		for(uint64_t i = 0; i < exponent - 1; ++i)
		{
			result *= base;
		}
		return result;
	}
}
	

std::string string_of_binary_uint64_t(uint64_t input)
{
	if(input == 0) return "0000000000000000000000000000000000000000000000000000000000000000";
	else
	{
		char cstr[65];
		cstr[64] = '\0';
		for(uint64_t i = 1; i < 64; ++i)
		{
			uint64_t twos_pow = uint64_t_pow(2,i);
			if((input % (twos_pow)) != 0)
			{
				cstr[64 - i] = '1';
			}
			else
			{
				cstr[64 - i] = '0';
			}
			input /= twos_pow;
		}
		return std::string(cstr);
	}
	
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
		std::cout << string_of_binary_uint64_t(reversed_index) << std::endl;
	}
	return result;
}

int main()
{
	//std::cout << uint64_t_pow(2,3) << std::endl;
	//std::cout << (123 % (uint64_t_pow(2,2))) << std::endl;
	//std::cout << string_of_binary_uint64_t(65) << std::endl;
	//std::cout << "hello" << std::endl;
	//bit_reverse_indexes_gen(1);
	bit_reverse_indexes_gen(3);

	std::cout << "The End" << std::endl;
	return 0;
}
