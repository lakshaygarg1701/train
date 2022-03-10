#include<fstream.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<dos.h>

/*===============================================
  CLASS CONTAINS ADMINISTRATOR FUNCTIONS OF TRAIN
  ===============================================*/

class train
{
 private:
   char delmark;
   int trainno;
   char trainnm[20];
   char from[10];
   int dep;
   char to[10];
   int arr;
   int tt;
 public:
   char* retnm(){return trainnm;}
   char retdelmark();
   int retno(){return trainno;}
   int retdep(){return dep;}
   int retto(){return arr;}
   void del();
   void input();
   void disp();
};

int traveltime(int dep,int arr)
{int d=arr-dep;
 if(arr<dep)
 return d+2400;
 else
 return d;
}
/*===================================
 INPUT FUNCTION OF TRAINDETAIL
 ====================================*/

 void train::input()
   { delmark=' ';
     cout<<"\n Train No.            : ";
     cin>>trainno;
     cout<<"\n Train name           : ";
     gets(trainnm);
     cout<<"\n From	            : ";
     gets(from);
     cout<<"\n Departure (24 hr)    : ";
     cin>>dep;
     cout<<"\n To        	    : ";
     gets(to);
      cout<<"\n Arrival Time (24 hr) : ";
     cin>>arr;
     cout<<"\n Total Travel Time    : ";
     tt=traveltime(dep,arr);
     cout<<tt;
   }
/*===================================
 DISPLAY FUNCTION OF TRAINDETAIL
 ====================================*/

 void train::disp()
  {if(delmark!='*')
   {
    cout<<"Train No: "<<trainno;
    cout<<"\nTrain name: "<<trainnm;
    cout<<"\nFrom: "<<from;
    cout<<"\nDeparture: "<<dep;
    cout<<"\nTo: "<<to;
    cout<<"\nArrival: "<<arr;
    cout<<"\nTravel Time:"<<tt<<endl<<endl;
   }
  }
 char train::retdelmark()
  {
   return delmark;
  }
 void train::del()
  {
   delmark='*';
  }

/*===================================
 WRITEDATA FUNCTION OF TRAINDETAIL
 ====================================*/

 void writedata(train ob)
{ofstream ofile("train.dat",ios::binary|ios::app|ios::out);
 if(!ofile)
 {
  cout<<"file not exist";
  return;
 }
 char ans;
 do
 {ob.input();
  ofile.write((char*)&ob,sizeof(ob));
  cout<<"\n\nDo you want to continue : ";
  cin>>ans;
  ans=toupper(ans);
 }while(ans!='N');
 ofile.close();
}

/*===================================
 READDATA FUNCTION OF TRAINDETAIL
 ====================================*/

void readdata(train ob)
{ifstream ifile("train.dat",ios::binary);
 if(!ifile)
 {cout<<"file dont exists";}
 while(ifile.read((char*)&ob,sizeof(ob)))
 {ob.disp();}
 getch();
 ifile.close();
}



/*===================================
 DELETE FUNCTION OF TRAINDETAIL
 ====================================*/

void del(train ob)
{
int recno=0;
int d;
char ans2;
fstream ifile("train.dat",ios::binary|ios::ate|ios::out|ios::in);
if(!ifile)
{
cout<<"file dont exists";
getch();
return;
}
cout<<"Enter train no : ";
cin>>d;
ifile.seekg(0,ios::beg);
while(ifile.read((char*)&ob,sizeof(ob)))
	{
	recno++;
	if(ob.retno()==d)
		{
		ob.disp();
		cout<<"\n\n\nconfirm deletion(y/n) : ";
		cin>>ans2;
		ans2=toupper(ans2);
		if(ans2=='Y')
			{
			ob.del();
			int x=-1*sizeof(ob);
			ifile.seekg(x,ios::cur);
			ifile.write((char*)&ob,sizeof(ob));

			}
		else
		 {
		  break;
		 }
		}

	}
getch();
ifile.close();
}

/*===================================
 MODIFY FUNCTION OF TRAINDETAIL
 ====================================*/

