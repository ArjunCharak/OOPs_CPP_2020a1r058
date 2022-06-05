//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<iostream>      //This header file contains definitions of objects like cin, cout
#include<fstream>       //Stream class to both read and write from/to files.
#include<cctype>        //This header file declares a set of functions to classify (and transform) individual characters.
#include<iomanip>       //This header file defines the manipulator functions i.e setw() in our case
using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************


class account
{
public:
	int account_number, contact, age;
	char name[50],address[100];
	int deposit;
	char type;
	void create_account();	//function to get data from user
	void show_account() const;	//function to show data on screen
	void modify();	//function to add new data
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report() const;	//function to show data in tabular format
	int retaccount_number() const;	//function to return account number
	int retdeposit() const;	//function to return balance amount
	char rettype() const;	//function to return type of account
};         //class ends here
//defining the create_account function outside the class declaration
void account::create_account()
{
	cout<<"\nEnter 9 digit Account No. :";
	cin>>account_number;
	cout<<"\n\nEnter The Name of The Account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\nEnter The Age of The Account Holder : ";
	cin>>age;
	cout<<"\n\nEnter The Address of Account Holder : ";
	cin.ignore();
	cin.getline(address,50);
	cout<<"\n\nEnter The Contact Number of The Account Holder : ";
	cin>>contact;
	cout<<"\n\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\nEnter The Initial amount(>=1000 for Saving/Current Acoount) : ";
	cin>>deposit;
}
//defining the show_account function outside the class declaration
void account::show_account() const
{
	cout<<"\nAccount No. : "<<account_number;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nAddress : "<<address;
	cout<<"\nContact : "<<contact;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}
//defining the modify function outside the class declaration
void account::modify()
{
	cout<<"\nAccount No. : "<<account_number;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Address : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Contact : ";
	cin>>type;
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}
//defining the dep function outside the class declaration
void account::dep(int x)
{
	deposit+=x;
}
//defining the draw function outside the class declaration
void account::draw(int x)
{
	deposit-=x;
}
//defining the report function outside the class declaration
void account::report() const
{
	cout<<account_number<<setw(23)<<" "<<name<<setw(21)<<" "<<type<<setw(36)<<deposit<<endl;
}
//defining the retaccount_number function outside the class declaration
int account::retaccount_number() const
{
	return account_number;
}
//defining the retdeposit function outside the class declaration
int account::retdeposit() const
{
	return deposit;
}
//defining the rettype function outside the class declaration
char account::rettype() const
{
	return type;
}


//***************************************************************
//    	function declaration
//****************************************************************
char write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to deposit/withdraw amount for given account
void intro();	//introductory screen function

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
	char ch;
	int num;
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\t\tWELCOME TO THE BANK OF ASGARD\n";
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. OPEN NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
			cout<<"\n\n\tThanks for visiting Bank of Asgard";
			cout<<"\n\n\tPress enter to exit\n";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
	return 0;
}


//***************************************************************
/*    	function to write in file,
        considering the exception handling for the new user to enter age above 18 years & minimum initial deposit by 1000,
        else exception will be generated and account will not be created.
*/
//****************************************************************

char write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);       //writing into the file account.dat using file handling
	ac.create_account();
	try {
    if(ac.age >=18 && ac.deposit >= 1000){
        cout<<"\n\nAccount opened successfully\n\n";
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
    outFile.close();
    } else {
        throw (ac.deposit);
        }
    }
    catch (int myDep) {
        if(myDep<1000){
        cout << "\n\nYour minimum deposit is "<<myDep<<" which is less than minimum deposit limit of 1000\n\n";
        cout << "Account cannot be opened\n";
        }
    else {
        cout << "\n\nYou are not eligible to open an account as you are under 18\n";
        }
    }
        return 0;
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retaccount_number()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}


//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retaccount_number()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retaccount_number()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\t\tACCOUNT HOLDERS LIST\n\n";
	cout<<"================================================================================================\n";
	cout<<"A/c no.\t\t\t\tNAME\t\t\t\tTYPE\t\t\t\tBALANCE\n";
	cout<<"================================================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retaccount_number()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited\n";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw\n";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************


void intro()
{
	cout<<"\n\n\n\t\t\t\t\t\t     ~~~~ MINI PROJECT ~~~~";
	cout<<"\n\n\n\t\t\t\t\t\tBANK \t MANAGEMENT \t SYSTEM";
	cout<<"\n\n\n\nMADE BY : ARJUN CHARAK";
	cout<<"\n\nROLL NO. : 2020A1R058";
	cout<<"\n\nSEMESTER : 4TH";
	cout<<"\n\nBRANCE : CSE";
	cout<<"\n\nCOLLEGE : MODEL INSTITUTE OF ENGINEERING AND TECHNOLOGY JAMMU";
	cout<<"\n\nCONTRIBUTION : STUTI BERDA (2020A1R044), ARUNIMA MAGOTRA (2020A1T049)";
	cout<<"\n\n\nPLEASE ENTER TO CONTINUE";
	cin.get();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
