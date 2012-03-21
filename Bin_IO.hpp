#ifndef BIN_IO_HPP
#define BIN_IO_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Binary_ofstream;
class Binary_ifstream;

class Bin_IO
{
	public:
		virtual Binary_ofstream& write(Binary_ofstream& output) const = 0;
		virtual Binary_ifstream& read(Binary_ifstream& input) = 0;
};

class Binary_ofstream : public ofstream
{
	public:
		Binary_ofstream();
		
		virtual ~Binary_ofstream();
		
		unsigned int size();
		
		Binary_ofstream& operator << (const int& data);
		
		Binary_ofstream& operator << (const unsigned int& data);
		
		Binary_ofstream& operator << (const long int& data);
		
		Binary_ofstream& operator << (const long unsigned int& data);
		
		Binary_ofstream& operator << (const short int& data);
		
		Binary_ofstream& operator << (const unsigned short int& data);
		
		Binary_ofstream& operator << (const long long int& data);
		
		Binary_ofstream& operator << (const unsigned long long int& data);
		
		Binary_ofstream& operator << (const char& data);
		
		Binary_ofstream& operator << (const unsigned char& data);
		
		Binary_ofstream& operator << (const float& data);
		
		Binary_ofstream& operator << (const double& data);
		
		Binary_ofstream& operator << (const long double& data);
		
		Binary_ofstream& operator << (const bool& data);
		
		template <class T>
		Binary_ofstream& operator << (const vector<T>& data)
		{
			unsigned int i;
			
			operator << (data.size());
			
			for(i=0; i<data.size(); i++)
			{
				operator << (data[i]);
			}
			
			return *this;
		}
		
		Binary_ofstream& operator << (const string& data);
		
		Binary_ofstream& operator << (const Bin_IO& data);
};


class Binary_ifstream : public ifstream
{
	public:
		Binary_ifstream();
		
		virtual ~Binary_ifstream();
		
		unsigned int size();
		
		Binary_ifstream& operator >> (int& data);
		
		Binary_ifstream& operator >> (unsigned int& data);
		
		Binary_ifstream& operator >> (long int& data);
		
		Binary_ifstream& operator >> (unsigned long int& data);
		
		Binary_ifstream& operator >> (short int& data);
		
		Binary_ifstream& operator >> (unsigned short int& data);
		
		Binary_ifstream& operator >> (long long int& data);
		
		Binary_ifstream& operator >> (unsigned long long int& data);
		
		Binary_ifstream& operator >> (char& data);
		
		Binary_ifstream& operator >> (unsigned char& data);
		
		Binary_ifstream& operator >> (float& data);
		
		Binary_ifstream& operator >> (double& data);
		
		Binary_ifstream& operator >> (long double& data);
		
		Binary_ifstream& operator >> (bool& data);
		
		template <class T>
		Binary_ifstream& operator >> (vector<T>& data)
		{
			data.clear();
			
			unsigned int i;
			unsigned int size;
			
			operator >> (size);
			
			for(i=0; i<size; i++)
			{
				T temp;
				
				operator >> (temp);
				
				data.push_back(temp);
			}
			
			return *this;
		}
		
		Binary_ifstream& operator >> (string& data);
		
		Binary_ifstream& operator >> (Bin_IO& data);
};
#endif
