import java.io.IOException; 
import java.util.Scanner;
import java.math.BigInteger;

class Main { 
	public static void main( String[] args ) throws IOException {
		Scanner sc = new Scanner( System.in );
		while( true ) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			if( A == 0 && B == 0 ) break;
			BigInteger novo = BigInteger.valueOf( A );
			BigInteger velho = BigInteger.ZERO;
			for( int i = 1; i <= B; i++ ) {
				BigInteger atual = novo.add( velho );
				velho = novo;
				novo = atual;
			}
			System.out.println( novo.add( velho ) );
		}
	}
}
