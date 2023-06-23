#include <iostream>
#include <random>

using namespace std;

int RNG();
int RNG(int lowest);
int RNG(int lowest, int highest);

int main()
{
	int x = RNG(), y = RNG(x), z = RNG(x, y);
	int myValue, count = 1;


	cout << "Hello, player." << endl;
	cout << "I'm thinking of a number between " << x << " and " << y << endl;
	cout << "Can you guess the number in my head?" << endl;

	cin >> myValue;

	while (z!=myValue &&  count<7)
	{
		if (myValue < z)
		{
			cout << "Your number is too low." << endl;
		}
		

		else if (myValue > z)
		{
			cout << "Your number is too high." << endl;
		}

		count++;
		cout << "Try again." << endl;
		cin >> myValue;
	}

	if (myValue == z)
	{
		cout << myValue << " is the correct number!";
		cout << "It took you " << count << " tries." << endl;
	}

	else
	{
		cout << "You didn't guess correctly." << endl;
		cout << "The correct answer is " << myValue << endl;
	}
}

int RNG()
{
	int myValueHolder;
	random_device myVal1;
	mt19937 myRandomizer(myVal1());

	uniform_int_distribution<int> distribution(1,100);

	myValueHolder = distribution(myRandomizer);

	return myValueHolder;
}


int RNG(int lowest)
{
	int myValueHolder;
	random_device myVal1;
	mt19937 myRandomizer(myVal1());

	uniform_int_distribution<int> distribution(lowest, 100);

	myValueHolder = distribution(myRandomizer);

	return myValueHolder;
}

int RNG(int lowest, int highest)
{
	int myValueHolder;
	random_device myVal1;
	mt19937 myRandomizer(myVal1());

	uniform_int_distribution<int> distribution(lowest, highest);

	myValueHolder = distribution(myRandomizer);

	return myValueHolder;
}