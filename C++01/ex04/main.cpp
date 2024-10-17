/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:17:09 by sbartoul          #+#    #+#             */
/*   Updated: 2024/10/16 15:23:05 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return (EXIT_FAILURE);
	}
	const std::string file = argv[1];
	const std::string str1 = argv[2];
	const std::string str2 = argv[3];

	if (file.length() == 0)
	{
		std::cerr << "Invalid filename" << std::endl;
		return (EXIT_FAILURE);
	}
	if (str1.length() == 0)
	{
		std::cerr << "First string to replace with cannot be empty." << std::endl;
	}
	if (str1 == str2)
	{
		std::cerr << "If both string are equal there is nothing to replace." << std::endl;
		return (EXIT_FAILURE);
	}
	std::string contents;
	char c;
	std::ifstream inStream(file.c_str(), std::ifstream::in); //c_str (C styled str as the constructor of std::ifstream expects it)
	//ifstream is a class from the <fstream> to open, read and process file sequentially.
	//in for read only operations.
	if (!inStream.good())
	{
		std::cerr << "Could not open file for reading" << std::endl;
		inStream.close();
		return (EXIT_FAILURE);
	}
	while (inStream.good())
	{
		inStream.get(c);
		if (inStream.good()) //After calling instream.get(c), the state of the stream might change(EOF or read error)
			contents.push_back(c);
	}
	inStream.close();
	if (contents.length() == 0)
	{
		std::ofstream outStream((file + ".replace").c_str(), std::ofstream::out | std::ofstream::trunc);
		outStream.close();
		return (EXIT_FAILURE);
	}
	while (contents.find(str1) != std::string::npos)
	{
		std::string before = contents.substr(0, contents.find(str1));
		std::string after = contents.substr(contents.find(str1) + str1.length(), contents.length());
		contents = before + str2 + after;
	}
	std::ofstream outStream((file + ".replace").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!outStream.good())
	{
		std::cerr << "Could not open file for writing" << std::endl;
		outStream.close();
		return (EXIT_FAILURE);
	}
	outStream << contents;
	outStream.close();
	return (EXIT_SUCCESS);
}

//Classes (Part of <fstream>)
//std::ifstream - for reading from file (input).
//std::ofstream - for writing to files (output).
//std::fstream - fo both reading and writing files.


//std::ios is the base class and std::istream and std::fstream inherits from this class.
// std::ios     <-- (manages stream state, provides good())
//    |
//    +-- std::istream  <-- (provides input functions like get())
//    |
//    +-- std::ostream  <-- (provides output functions)
//    |
//    +-- std::fstream  <-- (inherits both istream and ostream, provides close())
