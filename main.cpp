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
		}
};

int main()
{
	return 1;
}
