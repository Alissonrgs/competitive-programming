#include <bits/stdc++.h>
using namespace std;

int main() {
    string t;
    
    getline( cin, t );
    cout << ( t.size() <= 140 ? "TWEET" : "MUTE" ) << endl;

    return 0;
}
