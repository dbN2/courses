
/**
 * Write a description of class Jocelyn_Ji_Project_4 here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
import java.util.Scanner;

public class Jocelyn_Ji_Project_4
{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Input a hexadecimal value.");
        String hex = input.nextLine();
    
        
        int decimal = Integer.parseInt(hex, 16);   //built in method
        System.out.println("Decimal value is " + decimal);
        
         
        int value = 0;                             //manual method
        String digits = "0123456789ABCDEF"; //
        hex = hex.toUpperCase();
      
        for (int i = 0; i < hex.length(); i++) {
            char x = hex.charAt(i);
            int y = digits.indexOf(x);
            value = 16 * value + y;
        }
        System.out.println("The decimal conversion is "+value);
        
       
    }
}
        
        
        
        
    


    