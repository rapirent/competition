import java.util.*;
import java.math.*;
public class uva10606 {

    public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while(scan.hasNext()) {
			String input_string = scan.next();
			if(input_string.equals("0")) {
				break;
			}
			BigInteger input = new BigInteger(input_string);
			BigInteger high = input;
			BigInteger low = new BigInteger("1");
			while (high.subtract(low).compareTo(BigInteger.ZERO) > 0) {
				BigInteger mid = high.add(low).divide(new BigInteger("2"));
				if (mid.pow(2).compareTo(input) > 0 ) {
					high = mid;
				}
				else {
					low = mid;
				}
			}
			System.out.println(low.pow(2));
		}
	}
}
