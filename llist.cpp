/*******************
*
*NAME: Joseph Campbell
*
*PROJECT: 2
*
*CLASS: ICS212
*
*INSTRUCTOR: Ravi Narayan
*
*DATE: November 16th 2015
*
*FILE: storage.cpp
*
*DESCRIPTION: Contains all the storage functions for project 2
*
*******************/

#include "record.h"
#include "llist.h"
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string>
using namespace std;


/*****************
*
*Function name: llist
*
*DESCRIPTION: default constructor for the linked list
*
*
*****************/
llist::llist(void)
{    
    strcpy(this->filename, "test.txt");
    start = NULL;
    this->readfile();
}

/*****************
*
*Function name: llist
*
*DESCRIPTION: default constructor for the linked list
*
*Paramaters: name: the name of the file to be read and written
*
*****************/
llist::llist(char *name)
{    
    strcpy(this->filename, name);
    start = NULL;
    this->readfile();
}

llist::~llist(){
    this->writefile();    
    this->cleanup();
};

/*****************
*
*Function name: addRecord
*
*DESCRIPTION: create a record even if it already exists with the same name
*
*Paramaters: start: a pointer to an array of record structures storing friends, name: the name of friend, address: the address of friend,
*            yearofbirth: the friends year of birth, telNumber: the number of the friend 
*
*****************/
int llist::addRecord(char *uname, char *uaddr, int uyob, char *utelno)
{

    #ifdef DEBUGMODE
        cout << "\n----- DEBUG -----\n";
        cout << "Called Function: addRecord(char *, char *, int, char *)\n";
        cout << "char * = " << uname << "\n";
        cout << "char * = " << uaddr << "\n";
        cout << "int = " << uyob << "\n";       
        cout << "char * = " << utelno << "\n";
        cout << "----- DEBUG -----\n";
    #endif

    struct record *temp;
    temp = this->start;

    if (this->start ==  NULL)
    {
        this->start = (struct record *) malloc(sizeof(struct record));
        strcpy(((*(this->start)).name), uname);
        strcpy(((*(this->start)).address), uaddr);
        (*(this->start)).yearofbirth = uyob;        
        strcpy(((*(this->start)).telno), utelno);

        (*(this->start)).next = NULL;
    }
    else
    {
        while ((*temp).next != NULL)
        {
            temp = (*temp).next;
        }

        (*temp).next = (struct record *) malloc(sizeof(struct record));
        temp = (*temp).next;

        strcpy((*temp).name, uname);
        strcpy((*temp).address, uaddr);
        (*temp).yearofbirth = uyob;        
        strcpy((*temp).telno, utelno);

        (*temp).next = NULL;
    }

    return 0;
}


/*****************
*
*Function name: modifyRecord
*
*DESCRIPTION: modify only all records with the same name
*
*Paramaters: start: an array of record structures storing friends, name: the name of friend, address: the address of friend,
*            telNumber: the number of the friend 
*
*****************/
int modifyRecord(struct record *start, char *uname, char *uaddr, char *utelno)
{
    int totalModifies = 0;
    struct record *temp = start;

    #ifdef DEBUGMODE
        cout << "\n----- DEBUG -----\n";
        cout << "Called Function: modifyRecord(struct record *, char *, char *, char *)\n";
        cout << "struct record * = " << start << ", \n";
        cout << "char * = " << uname << "\n";
        cout << "char * = " << uaddr << "\n";
        cout << "char * = " << utelno << "\n";
        cout << "----- DEBUG -----\n";
    #endif

    cout << "Printing records that match the name: " << uname << "\n";

    while (temp != NULL)
    {
        if (strcmp(uname, (*temp).name)== 0)
        {         
            totalModifies++;
            strcpy((*temp).name, uname);            
            strcpy((*temp).address, uaddr);      
            strcpy((*temp).telno, utelno);
        }
        temp = (*temp).next;        
    }
    if(totalModifies == 0)
    {
        cout << "\nThe record does not exist.\n";
    }
    return 0;
}

