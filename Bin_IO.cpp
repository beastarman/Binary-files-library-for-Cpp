#include "Bin_IO.hpp"

Binary_ofstream::Binary_ofstream()
{
}

Binary_ofstream::~Binary_ofstream()
{
}

unsigned int Binary_ofstream::size()
{
	unsigned int cur = ofstream::tellp();
	
	ofstream::seekp(0,ios::end);
	
	unsigned int end = ofstream::tellp();
	
	ofstream::seekp(cur,ios::beg);
	
	return end;
}

Binary_ofstream& Binary_ofstream::operator << (const int& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const unsigned int& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const long int& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const long unsigned int& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const short int& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const unsigned short int& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const long long int& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const unsigned long long int& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const char& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const unsigned char& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const float& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const double& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const long double& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const bool& data)
{
	ofstream::write((char*)&data, sizeof(data));
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const string& data)
{
	unsigned int i;
	
	operator << (data.size());
	
	for(i=0; i<data.size(); i++)
	{
		operator << (data[i]);
	}
	
	return *this;
}

Binary_ofstream& Binary_ofstream::operator << (const Bin_IO& data)
{
	return data.write(*this);
}

Binary_ifstream::Binary_ifstream()
{
}

Binary_ifstream::~Binary_ifstream()
{
}

unsigned int Binary_ifstream::size()
{
	unsigned int cur = ifstream::tellg();
	
	ifstream::seekg(0,ios::end);
	
	unsigned int end = ifstream::tellg();
	
	ifstream::seekg(cur);
	
	return end;
}

Binary_ifstream& Binary_ifstream::operator >> (int& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (unsigned int& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (long int& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (unsigned long int& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (short int& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (unsigned short int& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (long long int& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (unsigned long long int& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (char& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (unsigned char& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (float& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (double& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (long double& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (bool& data)
{
	ifstream::read((char*)&data,sizeof(data));
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (string& data)
{
	data.clear();
	
	unsigned int i;
	unsigned int size;
	
	Binary_ifstream::operator >> (size);
	
	for(i=0; i<size; i++)
	{
		char temp;
		
		Binary_ifstream::operator >> (temp);
		
		data.push_back(temp);
	}
	
	return *this;
}

Binary_ifstream& Binary_ifstream::operator >> (Bin_IO& data)
{
	return data.read(*this);
}
