import java.io.IOException;
import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static int count_ones( BigInteger n ) {
        int count = 0;
        BigInteger dois = BigInteger.valueOf( 2 );
        
        while( n != BigInteger.ZERO ) {
            if( n.mod( dois ) != BigInteger.ZERO )
                count++;
            n = n.divide( dois );
        }
        return count;
    }

	public static void main( String[] args ) throws IOException {
		Scanner sc = new Scanner( System.in );
	    int t = sc.nextInt();
	    
	    while( t-- != 0 ) {
	        BigInteger n = sc.nextBigInteger();
	        System.out.println( count_ones( n ) );
	    }
	}
}
