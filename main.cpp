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

class Class_A : public Bin_IO
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

class Class_B : public Bin_IO
{
	public:
		vector<Class_A> classes;
	
	public:
		Binary_ofstream& write(Binary_ofstream& output) const
		{
			return output << classes;
		}
		
		Binary_ifstream& read(Binary_ifstream& input)
		{
			return input >> classes;
		}
		
		bool add(int a, int b)
		{
			Class_A temp;
			
			temp.a=a;
			temp.b=b;
			
			classes.push_back(temp);
			
			return 1;
		}
};

int main()
{
	Binary_ofstream output;
	Binary_ifstream input;
	
	unsigned int i=0;
	
	Class_B temp;
	Class_B other;
	
	temp.add(0,10);
	temp.add(20,10);
	temp.add(20,30);
	temp.add(40,30);
	temp.add(40,0);
	
	output.open("test.bin");
	output << temp;
	output.close();
	
	input.open("test.bin");
	input >> other;
	input.close();
	
	for(i=0; i<other.classes.size(); i++)
	{
		cout << other.classes[i].a << ' ' << other.classes[i].b << '\n';
	}
	
	return 1;
}
