//  Project description
//  Your Name
//  Date starts the project

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int binary_to_decimal_signed(string s);
// precondition: s is a string that consists of only 0s and 1s
// postcondition: the decimal integer that is represented by s in two's complement

string signed_extension(string s);
// precondition: s is a string that consists of only 0s and 1s that is at most 16 bits
// postcondition: a 16 bit string has been returned as signed extension of s. For instance, if s = "0101" then
//                return value will be "00000000000000000101" total 12 0s are added in front of s

string decimal_to_binary_signed(int n);
// precondition: n is an integer
// postcondition: n’s two's complement binary representation is returned as a string of 0s and 1s

string add_binaries_signed(string b1, string b2);
// precondition: b1 and b2 are strings that consists of 0s and 1s at most 32 bits, i.e.
//               b1 and b2 are two's complement binary representations of two integers. "0" is 0, "1" is -1
//               However, "10" will be consider as "1111111111111110" as -2
// postcondition: the sum of b1 and b2 is returned as (up to) 32 bits two's complement representation.
// For instance, if b1 = “1101” (-3), b2 = “01” (+1), then the return value is “1111111111111110” (-2)

string twos_complement(string s);
// precondition: s is a string that consists of only 0s and 1s
// postcondition: two's complement of s is returned as an 16 bits binary integer. For instance, if s = "1101", then
//                return value will be "1111111111111101"

int binary_to_decimal(string s);
// precondition: s is a string that consists of only 0s and 1s
// postcondition: the positive decimal integer that is represented by s

string decimal_to_binary(int n);
// precondition: n is a positive integer
// postcondition: n’s binary representation is returned as a string of 0s and 1s

string add_binaries(string b1, string b2);
// precondition: b1 and b2 are strings that consists of 0s and 1s, i.e.
//               b1 and b2 are binary representations of two positive integers
// postcondition: the sum of b1 and b2 is returned. For instance,
//  if b1 = “11”, b2 = “01”, then the return value is “100”

void menu();
// display the menu. Student shall not modify this function

int grade();
// returns an integer that represents the student’s grade of this projects.
// Student shall NOT modify

bool is_binary(string b);
// returns true if the given string s consists of only 0s and 1s; false otherwise

bool test_binary_to_decimal_signed();
// returns true if the student’s implementation of binary_to_decimal function
// is correct; false otherwise. Student shall not modify this function

bool test_decimal_to_binary_signed();
//  returns true if the student’s implementation of decimal_to_binary function is correct; false otherwise. Student shall not modify this function

bool test_add_binaries_signed();
// which returns true if the student’s implementation of add_binaries function
// is correct; false otherwise. Student shall not modify this function

bool test_signed_extension();
// return true if the student's implementation of sign_extension function
// is correct; false otherwise. Student shall not modify this function

bool test_twos_complement();
// return true if the student's implementation of twos_complement function
// is correct; false otherwise. Student shall not modify this function


int main()
{
    int choice;
    string b1, b2;
    int x, score;
    do{
        // display menu
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        // based on choice to perform tasks
        switch(choice){
            case 1:
                cout << "Enter a binary string: ";
                cin >> b1;
                if(!is_binary(b1))
                    cout << "It is not a binary number\n";
                else
                    cout << "Its decimal value is: " << binary_to_decimal_signed(b1) << endl;
                break;
                
            case 2:
                cout << "Enter an integer: ";
                cin >> x;
                
                cout << "Its binary representation is: " <<decimal_to_binary_signed(x) << endl;
                break;
                
            case 3:
                cout << "Enter two binary numbers, separated by white space: ";
                cin >> b1 >> b2;
                if(!is_binary(b1) || !is_binary(b2))
                    cout << "At least one number is not a binary" << endl;
                else
                    cout << "The sum is: " << add_binaries_signed(b1, b2) << endl;
                break;
                
            case 4:
                cout << "Enter a binary number: ";
                cin >> b1;
                cout << "Its signed extension to 16 bits is: " << signed_extension(b1) << endl;;
                break;
                
            case 5:
                cout << "Enter a binary number: ";
                cin >> b1;
                cout << "Its two's complement is: " << twos_complement(b1) << endl;
                break;
                
            case 6:
                score = grade();
                cout << "If you turn in your project on blackboard now, you will get " << score << " out of 10" << endl;
                cout << "Your instructor will decide if one-two more points will be added or not based on your program style, such as good commnets (1 points) and good efficiency (1 point)" << endl;
                break;
                
            case 7:
                cout << "Thanks for using binary calculator program. Good-bye" << endl;
                break;
            default:
                cout << "Wrong choice. Please choose 1-5 from menu" << endl;
                break;
        }
        
    }while(choice != 7);
    return 0;
}

