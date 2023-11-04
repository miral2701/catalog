#include<iostream>
#include<string>
using namespace std;

int main() {
	//1 
	/*string text;
	getline( cin,text);

	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ' ') {
			text[i] = '\t';
		}
	}
	cout << text;*/

	//2
	
	//Hi ita and Mira and
	string text;
	getline(cin, text);
	int count = 0;
	int i = 0;
	

	while (i<text.size()) {
			count++;
		
		i += text.find("and", i) + 1;
	}
	cout << count;
	return 0;
}