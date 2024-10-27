/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:20:58 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 21:39:09 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEPROCESSOR_HPP
# define FILEPROCESSOR_HPP
# include <string>
# include <iostream>
# include <fstream>

class FileProcessor
{
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
	
	public:
	    FileProcessor(const std::string &filename, const std::string &s1, const std::string &s2);
		~FileProcessor();
    	bool processFile();

	std::string replaceOccurrences(const std::string &content);
};


#endif