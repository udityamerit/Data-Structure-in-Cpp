#include<iostream>
#include<cstring> // in this header file we are using some inbuild functions for string
using namespace std;

int main(){

        char str1[90];
        cout<<"Enter the string: ";
        cin>>str1;

        //strlen() for finding the length
        int len = strlen(str1);
        cout<<"length the string is: "<<len<<endl;

        // strcmp() for comparing the two strings are equal or not in the form of (0--> strings are equal and 1--> strings are not equal)

        cout<<"Enter the string 2: ";
        char str2[90];
        cin>>str2;
        if(strcmp(str1, str2)==0){
                cout<<"same"<<endl;
        }
        else{
                cout<<"not same";
        }

        // String copy function  strcpy()
        char st1[90] = "abcd";
        char st2[90] = "edf";
        cout<<"Before copy"<<endl;
        cout<<"Str1:"<<st1<<endl;
        cout<<"Str2:"<<st2<<endl;

        strcpy(st2, st1); // it is replace the content of str2 with str1 and it is copy the null characters also:

        cout<<"After copy"<<endl;
        cout<<"Str1:"<<st1<<endl;
        cout<<"Str2:"<<st2<<endl;

        // strncopy(str1, str2, n) here n is tells that how many characters are coping you are
        char st11[90] = "abDFcd";
        char st21[90] = "edf";
        strncpy(st21, st11,4);
        cout<<"After copy N CHARES"<<endl;
        cout<<"Str1:"<<st11<<endl;
        cout<<"Str2:"<<st21<<endl;

        // strcat(str1, str2)  it is concatenate the string

        strcat(st21, st11);
        cout<<"Calctainating the strings: ";
        cout<<"Str1:"<<st11<<endl;
        cout<<"Str2:"<<st21<<endl;
        return 0;
}