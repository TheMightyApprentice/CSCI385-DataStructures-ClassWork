//Codi Uhouse - CSCI385 - Stable Matching Main File

#include "stablelist.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int FindIndex(string name, int num, string *ma, string *wo);
//Narrative: Return index of name if found in man array or woman array.
//Pre-condition: Name is a string, num is an int, and ma and wo are string arrays
//Post-condition: Index of name is returned or return 0


int main()
{
    MenList list;
    ifstream inFile, inFileW;
    string n, m, w, mprime, menFileName, womenFileName;
    int npeople, index, next, windex, mindex, mpindex, gnum, numFWP;
    bool proposedtoAll, testing;

    cout << endl << "Enter '1' for testing test plan or '0' for running algorithm: ";
    cin >> testing;

    if (testing)
    {
	/*Test Code*/
        const int size = 2;
        string tempM[size + 1];
        string tempW[size + 1];

	//Doing many different tests with a pre-determined input

        tempM[0] = "Tom";
        tempM[1] = "Flump";

        tempW[0] = "Wendy";
        tempW[1] = "Kylie";

	//Find index of person already in list
        cout << "F1: " << FindIndex("Flump", size, tempM, tempW) << endl;
        cout << "F2: " << FindIndex("Kylie", size, tempM, tempW) << endl;

        //If person is not in list.
        cout << "F3: " << FindIndex("BL", size, tempM, tempW) << endl;

	//Testing constructor
        cout << "C1: ";
        MenList thirdList;

	//Testing pushing a new person onto newly created list.
        cout << endl << "P2: ";
	thirdList.PushMan("Bob");
	cout << endl << thirdList.GetLength() << " ";
	thirdList.Display();

	//Testing popping a person off of the new list.
	cout << endl << "P4: ";
        thirdList.PopMan();
	cout << endl << thirdList.GetLength() << " ";

	//Testing the other functions in stablelist.h.
        cout << endl << "O8: ";
        thirdList.PushMan("Bob");
	thirdList.PushMan("Billy");
	thirdList.Display();
	cout << endl << "O7: " << thirdList.IsFull();
	cout << endl << "O5: " << thirdList.IsEmpty();
        cout << endl << "O3: " << thirdList.GetLength();
	cout << endl << "O1: " << thirdList.Peek();

        //Testing with an empty list
        MenList fifthList;
	cout << endl << "O9: ";
	fifthList.Display();
	cout << endl << "O6: " << fifthList.IsEmpty() << endl;
	cout << "O4: " << fifthList.GetLength() << endl;
	cout << "O2: " << fifthList.Peek() << endl;
	cout << "P3: ";
	fifthList.PopMan();
	cout << endl << fifthList.GetLength() << " ";
	fifthList.Display();

        //Testing PushMan with invaild input
	cout << endl << "P1: ";
	fifthList.PushMan(" ");
        cout << endl << fifthList.GetLength() << " ";
	fifthList.Display();

        //Testing the copy constructors and Copy functions
	cout << endl << "N2: ";
	MenList fourthList;
	fourthList.Copy(thirdList);
	cout << endl << fourthList.GetLength() << " ";
	fourthList.Display();
	cout << endl << "C2: ";
	MenList secList(fourthList);
	cout << endl << secList.GetLength() << " ";
        secList.Display();
        cout << endl << "OP1: ";
        secList = fourthList;
        cout << endl << secList.GetLength() << " ";
        secList.Display();
        cout << endl << "N1: ";
        MenList sixthList = fifthList;
        cout << endl << sixthList.GetLength() << " ";
        sixthList.Display();
	cout << endl << "OP2: ";
        thirdList.PopMan();
	fourthList = thirdList;
        cout << endl << fourthList.GetLength() << " ";
        fourthList.Display();
	cout << endl << "D1: ";
	cout << endl << "D2: " << endl;
    }
    else
    {
	/*Main Code*/
        cout << endl << "What is the name of the file for men? ";
        cin >> menFileName;

        inFile.open(menFileName.c_str());

        cout << endl << "What is the name of the file for women? ";
        cin >> womenFileName;

        inFileW.open(womenFileName.c_str());

        cout << endl << "How many men(n) or women(n) are there? ";
        cin >> npeople;

        string ManPref[npeople + 1][npeople + 1];
        string ManArray[npeople + 1];
        string WomanArray[npeople + 1];
        int WomanPref[npeople + 1][npeople + 1];
        int Next[npeople + 1];
        string Current[npeople + 1];
        int Ranking[npeople + 1][npeople + 1];
        int RankingHelp[npeople + 1][npeople + 1];

        //all m e M and all w e W are free

        if(inFile && inFileW)
        {
            for(int u = 1; u < npeople + 1; u++)
            {
                if(u != 0)
                {
	            for(int r = 0; r < npeople + 1; r++)
	            {
                        inFile >> n;
                        if(r == 0)
                        {
                            list.PushMan(n);
                            ManArray[u] = n;
		            inFileW >> n;
			    WomanArray[u] = n;
                        }
			else
			{
			    inFileW >> gnum;
                            WomanPref[u][r] = gnum;
			}
                        ManPref[u][r] = n;
                    }
                }
            }
        }

        for(int k = 0; k < npeople + 1; k++)
        {
            Next[k] = 1;
            Current[k] = " ";
        }

        for(int a = 1; a < npeople + 1; a++)
        {
            for(int b = 1; b < npeople + 1; b++)
            {
                RankingHelp[a][b] = b;
            }
        }

        for(int o = 1; o < npeople + 1; o++)
        {
            for(int p = 1; p < npeople + 1; p++)
            {
                numFWP = WomanPref[o][p];
                Ranking[o][numFWP] = RankingHelp[o][p];
            }
        }

        //while there is a man that is free and has not proposed to every woman

        while(!list.IsEmpty() && !proposedtoAll)
        {
            m = list.Peek();
            index = FindIndex(m, npeople, ManArray, WomanArray);
            next = Next[index];
            w = ManPref[index][next];
            windex = FindIndex(w, npeople, ManArray, WomanArray);
            mprime = Current[windex];
            mpindex = FindIndex(mprime, npeople, ManArray, WomanArray);

            if(Current[windex] == " ")
            {
                Current[windex] = m;
                list.PopMan();
                Next[index] = Next[index] + 1;
            }
            else
            {
                if(Ranking[windex][mpindex] < Ranking[windex][index])
                {
                    Next[index] = Next[index] + 1;
                }
                else
                {
                    Current[windex] = m;
                    list.PopMan();
                    list.PushMan(mprime);
                    Next[index] = Next[index] + 1;
                }
            }

            if(Next[index] > npeople)
            {
                proposedtoAll = true;
            }
        }

        //return S

        cout << endl;

        for(int q = 0; q < npeople + 1; q++)
        {
            cout << Current[q] << " " << WomanArray[q] << endl;
        }

        cout << endl;

        inFile.close();
        inFileW.close();
    }

    return 0;
}; 


int FindIndex(string name, int num, string *ma, string *wo)
{
    for(int i = 0; i < num + 1; i++)
    {
        if(wo[i] == name || ma[i] == name)
        {
            return i;
        }
    }

    return 99;
}
 
