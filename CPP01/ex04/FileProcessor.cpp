/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:22:22 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 22:12:44 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"

FileProcessor::FileProcessor(const std::string &filename, const std::string &s1, const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

FileProcessor::~FileProcessor() {}

bool FileProcessor::processFile()
{
	// Open the file
	std::ifstream infile(_filename);
	if (!infile)
	{
		std::cerr << "Error: Could not open file " << _filename << std::endl;
		return false;
	}
	// Read all the file content in one line
	// The last part is an empty iterator to flag the end
	std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	infile.close();
	// Replace s1 and s2
	std::string modifiedContent = replaceOccurrences(content);
	// Create the output file
	std::ofstream outfile(_filename + ".replace");
	if (!outfile)
	{
		std::cerr << "Error: Could not create output file " << _filename + ".replace" << std::endl;
		return false;
	}
	// Write the modified content in the output file
	outfile << modifiedContent;
	outfile.close();

	return true;
}

std::string FileProcessor::replaceOccurrences(const std::string &content)
{
    std::string modifiedContent;
    size_t pos = 0; 
	size_t found = 0;
    //Loop to find and replace each occurrence of _s1 in content
	// It will search s1 in content while they are occurrences of s1 from "pos"
	// In succes will return the index, if not, npos (eof)
    while ((found = content.find(_s1, pos)) != std::string::npos)
	{
        //Add the part before _s1 to the result
		// it appends content from pos to found - pos excluding the coincidence from s1
		// this includes the text before the coincidence
        modifiedContent.append(content, pos, found - pos);
        //add _s2 replacing the occurrence of _s1
        modifiedContent.append(_s2);
        //Move the search position just after the occurence to find the new one
        pos = found + _s1.length();
    }
    //Add the remaining part of the content after the last occurrence
    modifiedContent.append(content, pos, content.length() - pos);
    return modifiedContent;
}
/*
Ejemplo de replaceOccurrences:

- content es "Hola, s1 mundo s1 final".
- _s1 es "s1".
- _s2 es "reemplazo".

1. Busca la primera aparición de "s1" en content y la encuentra en el índice 6.
2. Copia "Hola, " a modifiedContent, luego añade "reemplazo" en lugar de "s1".
3. Busca nuevamente "s1" a partir de la posición después de la primera coincidencia.
4. Encuentra "s1" en el índice 14, añade " mundo " a modifiedContent, seguido de "reemplazo".
5. Después del bucle, agrega " final" al final de modifiedContent.

Resultado final:
"Hola, reemplazo mundo reemplazo final"
*/
