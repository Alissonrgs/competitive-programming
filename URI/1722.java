import java.io.IOException;
import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static BigInteger fib[] = new BigInteger[100005];
	public static BigInteger fibonacci( int p ) {
		if( fib[p].compareTo( BigInteger.ZERO ) > 0 ) return fib[p];
		return fib[p] = fibonacci( p-1 ).add( fibonacci( p-2 ) );
	}
	public static int q_fib( BigInteger a, BigInteger b ) {
		int pa = 1, pb;
		while( fibonacci( pa ).compareTo( a ) < 0 ) pa++;
		pb = pa;
		while( fibonacci( pb ).compareTo( b ) <= 0 ) pb++;
		return pb - pa;
	}
    public static void main( String[] args ) throws IOException {
        Scanner sc = new Scanner( System.in );
		for( int i = 2; i < 100005; i++ ) fib[i] = BigInteger.ZERO;
		fib[0] = BigInteger.ONE;
		fib[1] = BigInteger.ONE;
		while( true ) {
			BigInteger a = sc.nextBigInteger();
			BigInteger b = sc.nextBigInteger();
			if( a.compareTo( BigInteger.ZERO ) == 0 && b.compareTo( BigInteger.ZERO ) == 0 ) break;
			System.out.println( q_fib( a, b ) );
		}
    }
}