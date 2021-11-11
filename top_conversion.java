import java.util.Scanner;
public class top_conversion{
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
        double number=sc.nextDouble();
	System.out.println(doubleToBinaryString(number));
    }
    //le input en 0.8125 doit s'ecrire 0,8125.
public static String doubleToBinaryString( double n ) {
         String val = Integer.toBinaryString((int)n)+".";
	 //Setting up string for result

    String newN ="0" + (""+n).substring((""+n).indexOf("."));
    n = Double.parseDouble(newN);

        while ( n > 0 ) {
        //While the fraction is greater than zero (not equal or less than zero)
            double r = n * 2;
	    //Multiply current fraction (n) by 2
            if( r >= 1 ) {
		//If the ones-place digit >= 1
                val += "1";
		//Concat a "1" to the end of the result string (val)
                n = r - 1;
		//Remove the 1 from the current fraction (n)
            }else{
		//If the ones-place digit == 0
                val += "0";
		//Concat a "0" to the end of the result string (val)
                n = r;
		//Set the current fraction (n) to the new fraction
            }
        }
        return val;
	//return the string result with all appended binary values

}
}