/*****************
*
*Function name: printRecord
*
*DESCRIPTION: print on the screen information for all records with the name specified
*
*Paramaters: start: name: the name of friend 
*
*****************/
int llist::printRecord(char *uname)
{
    
    int totalPrints = 0;

    #ifdef DEBUGMODE
        cout << "\n----- DEBUG -----\n";
        cout << "Called Function: printRecord(char *)\n";
        cout << "char * = " << uname << "\n";
        cout << "----- DEBUG -----\n";
    #endif

    cout << "Printing the record with the name: " << uname << "\n";

    while (start != NULL)
    {
        if (strcmp(uname, (*start).name)== 0)
        {
            totalPrints++;
            cout << "\nName: " << (*start).name << "\nAddress:" << (*start).address << "\nTel Number:" << (*start).telno << "\nBirthyear:" << (*start).yearofbirth << "\n";
        }
        start = (*start).next;
    }

    if(totalPrints == 0)
    {
        cout << "\nThe record does not exist.\n"; 
    }

    return 0;
}



/*****************
*
*Function name: printAllRecords
*
*DESCRIPTION: print the entire address book on the screen
*
*****************/
void llist::printAll()
{   

    int totalPrints = 0;
    struct record * temp = this->start;    

    #ifdef DEBUGMODE
        cout << "\n----- DEBUG -----\n";
        cout << "Called Function: printAllRecords(struct record *)\n";        
        cout << "----- DEBUG -----\n";
    #endif

    cout << "\nPrinting every record: \n";

    cout << "the filename:" << this->filename << "\n";

    while (temp != NULL)
    {
        totalPrints++;
        cout << "\nName: " << (*temp).name << "\nAddress:" << (*temp).address << "\nTel Number:" << (*temp).telno << "\nBirthyear:" << (*temp).yearofbirth << "\n";
        temp = (*temp).next;
    }

    if(totalPrints == 0)
    {
        cout << "\nThe list is empty.\n";
    }
}


/*****************
*
*Function name: reverse
*
*DESCRIPTION: reverses the order of the entire address book
*
*****************/
void llist::reverse()
{   

/*    int totalPrints = 0;
    struct record * temp = start;
*/
    #ifdef DEBUGMODE
        cout << "\n----- DEBUG -----\n";
        cout << "Called Function: reverse()\n";
        cout << "----- DEBUG -----\n";
    #endif

    cout << "Reversing the list of records: \n";

/* 
    struct Node* reverse(struct Node** head) 
    {
        Node *parent = *head;
        Node *me = parent->next;
        Node *child = me->next;

     
        parent->next = NULL;
        while(child) {
            me->next = parent;
            parent = me;
            me = child;
            child = child->next;
        }
        me->next = parent;
        *head = me;
        return *head;
    }
*/}

/*****************
*
*Function name: deleteRecord
*
*DESCRIPTION: delete all records, including duplicates based on the name 
*
*Paramaters: start: an array of record structures storing friends, name: the name of friend 
*
*****************/
int deleteRecord(struct record **start, char *uname)
{
    int totalDeletes = 0;
    struct record *temp = *start;
    struct record *prev = *start;

    #ifdef DEBUGMODE
        cout << "\n----- DEBUG -----\n";
        cout << "Called Function: deleteRecord(struct record **, char *)\n";
        cout << "struct record ** = " << start <<" \n";
        cout << "char * = " << uname << "\n";
        cout << "----- DEBUG -----\n";
    #endif   

    cout << "Deleting records that match: " << uname << "\n";

    while (temp != NULL)
    {
        if (strcmp((*temp).name,uname) != 0)
        {
            prev = temp;
            temp = (*temp).next;
        }
        else 
        {        
            if((*temp).next == (*(*start)).next)/*If first*/
            {   
                *start = (*prev).next;

                free(temp);             
                totalDeletes++;

                if((*prev).next == NULL)/*Assign to temp*/
                {
                    temp = NULL;
                }
                else
                {
                    temp = (*prev).next;
                }
            }
            else/*If not first*/
            {
                (*prev).next = (*temp).next;

                free(temp);                    
                totalDeletes++;

                if((*prev).next == NULL)/*Assign to temp*/
                {
                    temp = NULL;
                }
                else
                {
                    temp = (*prev).next;
                }
            }
        }
    }
    if(totalDeletes == 0)
    {
        cout << "\nThe record does not exist.\n";
    }
    return 0;
}