string signed_extension(string s) {
    string extension = "";

    if (s[0] == '0')         //if starting digit is zero, add zeroes in the amount of 16 - string length
    {
        for (size_t i = 0; i < (16 - s.length()); i++)
        {
            extension += '0';
        }
    } 
    else if (s[0] == '1')   //if starting digit is one, add ones in the amount of 16 - string length
    {
        for (size_t i = 0; i < (16 - s.length()); i++)
        {
            extension += '1';
        }
    }

    return extension + s;
}

int binary_to_decimal_signed(string s){
    if (s[0] == '0')        //if binary string is positive, just return binary_to_decimal
    {
    	return binary_to_decimal(s);
    }
    else             //if binary string is negative, create twos_complement then binary_to_decimal
    {
        s = twos_complement(s);
        return -1 * binary_to_decimal(s);   //multiply by -1 since it is negative
    }
    
}

string decimal_to_binary_signed(int n){
    
    if (n >= 0)   //if n is positive
    {
        string bin = decimal_to_binary(n); //change int to binary 
        string zeroes = "";
        for (size_t i = 0; i < 16 - bin.length(); i++)   //add zeroes to string since it is positive
        {
            zeroes += "0";
        }
        return zeroes + bin;  //return full string with added zeroes
    }
    else    //if n is negative
    {
        n *= -1;   //have to make n positive to use decimal_to_binary
        string bin = decimal_to_binary(n);
        
        for (size_t i = 0; i < bin.length(); i++)     //create two's complement
        {
            if (bin[i] == '0')
            {
                bin[i] = '1';
            }
            else if (bin[i] == '1')
            {
                bin[i] = '0';
            }
        }
        string ones = "";                             //add ones to string since it is negative
        for (size_t j = 0; j < 16 - bin.length(); j++)
        {
            ones += "1";
        }

        bin = ones + bin;
        string result = add_binaries(bin, "1");   //add 1 to string
        return result;
    }
}

string add_binaries_signed(string b1, string b2){
    assert(is_binary(b1) && is_binary(b2));

    b1 = signed_extension(b1);  //do signed extension for b1 and b2
    b2 = signed_extension(b2);
    string result = "";
    int carry = 0;
    int i1 = (int)b1.length() - 1;
    int i2 = (int)b2.length() - 1;
    while (i1 >= 0 || i2 >= 0)
    {
        int d1 = 0, d2 = 0;
        if (i1 >= 0) d1 = b1[i1] - 48;
        if (i2 >= 0) d2 = b2[i2] - 48;
        int sum = carry + d1 + d2; // single digit sum
        carry = sum / 2; // carry is 1 if sum is 2 or 3; 0 otherwise
        result = string(1, (char)(48 + sum % 2)) + result;
        i1--;
        i2--;
    }
    return result;
}

string twos_complement(string s){
    if (s == "0")  //force overflow for case "0"
    {
        return "0000000000000000";
    }

    for (size_t i = 0; i < s.length(); i++)   //for all digits in string, reverse number
    {
        if (s[i] == '0')
        {
            s[i] = '1';
        }
        else if (s[i] == '1')
        {
            s[i] = '0';
        }
    }
    string twos = signed_extension(s);   //do signed extension
    twos = add_binaries(twos, "1");   //add "1" to string
    return twos;
}

int binary_to_decimal(string s){
    assert(is_binary(s));
    int result = 0;
    for(size_t i = 0; i < s.length(); i++)
        result = result * 2 + (s[i] - 48);
    return result;
}

string decimal_to_binary(int n){
    if(n == 0) return string("0"); // special case 0
    
    string result = "";
    while(n > 0){
        result = string(1, (char) (n%2 + 48)) + result; // add last digit of n in front of the result
        n = n/2;
    }
    return result;
}

