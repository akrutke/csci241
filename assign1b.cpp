/****************************************************
PROGRAM: 	Numerolgoy
AUTHOR: 	Andrew Krutke
LOGON ID:	z1756942
Due:		1/29/2015

Function:	Take the numerical value of a persons
			name and display a trait assicoated with
			said value using c++ style strings.

INPUT: String

OUTPUT: String

*****************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
using namespace std;

/***************************************************
Function Prototypes
****************************************************/

int		CharToNum(char*); //convert a cstring to a number
int		Find_Trait(int);  //loop through to the number value of a person's name
void	OutPut_Trait(int); //switch statement to to diplay the trait

/***************************************************
Main Function
****************************************************/

int main ()
{

	cout << "Numerology Program" << endl;
	char y='y';
	while (y == 'Y' || y== 'y' )
	{	char name[80];  //cstring declaration to store user name
		int Name_Num=0; //intialized to zero so that Name_Numfunction can caculate the total
		
		cout <<endl << "What's your name" << endl;
		cin.getline (name,80); //get line function to read a string without breaks
		
		int sum=CharToNum(name);
		Name_Num=Find_Trait(sum);
	
 
	while((Name_Num >12 || Name_Num < 0) and (Name_Num!=22 ))
	{
			Name_Num=Find_Trait (Name_Num);
	}
	
 			OutPut_Trait (Name_Num);
	do				//do while loop to resume or end
        {
            cout << "\n" << "Another? (y/n) ";
            cin >> y;
        }
	while((y !='Y')&&(y !='N')&&(y !='y')&&(y !='n'));
       
        cin.ignore(100, '\n');
    }
	  	   	      	    	    
return 0;	 

}

/****************************************************
CharToNum Function: this function takes in the name, 
converts to lower case letters and then to a numerical 
value. It will return that value as int.
*****************************************************/

int CharToNum(char* name) //char points to name 
{

	char lCase_name[80]={0}; //string intialization for names convertered to lower case
	int i=0;
	char x, y;
	while (name[i])		//array sorting
		{
		x=name[i];
		y=tolower(x);
		lCase_name[i]=y;
		i++;
		}
	
	int j=0;
	char alpha_num;
	int total=0;
	while (lCase_name[j])
	{
		alpha_num=lCase_name[j]; //isalpha to check if data is alphabetical
		if (isalpha(lCase_name[j]))
		{
			int number= 1 * alpha_num;
			number -= 96; //subtract 96 from ascii value
			total= total + number;
		}
		
		else if(isalnum(lCase_name[j])) //check to see if value is alpha numerical
		{
			int number=1 * alpha_num;
			number -= 48; //subtract 48 from value
			total=total + number;
		}	 
		else 
		{
		int number= 1 * alpha_num;
		number = 0; //set all other charcters to 0
		total = total + number;
		}
		
	j++;
	}
	
	for (int i=0; i<22; i++) 
		{ 
		lCase_name[i]=0; 
		}
		
		return total;
		
		
}
/******************************************************
Find_Trait Function: This fucntion will take the number
value from CharToNum Function and adds the value 
together to find the trait of someone's name.
*******************************************************/


int Find_Trait(int sum)
{
	char trait[80];
	int trait_total=0;
	sprintf(trait, "%d",sum); //convert the chars in the string to a number
	int i=0;
	int j=0;
	
	while (trait[i])
	{
		j=trait[i]-48; 
		trait_total+=j;
		i++;
	
	}
return trait_total;
}

/*********************************************************
OutPut_Trait Function: This function is going to 
take the digit value of a name and return a trait 
based on the number found so long as the number is 
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 22. 
**********************************************************/


void OutPut_Trait (int Name_Num) //switch statement to display the traits
{
     cout<< "That name has the traits ";
     switch (Name_Num)
     {  case 0:
            cout << "emptiness, nothingness, blank" << endl;
            break;
        case 1:
            cout << "independence, loneliness, creativity, originality, dominance, leadership, impatience" << endl;
            break;
        case 2:
            cout << "quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive, compromising, patient" << endl;
            break;
        case 3:
            cout << "charming, outgoing, self expressive, extroverted, abundance, active, energetic, proud" << endl;
            break;
        case 4:
            cout << "harmony, truth, justice, order discipline, practicality" << endl;
            break;
        case 5:
            cout << "new directions, excitement, change, adventure" << endl;
            break;
        case 6:
            cout << "love, harmony, perfection, marriage, tolerance, public service" << endl;
            break;
        case 7:
            cout << "spirituality, completeness, isolation, introspection" << endl;
            break;
        case 8:
            cout << "organization, business, commerce, new beginnings" << endl;
            break;
        case 9:
            cout << "romantic, rebellious, determined, passionate, compassionate" << endl;
            break;
        case 11:
            cout << "idealism, visionary, inspirational" << endl;
            break;
        case 12:
            cout << "perfectionist, discriminating" << endl;
            break;
        case 22:
            cout << "builder, leader, humanitarian, practical, honest" << endl;
            break;
     }
}	   
	
