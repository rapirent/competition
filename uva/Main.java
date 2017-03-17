import java.util.*;
import java.math.*;
class Main {

    public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while(scan.hasNext()) {
			String input_string = scan.next();
			if(input_string.equals("0")) {
				break;
			}
			BigInteger input = new BigInteger(input_string);
			BigInteger high = input;
			BigInteger low = BigInteger.ONE;
			BigInteger mid = null;
            while (high.compareTo(low)>= 0) {
				mid = high.add(low).divide(BigInteger.valueOf(2));
				if ((mid.pow(2)).compareTo(input) > 0 ) {
					high = mid.subtract(BigInteger.ONE);
				}
				else if((mid.pow(2)).compareTo(input) < 0){
					low = mid.add(BigInteger.ONE);
				}
                else {
                    break;
                }
			}
            if(mid.pow(2).compareTo(input)> 0) {
                mid = mid.subtract(BigInteger.ONE);
            }
			System.out.println(mid.pow(2));
		}
	}
}
