
#include <iostream>
#include <string>
#include "department.h"

using namespace std;

class Patient
{
private:
    string Patient_ID;
    string first_name;
    string last_name;
    string email_address;
    int age;
    int DaysToComplete[3];
    Hospitaldepartment hospital_department;
    

public:
  
    Patient(string Patient_ID, string first_name, string last_name, string email_address, int age, int days[], Hospitaldepartment hospital_program);

  void    SetPatientID(string);
  void    SetFirstName(string);
  void    SetLastName(string);
  void    SetEmailAddress(string);
  void    SetAge(int);
  void    SetDaysToComplete(int days[]);
  void    SetHospitalDepartment(Hospitaldepartment);
    
  string  GetPatient_ID();
  string  GetFirstName();
  string  GetLastName();
  string  GetEmailAddress();
  int     GetAge();
  int     GetDaysToComplete1();
  int     GetDaysToComplete2();
  int     GetDaysToComplete3();
  Hospitaldepartment  GetHospitaldepartment();
  
  ~Patient();

  void print();

};