void modify(train ob)
{
int recno=0;
int d;
int f=0;
char ans1;
fstream ifile("train.dat",ios::binary|ios::ate|ios::out|ios::in);
if(!ifile)
{
cout<<"file dont exists";
getch();
return;
}
cout<<"Enter the train no to be modified:";
cin>>d;
ifile.seekg(0,ios::beg);
while(ifile.read((char*)&ob,sizeof(ob)))
	{
	recno++;
	if(ob.retno()==d)
		{
		ob.disp();
		cout<<"\n\nwant to modify(y/n) : ";
		cin>>ans1;
		ans1=toupper(ans1);
		if(ans1=='Y')
			{
			ob.input();
			cout<<"\n\nconfirm modification (y/n) : ";
			cin>>ans1;
			ans1=toupper(ans1);
			if(ans1=='Y')
				{
				int x=-1*sizeof(ob);
				ifile.seekg(x,ios::cur);
				ifile.write((char*)&ob,sizeof(ob));
				f=1;
				break;
				}
			}
		}

	}
   if(f==0)
   {cout<<"no modification take place";
   }
getch();
ifile.close();
}


/*===================================
 MENU FUNCTION OF TRAINDETAIL
 ====================================*/


void trainm()
{
 train ob;
 int ch;
 do
 {
  clrscr();
  cout<<"\t\t TRAIN DETAILS ";
  cout<<"\n1.Input the data";
  cout<<"\n2.Display the data";
  cout<<"\n3.Modify the data";
  cout<<"\n4.Delete unwanted data";
  cout<<"\n5.Exit";

  cout<<"\nENTER YOUR CHOICE = ";
  cin>>ch;
  clrscr();
  switch(ch)
  {
   case 1 : {
	     writedata(ob);
	     break;
	    }
   case 2 : {
	     clrscr();
	     readdata(ob);
	     break;
	    }
   case 3 : {
	     modify(ob);
	     break;
	    }

   case 4 : {
	      del(ob);
	      break;
	    }
   case 5 : {
	     break;
	    }
   default :{
	     cout<<"WRONG CHOICE";
	      getch();
	    }
  }
}while(ch!=5);
}


//================================Next Part===================================


/*=============================
  CLASS CONTAINING USER DETAILS
  =============================*/
struct dot
{int dd,mm,yyyy;};
int nop=0;
class user
{char delmark;
 int traino;
 double PNR;
 char usernm[60];
 char sex;
 int age;
 dot doj;
 char classf[3];
 int id;
public:
 char retdelmark();
 int retno(){return traino;}
 char* retusernm();
 double retPNR(){return PNR;}
 void del();
 void input(int ,int &);
 void output(int );
};

char* user::retusernm()
{return usernm;}

char user::retdelmark()
{return delmark;}

void user::del()
{delmark='*';}

void searchtrain(int &f,int &tn)
{int traino;
 cout<<"Enter Train no to be searched : ";
 cin>>traino;
 ifstream ifile;
 ifile.open("train.dat",ios::binary);
 if(!ifile)
 {cout<<"Error Reading File";
  getch();
  return ;
 }
 train ob1;
 while(ifile.read((char*)&ob1,sizeof(train)))
 {if(traino==ob1.retno())
  {f=1;
   ob1.disp();
   tn=traino;
   break;
  }
 }
 if(f==0)
 {cout<<"Train no. does not exist";}

 ifile.close();
}


/*==========================================
 INPUT FUNCTIONS OF JOURNEYDETAILS
==========================================*/



void user::input(int a,int &tn)
{delmark=' ';
 traino=tn;
 PNR=a;
 cout<<"\nName of passenger    		       : ";
 gets(usernm);
 cout<<"Age of passenger             	       : ";
 cin>>age;
 cout<<"Date of journey (dd/mm/yyyy)         : ";
 cin>>doj.dd>>doj.mm>>doj.yyyy;
 cout<<"Gender Of Passenger (M/F)            : ";
 cin>>sex;
 cout<<"Selection Of Class (1A/2A/3A/SL/CC)  : ";
 gets(classf);
 cout<<"Enter AADHAR No.                     : ";
 cin>>id;
}


/*===============================
  OUTPUT FUNCTIONS OF USERDETAILS
  ===============================*/

void user::output(int nop)
{int ch=0;
 if(delmark!='*')
 {do
  {cout<<"\nTrain no                 : "<<traino;
   cout<<"\nName of Passenger        : "<<usernm;
   cout<<"\nGender of Passenger      : "<<sex;
   cout<<"\nAge of Passenger         : "<<age;
   cout<<"\nDate of Journey          : "<<doj.dd<<'/'<<doj.mm<<'/'<<doj.yyyy;
   cout<<"\nClass                    : "<<classf<<endl<<endl;
  }while(ch!=nop);
 }
}


