/*#ifndef POINT_H
#define POINT_H
*/
struct record
{
    char             name[25];
    char             address[80];
    int              yearofbirth;
    char             telno[15];
    struct record *  next;
};


int addRecord(struct record **, char[], char [], int, char []);
int printRecord(struct record *, char[]);
int modifyRecord(struct record *, char[], char [], char []);
/*void printAllRecords(struct record *);*/
void reverse();
int deleteRecord(struct record **, char[]);
void getfield(char *, int);
void cleanup(struct record **);
int readfile(struct record **, char []);
void writefile(struct record *, char []);
/*
#endif*/