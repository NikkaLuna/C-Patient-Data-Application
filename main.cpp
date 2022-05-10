#include <iostream>
#include <string>
#include "patient.h"
#include "roster.h"

using namespace std;

    
int main()
{
    cout << "Language: C++" << endl;
    cout << "Name: Andrea Hayes" << endl;
    
const string PatientData[5] =

    {"5467,Patrick,Maron,Patrick1997@gm ail.com,20,30,35,40,NEUROLOGY",
     "6734,Suzan,Evans,Evans_1998@gmailcom,19,50,30,40,ONCOLOGY",
     "2331,Jack,Kidman,The_lawyer99yahoo.com,19,20,40,33,CARDIOLOGY",
     "7998,Deborah,White,Deborah.White@comcast.net,22,50,58,40,NEUROLOGY",
     "5448,Andrea,Hayes,Ahaye74@wgu.edu,42,10,11,12,CARDIOLOGY"};
    
    
Roster PatientRoster;
    
    for (int i = 0; i < 5; i++)
         {
            PatientRoster.parse(PatientData[i]);
         }
    
        cout << endl;
        cout << "Displaying all Patients:" << endl;
        cout << endl;
    PatientRoster.printAll();
        cout << endl;
  
    
        cout << "Displaying invalid emails:" << endl;
        cout << endl;
    PatientRoster.printInvalidEmails();
        cout << endl;
    
        cout << "Displaying average days in Hospital:" << endl;
        cout << endl;
    for (int i = 0; i < 5; i++)
    PatientRoster.printAverageDaysInHospital(PatientRoster.PatientRosterArray[i]->GetPatient_ID());
        cout << endl;



        cout << "Showing Patients in department: CARDIOLOGY" << endl;
        cout << endl;
    PatientRoster.printByHospitalDepartment(Hospitaldepartment::CARDIOLOGY);
        cout << endl;

    
        cout << "Removing Patient 2331:" << endl;
    PatientRoster.remove("2331");
        cout << endl;
    
    PatientRoster.printAll();
        cout << endl;
    
      
    cout << "Removing Patient 2331 again:" << endl;
    cout << endl;
    PatientRoster.remove("2331");
    cout << endl;
    
    return 0;
}

