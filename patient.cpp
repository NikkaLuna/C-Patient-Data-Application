#include <iostream>
#include <string>
#include "patient.h"

using namespace std;

Patient::Patient(string id, string fname, string lname, string eaddress, int a, int days[], Hospitaldepartment department)
{
    this->Patient_ID = id;
    this->first_name = fname;
    this->last_name = lname;
    this->email_address = eaddress;
    this->age = a;
    this->DaysToComplete[0] = days[0];
    this->DaysToComplete[1] = days[1];
    this->DaysToComplete[2] = days[2];
    this->hospital_department = department;
}

void Patient::SetPatientID(string id)
{
    this->Patient_ID = id;
}
void Patient::SetFirstName(string fname)
{
    this->first_name = fname;
}
void Patient::SetLastName(string lname)
{
    this->last_name = lname;
}
void Patient::SetEmailAddress(string eaddress)
{
    this->email_address = eaddress;
}
void Patient::SetAge(int a)
{
    this->age = a;
}
void Patient::SetDaysToComplete(int days[])
{
    this->DaysToComplete[0] = days[0];
    this->DaysToComplete[1] = days[1];
    this->DaysToComplete[2] = days[2];
}
void Patient::SetHospitalDepartment(Hospitaldepartment department)
{
    this->hospital_department = department;
}


string Patient::GetPatient_ID()
{
    return this->Patient_ID;
}
string Patient::GetFirstName()
{
    return this->first_name;
}
string Patient::GetLastName()
{
    return this->last_name;
}
string Patient::GetEmailAddress()
{
    return this->email_address;
}
int Patient::GetAge()
{
    return this->age;
}
int Patient::GetDaysToComplete1()
{
    return this->DaysToComplete[0];
}
int Patient::GetDaysToComplete2()
{
    return this->DaysToComplete[1];
}
int Patient::GetDaysToComplete3()
{
    return this->DaysToComplete[2];
}
Hospitaldepartment Patient::GetHospitaldepartment()
{
    return this->hospital_department;
}

void Patient::print() 
{
   string department_string;
    if (hospital_department == Hospitaldepartment::NEUROLOGY)
  {
        department_string = "NEUROLOGY";
  }
    
    else if (hospital_department == Hospitaldepartment::ONCOLOGY)
  {
        department_string = "ONCOLOGY";
  }
    
    else if (hospital_department == Hospitaldepartment::CARDIOLOGY)
  {
        department_string = "CARDIOLOGY";
  }
    
    cout << Patient_ID << "\t" << "First Name: " << first_name << "\t" << "Last Name: " << last_name << "\t" << email_address << "\t" << "Age: " << age << "\t" << "Days In Hospital: " << "{" << DaysToComplete[0] << "," << DaysToComplete[1] << "," << DaysToComplete[2] << "}" << "\t" << "Hospital Department : " << department_string << endl;
}

Patient::~Patient()
{
    
}
