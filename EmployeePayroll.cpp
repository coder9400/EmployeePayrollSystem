#include<iostream>
using namespace std;
class EmployeePayroll{
    int id;
    string phone;
    string name;
    string email;
    float basic_salary;
    float HRA;
    float DA;
    float gross_salary;

    public : 
    float hra(float basic_salary)
    {
        if(basic_salary<=20000) return (basic_salary*0.8);
        else if(basic_salary>20000 && basic_salary<=50000) return (basic_salary*0.7);
        else return (basic_salary*0.65);
    }
    float dap(float basic_salary)
    {
        if(basic_salary<=20000) return (basic_salary*0.6);
        else if(basic_salary>20000 && basic_salary<=50000) return (basic_salary*0.5);
        else return (basic_salary*0.5);
    }
    float CalculateGrossSalary(float basic_salary)
    {
        return (basic_salary + dap(basic_salary) + hra(basic_salary));
    }
    void inputData()
    {
        cout<<"Enter Employee id : ";
        cin>>id;
        cout<<"Enter Employee Name : ";
        cin>>name;
        cout<<"Enter Employee Email : ";
        cin>>email;
        cout<<"Enter Phone : ";
        cin>>phone;
        cout<<"Enter Basic_Salary : ";
        cin>>basic_salary;
        cout<<endl<<endl;
    }
    int search()
    {
        return id;
    }
    void displayData()
    {
        cout<<"----------------Display Data-----------------\n";
        cout<<"Employee id : "<<id;
        cout<<endl;
        cout<<"Name : "<<name;
        cout<<endl;
        cout<<"Email : "<<email;
        cout<<endl;
        cout<<"Phone : "<<phone;
        cout<<endl;
        cout<<"Basic Salary : "<<basic_salary;
        cout<<endl;
        cout<<"HRA : "<<hra(basic_salary);
        cout<<endl;
        cout<<"DA : "<<dap(basic_salary);
        cout<<endl;
        cout<<"Gross Salary : "<<CalculateGrossSalary(basic_salary);
        cout<<endl<<endl;
    }
};

int main()
{
    int g = 3,iid;
    EmployeePayroll obj[g];
    char username[] = "admin_here";
    int pwd = 152209;
    string name;
    int pwwd,n;
    cout<<"\n\n------------Payroll System---------------\n";
    while(1)
    {
    cout<<"Enter User name : ";
    cin>>name;
    cout<<"Enter Password : ";
    cin>>pwwd;
    if((username==name) && (pwd==pwwd))
    {
        while(1)
        {
        cout<<"Welcome back admin_here!\n\n";
        cout<<"Enter your choice : \n";
        cout<<"1. Add new Employee's data\n";
        cout<<"2. Display the data\n";
        cout<<"3. Search for an employee\n";
        cout<<"4. Exit\n";
        cin>>n;
        
        if(n==1)
        {
            for(int i=0;i<g;i++)
            {
                obj[i].inputData();
            }
        }

        else if(n==2)
        {
            for(int i=0;i<g;i++)
            {
                obj[i].displayData();
            }
        }
        else if(n==3)
        {
            cout<<"Enter Employee id : ";
            cin>>iid;
            for(int i=0;i<g;i++)
            {
                if(iid==obj[i].search())
                {
                    cout<<"Yes,Employee Is There\n";
                    obj[i].displayData();
                }
            }
        }
        else {
            cout<<"\nThankYou\n";
            return 0;
        }
    }
    }
    else cout<<"Wrong Username or Password\n";
}
    return 0;
}