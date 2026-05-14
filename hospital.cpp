#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct Patient
{
    string name;
    int severity;
    bool operator<(const Patient&p)const
    {
        return severity<p.severity;
    }
};
queue<string>appointmentQueue;
priority_queue<Patient>emergencyQueue;
void addAppointment()
{
    string name;
    cout<<"Enter Patient Name: ";
    cin.ignore();
    getline(cin,name);
    appointmentQueue.push(name);
    cout<<"Appointment Added Successfully\n";
}
void addEmergency()
{
    Patient p;
    cout<<"Enter Emergency Patient Name: ";
    cin.ignore();
    getline(cin,p.name);
    cout<<"Enter Severity Level\n";
    cout<<"3 -> High\n";
    cout<<"2 -> Medium\n";
    cout<<"1 -> Low\n";
    cout<<"Enter Severity: ";
    cin>>p.severity;
    emergencyQueue.push(p);
    cout<<"Emergency Patient Added Successfully\n";
}
void servePatient()
{
    if(!emergencyQueue.empty())
    {
        Patient p=emergencyQueue.top();
        emergencyQueue.pop();
        cout<<"\nEmergency Patient Served: "<<p.name<<endl;
        if(p.severity==3)
        {
            cout<<"Severity Level: High\n";
        }
        else if(p.severity==2)
        {
            cout<<"Severity Level: Medium\n";
        }
        else
        {
            cout<<"Severity Level: Low\n";
        }
        cout<<"Doctor Assigned Successfully\n";
    }
    else if(!appointmentQueue.empty())
    {
        string name=appointmentQueue.front();
        appointmentQueue.pop();
        cout<<"\nAppointment Patient Served: "<<name<<endl;
        cout<<"Doctor Assigned Successfully\n";
    }
    else
    {
        cout<<"\nNo Patients Available\n";
    }
}
void displayPatients()
{
    queue<string>tempAppointment=appointmentQueue;
    priority_queue<Patient>tempEmergency=emergencyQueue;
    cout<<"\nAppointment Queue:\n";
    if(tempAppointment.empty())
    {
        cout<<"No Appointment Patients\n";
    }
    while(!tempAppointment.empty())
    {
        cout<<tempAppointment.front()<<endl;
        tempAppointment.pop();
    }
    cout<<"\nEmergency Queue:\n";
    if(tempEmergency.empty())
    {
        cout<<"No Emergency Patients\n";
    }
    while(!tempEmergency.empty())
    {
        cout<<tempEmergency.top().name<<" Severity: "<<tempEmergency.top().severity<<endl;
        tempEmergency.pop();
    }
}
int main()
{
    int choice;
    do
    {
        cout<<"\n===== Smart Emergency & Hospital Management System =====\n";
        cout<<"1. Add Appointment Patient\n";
        cout<<"2. Add Emergency Patient\n";
        cout<<"3. Serve Patient\n";
        cout<<"4. Display Patients\n";
        cout<<"5. Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                addAppointment();
                break;
            case 2:
                addEmergency();
                break;
            case 3:
                servePatient();
                break;
            case 4:
                displayPatients();
                break;
            case 5:
                cout<<"Exiting Program\n";
                break;
            default:
                cout<<"Invalid Choice\n";
        }
    }while(choice!=5);
    return 0;
}