/*==========================================
 WRITEDATA FUNCTIONS OF USERDETAILS
==========================================*/

void genPNR(double &PNR)
{PNR=random(10000000)+10000000;}

void writedata(user ob1,int &nop)
{ofstream ofile("user.dat",ios::binary|ios::app);
 if(!ofile)
 {cout<<"file not exist";
  return;
 }
 char ans,ans2;
 double a;
 int f,tn;
 searchtrain(f,tn);
 cout<<"Do you want to book ticket in this train?(Y/N)";
 cin>>ans2;
 ans2=toupper(ans2);
 if(f!=0 && ans2=='Y')
 {genPNR(a);
  do
  {ob1.input(a,tn);
   ofile.write((char*)&ob1,sizeof(user));
   cout<<"\n\nDo you want to add another passenger on the same train: ";
   cin>>ans;
   ans=toupper(ans);
   if(ans=='y')
   {nop++;}
  }while(ans!='N');
  cout<<"PNR for this ticket is: "<<ob1.retPNR()<<endl;
 }
 ofile.close();
 getch();
}


/*==========================================
 READDATA FUNCTIONS OF USERDETAILS
==========================================*/


void readdata(user ob1)
{ifstream ifile("user.dat",ios::binary);
 if(!ifile)
 {cout<<"file dont exists";
  getch();
  return;
 }
 double se;
 cout<<"Enter PNR to be searched   : ";
 cin>>se;
 while(ifile.read((char*)&ob1,sizeof(user)))
 {if(se==ob1.retPNR())
  {ob1.output(nop);}
  else
  {cout<<"No Records Found";
   break;
  }
 }
 getch();
 ifile.close();
}



/*==========================================
 DELETE FUNCTIONS OF USERDETAILS
==========================================*/



void deletep(user ob1)
{double d;
 char ans2;
 int recno=0;
 fstream fl("user.dat",ios::binary|ios::ate|ios::out|ios::in);
 if(!fl)
 {cout<<"file dont exists";
  getch();
  return;
 }
 cout<<"ENTER PNR NO. : ";
 cin>>d;
 fl.seekg(0,ios::beg);
 while(fl.read((char*)&ob1,sizeof(ob1)))
 {if(ob1.retPNR()==d)
  {recno++;
   ob1.output(nop);
   cout<<"\n\n\nconfirm deletion(y/n) : ";
   cin>>ans2;
   ans2=toupper(ans2);
   if(ans2=='Y')
   {int x=recno*sizeof(ob1);
    fl.seekg(x,ios::beg);
    ob1.del();
   }
  }
  else
  {cout<<"No Record Found";
   break;
  }
 }
 getch();
 fl.close();
}

/*==========================================
 MENU OF USERDETAILS
==========================================*/


void journey()
{
 user ob1;
 int ch;
 do
 {
  clrscr();
  cout<<"\t\t USER DETAILS ";
  cout<<"\n1.Input the data";
  cout<<"\n2.Display the data";
  cout<<"\n3.Delete unwanted data";
  cout<<"\n4.Exit";
  cout<<"\nENTER YOUR CHOICE = ";
  cin>>ch;
  clrscr();
  switch(ch)
  {
   case 1 : {writedata(ob1,nop);
	     break;
	    }
   case 2 : {clrscr();
	     readdata(ob1);
	     break;
	    }
   case 3 : {deletep(ob1);
	     break;
	    }
   case 4 : {
	     break;
	    }
   default :{
	     cout<<"WRONG CHOICE";
	      getch();
	    }
  }
}while(ch!=4);
}

/*===============================Next Part====================================*/

void main()
{clrscr();
 int ch,pw,f;
 char nm[20];
 do
 {clrscr();
  cout<<"1. Administrator Train\n";
  cout<<"2. User Menu\n";
  cout<<"3. Exit\n";
  cout<<"EYC: ";
  cin>>ch;
  switch(ch)
  {case 1:{do
	   {cout<<"Enter Administrator Name: ";
	    gets(nm);
	    cout<<"Enter Your Password: ";
	    cin>>pw;
	    if(strcmpi(nm,"Mridul")==0 && pw==12345)
	    {cout<<"Login Successful";
	     trainm();
	     f=1;
	    }
	    else
	    {cout<<"Username/Password is incorrect";}
	   }while(f!=1);
	   break;
	  }
   case 2:{journey();
	   break;
	  }
   case 3:{break;}
   default:{cout<<"Wrong Choice";
	    getch();}
  }
 }while(ch!=3);
}