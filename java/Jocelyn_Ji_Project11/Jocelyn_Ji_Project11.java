
/**
 * Write a description of class Jocelyn_Ji_Project11 here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Jocelyn_Ji_Project11
{
    public static void main(String[] args)
    {
        Account[] accounts = new Account[4];
        accounts[0] = new CheckingAccount();
        accounts[1] = new CheckingAccount();
        accounts[2] = new SavingAccount();
        accounts[3] = new SavingAccount();
        
        System.out.println("For account with " + accounts[0].toString());
        System.out.println("Starting balance is " + accounts[0].getBalance());
        accounts[0].setBalance(0);
        accounts[0].deposit(250);
        System.out.println("Balance after deposit is " + accounts[0].getBalance());
        accounts[0].withdraw(150);
        System.out.println("Balance after withdraw is " + accounts[0].getBalance());
        System.out.println(); 
        
        accounts[1].setId(1);
        accounts[1].setBalance(25);
        System.out.println("For account with " + accounts[1].toString());
        System.out.println("Starting balance is " + accounts[1].getBalance());
        accounts[1].deposit(250);
        System.out.println("Balance after deposit is " + accounts[1].getBalance());
        accounts[1].withdraw(250);
        System.out.println("Balance after withdraw is " + accounts[1].getBalance());
        System.out.println();
        
        accounts[2].setId(2);
        System.out.println("For account with " +accounts[2].toString());
        System.out.println("Starting balance is " + accounts[2].getBalance());
        accounts[2].deposit(650);
        System.out.println("Balance after deposit is " + accounts[2].getBalance());
        accounts[2].withdraw(150);
        System.out.println("Balance after withdraw is " + accounts[2].getBalance());
        ((SavingAccount)accounts[2]).setInterestRate(.02);
        System.out.println("Interest rate is " + ((SavingAccount)accounts[2]).getInterestRate());
        ((SavingAccount)accounts[2]).addInterest();
        System.out.println("Balance after adding interest is " + ((SavingAccount)accounts[2]).getBalance());
        System.out.println();
        
        accounts[3].setId(3);   
        System.out.println("For account with " +accounts[3].toString());
        System.out.println("Starting balance is " + accounts[3].getBalance());
        accounts[3].deposit(550);
        System.out.println("Balance after deposit is " + accounts[3].getBalance());
        accounts[3].withdraw(300);
        System.out.println("Balance after withdraw is " + accounts[3].getBalance());
        ((SavingAccount)accounts[3]).setInterestRate(.12);
        System.out.println("Interest rate is " + ((SavingAccount)accounts[3]).getInterestRate());
        ((SavingAccount)accounts[3]).addInterest();
        System.out.println("Balance after adding interest is " + ((SavingAccount)accounts[3]).getBalance());
        System.out.println();
   


        
        
    }
}
class Account
{
    private int id;
    private double balance;
    
    public Account()
    {
        id = 0;
        balance = 0;
    }
    public Account(int _id, double _balance)
    {
        id = _id;
        balance = _balance;
    }
    public void setBalance(double _balance)
    {
        balance = _balance;
    }
    public double getBalance()
    {
        return balance;
    }
    public void setId(int _id)
    {
        id = _id;
    }
    public int getId()
    {
        return id;
    }
    public void deposit(double amount)
    {
        balance+=amount;
    }
    public void withdraw(double amount)
    {
    }
    public String toString()
    {
        return "ID: " + Integer.toString(id);
    }
}
class CheckingAccount extends Account
{
    @Override
    public void withdraw(double amount)
    {
        if (amount>0 && amount<= getBalance())
        {
            setBalance(getBalance()-amount);
        }
        else
        {
            return;
        }
    }
    public String toString()
    {
        return "ID: " + Integer.toString(getId());
    }
}
class SavingAccount extends Account
{
   private double interestRate;
   public void setInterestRate(double rate)
   {
        interestRate = rate;
   }
   public double getInterestRate()
    {
        return interestRate;
    }
   @Override
   public void withdraw(double amount)
   {
        if (amount>0 && getBalance()-amount>=500)
        {
            setBalance(getBalance()-amount);
        }
        else
        {
            return;
        }
   }
   public void addInterest()
   {
        setBalance(getBalance()*(1+interestRate));
   }
   public String toString()
   {
        return "ID: " + Integer.toString(getId());
   }
}
        
