h30365
s 00219/00000/00000
d D 1.1 15/10/19 17:08:59 jsc940 1 0
c date and time created 15/10/19 17:08:59 by jsc940
e
u
U
f e 0
t
T
I 1
/*******************
*
*uNAME: Joseph Campbell
*
*PROJECT: 1
*
*CLASS: ICS212
*
*INSTRUCTOR: Ravi Narayan
*
*DATE: October 6th 2015
*
*FILE: ui.c
*
*DESCRIPTION: Contains the user interface for project 1
*
*******************/

#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DEBUGMODE = 1;

int main( int argc, char *argv[])
{
    int i;

    if(argc == 2)/*If arguments given are 2 total */
    {
        DEBUGMODE = strcmp("debug", argv[1]);    

        if(DEBUGMODE == 0)/*If argument1 is equal to the string literal "debug" */
        {
            menuInterface();
        } 
        else
        {
            printf("ui: Invalid argument \"%s\"\nUsage: ui [-f]\n       ui [-f] [-i]\n", argv[1]);
        }   
    }
    else if(argc == 1)/*If only 1 argument supplied*/
    {
        menuInterface();
    }
    else if( argc > 2 )
    {
        printf("ui: Too many arguments supplied (%d)\nUsage: ui [-f]\n       ui [-f] [-i]\n", argc);
    }       
    else
    {
        printf("ui: An argument is expected\nUsage: ui [-f]\n       ui [-f] [-i]\n");
    }
    return 0;
}


/*******************
*
*Function uname: menuInterface
*
*DESCRIPTION: User Interface function
* 
*******************/
void menuInterface()
{
    char uname[25];
    char uaddr[80];
    int uyob;
    char utelno[15];    
    char line[256];
    int arg1;
    int isint;

    char filename[] = "test.txt";    

    int temp;
    int programEnd = 0;

    struct record * start = NULL;

    readfile(&start, filename);

    while(programEnd != 1){
        char prompt[] = "Choose one of the following,\n\t[1]Add a new record in the database\n\t[2]Modify a record in the database using the uname as the key\n\t[3]Print information about a record using the uname as the key\n\t[4]Print all information in the database\n\t[5]Delete an existing record from the database using the uname as a key\n\t[6]Quit the program\n"; 

         printf("\n%s", prompt);
         while (1) {            
            arg1 = 0;
            isint = 0;          

            fgets(line, sizeof line, stdin);
            isint = sscanf(line, "%d",&arg1);
            if(arg1 < 1 || arg1 > 6)
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

          printf("Enter name: ");

          /* Get the name, with size limit. */
          fgets (uname, 25, stdin);

          /* Remove trailing newline, if there. */
          if ((strlen(uname)>0) && (uname[strlen (uname) - 1] == '\n'))
              uname[strlen (uname) - 1] = '\0';

              

          printf("Enter address: ");
          getfield(uaddr, 80);
              
          printf("Enter year of birth: ");
          scanf("%d", &uyob);
              
          printf("Enter phone number: ");
          scanf("%s", &utelno);

       	  addRecord(&start, uname, uaddr, uyob, utelno);   

          break;
        case 2:
          printf("Enter name: ");

          /* Get the name, with size limit. */
          fgets (uname, 25, stdin);

          /* Remove trailing newline, if there. */
          if ((strlen(uname)>0) && (uname[strlen (uname) - 1] == '\n'))
              uname[strlen (uname) - 1] = '\0';

    	    printf("Enter address: ");
      	  getfield(uaddr, 100);
   
       	  printf("Enter phone number: ");
   	      scanf("%s", &utelno);
   
    	    modifyRecord(start, uname, uaddr, utelno);
             
        	break; 
       case 3:
          printf("Enter name: ");

          /* Get the name, with size limit. */
          fgets (uname, 25, stdin);

          /* Remove trailing newline, if there. */
          if ((strlen(uname)>0) && (uname[strlen (uname) - 1] == '\n'))
              uname[strlen (uname) - 1] = '\0';


           printRecord(start, uname);
           break;
       case 4:

            printAllRecords(start);
   
            break; 
       case 5:
          printf("Enter name: ");

          /* Get the name, with size limit. */
          fgets (uname, 25, stdin);

          /* Remove trailing newline, if there. */
          if ((strlen(uname)>0) && (uname[strlen (uname) - 1] == '\n'))
              uname[strlen (uname) - 1] = '\0';
      
    	     deleteRecord(&start, uname);
   
           break; 
       case 6:
       	  /*End program*/
           programEnd = 1;
           printf("Program Ended\n");    
           break; 
       }  
       
    }

    writefile(start, filename); 
    cleanup(&start);

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
    printf("Hit tab, then enter key when done.\n");
    while( (inputchar = getchar()) != '\t')
    {      
      field[counter] = inputchar;
      counter++;        
    }
    field[counter] = '\t';
    field[counter+1] = '\0';
}
E 1
