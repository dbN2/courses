
public class Jocelyn_Ji_Project12
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
        try
        {
        accounts[0].deposit(0);
        accounts[0].deposit(250);
        }
        catch (IllegalAmountException ex)
        {
            System.out.println("IllegalAmountException : " + ex.getMessage());
        }
        System.out.println("Balance after deposit is " + accounts[0].getBalance());
        try
        {
            accounts[0].withdraw(150);
        }
        catch (NoSufficientFundsException e)
        {
            System.out.println("IllegalAmountException : " + e.getMessage());
        }
        
            
        System.out.println("Balance after withdraw is " + accounts[0].getBalance());
        System.out.println(); 
        
        accounts[1].setId(1);
        accounts[1].setBalance(25);
        System.out.println("For account with " + accounts[1].toString());
        System.out.println("Starting balance is " + accounts[1].getBalance());
        try
        {
        accounts[1].deposit(250);
        }
        catch (IllegalAmountException ex)
        {
            System.out.println("IllegalAmountException : " + ex.getMessage());
        }
        System.out.println("Balance after deposit is " + accounts[1].getBalance());
        try
        {
            accounts[1].withdraw(700);
        }
        catch (NoSufficientFundsException e)
        {
            System.out.println("IllegalAmountException : " + e.getMessage());
        }
        System.out.println("Balance after withdraw is " + accounts[1].getBalance());
        System.out.println();
        
        accounts[2].setId(2);
        System.out.println("For account with " +accounts[2].toString());
        System.out.println("Starting balance is " + accounts[2].getBalance());
        try
        {
        accounts[2].deposit(-50);
        }
        catch (IllegalAmountException ex)
        {
            System.out.println("IllegalAmountException : " + ex.getMessage());
        }
        System.out.println("Balance after deposit is " + accounts[2].getBalance());
        try
        {
            accounts[2].withdraw(150);
        }
        catch (NoSufficientFundsException e)
        {
            System.out.println("IllegalAmountException : " + e.getMessage());
        }
        System.out.println("Balance after withdraw is " + accounts[2].getBalance());
        ((SavingAccount)accounts[2]).setInterestRate(.02);
        System.out.println("Interest rate is " + ((SavingAccount)accounts[2]).getInterestRate());
        ((SavingAccount)accounts[2]).addInterest();
        System.out.println("Balance after adding interest is " + ((SavingAccount)accounts[2]).getBalance());
        System.out.println();
        
        accounts[3].setId(3);   
        System.out.println("For account with " +accounts[3].toString());
        System.out.println("Starting balance is " + accounts[3].getBalance());
        try
        {
        accounts[3].deposit(550);
        }
        catch (IllegalAmountException ex)
        {
            System.out.println("IllegalAmountException : " + ex.getMessage());
        }
        System.out.println("Balance after deposit is " + accounts[3].getBalance());
        try
        {
            accounts[3].withdraw(300);
        }
        catch (NoSufficientFundsException e)
        {
            System.out.println("IllegalAmountException : " + e.getMessage());
        }
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
    public void deposit(double amount) throws IllegalAmountException
    {
        if (amount<=0)
        {
            throw new IllegalAmountException("Error - Illegal amount for deposit.");
        }
        else
        {
        balance+=amount;
        }
    }
    public void withdraw(double amount) throws NoSufficientFundsException
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
    public void withdraw(double amount) throws NoSufficientFundsException
    {
        if (amount>0 && amount<= getBalance())
        {
            setBalance(getBalance()-amount);
        }
        else
        {
            throw new NoSufficientFundsException("Error - Illegal amount for withdrawal.");
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
   public void withdraw(double amount) throws NoSufficientFundsException
   {
        if (amount>0 && getBalance()-amount>=500)
        {
            setBalance(getBalance()-amount);
        }
        else
        {
            throw new NoSufficientFundsException("Error - Illegal amount for withdrawal.");
            
                
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
class IllegalAmountException extends Exception
{
    public IllegalAmountException(String message)
    {
        super(message);
    }
}
class NoSufficientFundsException extends Exception
{
    public NoSufficientFundsException(String message)
    {
        super(message);
    }
}
    
