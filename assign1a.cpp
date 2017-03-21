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
#include <string>
#include <cctype>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

/***************************************************
Function Prototypes
****************************************************/

int		CharToNum(string);  //convert a string to a number
int		Find_Trait(int);    //loop through to find the trait of a person's name
void		OutPut_Trait(int);  //use a switch statement to display the trait of a person based on their name

/***************************************************
Main Function
****************************************************/

int main ()
{

	cout << "Numerology Program" << endl;
	char y='y';
	while (y == 'Y' || y== 'y' )
	{	string name; //c++ string intialization
		int Name_Num=0; //set to zero to avoid garbage value

		cout <<endl << "What's your name" << endl;
		getline (cin, name);  //read white space between a first and lasy name

	int sum= CharToNum(name); 
	Name_Num=Find_Trait(sum);
	
 
	while((Name_Num >12 || Name_Num < 0) and (Name_Num!=22 )) //while the  string is not between 0 and 12, and not equalt to 22 run Name_Num function 
	{
			Name_Num=Find_Trait (Name_Num); 
	}
			OutPut_Trait (Name_Num);
	do   //do while loop to end program
        {
            cout << "\n" << "Another? (y/n) ";
            cin >> y;
        }
	while((y !='Y')&&(y !='N')&&(y !='y')&&(y !='n'));
        cin.ignore(80, '\n'); //if 'n' ignore up to 80 char values
    }

return 0;

}

/****************************************************
CharToNum Function: this function takes in the name
converts to lower case letters and then to a numerical 
value. It will return that value as int.
*****************************************************/

int CharToNum(string name)	//use c++ string to convert a string into its ascii value and reduce it
{

	string lCase_name;
	int i=0;
	char x, y;
	while (name[i])		//sort the array
		{
		x=name[i];
		y=tolower(x);
		lCase_name[i]=y;
		i++;
		}

	int j=0;
	char alpha_num;		//alphabet/number representation
	int total=0;
	while (lCase_name[j])
	{
		alpha_num=lCase_name[j];
		if (isalpha(lCase_name[j])) 	//isaplha to check if data is alphabetical, if so subtract 96 from ascii valut
		{
			int number= 1 * alpha_num;
			number -= 96;
			total= total + number;
		}

		else if(isalnum(lCase_name[j]))		//isalnum to check if number is alphanumerical, if so subtact 48 from ascii value
		{
			int number=1 * alpha_num;
			number -= 48;
			total=total + number;
		}
		else
		{
		int number= 1 * alpha_num;
		number = 0; //set characters to 0 such as -
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
	string trait;		//c++ string 
	int trait_total=0;	//intialize trait_total to 0 so garbage isn't stored
	ostringstream convert;	//convert the string into an integer
	convert << sum;
	trait = convert.str();
	int i=0;
	int j=0;

	while (trait[i])
	{
		j=trait[i]-48; //if the converted string doesnt equal one of the switch statment value, break it down further.
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


void OutPut_Trait (int Name_Num)
{
     cout<< "That name has the traits ";  //Switch statment to display the traits of the person's name, return no value
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
