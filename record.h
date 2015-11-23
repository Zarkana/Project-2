#ifndef POINT_F
#define POINT_F

struct record
{
    char             name[25];
    char             address[80];
    int              yearofbirth;
    char             telno[15];
    struct record *  next;
};

void getfield(char *, int);
#endif