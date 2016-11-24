#include <bits/stdc++.h>
using namespace std;

vector<string> d;
vector<string> s;

char ctoi( int i ) {
    return (char)( i + '0' );
}

int main() {
    int n, r;
    string dic, rule;
    
    while( cin >> n ) {
        d.clear();
        s.clear();
        for( int i = 0; i < n; i++ )
            cin >> dic, d.push_back( dic );
        cin >> r;
        for( int i = 0; i < r; i++ )
            cin >> rule;
        for( int j = 0; j < (int)d.size(); j++ ) {
            vector<string> ans;
            for( int i = 0; i < (int)rule.size(); i++ ) {
                if( rule[i] == '#' ) {
                    if( ans.empty() ) {
                        ans.push_back( d[j] );
                    } else {
                        for( int k = 0; k < (int)ans.size(); k++ )
                            ans[k] += d[j];
                    }
                } else {
                    if( ans.empty() ) {
                        for( int _n = 0; _n <= 9; _n++ ) {
                            string aux_n; aux_n += ctoi( _n );
                            ans.push_back( aux_n );
                        }
                    } else {
                        int size = (int)ans.size();
                        for( int k = 0; k < size; k++ ) {
                            string aux = ans[k];
                            for( int _n = 0; _n <= 9; _n++ ) {
                                string aux_n; aux_n += ctoi( _n );
                                if( !_n ) ans[k] += aux_n;
                                else ans.push_back( aux + aux_n );
                            }
                        }
                    }
                }
            }
            sort( ans.begin(), ans.end() );
            for( int k = 0; k < (int)ans.size(); k++ )
                s.push_back( ans[k] );
        }
        cout << "--" << endl;
        for( string str : s )
            cout << str << endl;
    }

    return 0;
}
