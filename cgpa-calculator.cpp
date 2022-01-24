//**********************************************************************
// This program calculates your CGPA and GPA per semester and determines
// which group you are in (excellent, very good, etc.) based on your
// grades for each course in each semester.
//**********************************************************************

#include <iostream>
#include <iomanip> //Header file to allow functions to manipulate output decimal places.
using namespace std;

int main()
{
//Declare and initialise variables...
//Fixed inputs:
double gradePoint;

//User inputs:
int courseNo, semesterNo, units;
string grade;

//Calculation variables:
int counterSem, counterCourse; //loop control variables for semester and course input loops
int sumUnits, accumulatedUnits;
double gradePointUnits, accumulatedgpa, sumGradePointUnits; 

//Outputs:
double cgpa, gpa;

cout<<fixed<<showpoint<<setprecision(2); //set output correct to 2 decimal places.

cout<<"======================================================================================="<<endl;
cout<<"==                           Your personal CGPA calculator!                          =="<<endl;
cout<<"======================================================================================="<<endl;
cout<<endl;
cout<<" Table of Available Grades:"<<endl<<endl;
cout<<"***************************************************************************************"<<endl;
cout<<"**  A   |  A-  |  B+  |  B   |  B-  |  C+  |  C   |  C-  |  D+  |  D   |  D-  |  F   **"<<endl;
cout<<"** 4.00 | 3.67 | 3.33 | 3.00 | 2.67 | 2.33 | 2.00 | 1.67 | 1.33 | 1.00 | 0.67 | 0.00 **"<<endl;
cout<<"***************************************************************************************"<<endl;
cout<<endl;
cout<<" Please input without any spaces..."<<endl<<endl;
cout<<" Number of semesters: ";

semesterNo = 0; //This statement is needed to ensure the validation loop is entered.
while(!(1<=semesterNo) || !(semesterNo<=10)) //Input validation loop for number of semesters.
{
	cin>>semesterNo;
    if(cin.fail()) //Validation for wrong data types being entered into integer data type.
    {
	  cin.clear();
	  cin.ignore(100, '\n');
	  cout<<" ERROR: The number of semesters must be a number!"<<endl;
      cout<<" Please enter again: ";
	} else if(semesterNo<=0) //Validation for negative numbers and the number zero.
      {
	          cout<<" ERROR: The number of courses must be at least 1!"<<endl;
	          cout<<" Please enter again: ";
      }
    if(semesterNo>10) //Validation for numbers larger than 10 since the question stipulates that maximum number of semesters is 10.
    {
      cout<<" ERROR: 10 is the maximum number of semesters possible!"<<endl;
      cout<<" Please enter again: ";
    }
}

counterSem = 1;
accumulatedgpa = 0;
accumulatedUnits = 0;
while(counterSem<=semesterNo) //"Number of courses" input loop that loops for how many semesters there are.
{
     cout<<endl;
     cout<<"===================== Semester "<<counterSem<<" ====================="<<endl<<endl;
     cout<<" Number of courses for semester "<<counterSem<<": "; //Each semester can have different number of courses taken.
     
     courseNo = 0; //This statement is needed to ensure the validation loop is entered.
	 while(!(1<=courseNo) || !(courseNo<=6)) //Input validation loop for number of courses.
     {
	   cin>>courseNo;
       if(cin.fail())
       {
	   cin.clear();
	   cin.ignore(100, '\n');
	   cout<<" ERROR: The number of courses must be a number!"<<endl;
       cout<<" Please enter again: ";
	   } else if(courseNo<=0)
         {
	             cout<<" ERROR: The number of courses must be at least 1!"<<endl;
	             cout<<" Please enter again: ";
         }
       if(courseNo>6)
       {
         cout<<" ERROR: 6 is the maximum number of courses possible!"<<endl;
         cout<<" Please enter again: ";
       }
     }     
          
     counterCourse = 1; //It's important to reset this to one before a course loop is started for a new semester because semester 2 onwards will restart from course 1.
     sumUnits = 0;  
     sumGradePointUnits = 0; //The sum units and sum of product of grade point and units will be reused for each semester's courses so it must be reset to zero for every semester
     while(counterCourse<=courseNo) //"Course's grade and units" input loop that loops for how many courses there are for each semester.
	  {
          cout<<endl;
		  cout<<" * Course "<<counterCourse<<endl;
          cout<<" Grade: ";
          
          //Input validation loop for grade (only accepts grades that are mentioned in the table of available grades):
          
          grade = "X"; //This statement is needed to ensure the loop is entered.
          while(!(grade == "A" || grade == "A-" || grade == "B+" || grade == "B" || grade == "B-" || grade == "C+" ||
		        grade == "C" || grade == "C-" || grade == "D+" || grade == "D" || grade == "D-" || grade == "F")) 
          {
	       cin>>grade;
	       
	       if (!(grade == "A" || grade == "A-" || grade == "B+" || grade == "B" || grade == "B-" || grade == "C+" ||
		       grade == "C" || grade == "C-" || grade == "D+" || grade == "D" || grade == "D-" || grade == "F")) 
	       {
	         cout<<" ERROR: Invalid grade input! Please refer to table for valid grade inputs. (must be in CAPS)"<<endl;
	         cout<<" Please enter again: ";
	       }
          }
          
		  cout<<" Units: ";
          units = 0; //This statement is needed to ensure the loop is entered.
          while(!(1<=units)) //Input validation loop for units.
     	  {
	   	       cin>>units;
               if(cin.fail())
               {
	              cin.clear();
	              cin.ignore(100, '\n');
	              cout<<" ERROR: The units must be a number!"<<endl;
                  cout<<" Please enter again: ";
	           } else if(units<=0)
                  {
	                cout<<" ERROR: The units must be at least 1!"<<endl;
	                cout<<" Please enter again: ";
                  }    
	      }


     //Assign grade point according to grade that has been inputted:
 
          if(grade == "A")
           gradePoint = 4.00;
           else if(grade == "A-")
            gradePoint = 3.67;
            else if (grade == "B+")
             gradePoint = 3.33;
             else if (grade == "B")
              gradePoint = 3.00;
              else if (grade == "B-")
               gradePoint = 2.67;
               else if (grade == "C+")
                gradePoint = 2.33;
                else if (grade == "C")
                 gradePoint = 2.00;
                 else if (grade == "C-")
                  gradePoint = 1.67;
                  else if (grade == "D+")
                   gradePoint = 1.33;
                   else if (grade == "D")
                    gradePoint = 1.00;
                    else if (grade == "D-")
                     gradePoint = 0.67;
                     else if (grade == "F")
                      gradePoint = 0;
        
          cout<<endl;
          cout<<" Grade point: "<<gradePoint<<endl;
          sumUnits += units; //Adds current course's units to the total of all previous course's units.
          gradePointUnits = gradePoint * units; //Product of grade points and units which must be summed for the formula of GPA and CGPA.
          cout<<" Total GP: "<<gradePointUnits<<endl; //Outputs the Total GP (which is the same as gradePointUnits) for user's convenience to trace the calculations.
          sumGradePointUnits += gradePointUnits; //Adds current course's Total GP to the total of all previous course's units.
          cout<<endl;
          counterCourse++; //Increases course count by 1 so that the next course can begin being inputted.
		  }
     
     gpa = sumGradePointUnits/sumUnits;
     cout<<endl<<endl;
     cout<<" Sum of total GP: "<<sumGradePointUnits<<endl;
     cout<<" Sum of units: "<<sumUnits<<endl;
	 cout<<" Sum of grade points: "<<sumGradePointUnits<<endl;
     cout<<" GPA for Semester "<<counterSem<<" is "<<gpa<<endl;
	 accumulatedUnits += sumUnits;
     accumulatedgpa += sumGradePointUnits;
	 counterSem++;
}

cgpa = accumulatedgpa/accumulatedUnits;
cout<<endl<<endl;

cout<<" Accumulated GPA: "<<accumulatedgpa<<endl;
cout<<" Accumulated Unit: "<<accumulatedUnits<<endl;
cout<<" Your CGPA is "<<cgpa<<endl<<endl;

//Remarks regarding CGPA:
if(3.75<=cgpa && cgpa<=4.00)
 cout<<" Excellent"<<endl;
 else if(3.25<=cgpa && cgpa<=3.74)
  cout<<" Very Good"<<endl;
  else if(2.75<=cgpa && cgpa<=3.24)
   cout<<" Good"<<endl;
   else if(2.25<=cgpa && cgpa<=2.74)
    cout<<" Work Smart"<<endl;
    else if(cgpa<=2.24)
     cout<<" Work Very Hard and Work Smart"<<endl;
    
system("pause");
return 0;
}
