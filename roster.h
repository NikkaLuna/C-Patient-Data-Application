


class Roster
{
public:
    
    Patient* PatientRosterArray[5];
    int nextPatient = 0;
    
    void parse(string row);
    void add(string PatientID, string firstName, string lastName, string emailAddress, int age, int daysInHospital1, int daysInHospital2, int daysInHospital3, Hospitaldepartment Hospitaldepartment);
    void remove(string PatientID);
    void printAll();
    void printAverageDaysInHospital(string PatientID);
    void printInvalidEmails();
    void printByHospitalDepartment(Hospitaldepartment Hospitaldepartment);
    
    ~Roster();
};



