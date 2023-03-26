#include <iostream>
//#include "queue.h"
#include <time.h>
#include <fstream>
#include <sstream>


using namespace std;

int main()
{
	string path = "text.txt";
	fstream fs;

	fs.open(path, fstream::in);

	if (fs.is_open())
	{
		//char str[256];
		string str2;
		while (!fs.eof())
		{
			getline(fs, str2);
			cout << str2 << endl;
		}
	}
	else
	{
		cout << "Error" << endl;
	}


}