#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//typedef struct to define what's in the phonebook
typedef struct PhoneBookContacts
{
    char Name[20];
    char Surname[20];
    char PhoneNumber[20];
} phone;

//Function prototypes
void AddEntry (phone[]);
void DeleteEntry (phone[]);
void PrintEntry (phone[]);
void Sort (phone[]);
void searchData(phone[]);
int counter = 0; //Global counter variable used to keep track of number of contacts

//Begin main function
int main (void)
{
    clrscr();
    phone phonebook[20]; //Phonebook instance
    char userChoice; //Variable to use to select menu choice

    while (userChoice != 'Q'|| userChoice != 'q') {
        printf ("***************\n");
        printf ("Please enter a command:\n");
        printf("'A': Add an entry\n");
        printf("'D': Delete an entry\n");
        printf("'S': Sort entries\n");
        printf("'P': Print the phonebook\n");
		printf("'F': Find data\n");
        printf("'Q': Quit\n");
        printf ("***************\n");

        scanf("%s", &userChoice);  //Stores menu choice into variable userChoice

        // Add Contact
        if (userChoice == 'A'|| userChoice == 'a')
            AddEntry(phonebook);

        //Remove Contact
        if (userChoice == 'D'|| userChoice == 'd')
            DeleteEntry (phonebook);

        //Print Contacts
        if (userChoice == 'P'|| userChoice == 'p')
            PrintEntry(phonebook);

        //Sort Contacts
        if (userChoice == 'S'|| userChoice == 's')
            Sort(phonebook);
			
	//Find data	
	if (userChoice=='F'|| userChoice == 'f')
	    searchData (phonebook);

        //Quit
        if (userChoice == 'Q'||  userChoice == 'q') {
            printf("Phonebook will now quit.");
            return 0;
        }
    }
getch();
}


//Function Definition to Add Contacts to the Phonebook
void AddEntry (phone phonebook[]) {
    
    clrscr();	
    counter++; //global counter increase

    printf("\nFirst Name: ");
    scanf("%s" ,&phonebook[counter-1].Name); //counter-1 b/c arrays start at 0

    printf("Last Name: ");
   scanf("%s", &phonebook[counter-1].Surname);

    printf("Phone Number (XXX-XXX-XXXX): ");
   scanf("%s", &phonebook[counter-1].PhoneNumber);

    printf("\n%s added to phonebook\n", phonebook[counter-1].Name); //tell user friend added
    getch();
}

void DeleteEntry (phone phonebook[])
{
    clrscr();
    int x = 0;
    int i = 0;
	
    char deleteName[20];  // Temp string to compare to existing phonebook
    char deleteSurname[20];  //temp string
    
    printf("\nEnter name: ");
    scanf("%s",&deleteName); //place into temp string
    printf("Enter Surname: ");
    scanf("%s",&deleteSurname); //place into temp string

    for (x = 0; x < counter; x++)
    {
        if (strcmp(deleteName, phonebook[x].Name) == 0) //compare deleteName to phonebook.Name
        {
           if (strcmp(deleteSurname, phonebook[x].Surname) == 0)
            
            {
                for ( i = x; i < counter - 1; i++ ) //If deleteSurname matches phonebook.Surname
                {
                    strcpy(phonebook[i].Name, phonebook[i+1].Name);  //Put null into Name
                    strcpy(phonebook[i].Surname, phonebook[i+1].Surname); //Null into Surname
                    strcpy(phonebook[i].PhoneNumber, phonebook[i+1].PhoneNumber); //Null into PhoneNumber
                    printf("Contact removed from phonebook.\n");
                    counter--;
                    break;
                }
            }
	    else
	     printf("That contact was not found, please try again.\n");
        }

        
    }
	
	getch();
}

// Function def to print contacts
void PrintEntry (phone phonebook[]) {
    
    clrscr();
    int x = 0;
    printf("\nPhonebook entries:\n");

    for ( x = 0; x < counter; x++) {
        printf("\n(%d)\n", x+1); //Show contact number
        printf("Name: %s %s\n", phonebook[x].Name, phonebook[x].Surname); //Name
        printf("Number: %s\n", phonebook[x].PhoneNumber); //Number
    }
   getch();	
}

void Sort (phone phonebook[]) {
    
    clrscr();
    phone temp;
    int i;  int j;

    for (i=0; i<counter; i++) {
        for (j=i+1; j<counter; j++) {
            if (strcmp(phonebook[i].Surname, phonebook[j].Surname) > 0) {
                temp=phonebook[i];
                phonebook[i]=phonebook[j];
                phonebook[j]=temp;
            }
        }
    }
getch();
}

void searchData(phone phonebook[])
{
	clrscr();
	int x=0;
	
	char TempName[20];
	char TempSurname[20];

	printf("\nPlease type the name of the friend you wish to find a number for.");
	printf("\n\nName:");
	scanf("%s",&TempName);
	printf("Surname:");
	scanf("%s", TempSurname);
	for(x=0; x < counter; x++)
	{
		if(strcmp(TempName, phonebook[x].Name)==0)
		{
		   if(strcmp(TempSurname, phonebook[x].Surname)==0)
		   {
			printf("\n%s %s 's phone number is %s\n", phonebook[x].Name, phonebook[x].Surname, phonebook[x].PhoneNumber);
		    }
	         }
       	         else 
		 printf("That contact was not found, please try again.\n");

	}

	getch();
}
