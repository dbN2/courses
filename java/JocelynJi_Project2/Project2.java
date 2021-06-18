
/**
 * Write a description of class Project2 here.
 *
 * Jocelyn Ji
 * 
 */
import java.util.Scanner;
import java.util.Random; 

public class Project2
{
   public static void main(String[] args) {
       System.out.println("Input an amount of change between 1 and 99 cents.");
       
       //Scanner input = new Scanner(System.in);
       //int change = input.nextInt();
       
       Random rand = new Random();
       int change = rand.nextInt(100);
       int originalChange = change; 
      
        int q,d,n,p;   //declare vars
        
        q = change / 25;
        change -= q*25;   //subtract coins from change
        d = change / 10;
        change -= d*10;
        n = change / 5;
        change -= n*5;
        p = change;
        
        System.out.println("You have " + originalChange + " cents, which is equal to");
        System.out.println(q+ " quarters");
        System.out.println(d+ " dimes");
        System.out.println(n+ " nickles");
        System.out.println(p + " pennies");
        
       
       
       
    }
}
       
       
       