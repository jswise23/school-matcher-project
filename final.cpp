//////////////////////////////////////////////////////////////////////////////////////////////
//FILE NAME:        final.cpp
//TITLE:            Final
//PROGRAMMER:       Jacob Wise
//COURSE:           CS 2010, 5:30 - 7:00 pm
//DUE:              May 5, 2014
//
//
//PURPOSE:          Match user with a public university in Ohio.
//
//
//METHOD:           1. Welcome User
//                  2. Fill arrays of colleges with pre-set info
//                  3. Display questionnaire to user and record answers in array
//                  4. Compare user's answers array with college info arrays
//                     a. Calculate percent similar for each college and store in array
//                  5. Sort percents similar from largest to smallest
//                  6. Display colleges back to user in order of best match to worst match
//                  7. Ask user if info about top match is wanted
//                     a. Display college if "yes"
//                  8. Thank user
//
//
//FUNCTIONS:        welcome()
//                  fillCollegeArrays()
//                  inputQuiz()
//                  compareColleges()
//                  sortColleges()
//                  displayMatch()
//                  displayInfo()
//                  thanks()
//
//
//INCLUDED FILES:   iostream
//                  fstream
//
//DATA FILES:       collegeInfo.txt
//
//All code is mine unless otherwise indicated.
//////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;
//////////////
//Prototypes//
//////////////

int welcome(); //welcome message
int fillCollegeArys(int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int[], int); //fills arrays from a data file
void inputQuiz(int []); //stores user answers in array 
double compareColleges(int [], int [], int); //compare college arrays with user input
void sortColleges(double [], string [], int);
void displayMatch(string [], double [], int); //display each college with % match
void displayInfo(int []); //display college info if requested
void thanks(); //thank user



/////////////////
//Main Function//
/////////////////

int main()
{
	//CONSTANTS//
	const int INFO_MAX = 10;
	const int MAX_COLLEGES = 13;
	
	
	//VARIABLES//
	int confirm = 0;
	int test = 0;
	string display;
	
	
	//ARRAYS//
	int userData[INFO_MAX];
	int akron[INFO_MAX];
	int central[INFO_MAX];
	int cleveland[INFO_MAX];
	int miami[INFO_MAX];
	int ohioUni[INFO_MAX];
	int toledo[INFO_MAX];
	int youngstown[INFO_MAX];
	int bgsu[INFO_MAX];
	int cincinnati[INFO_MAX];
	int kent[INFO_MAX];
	int osu[INFO_MAX];
	int wright[INFO_MAX];
	int shawnee[INFO_MAX];
	double percents[MAX_COLLEGES];
	string collegeNames[MAX_COLLEGES] = {"Akron", "Central State", "Cleveland State", "Miami University", "Ohio University", "University of Toledo", "Youngstown State", "Bowling Green State University", "University of Cincinnati", "Kent State", "Ohio State", "Wright State", "Shawnee State"};
	
	
	//WELCOME USER//
	confirm = welcome();
	
	if(confirm == 0)            //Allow user to back out
	{
		cout << "*********************************" << endl;
		cout << "            THANK YOU!"<< endl;
		cout << "*********************************" << endl;
		
		return 0;
	}
	
	
	//FILL ARRAYS//
	test = fillCollegeArys(akron, central, cleveland, miami, ohioUni, toledo, youngstown, bgsu, cincinnati, kent, osu, wright, shawnee, INFO_MAX);
	
	if(test != 0)             //if files open unsuccessfully, end.
	{
		cerr << "Error! Please try again!" << endl;
		return 0;
	}
	
	
	//USER INPUT - QUESTIONNAIRE//
	cout << endl;
	inputQuiz(userData);
	
	
	//COMPARE USER WITH COLLEGES//
	percents[0] = compareColleges(userData, akron, INFO_MAX);
	percents[1] = compareColleges(userData, central, INFO_MAX);
	percents[2] = compareColleges(userData, cleveland, INFO_MAX);
	percents[3] = compareColleges(userData, miami, INFO_MAX);
	percents[4] = compareColleges(userData, ohioUni, INFO_MAX);
	percents[5] = compareColleges(userData, toledo, INFO_MAX);
	percents[6] = compareColleges(userData, youngstown, INFO_MAX);
	percents[7] = compareColleges(userData, bgsu, INFO_MAX);
	percents[8] = compareColleges(userData, cincinnati, INFO_MAX);
	percents[9] = compareColleges(userData, kent, INFO_MAX);
	percents[10] = compareColleges(userData, osu, INFO_MAX);
	percents[11] = compareColleges(userData, wright, INFO_MAX);
	percents[12] = compareColleges(userData, shawnee, INFO_MAX);
	
	
	//SORT COLLEGES BY PERCENTS//
	sortColleges(percents, collegeNames, MAX_COLLEGES);
	
	
	//DISPLAY MATCHES BY PERCENTS//
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	displayMatch(collegeNames, percents, MAX_COLLEGES);
	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Would you like to see specific info about your top match?" << endl;   
	cout << "('y' for yes, 'n' for no):  ";     //Display 1st match info if desired
	cin >> display;
	cout << endl;
	
	if(display == "y")            //Need to check identity of top match, then run displayInfo
	{
		if(collegeNames[0] == "Akron")
			{
				displayInfo(akron);
			}
		else if(collegeNames[0] == "Central State")
			{
				displayInfo(central);
			}
		else if(collegeNames[0] == "Cleveland State")
			{
				displayInfo(cleveland);
			}
		else if(collegeNames[0] == "Miami University")
			{
				displayInfo(miami);
			}
		else if(collegeNames[0] == "Ohio University")
			{
				displayInfo(ohioUni);
			}
		else if(collegeNames[0] == "University of Toledo")
			{
				displayInfo(toledo);
			}
		else if(collegeNames[0] == "Youngstown State")
			{
				displayInfo(youngstown);
			}
		else if(collegeNames[0] == "Bowling Green State University")
			{
				displayInfo(bgsu);
			}
		else if(collegeNames[0] == "University of Cincinnati")
			{
				displayInfo(cincinnati);
			}
		else if(collegeNames[0] == "Kent State")
			{
				displayInfo(kent);
			}
		else if(collegeNames[0] == "Ohio State")
			{
				displayInfo(osu);
			}
		else if(collegeNames[0] == "Wright State")
			{
				displayInfo(wright);
			}
		else if(collegeNames[0] == "Shawnee State")
			{
				displayInfo(shawnee);
			}
		else
			{
				cout << "There was an error. The info cannot be displayed." << endl;
			}
	}

	
	//Thank user//
	thanks();
	
	cout << endl;
	
	return 0;
}



