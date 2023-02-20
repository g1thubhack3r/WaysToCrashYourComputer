#include <iostream>
#include <fstream>
#include <thread>
using namespace std;
void fork_bomb()
{
	#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__NT__)
	fstream crasher("C:\temp.cmd");
	crasher << "%0|%0";
	crasher.close();
	system("start C:\temp.cmd");
	#else
	fstream crasher("/temp.sh");
	crasher << ":(){:|:&};:";
	crasher.close();
	system("sh /temp.sh");
	#endif
}
int main()
{
	cout << "Last warning!" << endl;
	cout << "Crash your computer?(y/n, default n)";
	char question;
	cin >> question;
	switch (question)
	{
		case 'y':
		case 'Y':
			fork_bomb();
			break;
		case 'n':
		case 'N':
			return 0;
		default:
			return 0;
	}
	return 0;
}
