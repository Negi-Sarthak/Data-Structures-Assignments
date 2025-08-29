#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[100];
    cout << "Enter string: ";
    cin >> s;
    int len=strlen(s);
    cout << "Reversed string: ";
    for(int i=len-1;i>=0;i--) cout << s[i];
    return 0;
}
