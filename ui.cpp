/*******************
*
*uNAME: Joseph Campbell
*
*PROJECT: 2
*
*CLASS: ICS212
*
*INSTRUCTOR: Ravi Narayan
*
*DATE: November 12th 2015
*
*FILE: ui.cpp
*
*DESCRIPTION: Contains the user interface for project 2
*
*******************/

#include "record.h"
#include "llist.h"
#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;

int main( int argc, char *argv[])
{
    char uname[25];
    char uaddr[80];
    int uyob;
    char utelno[15];    
    char line[256];
    int arg1;
    int isint;

    int temp;
    int programEnd = 0;

    llist myllist("test.txt"); 

    while(programEnd != 1)
    {
        char prompt[] = "\nChoose one of the following,\n\t[1]Add a new record in the database\n\t[2]Modify a record in the database using the name as the key\n\t[3]Print information about a record using the name as the key\n\t[4]Print all information in the database\n\t[5]Delete an existing record from the database using the name as a key\n\t[6]Reverse the list\n\t[7]Quit the program\n"; 

        cout << prompt << "\n";
        while (1) {            
            arg1 = 0;
            isint = 0;          

            fgets(line, sizeof line, stdin);
            isint = sscanf(line, "%d",&arg1);
            if(arg1 < 1 || arg1 > 7)
            {
              isint = 0;
            }
            if(isint) 
            {
              break;
            }
        }
        
        switch(arg1)
        {
        case 1:
          cout << "Enter name: ";

          cin.getline(uname, 25);
              
          cout << "Enter address: ";
          getfield(uaddr, 80);
              
          cout << "Enter year of birth: ";        

          cin >> uyob;

          cout << "Enter phone number: ";              
          scanf("%s", &utelno);

          myllist.addRecord(uname, uaddr, uyob, utelno);   

          break;
        case 2:
          cout << "Enter name: ";        

          cin.getline(uname, 25);

          cout << "Enter address: ";
          getfield(uaddr, 100);

          cout << "Enter phone number: ";   
          scanf("%s", &utelno);
   
          /*modifyRecord(start, uname, uaddr, utelno);*/
             
          break; 
       case 3:
          cout << "Enter name: ";

          cin.getline(uname, 25);

           myllist.printRecord(uname);
           break;
       case 4:            
            myllist.printAll();
            break; 
       case 5:
          cout << "Enter name: ";

          cin.getline(uname, 25);
      
          /*deleteRecord(&start, uname);*/
   
          break;
       case 6:
          
          /*reverse();*/
          break;          
       case 7:
          /*End program*/
          programEnd = 1;
          cout << "Program Ended\n";
          break; 
      }  
    }    
    
    return 0;
}

/*******************
*
*Function name: getfield
*
*DESCRIPTION: gets a field of information including spaces
*
*Paramaters field: the field to be edited
* 
*******************/
void getfield(char *field, int size)
{
    char inputchar;
    int counter = 0;
    int first  = 0;
    int i = 0;

    cout << "Hit tab, then enter key when done.\n";
    while( (inputchar = cin.get()) != '\t')
    {      
      field[counter] = inputchar;
      counter++;        
    }

    field[counter] = '\t';
    field[counter+1] = '\0';
}
