#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Binary_ofstream
{
	private:
		ofstream output;
	
	public:
		Binary_ofstream()
		{
		}
		
		virtual ~Binary_ofstream()
		{
			output.close();
		}
		
		bool open(char* name)
		{
			output.open(name, ios::binary);
			
			return output.good();
		}
		
		bool open(string name)
		{
			output.open(name.c_str(), ios::binary);
			
			return output.good();
		}
		
		bool close()
		{
			output.close();
			
			return 1;
		}
		
		bool good()
		{
			return output.good();
		}
		
		bool bad()
		{
			return output.bad();
		}
		
		bool eof()
		{
			return output.eof();
		}
		
		Binary_ofstream& operator << (const int& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
};

class Binary_ifstream
{
	private:
		ifstream input;
	
	public:
		Binary_ifstream()
		{
		}
		
		virtual ~Binary_ifstream()
		{
			input.close();
		}
		
		bool open(char* name)
		{
			input.open(name, ios::binary);
			
			return input.good();
		}
		
		bool open(string name)
		{
			input.open(name.c_str(), ios::binary);
			
			return input.good();
		}
		
		bool close()
		{
			input.close();
			
			return 1;
		}
		
		bool good()
		{
			return input.good();
		}
		
		bool bad()
		{
			return input.bad();
		}
		
		bool eof()
		{
			return input.eof();
		}
		
		unsigned int tell()
		{
			return input.tellg();
		}
		
		void* seek(unsigned int pos)
		{
			return input.seekg(pos);
		}
		
		Binary_ifstream& operator >> (int& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
};

int main()
{
	Binary_ofstream output;
	Binary_ifstream input;
	
	output.open("test.bin");
	
	output << 0;
	output << 1;
	output << 2;
	output << 4;
	output << 8;
	
	output.close();
	
	input.open("test.bin");
	
	int temp;
	
	while(!input.eof())
	{
		input >> temp;
		
		cout << temp << '\n';
	}
	
	input.close();
	
	return 1;
}
