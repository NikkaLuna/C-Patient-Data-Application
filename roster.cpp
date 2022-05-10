#include <iostream>
#include <string>
using namespace std;
#include "patient.h"
#include "roster.h"


void Roster::parse(string data)
    {
        size_t rhs = data.find(",");
        string Patient_ID = data.substr(0, rhs);
        
        size_t lhs = rhs +1;
        rhs = data.find(",", lhs);
        string first_name = data.substr(lhs, rhs - lhs);
        
        lhs = rhs +1;
        rhs = data.find(",", lhs);
        string last_name = data.substr(lhs, rhs - lhs);
        
        lhs = rhs +1;
        rhs = data.find(",", lhs);
        string email_address = data.substr(lhs, rhs - lhs);
        
        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int age = stoi(data.substr(lhs, rhs - lhs));
        
        lhs = rhs +1;
        rhs = data.find(",", lhs);
        int DaysToComplete1 = stoi(data.substr(lhs, rhs - lhs));
        
        lhs = rhs +1;
        rhs = data.find(",", lhs);
        int DaysToComplete2 = stoi(data.substr(lhs, rhs - lhs));
        
        lhs = rhs +1;
        rhs = data.find(",", lhs);
        int DaysToComplete3 = stoi(data.substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        string strHospitaldepartment = data.substr(lhs, rhs - lhs);
        
    Hospitaldepartment hospital_department = Hospitaldepartment::CARDIOLOGY;
        if (strHospitaldepartment == "NEUROLOGY")
        {
            hospital_department = Hospitaldepartment::NEUROLOGY;
        }
        else if (strHospitaldepartment == "ONCOLOGY")
        {
            hospital_department = Hospitaldepartment::ONCOLOGY;
        }

  add(Patient_ID, first_name, last_name, email_address, age, DaysToComplete1, DaysToComplete2, DaysToComplete3, hospital_department);
}


void Roster::add(string PatientID, string firstName, string lastName, string emailAddress, int age, int daysInHospital1, int daysInHospital2, int daysInHospital3, Hospitaldepartment Hospitaldepartment)
{
      int days[3] = {daysInHospital1, daysInHospital2, daysInHospital3};
      PatientRosterArray[nextPatient++] = new Patient(PatientID, firstName, lastName, emailAddress, age, days, Hospitaldepartment);
}


void Roster::remove(string PatientID)
{
    for (int i = 0; i < 5; i++)
    {
        if (PatientRosterArray[i] == nullptr)
        {
            cout << "ERROR: Patient with ID: " << PatientID << " not found" << endl;
        }
        else if (PatientID == PatientRosterArray[i]->GetPatient_ID())
        {
            PatientRosterArray[i] = nullptr;
            cout << "Patient removed" << endl;
        }
    }
}


void Roster::printAll()
{
    for (int i = 0; i < 5; i++)
    {
            if (PatientRosterArray[i] != nullptr)
                PatientRosterArray[i]->print();
    }
}


void Roster::printAverageDaysInHospital(string PatientID)

{
    for (int i = 0; i < 5; i++)
        {
            if (this->PatientRosterArray[i]->GetPatient_ID() == PatientID)
            {
                int days1 = PatientRosterArray[i]->GetDaysToComplete1();
                int days2 = PatientRosterArray[i]->GetDaysToComplete2();
                int days3 = PatientRosterArray[i]->GetDaysToComplete3();
                
                cout << "PatientID: " << PatientID << " averages " << (days1 + days2 + days3) / 3 << " days in Hospital" << endl;
            }
        }
}


void Roster::printInvalidEmails()

 {
    for (int i = 0; i < 5; i++)
    {
              string emailAddress = PatientRosterArray[i]->GetEmailAddress();
                
                  if (emailAddress.find('@') == std::string::npos)
                  {
                      cout << emailAddress << " - missing an @ symbol." << endl;
                  }
           
                  else if (emailAddress.find(' ') != string::npos)
                  {
                      cout << emailAddress << " - no spaces allowed." << endl;
                  }
                  else if (emailAddress.find('.') == string::npos)
                  {
                      cout << emailAddress << " - missing a period." << endl;
                  }
      }
}


void Roster::printByHospitalDepartment(Hospitaldepartment Hospitaldepartment)
{
    for (int i = 0; i < 5; i++)
     {
      if (PatientRosterArray[i]->GetHospitaldepartment() == Hospitaldepartment::CARDIOLOGY) PatientRosterArray[i]->print();
     }
}


Roster::~Roster()
{
    {
        for (int i = 0; i < 5; i++)
        {
            delete PatientRosterArray[i];
            PatientRosterArray[i] = nullptr;
        }
    }
}
           

    
