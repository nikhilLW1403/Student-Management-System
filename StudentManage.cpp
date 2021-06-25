#include<stdio.h>
#include<string.h>
#include<iostream>
#include<sstream>

using namespace std;

struct node
{
	int roll;
	char fname[30];
	char lname[30];
	int mark;
	struct node *next;
};
typedef struct node NODE;
typedef struct node* PNODE;

class Student
{
	private:
	int rn;
	int iSize;
	PNODE Head;
	
	public:
	Student()
	{
		rn=0;
		iSize=0;
		Head=NULL;
	}
	
	void InsertLast(char *fname,char *lname,int mark)
	{
		int i=0,j=0;
		rn++;
		PNODE newn=new NODE;
		newn->roll=rn;
		while(*fname!='\0')
		{
			newn->fname[i]=*fname;
			i++;
			fname++;
		}
		while(*lname!='\0')
		{
			newn->lname[j]=*lname;
			j++;
			lname++;
		}
		newn->fname[i]='\0';
		newn->lname[j]='\0';
		
		if(mark<1 || mark>100)
		{
			cout<<"*** Please enter proper marks ***\n\n";
			newn->mark=0;
		}
		else
		{
			newn->mark=mark;
		}
		
		newn->next=NULL;
		if(Head==NULL)
		{
			Head=newn;
			iSize++;
		}
		else
		{
			PNODE temp=Head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newn;
			iSize++;
		}
	}
	