string add_binaries(string b1, string b2){
    // you implement this
    assert(is_binary(b1) && is_binary(b2));
    string result = "";
    int carry = 0;
    int i1 = (int) b1.length()-1;
    int i2 = (int) b2.length()-1;
    while(i1 >= 0 || i2 >= 0)
    {
        int d1 = 0, d2 = 0;
        if(i1 >= 0) d1 = b1[i1] - 48;
        if(i2 >= 0) d2 = b2[i2] - 48;
        int sum = carry + d1 + d2; // single digit sum
        carry = sum / 2; // carry is 1 if sum is 2 or 3; 0 otherwise
        result = string(1, (char) (48+sum%2)) + result;
        i1--;
        i2--;
    }
    if(carry != 0)
        result = "1" + result;
    return result;
}
void menu()
{
    cout << "\n******************************\n";
    cout << "*          Menu              *\n";
    cout << "* 1. Binary to Decimal       *\n";
    cout << "* 2. Decimal to Binary       *\n";
    cout << "* 3. Add two Binaries        *\n";
    cout << "* 4. Signed extension        *\n";
    cout << "* 5. Two's complement        *\n";
    cout << "* 6. Grade                   *\n";
    cout << "* 7. Quit                    *\n";
    cout << "******************************\n\n";
}

int grade(){
    int result = 0;
    // binary_to_decimal function worth 2 points
    if(test_binary_to_decimal_signed()){
        cout << "binary_to_decimal_signed function pass the test" << endl;
        result += 2;
    }
    else
        cout << "binary_to_decimal_signed function failed" << endl;
    
    // decinal_to_binary_signed function worth 1 points
    if(test_decimal_to_binary_signed()){
        cout << "decimal_to_binary_signed function passed the test" << endl;
        result += 1;
    }
    else
        cout << "decimal_to_binary_signed function failed" << endl;
    
    // add_binaries function worth 2 points
    if(test_add_binaries_signed()){
        cout << "add_binaries_signed function passed the test" << endl;
        result += 2;
    }
    else
        cout << "add_binaries_signed function failed" << endl;
    
    // signed_extension function worth 1 point
    if(test_signed_extension()){
        cout << "sign_extension function passed the test" << endl;
        result += 1;
    }
    else
        cout << "sign_extension function failed" << endl;
    
    // twos_complement function worth 2 point
    if(test_twos_complement()){
        cout << "twos_complement function passed the test" << endl;
        result += 2;
    }
    else
        cout << "twos_complement function failed" << endl;
    return result;
}

bool is_binary(string s){
    for(size_t i = 0; i < s.length(); i++)
        if(s[i] != '0' && s[i] != '1') // one element in s is not '0' or '1'
            return false;  // then it is not a binary number representation
    return true;
}

bool test_binary_to_decimal_signed(){
    if(binary_to_decimal_signed("0") != 0 || binary_to_decimal_signed("1") != -1 || binary_to_decimal_signed("01") != 1)
        return false;
    if(binary_to_decimal_signed("010") != 2 || binary_to_decimal_signed("10") != -2)
        return false;
    if(binary_to_decimal_signed("01101") != 13 || binary_to_decimal_signed("1101") != -3)
        return false;
    return true;
}

bool test_decimal_to_binary_signed(){
    if(decimal_to_binary_signed(0) != "0000000000000000" || decimal_to_binary_signed(1) != "0000000000000001")
        return false;
    if(decimal_to_binary_signed(-1) != "1111111111111111")
        return false;
    if(decimal_to_binary_signed(-2) != "1111111111111110" || decimal_to_binary_signed(-13) != "1111111111110011")
        return false;
    return true;
}

bool test_add_binaries_signed(){
    if(add_binaries_signed("0", "0") != "0000000000000000") return false;
    if(add_binaries_signed("0", "110101") != "1111111111110101") return false;
    if(add_binaries_signed("1", "110101") != "1111111111110100") return false;
    if(add_binaries_signed("101", "111011") != "1111111111111000") return false;
    return true;
}

bool test_signed_extension(){
    if(signed_extension("1") != "1111111111111111" || signed_extension("0") != "0000000000000000") return false;
    if(signed_extension("10101") != "1111111111110101" || signed_extension("0101") != "0000000000000101") return false;
    return true;
}

bool test_twos_complement(){
    if(twos_complement("1") != "0000000000000001" || twos_complement("0") != "0000000000000000") return false;
    if(twos_complement("01") != "1111111111111111" || twos_complement("10") != "0000000000000010") return false;
    if(twos_complement("10101") != "0000000000001011") return false;
    return true;
    
}
