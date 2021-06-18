#include <iostream>
#include <string>
#include <cstdlib>
#include "Set.cpp"

using namespace myset;
using namespace std;

template<class T>
void printSet(Set<T> set)
{
	T *ptr = set.toArray();   //change to array to iterate through it
	if (ptr != NULL) //if set contains elements
	{
	for (int i=0; i<set.size(); i++)
	{
		cout << ptr[i] << endl;
	}
	delete[] ptr;
	}
	else
	{
		cout<< "Empty set.\n";
	}
}

int main()
{
	Set<int> set1;
	set1.add(1);
	set1.add(5);
	set1.add(9);
	set1.add(13);
	set1.add(17);
	Set<int> set2;
	set2.add(5);
	set2.add(10);
	set2.add(15);
	Set<string> set3;
	set3.add("ace");
	set3.add("ceg");
	set3.add("egi");
	set3.add("gik");
	
	cout << "The set is : \n";       //int sets
	printSet(set1);
	cout << "The set contains 5 : " << set1.contains(5) << endl;
	set1.remove(1);
	set1.remove(9);
	cout << "After removing 1 and 9, the set is : \n";
	printSet(set1);
	cout << "Set 2 is : \n";
	printSet(set2);
	set1 = set2;
	cout << "After equalizing set 1 to set 2, set 1 is : \n";
	printSet(set1);
	
	cout << "Set 3 is : \n";        //string set
	printSet(set3);
	set3.remove("ace");
	cout << "After removing \"ace\", the set is : \n";
	printSet(set3);
	set3.remove("ceg");
	set3.remove("egi");
	set3.remove("gik");
	cout << "After removing remaining elements, the set is :";
	printSet(set3);
	
	
	
	
	
	return 0;
}
