#include<iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct login_details
{
	char name[30];
	char email_id[30];
	char mobile_no[11];
	char doorno[5];
	char street_name[30],dummy[2];
	char area[20];
	unsigned int pin_code;
	char username[15];
	char password[20];
}us;

char tmp_username[15];
char tmp_password[20];

void registration_form()
{
	cout<<"\tRegistration Form"<<endl;
	cout<<"Name :"; cin.getline(us.name,20,'\n');
	cout<<"Email :"; cin>>us.email_id;
	cin.getline(us.dummy,3,'\n');
	cout<<"Mobile :";  cin>>us.mobile_no;
	cout<<"Door No :"; cin>>us.doorno;
	cin.getline(us.dummy,1,'\n');
	cout<<"Street :"; cin.getline(us.street_name,30,'\n');
	cout<<"Area :";  cin.getline(us.area,20,'\n');
	cout<<"Pincode :"; cin>>us.pin_code;
	cout<<"\n\n\tSet Username and Password";
	cout<<"\nUSERNAME : "; cin>>us.username; 
	cout<<"PASSWORD : "; cin>>us.password;
	ofstream file ("user7.bin", ios::app | ios::binary);
    file.write((char *)&us,sizeof(us));
    file.close();
}


void login_form()
{
	int success;
	success = 0;
  cout<<"\nUSERNAME : "; cin>>tmp_username; 
  cout<<"PASSWORD : "; cin>>tmp_password;
  ifstream f;
  f.open("user7.bin",ios::in|ios::binary);
  f.seekg(0);
  while(f.read((char*)&us,sizeof(us)))
  {
  	if(strcmp(tmp_username,us.username)==0 && strcmp(tmp_password,us.password)==0)
  	{
  		cout<<"Succesfully Logged in as "<<us.name<<endl;
  		success++;
  		break;
    }
  }
  if(success < 1)
	   cout<<"Invalid User"<<endl;
  f.close();
}

int main()
{
//registration_form();
login_form();
}
