#include <iostream>
#include <string>
using namespace std;


int main(){
	string s;
	while (getline(cin, s)){
		int i = 0;
		while (i < s.size()){
			for (; i < s.size() && s[i] != ']'; i++){}
			if (i>=s.size())
				break;
			int k = 0;
			int j = i;
			for (; s[j] != '['; j--){
				if (s[j] == '|')
					k = j;
			}
			size_t val = stoi(s.substr(j + 1, k - j));
			string s1 = s.substr(k + 1, i - k - 1);
			string s2 = s1;
			while (--val){
				s2 += s1;
			}
			s.replace(j, i-j+1, s2);
			i = 0;
		}
		cout << s << endl;
	}

	return 0;
}