#pragma once

# include <cstddef>
# include <iostream>

template<typename T_array, typename T_function>
void	iter(T_array* array, size_t len, T_function function)
{
	for (size_t i = 0; i < len; i++)
		function(array[i]);
}