	void InsertAtPos(char *fn,char *ln,int mark,int iPos)
	{
		if(iSize==0 && iPos!=1)
		{
			cout<<"** LIST IS EMPTY **\n\n";
			return;
		}
		int i=0,j=0;
		PNODE temp=Head;
		PNODE newn=new NODE;
		newn->roll=iPos;
		char* first=fn;
		char* last=ln;
		while(*fn!='\0')
		{
			newn->fname[i]=*fn;
			i++;
			fn++;
		}
		while(*ln!='\0')
		{
			newn->lname[j]=*ln;
			j++;
			ln++;
		}
		newn->fname[i]='\0';
		newn->lname[j]='\0';
		
		newn->mark=mark;
		newn->next=NULL;
	
		if(iPos<1 || iPos>iSize+1)
		{
			cout<<"*** Please enter proper position ***\n\n";
			return;
		}
		if(iPos==1)
		{
			newn->roll=1;
			newn->next=Head;
			Head=newn;
			
			while(temp!=NULL)
			{
				temp->roll=temp->roll+1;
				temp=temp->next;
			}
			iSize++;
		}
		else if(iPos==iSize+1)
		{
			InsertLast(first,last,mark);
		}
		else
		{
			rn++;
			for(int k=1; k<iPos-1; k++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next=newn;
			
			temp=temp->next->next;
			while(temp!=NULL)
			{
				temp->roll=temp->roll+1;
				temp=temp->next;
			}
			iSize++;
		}
	}
	
	void DeleteAtPos(int iPos)
	{
		if(iSize==0)
		{
			cout<<"** LIST IS EMPTY **\n\n";
			return;
		}
		PNODE temp=Head;
		PNODE Target=NULL;
		if(iPos<1 || iPos>iSize)
		{
			cout<<"** Please enter proper roll number **\n";
			return;
		}
		if(iPos==1)
		{
			rn--;
			temp=temp->next;
			Target=Head;
			Head=Head->next;
			delete (Target);
			iSize--;
	
			while(temp!=NULL)
			{
				temp->roll=temp->roll-1;
				temp=temp->next;
			}
		}
		else if(iPos==iSize)
		{
			rn--;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			Target=temp->next;
			temp->next=NULL;
			delete(Target);
			iSize--;
		}
		else
		{
			rn--;
			for(int i=1; i<iPos-1; i++)
			{
				temp=temp->next;
			}
			Target=temp->next;
			temp->next=temp->next->next;
			delete (Target);
			iSize--;
			temp=temp->next;
			while(temp!=NULL)
			{
				temp->roll=temp->roll-1;
				temp=temp->next;
			}
		}
	}
	
	void UpdateName(int roll,char *fname,char *lname)
	{
		if(iSize==0)
		{
			cout<<"** LIST IS EMPTY **\n\n";
			return;
		}
		int i=0,j=0;
		PNODE temp=Head;
		if(roll<1 || roll>iSize)
		{
			cout<<"** Please enter proper roll number **\n";
			return;
		}
		while(temp->roll!=roll)
		{
			temp=temp->next;
		}
		while(*fname!='\0')
		{
			temp->fname[i]=*fname;
			i++;
			fname++;
		}
		while(*lname!='\0')
		{
			temp->lname[j]=*lname;
			j++;
			lname++;
		}
		temp->fname[i]='\0';
		temp->lname[j]='\0';
	}

	void UpdateMark(int iPos,int mark)
	{
		if(iSize==0)
		{
			cout<<"** LIST IS EMPTY **\n\n";
			return;
		}
		if(iSize==0)
		{
			cout<<"** LIST IS EMPTY **\n\n";
			return;
		}
		PNODE temp=Head;
		if(iPos<1 || iPos>iSize+1)
		{
			cout<<"** Please enter proper roll number **\n";
			return;
		}
		while(temp->roll!=iPos)
		{
			temp=temp->next;
		}
		if(mark<1 || mark>100)
		{
			cout<<"*** Please enter proper marks ***\n\n";
			temp->mark=0;
		}
		else
		{
			temp->mark=mark;
		}
	}
	
	void Display()
	{
		if(iSize==0)
		{
			cout<<"** LIST IS EMPTY **\n\n";
			return;
		}
		PNODE temp=Head;
		cout<<"----------------------\n\n";
		while(temp!=NULL)
		{
			cout<<"Roll no.: "<<temp->roll<<"\n";
			cout<<"Name: "<<temp->fname<<" ";
			cout<<temp->lname<<"\n";
			cout<<"Mark: "<<temp->mark<<"\n";
			temp=temp->next;
			cout<<"----------------------\n\n";
		}
	}
	int Count()
	{
		return iSize;
	}
	void Query(char *str)
	{
		int value=1;
		char sel[10],ch[30],from[10],stud[10];
		char where[10],att[30],op[20],mark1[20],mark2[20];
		char mark[30],op1[20];
		
		sscanf(str,"%s %s %s %s %s %s %s %s %s %s %s",sel,ch,from,stud,where,att,op,mark,mark1,mark2,op1);
		
	if(value=strcmp(sel,"select")==0)
	{
		if(value=strcmp(ch,"*")==0)
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					if(value=strcmp(where,"where")==0)
					{
						if(value=strcmp(att,"mark")==0)
						{
							if(value=strcmp(op,"=")==0)
							{
								stringstream s(mark);   //stringstream-->  convert string to integer
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark==smark)
									{
										cout<<"Roll no.: "<<temp->roll<<"\n";
										cout<<"Name: "<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"Mark: "<<temp->mark<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,">")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark>smark)
									{
										cout<<"Roll no.: "<<temp->roll<<"\n";
										cout<<"Name: "<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"Mark: "<<temp->mark<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,"<")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark<smark)
									{
										cout<<"Roll no.: "<<temp->roll<<"\n";
										cout<<"Name: "<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"Mark: "<<temp->mark<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;								
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
								return;
							}
						}
						else if(value=strcmp(att,"name")==0)
						{
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(value=strcmp(temp->fname,mark)==0)
								{
									cout<<"Roll no.: "<<temp->roll<<"\n";
									cout<<"Name: "<<temp->fname<<" ";
									cout<<temp->lname<<"\n";
									cout<<"Mark: "<<temp->mark<<"\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;		
						}
						else if(value=strcmp(att,"rollno")==0)
						{
							stringstream s(mark);
							int smark=0;
							s>>smark;
								
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(temp->roll==smark)
								{
									cout<<"Roll no. : "<<temp->roll<<"\n";
									cout<<"Name : "<<temp->fname<<" ";
									cout<<temp->lname<<"\n";
									cout<<"Mark : "<<temp->mark<<"\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<att<<"\n\n";
							return;
						}
					}
					else if(value=strcmp(where,"\0")==0)
					{
						cout<<"\n";
						PNODE temp=Head;
						cout<<"----------------------\n\n";
						while(temp!=NULL)
						{
							cout<<"Roll no.: "<<temp->roll<<"\n";
							cout<<"Name: "<<temp->fname<<" ";
							cout<<temp->lname<<"\n";
							cout<<"Mark: "<<temp->mark<<"\n";
							temp=temp->next;
							cout<<"----------------------\n\n";
						}
						return;
					}
					//else if(value=strcmp(where,"where")!=1)
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"name")==0)
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					if(value=strcmp(where,"where")==0)
					{
						if(value=strcmp(att,"mark")==0)
						{
							if(value=strcmp(op,"=")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark==smark)
									{
										cout<<" -->  "<<temp->fname<<" ";
										cout<<temp->lname<<"\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,">")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark>smark)
									{
										cout<<" -->  "<<temp->fname<<" ";
										cout<<temp->lname<<"\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,"<")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark<smark)
									{
										cout<<" -->  "<<temp->fname<<" ";
										cout<<temp->lname<<"\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
								return;
							}
						}
						else if(value=strcmp(att,"name")==0)
						{
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(value=strcmp(temp->fname,mark)==0)
								{
									cout<<" -->  "<<temp->fname<<" ";
									cout<<temp->lname<<"\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else if(value=strcmp(att,"rollno")==0)
						{
							stringstream s(mark);
							int smark=0;
							s>>smark;
								
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(temp->roll==smark)
								{
									cout<<" -->  "<<temp->fname<<" ";
									cout<<temp->lname<<"\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<att<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"rollno")==0)
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					if(value=strcmp(where,"where")==0)
					{
						if(value=strcmp(att,"mark")==0)
						{
							if(value=strcmp(op,"=")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark==smark)
									{
										cout<<" -->  "<<temp->roll<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,">")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark>smark)
									{
										cout<<" -->  "<<temp->roll<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,"<")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark<smark)
									{
										cout<<" -->  "<<temp->roll<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
								return;
							}
						}
						else if(value=strcmp(att,"name")==0)
						{
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(value=strcmp(temp->fname,mark)==0)
								{
									cout<<" -->  "<<temp->roll<<"\n\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else if(value=strcmp(att,"rollno")==0)
						{
							stringstream s(mark);
							int smark=0;
							s>>smark;
								
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(temp->roll==smark)
								{
									cout<<" -->  "<<temp->roll<<"\n\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<att<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"mark")==0)
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					if(value=strcmp(where,"where")==0)
					{
						if(value=strcmp(att,"mark")==0)
						{
							if(value=strcmp(op,"=")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark==smark)
									{
										cout<<" -->  "<<temp->mark<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,">")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark>smark)
									{
										cout<<" -->  "<<temp->mark<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,"<")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark<smark)
									{
										cout<<" -->  "<<temp->mark<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
								return;
							}
						}
						else if(value=strcmp(att,"name")==0)
						{
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(value=strcmp(temp->fname,mark)==0)
								{
									cout<<" -->  "<<temp->mark<<"\n\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else if(value=strcmp(att,"rollno")==0)
						{
							stringstream s(mark);
							int smark=0;
							s>>smark;
								
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(temp->roll==smark)
								{
									cout<<" -->  "<<temp->mark<<"\n\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<att<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"name,mark")==0)  //(%s[a-zA-z,])
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					if(value=strcmp(where,"where")==0)
					{
						if(value=strcmp(att,"mark")==0)
						{
							if(value=strcmp(op,"=")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark==smark)
									{
										cout<<" -->  "<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<" -->  "<<temp->mark<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,">")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark>smark)
									{
										cout<<" -->  "<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<" -->  "<<temp->mark<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,"<")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark<smark)
									{
										cout<<" -->  "<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<" -->  "<<temp->mark<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
								return;
							}
						}
						else if(value=strcmp(att,"name")==0)
						{
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(value=strcmp(temp->fname,mark)==0)
								{
									cout<<" -->  "<<temp->fname<<" ";
									cout<<temp->lname<<"\n";
									cout<<" -->  "<<temp->mark<<"\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else if(value=strcmp(att,"rollno")==0)
						{
							stringstream s(mark);
							int smark=0;
							s>>smark;
								
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(temp->roll==smark)
								{
									cout<<" -->  "<<temp->fname<<" ";
									cout<<temp->lname<<"\n";
									cout<<" -->  "<<temp->mark<<"\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<att<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"mark,name")==0)  //(%s[a-zA-z,])
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					if(value=strcmp(where,"where")==0)
					{
						if(value=strcmp(att,"mark")==0)
						{
							if(value=strcmp(op,"=")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark==smark)
									{
										cout<<" -->  "<<temp->mark<<"       ";
										cout<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,">")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark>smark)
									{
										cout<<" -->  "<<temp->mark<<"       ";
										cout<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,"<")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark<smark)
									{
										cout<<" -->  "<<temp->mark<<"       ";
										cout<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
								return;
							}
						}
						else if(value=strcmp(att,"name")==0)
						{
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(value=strcmp(temp->fname,mark)==0)
								{
									cout<<" -->  "<<temp->mark<<"       ";
									cout<<temp->fname<<" ";
									cout<<temp->lname<<"\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else if(value=strcmp(att,"rollno")==0)
						{
							stringstream s(mark);
							int smark=0;
							s>>smark;
								
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(temp->roll==smark)
								{
									cout<<" -->  "<<temp->mark<<"       ";
									cout<<temp->fname<<" ";
									cout<<temp->lname<<"\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<att<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"rollno,name")==0)  //(%s[a-zA-z,])
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					if(value=strcmp(where,"where")==0)
					{
						if(value=strcmp(att,"mark")==0)
						{
							if(value=strcmp(op,"=")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark==smark)
									{
										cout<<" -->  "<<temp->roll<<"       ";
										cout<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,">")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark>smark)
									{
										cout<<" -->  "<<temp->roll<<"       ";
										cout<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,"<")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark<smark)
									{
										cout<<" -->  "<<temp->roll<<"       ";
										cout<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
								return;
							}
						}
						else if(value=strcmp(att,"name")==0)
						{
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(value=strcmp(temp->fname,mark)==0)
								{
									cout<<" -->  "<<temp->roll<<"       ";
									cout<<temp->fname<<" ";
									cout<<temp->lname<<"\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else if(value=strcmp(att,"rollno")==0)
						{
							stringstream s(mark);
							int smark=0;
							s>>smark;
								
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(temp->roll==smark)
								{
									cout<<" -->  "<<temp->roll<<"       ";
									cout<<temp->fname<<" ";
									cout<<temp->lname<<"\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<att<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"name,rollno")==0)  //(%s[a-zA-z,])
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					if(value=strcmp(where,"where")==0)
					{
						if(value=strcmp(att,"mark")==0)
						{
							if(value=strcmp(op,"=")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark==smark)
									{
										cout<<" -->  "<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"   "<<temp->roll<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,">")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark>smark)
									{
										cout<<" -->  "<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"   "<<temp->roll<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,"<")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark<smark)
									{
										cout<<" -->  "<<temp->fname<<" ";
										cout<<temp->lname<<"\n";
										cout<<"   "<<temp->roll<<"\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
								return;
							}
						}
						else if(value=strcmp(att,"name")==0)
						{
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(value=strcmp(temp->fname,mark)==0)
								{
									cout<<" -->  "<<temp->fname<<" ";
									cout<<temp->lname<<"\n";
									cout<<"   "<<temp->roll<<"\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else if(value=strcmp(att,"rollno")==0)
						{
							stringstream s(mark);
							int smark=0;
							s>>smark;
								
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(temp->roll==smark)
								{
									cout<<" -->  "<<temp->fname<<" ";
									cout<<temp->lname<<"\n";
									cout<<"   "<<temp->roll<<"\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<att<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"mark,rollno")==0)  //(%s[a-zA-z,])
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					if(value=strcmp(where,"where")==0)
					{
						if(value=strcmp(att,"mark")==0)
						{
							if(value=strcmp(op,"=")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark==smark)
									{
										cout<<"Mark: "<<temp->mark<<"		";
										cout<<"Rollno: "<<temp->roll<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,">")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark>smark)
									{
										cout<<"Mark: "<<temp->mark<<"		";
										cout<<"Rollno: "<<temp->roll<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,"<")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark<smark)
									{
										cout<<"Mark: "<<temp->mark<<"		";
										cout<<"Rollno: "<<temp->roll<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
								return;
							}
						}
						else if(value=strcmp(att,"name")==0)
						{
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(value=strcmp(temp->fname,mark)==0)
								{
									cout<<"Mark: "<<temp->mark<<"		";
									cout<<"Rollno: "<<temp->roll<<"\n\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else if(value=strcmp(att,"rollno")==0)
						{
							stringstream s(mark);
							int smark=0;
							s>>smark;
								
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(temp->roll==smark)
								{
									cout<<"Mark: "<<temp->mark<<"		";
									cout<<"Rollno: "<<temp->roll<<"\n\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<att<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"rollno,mark")==0)  //(%s[a-zA-z,])
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					if(value=strcmp(where,"where")==0)
					{
						if(value=strcmp(att,"mark")==0)
						{
							if(value=strcmp(op,"=")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark==smark)
									{
										cout<<"Rollno: "<<temp->roll<<"		";
										cout<<"Mark: "<<temp->mark<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,">")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark>smark)
									{
										cout<<"Rollno: "<<temp->roll<<"		";
										cout<<"Mark: "<<temp->mark<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else if(value=strcmp(op,"<")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								
								PNODE temp=Head;
								cout<<"----------------------\n\n";
								while(temp!=NULL)
								{
									if(temp->mark<smark)
									{
										cout<<"Mark: "<<temp->mark<<"		";
										cout<<"Rollno: "<<temp->roll<<"\n\n";
										cout<<"----------------------\n\n";
									}
									temp=temp->next;
								}
								return;
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
								return;
							}
						}
						else if(value=strcmp(att,"name")==0)
						{
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(value=strcmp(temp->fname,mark)==0)
								{
									cout<<"Rollno: "<<temp->roll<<"		";
									cout<<"Mark: "<<temp->mark<<"\n\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else if(value=strcmp(att,"rollno")==0)
						{
							stringstream s(mark);
							int smark=0;
							s>>smark;
								
							PNODE temp=Head;
							cout<<"----------------------\n\n";
							while(temp!=NULL)
							{
								if(temp->roll==smark)
								{
									cout<<"Rollno: "<<temp->roll<<"		";
									cout<<"Mark: "<<temp->mark<<"\n\n";
									cout<<"----------------------\n\n";
								}
								temp=temp->next;
							}
							return;
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<att<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"MAX(mark)")==0)  //%[a-zA-z()]
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					cout<<"\n";
					PNODE temp=Head;
					int Max=temp->mark;
					temp=temp->next;
					while(temp!=NULL)
					{
						if(Max<temp->mark)
						{
							Max=temp->mark;
						}
						temp=temp->next;
					}
					cout<<" -->  "<<Max<<"\n\n";
					return;
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"MIN(mark)")==0)
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					cout<<"\n";
					PNODE temp=Head;
					int Min=temp->mark;
					temp=temp->next;
					while(temp!=NULL)
					{
						if(Min>temp->mark)
						{
							Min=temp->mark;
						}
						temp=temp->next;
					}
					cout<<" -->  "<<Min<<"\n\n";
					return;
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"AVG(mark)")==0)
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					cout<<"\n";
					PNODE temp=Head;
					int iSum=0,Avg=0,iCnt=0;
					while(temp!=NULL)
					{
						iCnt++;
						iSum=iSum + (temp->mark);
						temp=temp->next;
					}
					Avg=iSum/iCnt;
					cout<<" -->  "<<Avg<<"\n\n";
					return;
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"COUNT(mark)")==0)
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					if(value=strcmp(where,"where")==0)
					{
						if(value=strcmp(att,"mark")==0)
						{
							if(value=strcmp(op,"=")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								int iCnt=0;
								
								PNODE temp=Head;
								cout<<"\n";
								while(temp!=NULL)
								{
									if(temp->mark==smark)
									{
										iCnt++;
									}
									temp=temp->next;
								}
								cout<<" -->  "<<iCnt<<"\n\n";
								return;
							}
							else if(value=strcmp(op,">")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								int iCnt=0;
								
								PNODE temp=Head;
								cout<<"\n";
								while(temp!=NULL)
								{
									if(temp->mark>smark)
									{
										iCnt++;
									}
									temp=temp->next;
								}
								cout<<" -->  "<<iCnt<<"\n\n";
								return;
							}
							else if(value=strcmp(op,"<")==0)
							{
								stringstream s(mark);
								int smark=0;
								s>>smark;
								int iCnt=0;
								
								PNODE temp=Head;
								cout<<"\n";
								while(temp!=NULL)
								{
									if(temp->mark<smark)
									{
										iCnt++;
									}
									temp=temp->next;
								}
								cout<<" -->  "<<iCnt<<"\n\n";
								return;
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
								return;
							}
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<att<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else if(value=strcmp(ch,"SUM(mark)")==0)
		{
			if(value=strcmp(from,"from")==0)
			{
				if(value=strcmp(stud,"student")==0)
				{
					cout<<"\n";
					PNODE temp=Head;
					int iSum=0;
					while(temp!=NULL)
					{
						iSum=iSum + (temp->mark);
						temp=temp->next;
					}
					cout<<" -->  "<<iSum<<"\n\n";
					return;
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else
		{
			cout<<"\n --> "<<"Error at : "<<ch<<"\n\n";
			return;
		}
	}
	else if(value=strcmp(sel,"insert")==0)
	{
		if(value=strcmp(ch,"into")==0)
		{
			if(value=strcmp(from,"student")==0)
			{
				if(value=strcmp(stud,"values")==0)
				{
					if(value=strcmp(where,"(")==0)
					{
						if(value=strcmp(mark1,")" )==0)
						{
							char ma[30];
							stringstream s(mark);
							int smark=0;
							s>>smark;
							
							InsertLast(att,op,smark);
							return;
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<mark1<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else
		{
			cout<<"\n --> "<<"Error at : "<<ch<<"\n\n";
			return;
		}
	}
	else if(value=strcmp(sel,"UPDATE")==0)
	{
		if(value=strcmp(ch,"student")==0)
		{
			if(value=strcmp(from,"SET")==0)
			{
				if(value=strcmp(stud,"mark")==0)
				{
					if(value=strcmp(where,"=")==0)
					{	
						if(value=strcmp(op,"where")==0)
						{
							if(value=strcmp(mark,"rollno")==0)
							{
								if(value=strcmp(mark1,"=")==0)
								{
									stringstream up(att);
									int update=0;
									up>>update;
									
									stringstream uproll(mark2);
									int updateroll=0;
									uproll>>updateroll;
									
									PNODE temp=Head;
									while(temp!=NULL)
									{
										if(temp->roll==updateroll)
										{
											temp->mark=update;
											return;
										}
										temp=temp->next;
									}
									return;
								}
								else if(value=strcmp(mark1,"<")==0)
								{
									stringstream up(att);
									int update=0;
									up>>update;
									
									stringstream uproll(mark2);
									int updateroll=0;
									uproll>>updateroll;
									
									PNODE temp=Head;
									while(temp!=NULL)
									{
										if(temp->roll<updateroll)
										{
											temp->mark=update;
										}
										temp=temp->next;
									}
									return;
								}
								else if(value=strcmp(mark1,">")==0)
								{
									stringstream up(att);
									int update=0;
									up>>update;
									
									stringstream uproll(mark2);
									int updateroll=0;
									uproll>>updateroll;
									
									PNODE temp=Head;
									while(temp!=NULL)
									{
										if(temp->roll>updateroll)
										{
											temp->mark=update;
										}
										temp=temp->next;
									}
									return;
								}
								else
								{
									cout<<"\n --> "<<"Error at : "<<mark1<<"\n\n";
									return;
								}
							}
							else if(value=strcmp(mark,"name")==0)
							{
								if(value=strcmp(mark1,"=")==0)
								{
									stringstream upname(att);
									int updateMark=0;
									upname>>updateMark;
									
									PNODE temp=Head;
									while(temp!=NULL)
									{
										if(value=strcmp(temp->fname,mark2)==0)
										{
											temp->mark=updateMark;
										}
										temp=temp->next;
									}
									return;
								}
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<mark<<"\n\n";
								return;
							}
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<op<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else if(value=strcmp(stud,"name")==0)
				{
					if(value=strcmp(where,"=")==0)
					{
						if(value=strcmp(mark,"where")==0)
						{
							if(value=strcmp(mark1,"rollno")==0)
							{
								if(value=strcmp(mark2,"=")==0)
								{
									stringstream updatename(op1);
									int uname=0;
									updatename>>uname;
									
									PNODE temp=Head;
									while(temp!=NULL)
									{
										if(temp->roll==uname)
										{
											strcpy(temp->fname,att);
											strcpy(temp->lname,op);
										}
										temp=temp->next;
									}
									return;
								}
								else if(value=strcmp(mark2,">")==0)
								{
									stringstream updatename(op1);
									int uname=0;
									updatename>>uname;
									
									PNODE temp=Head;
									while(temp!=NULL)
									{
										if(temp->roll>uname)
										{
											strcpy(temp->fname,att);
											strcpy(temp->lname,op);
										}
										temp=temp->next;
									}
									return;
								}
								else if(value=strcmp(mark2,"<")==0)
								{
									stringstream updatename(op1);
									int uname=0;
									updatename>>uname;
									
									PNODE temp=Head;
									while(temp!=NULL)
									{
										if(temp->roll<uname)
										{
											strcpy(temp->fname,att);
											strcpy(temp->lname,op);
										}
										temp=temp->next;
									}
									return;
								}
								else
								{
									cout<<"\n --> "<<"Error at : "<<mark2<<"\n\n";
									return;
								}
							}
							else if(value=strcmp(mark1,"mark")==0)
							{
								if(value=strcmp(mark2,"=")==0)
								{
									stringstream updatename(op1);
									int uname=0;
									updatename>>uname;
									
									PNODE temp=Head;
									while(temp!=NULL)
									{
										if(temp->mark==uname)
										{
											strcpy(temp->fname,att);
											strcpy(temp->lname,op);
										}
										temp=temp->next;
									}
									return;
								}
								else if(value=strcmp(mark2,"<")==0)
								{
									stringstream updatename(op1);
									int uname=0;
									updatename>>uname;
									
									PNODE temp=Head;
									while(temp!=NULL)
									{
										if(temp->mark<uname)
										{
											strcpy(temp->fname,att);
											strcpy(temp->lname,op);
										}
										temp=temp->next;
									}
									return;
								}
								else if(value=strcmp(mark2,">")==0)
								{
									stringstream updatename(op1);
									int uname=0;
									updatename>>uname;
									
									PNODE temp=Head;
									while(temp!=NULL)
									{
										if(temp->mark>uname)
										{
											strcpy(temp->fname,att);
											strcpy(temp->lname,op);
										}
										temp=temp->next;
									}
									return;
								}
								else
								{
									cout<<"\n --> "<<"Error at : "<<mark2<<"\n\n";
									return;
								}
							}
							else
							{
								cout<<"\n --> "<<"Error at : "<<mark1<<"\n\n";
								return;
							}
						}
						else
						{
							cout<<"\n --> "<<"Error at : "<<mark<<"\n\n";
							return;
						}
					}
					else
					{
						cout<<"\n --> "<<"Error at : "<<where<<"\n\n";
						return;
					}
				}
				else
				{
					cout<<"\n --> "<<"Error at : "<<stud<<"\n\n";
					return;
				}
			}
			else
			{
				cout<<"\n --> "<<"Error at : "<<from<<"\n\n";
				return;
			}
		}
		else
		{
			cout<<"\n --> "<<"Error at : "<<ch<<"\n\n";
			return;
		}
	}
	else
	{
		cout<<"\n --> "<<"Error at : "<<sel<<"\n\n";
		return;
	}
	}
};

int main()
{
	int iValue=0,iChoice=1,iRet=0,iPos=0;
	char fname[30];
	char lname[30];
	char que[100];
	unsigned int mark=0;
	Student obj;
	
	while(iChoice!=0)
	{
		cout<<"1: Insert the info of student\n";
		cout<<"2: Insert the info of student at pos\n";
		cout<<"3: Delete info of perticular student\n";
		cout<<"4: Update name of the student\n";
		cout<<"5: Update marks of the student\n";
		cout<<"6: Display info all student\n";
		cout<<"7: Count the number of student\n";
		cout<<"8: Query:\n";
		cout<<"0: Exit the application\n";
		
		cout<<"Enter your choice:\n";
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1:
			//roll++;
			cout<<"Enter first name:\n";
			cin>>fname;
			cout<<"Enter last name:\n";
			cin>>lname;
			cout<<"Enter the mark:\n";
			cin>>mark;
			obj.InsertLast(fname,lname,mark);
			break;
			
			case 2:
			//roll++;
			cout<<"Enter first name:\n";
			cin>>fname;
			cout<<"Enter last name:\n";
			cin>>lname;
			cout<<"Enter the mark:\n";
			cin>>mark;
			cout<<"Enter position:\n";
			cin>>iPos;
			obj.InsertAtPos(fname,lname,mark,iPos);
			break;
			
			case 3:
			//roll--;
			cout<<"Enter roll number of student:\n";
			cin>>iPos;
			obj.DeleteAtPos(iPos);
				break;
				
			case 4:
			cout<<"Enter roll number:\n";
			cin>>iPos;
			cout<<"Enter first name :\n";
			cin>>fname;
			cout<<"Enter last name:\n";
			cin>>lname;
			obj.UpdateName(iPos,fname,lname);
				break;
				
			case 5:
			cout<<"Enter roll number:\n";
			cin>>iPos;
			cout<<"Enter new mark number:\n";
			cin>>mark;
			obj.UpdateMark(iPos,mark);
				break;
				
			case 6:
			obj.Display();
			break;
			
			case 7:
			iRet=obj.Count();
			cout<<"Number of student are: "<<iRet<<"\n\n";
			break;
			
			case 8:
			printf("enter query:\n");
			scanf(" %[^'\n']s",que);
			obj.Query(que);
			break;
			
			case 0:
			cout<<"**Thank you for using application**\n";
			break;
			
			default:
			cout<<"** Please enter proper option";
			break;
		}
	}
	return 0;
}