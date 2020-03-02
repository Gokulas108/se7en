#include <windows.h>
#include <iostream>
#include<string.h>
using namespace std;

int eee(char str2[100]){
	
//	char str2[100];
//	cout<<"Email id : ";
 //   cin>>str2;
    char str1[200] = "curl smtp://smtp.gmail.com:587 -v --mail-from \"ghirihari@gmail.com\" --mail-rcpt \"";
	strcat(str1,str2);

	char str3[] = "\" --ssl -u ghirihari@gmail.com:06071967 -T \"ATTACHMENT.txt\" -k --anyauth";
	strcat(str1,str3);
	//cout<<str1;
	
//	char* command = "curl smtp://smtp.gmail.com:587 -v --mail-from \"ghirihari@gmail.com\" --mail-rcpt \"ghirihari7@gmail.com\" --ssl -u ghirihari@gmail.com:06071967 -T \"ATTACHMENT.txt\" -k --anyauth";
 //   char* command = "curl smtp://smtp.gmail.com:587 -v --mail-from \"ghirihari@gmail.com\" --mail-rcpt \"aaa\" --ssl -u ghirihari@gmail.com:06071967 -T \"ATTACHMENT.txt\" -k --anyauth";
//	int i = strcmp(str1,command);
//	cout<<i;
	WinExec(str1, SW_SHOW);
    return 0;
}


