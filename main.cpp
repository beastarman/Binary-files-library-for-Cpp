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
		
		unsigned int tell()
		{
			return output.tellp();
		}
		
		void* seek(unsigned int pos)
		{
			return output.seekp(pos);
		}
		
		unsigned int size()
		{
			unsigned int cur = output.tellp();
			
			output.seekp(0,ios::end);
			
			unsigned int end = output.tellp();
			
			output.seekp(cur,ios::beg);
			
			return end;
		}
		
		Binary_ofstream& operator << (const int& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const unsigned int& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const long int& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const long unsigned int& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const short int& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const unsigned short int& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const long long int& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const unsigned long long int& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const char& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const unsigned char& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const float& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const double& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const long double& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
		Binary_ofstream& operator << (const bool& data)
		{
			output.write((char*)&data, sizeof(data));
			
			return *this;
		}
		
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
		
		Binary_ofstream& operator << (const string& data)
		{
			unsigned int i;
			
			operator << (data.size());
			
			for(i=0; i<data.size(); i++)
			{
				operator << (data[i]);
			}
			
			return *this;
		}
		
		Binary_ofstream& operator << (const Bin_IO& data)
		{
			return data.write(*this);
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
		
		unsigned int size()
		{
			unsigned int cur = input.tellg();
			
			input.seekg(0,ios::end);
			
			unsigned int end = input.tellg();
			
			input.seekg(cur);
			
			return end;
		}
		
		Binary_ifstream& operator >> (int& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (unsigned int& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (long int& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (unsigned long int& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (short int& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (unsigned short int& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (long long int& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (unsigned long long int& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (char& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (unsigned char& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (float& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (double& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (long double& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
		Binary_ifstream& operator >> (bool& data)
		{
			input.read((char*)&data,sizeof(data));
			
			return *this;
		}
		
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
		
		Binary_ifstream& operator >> (string& data)
		{
			data.clear();
			
			unsigned int i;
			unsigned int size;
			
			operator >> (size);
			
			for(i=0; i<size; i++)
			{
				char temp;
				
				operator >> (temp);
				
				data.push_back(temp);
			}
			
			return *this;
		}
		
		Binary_ifstream& operator >> (Bin_IO& data)
		{
			return data.read(*this);
		}
};

class A : public Bin_IO
{
	public:
		int a;
		int b;
		
		Binary_ofstream& write(Binary_ofstream& output) const
		{
			return output << a << b;
		}
		
		Binary_ifstream& read(Binary_ifstream& input)
		{
			return input >> a >> b;
		}
};

int main()
{
	Binary_ofstream output;
	Binary_ifstream input;
	
	A temp;
	
	temp.a=10;
	temp.b=20;
	
	output.open(string("test.bin"));
	output << temp;
	output.close();
	
	temp.a=0;
	temp.b=0;
	
	input.open(string("test.bin"));
	input >> temp;
	input.close();
	
	cout << temp.a << ' ' << temp.b << '\n';
	
	return 1;
}
