// File: llist.h

#ifndef POINT_H
#define POINT_H

class llist
{
	private:
		record *	start;
		char 		filename[16];
		int 		readfile();
		int   		writefile();
		record *   	reverse(record *);
		void 		cleanup();

	public:
		llist();
		llist(char[]);
		~llist();
		int addRecord(char[], char [], int, char []);
		int printRecord(char[]);
		int modifyRecord(char[], char [], char []);
		void printAll();
		int deleteRecord(char[]);
		void reverse();
};
#endif