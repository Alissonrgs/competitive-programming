#include <bits/stdc++.h>
using namespace std;

int q[10] = {0};

bool check_num( string n ) {
    bool c = true;
    for( int i = 0; i < n.size(); i++ )
        if( q[ int( n[i] - '0' ) ] > 2 )
            c = false;
    return c;
}

int main() {
    string n, ans, s = "998877665544332211";
    long long int_n;
    
    cin >> n;
    int_n = stoll( n, nullptr, 10 );
    
    for( int i = 0; i < n.size(); i++ )
        q[ int( n[i] - '0' ) ]++;

    ans = n;
    for( int i = ans.size()-1; i >= 0; i-- ) {
        while( q[ int( ans[i] - '0' ) ] > 2 ) {
            if( ans[i] == '0' ) {
                for( int j = i-1; j >= 0; j-- ) {
                    if( ans[j] != '0' ) {
                        q[ int( ans[j] - '0' ) ]--;
                        ans[j]--;
                        q[ int( ans[j] - '0' ) ]++;
                        
                        for( int jj = j+1; jj < ans.size(); jj++ ) {
                            q[ int( ans[jj] - '0' ) ]--;
                            ans[jj] = '0';
                            q[ int( ans[jj] - '0' ) ]++;
                        }
                        
                        if( q[0] == n.size()-1 ) {
                            cout << s.substr( 0, n.size()-1 ) << endl;
                            return 0;
                        }
                        
                        for( int jj = j+1, k = 0; jj < ans.size() && k < s.size(); jj++, k++ ) {
                            if( q[ int( s[k] - '0' ) ] == 2 ) {
                                jj--;
                                continue;
                            }
                            q[ int( ans[jj] - '0' ) ]--;
                            ans[jj] = s[k];
                            q[ int( ans[jj] - '0' ) ]++;
                        }
                        break;
                    }
                }
                break;
            }
            q[ int( ans[i] - '0' ) ]--;
            ans[i]--;
            q[ int( ans[i] - '0' ) ]++;
            
            for( int jj = i+1; jj < ans.size(); jj++ ) {
                q[ int( ans[jj] - '0' ) ]--;
                ans[jj] = '0';
                q[ int( ans[jj] - '0' ) ]++;
            }
            
            for( int jj = i+1, k = 0; jj < ans.size() && k < s.size(); jj++, k++ ) {
                if( q[ int( s[k] - '0' ) ] == 2 ) {
                    jj--;
                    continue;
                }
                q[ int( ans[jj] - '0' ) ]--;
                ans[jj] = s[k];
                q[ int( ans[jj] - '0' ) ]++;
            }
        }
    }
    cout << stoll( ans, nullptr, 10 ) << endl; 

    return 0;
}
