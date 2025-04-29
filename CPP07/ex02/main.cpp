#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char **)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));

	// Llenar arrays
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	// Pruebas de copia
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	// Verificación inicial
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "Error: valores no coinciden!\n";
			return 1;
		}
	}

//************************************************************************************* */
#ifdef DEBUG
	std::cout << "\n--- CONTENIDO INICIAL (primeros 10 elementos) ---\n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << "\n";
#endif
	//************************************************************************************* */

	// Pruebas de excepciones
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// Modificar valores
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

//************************************************************************************* */
#ifdef DEBUG
	std::cout << "\n--- CONTENIDO FINAL (primeros 10 elementos) ---\n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << "\n";
#endif
	//************************************************************************************* */

	delete[] mirror;
	return 0;
}
