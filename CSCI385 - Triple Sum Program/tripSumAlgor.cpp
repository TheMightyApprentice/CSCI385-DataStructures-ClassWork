//Codi Uhouse - CSCI385 - Triple Sum Algorithm
/*
This program generates arrays that are a mix of positive and negative values to then evaluate the number
of triples that exist within the range of 0 to array size. As each array has its number of triples found,
the program makes an array with double the last array's size. This continues until the size is over 2,000.

Triples are defined as three numbers whose sum is 0.
*/

#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int TripleSum(int *a, int N);
//Narrative: Finds the count of triples in an array of numbers.
//Pre: a is an array of integers and N is an integer.
//Post: The count of triples in a is returned.

void TestFunction();
//Narrative: Runs numerous tests on arrays that have no negative numbers and 
//that are different sizes.
//Pre: None
//Post: Test results are output.

int TestTimeLength(int *a, int N);
//Narrative: Returns the number of seconds that are taken to find the triples in a given array.
//Pre: a is an array of integers and N is an integer.
//Post: The number of seconds taken to run the TripleSum function is returned.

void TestTriples(int *a, int N);
//Narrative: Used in the test functions to return the size of a test array as well as the number
//of triples found within said array.
//Pre: a is an array of integers and N is an integer.
//Post: The size of the array is output as well as the number of triples found inside.

int main()
{
    //Start array size at 500 and set up basic variables.
    const char TEST = 'E';
    int f = 0;
    int r;
    int size = 500;
    clock_t t;
    bool negative;
    char answer;
    float seconds;

    cout << endl << "Request for test or trials? ('E' test or 'R' trials) ";
    cin >> answer;
    cout << endl;

    if(answer == TEST)
    {
        TestFunction();
    }
    else
    {
	//Run trials until array size goes over 2000
        srand(time(NULL));

        while(size <= 2000)
        {
            int arr[size];

            while(f < size)
            {
		//Have numbers randomly be positive or negative
                negative = rand()%2;

                if(negative)
                {
                    arr[f] = -1 * (rand()%10000);
                }
                else
                {
                    arr[f] = rand()%10000;
                }

                f++;
            }
       
	    //Evaluate the time in seconds taken to find answer
            t = clock();
            r = TripleSum(arr, size);
            t = clock() - t;

            seconds = t/CLOCKS_PER_SEC;

            cout << "Size of list: " << size << endl;
            cout << "Num of Triples: " << r << endl;
            cout << "Time taken in seconds: " << seconds << endl << endl;

	    //Set up variables for next array
            size = size * 2;
            t = clock();
            f = 0;
        }
    }

    return 0;
}


int TripleSum(int *a, int N)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int cnt = 0;

    //Find the number of triples in a
    while(i < N)
    {
        j = i + 1;

        while(j < N)
        {
            k = j + 1;

            while(k < N)
            {
                if((a[i] + a[j] + a[k]) == 0)
                {
                    cnt = cnt + 1;
                }

                k = k + 1;
            }

            j = j + 1;
        }

        i = i + 1;
    }

    return cnt;
}


void TestFunction()
{
    int triples;
    int i = 0;
    int size = 12;
    int arr[size];

    cout << endl << "Array size 12 without any triples." << endl;

    for(int f = 0; f < size; f++)
    {
        arr[f] = 4;
    }

    TestTriples(arr, size);

    cout << "Array with triples." << endl;

    arr[size - 1] = -8;

    TestTriples(arr, size);

    cout << "Small array of size 5." << endl;

    size = 5;
    int ary[size];
    
    for(int f = 0; f < size; f++)
    {
        ary[f] = 4;
    }

    ary[size - 1] = -8;

    TestTriples(ary, size);

    cout << "Small array of size 5 for less than one second time." << endl;
    cout << "Seconds taken: " << TestTimeLength(ary, size) << endl << endl;

    size = 2500;
    int array[size];

    for(int f = 0; f < size; f++)
    {
        array[f] = 4;
    }

    cout << "Large array of size 2500 for greater than one second time." << endl;
    cout << "Seconds taken: " << TestTimeLength(array, size) << endl << endl;
}


int TestTimeLength(int *a, int N)
{
    clock_t ti;
    float seconds, r;

    ti = clock();
    r = TripleSum(a, N);
    ti = clock() - ti;

    seconds = ti/CLOCKS_PER_SEC;

    return seconds;    
}


void TestTriples(int *a, int N)
{
    int triples = TripleSum(a, N);

    cout << "Size of List: " << N << endl;
    cout << "Num of Triples: " << triples << endl << endl;
}
