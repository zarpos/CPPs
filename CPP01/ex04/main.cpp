/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:21:12 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 22:21:47 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"

#include "FileProcessor.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 4)
	{
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
	
	if (std::string(argv[2]).empty())
	{
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }
	
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    FileProcessor processor(filename, s1, s2);

    if (!processor.processFile())
	{
        std::cerr << "Error: Failed to process the file." << std::endl;
        return 1;
    }
    std::cout << "File processed successfully. Output saved as " << filename << ".replace" << std::endl;

    return 0;
}

