#include "Bin_IO.hpp"

using namespace std;

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
