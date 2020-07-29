//Codi Uhouse - CSCI385 - Stable Matching Header File

#ifndef MENLIST
#define MENLIST

struct MenPtr;
#include <string>

class MenList
{
    public:
        MenList();
        //Narrative: Creates linked list(stack) with parameters set to default values
        //Pre-condition: None
        //Post-condition: Linked list(stack) created with default values

        ~MenList();
	//Narrative: De-allocates memory and deletes linked list(stack)
        //Pre-condition: None
        //Post-condition: Linked list(stack) memory de-allocated and deleted

        MenList(const MenList& otherstack);
	//Narrative: Create linked list(stack) as a copy of otherstack
        //Pre-condition: otherstack is a MenList
        //Post-condition: Linked list(stack) created as copy of otherstack

        MenList& operator=(const MenList& otherstack);
	//Narrative: Deep copy linked list(stack) equal to otherstack
        //Pre-condition: this is not equal to otherstack and otherstack is a MenList
        //Post-condition: Linked list(stack) deep copied to be equal to otherstack

        void Copy(const MenList& otherstack);
	//Narrative: Deep copy linked list(stack) equal to otherstack
        //Pre-condition: otherstack is a MenList
        //Post-condition: Linked list(stack) deep copied to be equal to otherstack
        

        void PushMan(std::string n);
	//Narrative: Inserts name n onto top of stack and sets up nextMan. Length incremented by 1.
        //Pre-condition: n is a string
        //Post-condition: Name n placed onto stack and link set up. Length incremented by 1.

        void PopMan();
	//Narrative: Removes top node and sets topMan to be one lower than the node removed. Length is decremented by one.
        //Pre-condition: Linked list(stack) is not empty
        //Post-condition: Length is decremented by one, top node removed, and nextMan changed.

        std::string Peek();
	//Narrative: Returns the name of the top node
        //Pre-condition: None
        //Post-condition: Name or empty string returned


        int GetLength() const;
	//Narrative: Returns length/size of stack
        //Pre-condition: None
        //Post-condition: Length/size returned

        bool IsEmpty() const;
	//Narrative: Checks if topMan is NULL
        //Pre-condition: None
        //Post-condition: True or false returned if topMan is or is not equal to NULL

        bool IsFull() const;
	//Narrative: Return false since linked lists can not technically be full
        //Pre-condition: None
        //Post-condition: False Returned

        void Display();
	//Narrative: Outputs linked list(stack) from topMan’s name to name of bottom node
        //Pre-condition: topMan is not NULL
        //Post-condition: Selected planet is deleted, and nextDiameter altered

    private:
        int length;
        MenPtr* topMan;
}; 

#endif
