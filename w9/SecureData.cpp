// Name: Suleyman Umalatov
// Seneca Student ID: 135476182
// Seneca email: sumalatov@myseneca.ca
// Date of completion: 11/26/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		thread t1(std::bind(converter, text, key, nbytes / 3, Cryptor()));
		thread t2(std::bind(converter, text + (nbytes / 3), key, nbytes / 3, Cryptor()));
		thread t3(std::bind(converter, text + (nbytes * 2 / 3), key, nbytes / 3, Cryptor()));
		t1.join();
		t2.join();
		t3.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			std::ofstream myFile(file, std::ios::binary | std::ios::out);

			// TODO: write data into the binary file
			//         and close the file
			myFile.write(text, nbytes);
			myFile.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		std::ifstream myFile(file, std::ios::in | std::ios::binary);
		
		// TODO: - allocate memory here for the file content
		if (text)
			delete[] text;
		myFile.seekg(0, std::ios::end);
		nbytes = (int)myFile.tellg();
		text = new char [nbytes + 1];

		// TODO: - read the content of the binary file
		myFile.seekg(0, std::ios::beg);
		myFile.read(text, nbytes);
		myFile.close();

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}