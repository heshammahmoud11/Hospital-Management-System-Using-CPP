#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;

//------ HOSIPTAL MANAGEMENT SYSTEM | OOP & FILE HANDLING ------------

class Hospital
{
    private:
        string name;
        string address;
        string bGroup;
    public:
        Hospital():name(""), address(""), bGroup(""){}
        
        void setName(string n)
        {
            name = n;
        }
        void setAddress(string add)
        {
            address = add;
        }
        void setbGroup(string group)
        {
            bGroup = group;
        }
        string getName()
        {
            return name;
        }
        string getAddress()
        {
            return address;
        }
        string getbGroup()
        {
            return bGroup;
        }
};
// -------- function to admit patient ----------
void admitPatient(Hospital patient)
{
    system("cls");

    string name, address, group;
    cout << "Enter the Patient Name: ";
    cin >> name;
    patient.setName(name);
    cout << "Enter the Patient Address: ";
    cin >> address;
    patient.setAddress(address);
    cout << "Enter Blood Group of Patient: ";
    cin >> group;
    patient.setbGroup(group);

    ofstream outfile("simple.txt", ios::app);

    if( !(outfile.is_open()) ) // ==> (!outfile)
    {
        cout << "Error in OPening File\n";
    }else{
        outfile << "Patient Name: " << patient.getName() << endl;
        outfile << "Patient Address: " << patient.getAddress() << endl;
        outfile << "Patient Blood Group: " << patient.getbGroup() << endl;
        outfile << "------------------\n";
        cout << "Patient Addmitted Successfuly...\n";
    }
    outfile.close();
    Sleep(3000);

}
// -------- function to discharge(Cancelled) the patient ----------

void dischargePatient()
{
    string name;
    cout << "Enter the Patient Name: ";
    cin >> name;

    ifstream infile("simple.txt"); // to read from the file
    ofstream outfile("test.txt"); //  to write in this temp file
    if (!(infile.is_open()) || !outfile.is_open())
    {
        cout << "Error in Opening File\n";
    }else{
        string line;
        bool found = false;
        while (getline(infile, line))
        {
            infile >> line;
            string patientName;
            infile >> patientName;
            if(name == patientName)
            {
                found = true;
                cout << "Patient Discharged Successfully\n";
            }else{
                outfile << line << endl;
            }
        }
        // if(!found)
        // {
        //     cout << "Patient Not Found\n";
        // }
    }
    outfile.close();
    infile.close();
    // remove("simple.txt");
    // rename("test.txt", "simple.txt");
    Sleep(3000);
}





int main()
{
    Hospital patient;
    bool exit = false;

    while(!exit)
    {
        system("cls");
        int val;

        cout << "------ Hoispital Management System ------\n";
        cout << "-----------------------------------------\n";
        cout << "1- Admit Patient\n";
        cout << "2- Discharge Patient\n";
        cout << "3- Exit\n";
        cout << "Enter Your Choice: ";
        cin >> val;
        if(val == 1)
        {
            admitPatient(patient);
        }else if(val == 2)
        {
            dischargePatient();
            
        }else if(val == 3)
        {
            system("cls");
            exit = true;
            cout <<"Good Luck\n";
            Sleep(3000);
        }

        Sleep(3000);
    }
    return 0;
}