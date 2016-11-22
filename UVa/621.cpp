#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, size;
    string ascII;
    
    cin >> n;
    while( n-- ) {
        cin >> ascII;
        size = (int)ascII.size();
        
        if( ascII == "1" || ascII == "4" || ascII == "78" )
            cout << "+";
        else if( size >= 2 && ascII.substr(size-2, 2 ) == "35" )
            cout << "-";
        else if( ascII[0] == '9' && ascII[size-1] == '4' )
            cout << "*";
        else if( ascII.substr(0, 3) == "190" )
            cout << "?";
        cout << endl;
    }

    return 0;
}
