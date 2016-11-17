#include <bits/stdc++.h>
#define pb push_back
using namespace std;
 
int p[24][6] = {
    1,2,3,4,5,6,
    1,4,2,5,3,6,
    1,5,4,3,2,6,
    1,3,5,2,4,6,
    
    2,3,1,6,4,5,
    2,4,6,1,3,5,
    2,1,4,3,6,5,
    2,6,3,4,1,5,
    
    3,1,2,5,6,4,
    3,5,1,6,2,4,
    3,6,5,2,1,4,
    3,2,6,1,5,4,
    
    4,2,1,6,5,3,
    4,1,5,2,6,3,
    4,5,6,1,2,3,
    4,6,2,5,1,3,
    
    5,4,1,6,3,2,
    5,1,3,4,6,2,
    5,3,6,1,4,2,
    5,6,4,3,1,2,
    
    6,2,4,3,5,1,
    6,3,2,5,4,1,
    6,4,5,2,3,1,
    6,5,3,4,2,1
};
 
int main() {
    string color, color2;
   
    while( cin >> color ) {
        color2.clear();
        for( int j = 6; j < 12; j++ )
            color2 += color[j];
       
        bool equal = false;
        for( int i = 0; i < 24 && !equal; i++ ) {
            string color1 = "";
            for( int j = 0; j < 6; j++ )
                color1 += color[ p[i][j]-1 ];
            if( color1 == color2 )
                equal = true;
        }
   
        cout << ( equal ? "TRUE" : "FALSE" ) << endl;
    }
 
    return 0;
}
