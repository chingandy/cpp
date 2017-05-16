#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;
int main()
{
string s[][2] = { { "black", "#ffffff" },{ "white", "#000000" },
{ "blue", "#0000ff" },{ "red", "#ff0000" },
{ "green", "#00ff00" },{ "", "" } };
map<string, string> m;
map<string, string>::iterator it;
for (int i = 0; !s[i][0].empty(); ++i)
m.insert(map<string, string>::value_type(s[i][0], s[i][1]));
for (it = m.begin(); it != m.end(); ++it) {
cout << (*it).first << " => " << (*it).second << endl;
}
if ((it = m.find("blue")) != m.end()) {
cout << "'blue' Find! It's value is " << (*it).second << endl;
}
return 0;
}