/*****************
*
*Function name: cleanup
*
*DESCRIPTION: destroy all of the records in the linked list and reset the start of the list to NULL
*
*Paramaters: start: an array of record structures storing friends, name: the name of the file to be written
*
*****************/
void llist::cleanup(/*struct record **start*/)
{

    struct record *temp = this->start;
    struct record *nextNode = NULL;
    
    #ifdef DEBUGMODE
        cout << "\n----- DEBUG -----\n";
        cout << "Called Function: cleanup()\n";
        cout << "----- DEBUG -----\n";
    #endif   

    while (temp != NULL)
    {
        nextNode = (*temp).next;

        free(temp);

        temp = nextNode;        
    }
    
    this->start = NULL;

}

/*****************
*
*Function name: readfile
*
*DESCRIPTION: reads a files contents into a program
*
*****************/
int llist::readfile()
{
 /*
    FILE *input;
    char *mode = "r";
*/
    char string [100];
    char inputChar;
    int i = 0;    
    int tab = 0;    

    ifstream input;
    /*input = fopen(filename, mode);*/
    input.open(this->filename, ios::in);

    char name [100];
    char address [100];
    int yearofbirth;
    char telno [20];

    int currVar = 0;

    #ifdef DEBUGMODE
        cout << "\n----- DEBUG -----\n";
        cout << "Called Function: readfile()\n";
        cout << "----- DEBUG -----\n";
    #endif   

    if (input != NULL)
    { 
       while (inputChar != EOF)
       {
            inputChar = input.get();

            if (inputChar == '\n' && currVar != 1)/*If new line and NOT looking for Address*/
            {
                string[i] = '\0';
                if (currVar == 0)
                {
                    strcpy(name, string);                    
                    currVar++;
                    i = 0;
                }
                else if (currVar == 2)
                {
                    yearofbirth = atoi(string);                    
                    currVar++;
                    i = 0;
                }
                else if (currVar == 3)
                {
                    strcpy(telno, string);
                    i = 0;
                    tab = 0;
                    currVar = 0;
                    this->addRecord(name, address, yearofbirth, telno);
                }
            }
            else if ((inputChar == '\t' || tab == 1) && currVar == 1)/*If tab and collecting Address*/
            {
                if(tab==1)
                {
                    string[i] = '\t';
                    string[i+1] = '\0';
                    strcpy(address, string);
                    i = 0;
                    currVar++;
                } else if(inputChar == '\t'){
                    tab = 1;
                }
            }
            else
            {
              string[i] = inputChar;  
              i++;   
            }
        }
    }
    else
    {
        cout << "\nThe file" << this->filename <<", is not in the current directory.\n";        
    }
    
    input.close();

    return 0;
}


/*****************
*
*Function name: writefile
*
*DESCRIPTION: writes content into a file
*
*Paramaters: start: an array of record structures storing friends, name: the name of the file to be written
*
*****************/
int llist::writefile()
{

    struct record *temp = this->start;
/*
    FILE *output;
    char *mode = "w";  

    output = fopen(filename, mode);*/
    ofstream output;
    output.open(this->filename);

    #ifdef DEBUGMODE
        cout << "\n----- DEBUG -----\n";
        cout << "Called Function: writefile()\n";        
        cout << "----- DEBUG -----\n";
    #endif

    if ((temp) ==  NULL)
    {
        cout << "No linked list to write.\n";        
        return 0;
    }

    while ((temp) != NULL)
    {
        output << (*temp).name << "\n";
        output << (*temp).address << "\n";
        output << (*temp).yearofbirth << "\n";
        output << (*temp).telno << "\n";
        temp = (*temp).next;

    }

    output.close();
    /*fclose(output);*/
    return 0;
}