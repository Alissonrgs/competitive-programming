#include <bits/stdc++.h>
using namespace std;

int main() {
    int month, day, date[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, days;
    bool m;
    
    while( ~scanf( "%d%d", &month, &day ) ) {
        days = 0;
        m = false;
        
        if( month < 12 )
            days += date[month++] - day, m = true;
            
        for( ; month < 12; month++ )
            days += date[month];
        
        if( m )
            days += 25;
        else
            days = 25 - day;
        
        if( days < 0 )
            printf( "Ja passou!\n" );
        else if( days == 0 )
            printf( "E natal!\n" );
        else if( days == 1 )
            printf( "E vespera de natal!\n" );
        else
            printf( "Faltam %d dias para o natal!\n", days );
    }

    return 0;
}
