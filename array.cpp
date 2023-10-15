#include <iostream> 
#include <string> 
#include <cassert> 
#include <cctype>

using namespace std;


int locateMaximum(const  string  array[], int  n);


int shiftLeft(string array[], int n, int amount, string placeholder);


int countFloatingPointValues(const string array[], int  n);




bool hasNoCapitals(const string array[], int n);



int main() {
	
	/*
	string name[5] = { "Andrew", "Jason", "tyrion", "xyz", "Edward"};
	cout << locateMaximum(name, 5);
	

	
	int n;

	string fruit[5] = { "apple", "orange", "banana", "peach", "grape" };
	shiftLeft(fruit, 4, 2, "aa");

	n = sizeof(fruit) / sizeof(fruit[0]);
	for (int i = 0; i < n; i++)
	{
		cout << fruit[i] << " ";
	}
	return 0;
	
	*/

	/*
	int n;
	string fruit[4] = { "Andrew", "Bethany", "foo", "foo" };
	shiftLeft(fruit, 3, 4, "foo");

	n = sizeof(fruit) / sizeof(fruit[0]);
	for (int i = 0; i < n; i++)
	{
		cout << fruit[i] << " ";
	}
	return 0;
	*/
	
	/*
	string values[6] = { "mamaBbcca", "mamaBbcca", "12", "98.76", "tyrion", "69"};
	cout << countFloatingPointValues(values, 6);
	*/
	
	

	/*
	string array[6] = { "1", "2", "3", "4", "5", "6"};

	shiftLeft(array, 4, 2, "x");
	*/

	/*
	string data[5] = { "mamaBbcca", "mamaBbcca", "12,", "tyrion", "98.76" };
	cout << locateMaximum(data, 5);
	*/

	/*
	string empty[3] = {"", "tyrion", "xyz"};

	cout << locateMaximum(empty, 3);
	*/

	/*
	string a[6] = { "123", "456", "789", "gamma", "beta", "delta" };

	assert(hasNoCapitals(a, 6) == true);

	assert(countFloatingPointValues(a, 3) == 3);

	cerr << "All tests succeeded" << endl;
	*/	
}



//first we check that the specified array size 'n' is not 0.  Otherwise, there will
//be no array to manipulate.
int shiftLeft(string array[], int n, int amount, string placeholder) {
	if (n <= 0 || amount < 0) {
		return -1;
	}


	int numPlaceholders = 0;

	//here we create a for loop to loop through the elements in the specified n array size.
	//we say that while i < n(array size) if the amount of shifts is greater than the
	//the specified array size then every value will just be replaced with the placeholder.
	for (int i = 0; i < n; i++) {
		if (amount >= n) {

			while (i < n) {
				array[i] = placeholder;

				i++;

				numPlaceholders++;
			}

	//if the amount of left shifts is less than the array size we say that while the index + amount is
	//less than array that index position will become the index + amount.
		} else if (amount < n) {
			while (i + amount < n) {
				array[i] = array[i + amount];

				i++;
			}
	//if it happens that index is still less than n, then those remaining positions will be filled
	//with the placeholder.
			while (i < n) {
				array[i] = placeholder;
				i++;

				numPlaceholders++;
			}
		}	
	}
	return numPlaceholders;
}





int locateMaximum(const  string  array[], int  n) {

	//to locate the maximum value, we first immediatey set the first element as a
	//temporary maximum value.
	string maximumValue = array[0];

	int maxIndex = 0;

	if (n <= 0) {
		return -1;
	}

	//we then use a for loop to loop through each element after the 0th index while
	//i is less than the n array size. If it happens that the maximum value is less
	//than the element at array[i], then the maximum value will now become array[i]
	//and max index would be whatever that i value is.
	for (int i = 1; i < n; i++) {
		
		if (maximumValue < array[i]) {
			maximumValue = array[i];
			maxIndex = i;
		}

	}
	return maxIndex;

}


bool hasNoCapitals(const string array[], int n) {

	if (n <= 0) {
		return true;
	}

	//we use a for loop to go through each element in the array
	for (int i = 0; i < n; i++) {

		//then we use a for each loop to go through the individual characters of the array
		const string data = array[i];

		//if there is an uppercase letter then we return false.  Otherwise we return true;
		for (char letter : data) {
			if (isupper(letter)) {
				return false;
			}
		}
	}
	return true;
}



int countFloatingPointValues(const string array[], int  n) {
	if (n <= 0) {
		return -1;
	}

	//we first initialize variables for the total floating points, amount of decimal points, and
	//number of digits.  
	int totalFloatingPoints = 0;
	int numDecimalPoints = 0;
	int numDigits = 0;

	for (int i = 0; i < n; i++) {

		//we then use a for loop to loop through each element in the array
		//and then nest a for each loop in order to loop through each
		//individual character of an element.  We immediately make the first
		//if statement check that there are no leading '+' or minus signs
		for (char charValue : array[i]) {
			if (charValue == '+' || charValue == '-') {
				break;

				//otherwise, if the character is a '.' we increment the amount of decimal
				//points and continue
			} else if (charValue == '.') {
				numDecimalPoints++;
				continue;

				//a number is not a floating point if it has more then one decimal. So,
				//we make sure that the current amount of decimals does not exceed 1.
				if (numDecimalPoints > 1) {
					break;
				}
			}
			//if it was neither a decimal nor a plus or minus, we check to make sure that
			//it is a digit and increase the amount of digits because a number can't be a floating
			//point if it has no digits in the first place
			else if (isdigit(charValue)) {
				numDigits++;
				continue;
			}
			else {
				break;
			}
		}
		//lastly, we make sure that there are, in fact, digits and that the amount is greater than 0.
		//And, we make sure that the number of decimal points is either greater than or equal to 0 and 
		//less than or equal to 1 since an int is also considered a floating point.
		if ((numDigits > 0) && (numDecimalPoints >= 0 && numDecimalPoints <= 1)) {
			totalFloatingPoints++;

			numDecimalPoints = 0;
			numDigits = 0;
		}
	}
	return totalFloatingPoints;
}




