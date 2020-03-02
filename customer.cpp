#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct user_details
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
};
char tmp_username[15];
  char tmp_password[20];
  
void get_user_details(struct user_details *user)
{
	cout<<"\tRegistration Form"<<endl;
/*	cout<<"Name :"; cin.getline(user->name,20,'\n');
	cout<<"Email :"; cin>>user->email_id;
	cin.getline(user->dummy,3,'\n');
	cout<<"Mobile :";  cin>>user->mobile_no;
	cout<<"Door No :"; cin>>user->doorno;
	cin.getline(user->dummy,1,'\n');
	cout<<"Street :"; cin.getline(user->street_name,30,'\n');
	cout<<"Area :";  cin.getline(user->area,20,'\n');;
	cout<<"Pincode :"; cin>>user->pin_code;
	cout<<"\n\n\tSet Username and Password";
*/	cout<<"\nUSERNAME : "; cin>>user->username; 
	cout<<"PASSWORD : "; cin>>user->password;
	
	ofstream file ("user.bin", ios::app | ios::binary);
    file.write((char *)&user,sizeof(user));
    file.close();
}

void login_form(struct user_details user)
{
  int success;
  
  success = 0;
  system("CLS");
  cout<<"USERNAME : "; cin>>tmp_username; 
  cout<<"PASSWORD : "; cin>>tmp_password;
  ifstream f;
  f.open("user.bin",ios::in|ios::binary);
  f.seekg(0);
  while(f.read((char*)&user,sizeof(user)))
  {
  	if(strcmp(tmp_username,user.username)==0 && strcmp(tmp_password,user.password)==0)
  	{
  		cout<<"Succesfully Logged in"<<endl;
  		success++;
  		break;
    }
  }
  if(success < 1)
	   cout<<"Invalid User"<<endl;
  f.close();
}

void display_user_details(struct user_details *user)
{
	ifstream f;
    f.open("user.bin",ios::in|ios::binary);
    f.seekg(0);
    while(f.read((char*)&user,sizeof(user)))
    {
  	if(strcmp(tmp_username,user->username)==0 && strcmp(tmp_password,user->password)==0)
  	{
	cout<<"\nName :"<<user->name<<endl;
	cout<<"Email :"<<user->email_id<<endl;
	cout<<"Mobile :"<<user->mobile_no<<endl;
	cout<<"Door No :"<<user->doorno<<endl;
	cout<<"Street :"<<user->street_name<<endl;
	cout<<"Area :"<<user->area<<endl;
	cout<<"Pincode :"<<user->pin_code<<endl;
    }
}
}
int main()
{
	struct user_details user;
	get_user_details(&user);
	login_form(user);
	display_user_details(&user);

}