/////////////
//FUNCTIONS//
/////////////


//welcome() - welcome user//
int welcome()
{
	int tempConfirm = 0;
	
	cout << "*********************************" << endl;
	cout << " WELCOME TO THE COLLEGE MATCHER!" << endl;
	cout << "This program will help you choose" << endl;
	cout << "which public college in Ohio is" << endl;
	cout << "best for you!" << endl << endl;
	
	cout << "If you would like to continue, " << endl;
	cout << "please enter 1. If you would like" << endl;
	cout << "to quit, enter 0:  ";
	cin >> tempConfirm;
	cout << "---------------------------------" << endl;
	
	return tempConfirm;
}


//fillCollegeArys - fill college arrays from data file//
int fillCollegeArys(int tempAkron[], int tempCentral[], int tempCleveland[], int tempMiami[], int tempOhioUni[], int tempToledo[], int tempYoungstown[], int tempBgsu[], int tempCincinnati[], int tempKent[], int tempOsu[], int tempWright[], int tempShawnee[], int TEMP_MAX)
{
	int i;
	ifstream indata;
	
	indata.open("collegeInfo.txt");
	
	if(!indata)
	{
		return 1;
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempAkron[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempCentral[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempCleveland[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempMiami[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempOhioUni[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempToledo[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempYoungstown[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempBgsu[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempCincinnati[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempKent[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempOsu[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempWright[i];
	}
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		indata >> tempShawnee[i];
	}
	
	indata.close();
	
	return 0;
}


//inputQuiz() - display questionnaire and record answers//
void inputQuiz(int tempUserData[])
{
	string choice;
	
	cout << "Enter the number corresponding to your choice:" << endl;
	cout << "PLEASE ONLY ENTER GIVEN CHOICES." << endl;
	cout << "FAILURE TO DO SO WILL RESULT IN INCORRECT RESULTS" << endl << endl;
	
	cout << "A. What size college do you like?" << endl;      //Question 1
	cout << "  1. less than 5,000 students" << endl;
	cout << "  2. between 5,000 and 15,000" << endl;
	cout << "  3. between 15,000 and 30,000" << endl;
	cout << "  4. greater than 30,000" << endl;
	cout << "Answer:  ";
	cin >> tempUserData[0];
	cout << endl;
	
	cout << "B. What setting do you like?" << endl;            //Question 2
	cout << "  1. Rural" << endl;
	cout << "  2. Suburban" << endl;
	cout << "  3. Urban" << endl;
	cout << "Answer:  ";
	cin >> tempUserData[1];
	cout << endl;
	
	cout << "C. What location do you like?" << endl;          //Question 3
	cout << "  1. Northeast Ohio" << endl;
	cout << "  2. Central West Ohio" << endl;
	cout << "  3. Southwest Ohio" << endl;
	cout << "  4. Central Ohio" << endl;
	cout << "  5. Northwest Ohio" << endl;
	cout << "  6. South Central Ohio" << endl;
	cout << "Answer:  ";
	cin >> tempUserData[2];
	cout << endl;
	
	cout << "D. What tuition range do you prefer?" << endl;          //Question 4
	cout << "  1. Greater than $25,000" << endl;
	cout << "  2. Between $15,000 and $25,000" << endl;
	cout << "  3. Less than $15,000" << endl;
	cout << "Answer:  ";
	cin >> tempUserData[3];
	cout << endl;
	
	cout << "E. What acceptance rate do you prefer?" << endl;          //Question 5
	cout << "  1. Open" << endl;
	cout << "  2. Greater than 80%" << endl;
	cout << "  3. Between 70% and 80%" << endl;
	cout << "  4. Less than 70%" << endl;
	cout << "Answer:  ";
	cin >> tempUserData[4];
	cout << endl;
	
	cout << "F. What graduation rate do you prefer?" << endl;          //Question 6
	cout << "  1. Less than 15%" << endl;
	cout << "  2. Between 15% and 30%" << endl;
	cout << "  3. Greater than 30%" << endl;
	cout << "Answer:  ";
	cin >> tempUserData[5];
	cout << endl;
	
	cout << "G. What ACT score range do you prefer?" << endl;          //Question 7
	cout << "  1. Open (not considered)" << endl;
	cout << "  2. Greater than 22" << endl;
	cout << "  3. Between 19 and 22" << endl;
	cout << "  4. Less than 19" << endl;
	cout << "Answer:  ";
	cin >> tempUserData[6];
	cout << endl;
	
	cout << "H. What percent of classes would you like" << endl;	//Question 8
	cout << "to have more than 50 students?" << endl;
	cout << "  1. Less than 10%" << endl;
	cout << "  2. Between 10% and 20%" << endl;
	cout << "  3. Greater than 20%" << endl;
	cout << "Answer:  ";
	cin >> tempUserData[7];
	cout << endl;
	
	cout << "I. What percent of freshman do you prefer" << endl;          //Question 9
	cout << "to live in campus housing?" << endl;
	cout << "  1. Greater than 90%" << endl;
	cout << "  2. Between 70% and 90%" << endl;
	cout << "  3. Between 40% and 70%" << endl;
	cout << "  4. Less than 40%" << endl;
	cout << "Answer:  ";
	cin >> tempUserData[8];
	cout << endl;
	
	cout << "J. What retention rate do you prefer?" << endl;          //Question 10
	cout << "  1. Greater than 80%" << endl;
	cout << "  2. Between 80% and 68%" << endl;
	cout << "  3. Less than 68%" << endl;
	cout << "Answer:  ";
	cin >> tempUserData[9];
}


//compareColleges() - compare colleges to user data, calculate percent similarity//
double compareColleges(int tempUserData[], int tempCollegeData[], int TEMP_MAX)
{
	double match = 0;
	double percent = 0;
	int i;
	
	for(i = 0; i < TEMP_MAX; i++)
	{
		if(tempUserData[i] == tempCollegeData[i])
		{
			match++;
		}
	}
	
	percent = (match/TEMP_MAX) * 100;
	
	return percent;
}


//sortColleges() - sort colleges based on percents//
void sortColleges(double tempPercents[], string tempNames[], int TEMP_MAX)
{
	int i;
	int swap = 1;
	string holdName;
	double holdPercent;
	
	while(swap != 0)
	{
		swap = 0;
		
		for(i = 0; i < (TEMP_MAX - 1); i++)
		{
			if(tempPercents[i] < tempPercents[i + 1])
			{
				holdPercent = tempPercents[i];
				tempPercents[i] = tempPercents[i + 1];
				tempPercents[i + 1] = holdPercent;
				
				holdName = tempNames[i];
				tempNames[i] = tempNames[i + 1];
				tempNames[i + 1] = holdName;
				
				swap++;
			}
		}
	}
}


//displayMatch() - display colleges similar back to user from highest to lowest percent// 
void displayMatch(string tempNames[], double tempPercents[], int TEMP_MAX)
{
	int i;
	
	cout << "These are your matches!" << endl;
	for(i = 0; i < TEMP_MAX; i++)
	{
		cout << tempPercents[i] << "%  " << tempNames[i] << endl;
	}
}


//displayInfo() - if requested, show user info about best match//
void displayInfo(int tempCollege[])
{
	if(tempCollege[0] == 1)                         //Question 1
	{	
		cout << "This college has less than 5,000 students" << endl;
	}
	else if(tempCollege[0] == 2)
	{	
		cout << "This college has between 5,000 and 15,000 students" << endl;
	}
	else if(tempCollege[0] == 3)
	{	
		cout << "This college has between 15,000 and 30,000 students" << endl;
	}
	else if(tempCollege[0] == 4)
	{	
		cout << "This college has more than 30,000 students" << endl;
	}
	
	if(tempCollege[1] == 1)                         //Question 2
	{	
		cout << "This college has a rural" << endl;
	}
	else if(tempCollege[1] == 2)
	{	
		cout << "This college has a suburban setting" << endl;
	}
	else if(tempCollege[1] == 3)
	{	
		cout << "This college has an urban setting" << endl;
	}
	
	if(tempCollege[2] == 1)                         //Question 3
	{	
		cout << "This college is located in Northeast Ohio" << endl;
	}
	else if(tempCollege[2] == 2)
	{	
		cout << "This college is located in Central West Ohio" << endl;
	}
	else if(tempCollege[2] == 3)
	{	
		cout << "This college is located in Southwest Ohio" << endl;
	}
	else if(tempCollege[2] == 4)
	{	
		cout << "This college is located in Central Ohio" << endl;
	}
	else if(tempCollege[2] == 5)
	{
		cout << "This college is located in Northwest Ohio" << endl;
	}
	else if(tempCollege[2] == 6)
	{
		cout << "This college is located in South Central Ohio" << endl;
	}
	
	if(tempCollege[3] == 1)                         //Question 4
	{	
		cout << "This college costs more than $25,000 per year" << endl;
	}
	else if(tempCollege[3] == 2)
	{	
		cout << "This college costs between $15,000 and $25,000 per year" << endl;
	}
	else if(tempCollege[3] == 3)
	{	
		cout << "This college costs less than $15,000 per year" << endl;
	}
	
	if(tempCollege[4] == 1)                         //Question 5
	{	
		cout << "This college has open acceptance" << endl;
	}
	else if(tempCollege[4] == 2)
	{	
		cout << "This college has an acceptance rate greater than 80%" << endl;
	}
	else if(tempCollege[4] == 3)
	{	
		cout << "This college has an acceptance rate between 70% and 80% students" << endl;
	}
	else if(tempCollege[4] == 4)
	{	
		cout << "This college has an acceptance rate less than 70%" << endl;
	}
	
	if(tempCollege[5] == 1)                         //Question 6
	{	
		cout << "This college has a graduation rate less than 15%" << endl;
	}
	else if(tempCollege[5] == 2)
	{	
		cout << "This college has a graduation rate between 15% and 30%" << endl;
	}
	else if(tempCollege[5] == 3)
	{	
		cout << "This college has a graduation rate greater than 30%" << endl;
	}
	
	if(tempCollege[6] == 1)                         //Question 7
	{	
		cout << "ACT scores are not considered at this college" << endl;
	}
	else if(tempCollege[6] == 2)
	{	
		cout << "The middle 50% of ACT scores generally fall above 22 at this college" << endl;
	}
	else if(tempCollege[6] == 3)
	{	
		cout << "The middle 50% of ACT scores generally fall between 19 and 22 at this college" << endl;
	}
	else if(tempCollege[6] == 4)
	{	
		cout << "The middle 50% of ACT scores generally fall below 19 at this college" << endl;
	}
	
	if(tempCollege[7] == 1)                         //Question 8
	{	
		cout << "Less than 10% of classes have more than 50 students at this college" << endl;
	}
	else if(tempCollege[7] == 2)
	{	
		cout << "Between 10% and 20% of classes have more than 50 students at this college" << endl;
	}
	else if(tempCollege[7] == 3)
	{	
		cout << "Greater than 20% of classes have more than 50 students at this college" << endl;
	}
	
	if(tempCollege[8] == 1)                         //Question 9
	{	
		cout << "Greater than 90% of freshmen live on campus at this college" << endl;
	}
	else if(tempCollege[8] == 2)
	{	
		cout << "Between 70% and 90% of freshmen live on campus at this college" << endl;
	}
	else if(tempCollege[8] == 3)
	{	
		cout << "Between 40% and 70% of freshmen live on campus at this college" << endl;
	}
	else if(tempCollege[8] == 4)
	{	
		cout << "Less than 40% of freshmen live on campus at this college." << endl;
	}
	
	if(tempCollege[9] == 1)                         //Question 10
	{	
		cout << "This college has a retention rate of greater than 80%" << endl;
	}
	else if(tempCollege[9] == 2)
	{	
		cout << "This college has a retention rate of between 68% and 80%" << endl;
	}
	else if(tempCollege[9] == 3)
	{	
		cout << "This college has a retention rate of less than 68%" << endl;
	}
	
	cout << endl;
}


//thanks() - thank user
void thanks()
{
	cout << "----------------------------------" << endl;
	cout << " THANK YOU FOR USING THIS PROGRAM" << endl;
	cout << "We hope you found the right match!" << endl;
	cout << "**********************************" << endl;
}
