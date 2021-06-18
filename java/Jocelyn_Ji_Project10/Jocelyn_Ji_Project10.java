
/**
 * Write a description of class Jocelyn_Ji_Project10 here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
import java.util.Arrays;

public class Jocelyn_Ji_Project10
{
    public static void main(String[] args)
    {
        char[] a = {'a','B','c','D','e'};
        MyString x = new MyString(a);
        MyString y = x;
        MyString lowerString = x.toLowerCase();
        MyString substr = x.substring(2,4);
        int value = 12;
        MyString intToString = MyString.valueOf(value);
        
        System.out.print("The string is " );
        x.printString(); 
        System.out.println("The char at position 0 is " + x.charAt(0));
        System.out.println("The length of the string is " + x.length());
        System.out.print("The substring is " );
        substr.printString(); 
        System.out.print("The lowercase conversion is " ); 
        lowerString.printString();
        System.out.print("The string value of integer " + value + " is ");
        intToString.printString();
        
        
        if (x.equals(substr))
        {
            System.out.println("String aBcDe is equal to string cD");
        }
        else
        {
            System.out.println("String aBcDe is not equal to string cD");
        }
        if (x.equals(y))
        {
            System.out.println("String aBcDe is equal to string aBcDe");
        }


    }
}
class MyString
{
    private char[] data;
    
    MyString()   //default  constructor
    {
    }
    MyString(char[] chars)  //constructor copies char array to data
    {
        data = new char[chars.length];
        for (int i=0; i<data.length; i++) 
        {
            data[i] = chars[i];
        }
    }
    public char charAt(int i)
    {
        return data[i];
    }
    public int length()
    {
        return data.length;
    }
    public MyString substring(int begin, int end)
    {
        char arr[] = new char[end - begin]; //length of substring
        arr = Arrays.copyOfRange(data,begin,end);
        return new MyString(arr);
    }
    public MyString toLowerCase()
    {
        char arr[] = new char[length()]; 
        for (int i=0;i<arr.length;i++)
        {
            arr[i] = Character.toLowerCase(data[i]);
        }
        return new MyString(arr);
    }
    public boolean equals(MyString other)
    {
        if (other.length() > data.length || other.length() < data.length)  //if lengths dont match, return false
        {
            return false;
        }
        for (int i=0;i<data.length;i++)
        {
            if (data[i] != other.charAt(i))
            {
                return false;
            }
        }
        return true;
    }
    public static MyString valueOf(int i)  //code from lecture video
    {
        int digits = (int)Math.log10(i) + 1;
        char [] arr = new char[digits]; 
        
        for (int k = arr.length - 1; k>=0; k--) 
        {
            arr[k] = (char) (i%10 + 48);
            
            i /= 10;
        }
        return new MyString(arr);
    }
    public void printString()
    {
        for (int i=0;i<data.length;i++)
        {
            System.out.print(data[i]);
        }
        System.out.println();
    }
    
}