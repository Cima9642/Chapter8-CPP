/**
 * The function getEmployeeInfo() takes in the number of employees, the employee ID, the hours worked,
 * the pay rate, and the wages
 *
 * @return the user's input.
 */
#include <iostream>
#include <iomanip>

using namespace std;

int inputValidate(int, int = 0);
double inputValidate(double, double = 15.00);
void getEmployeeInfo(const int, const int[], double[], double[], double[]);
void displayWages(const int, const int[], const double[]);

int main()
{
    const int NUM_EMPLOYEES = 7;
    int empId[] = {5658845,
                   4520125,
                   7895122,
                   8777541,
                   8451277,
                   1302850,
                   7580489};

    double hours[NUM_EMPLOYEES],
        payRate[NUM_EMPLOYEES],
        wages[NUM_EMPLOYEES];

    getEmployeeInfo(NUM_EMPLOYEES, empId, hours, payRate, wages);

    displayWages(NUM_EMPLOYEES, empId, wages);

    return 0;
}

int inputValidate(int user_number, int condition_number)
{
    while (!(cin >> user_number) || user_number < condition_number)
    {
        cout << "Your number must be "
             << condition_number
             << " or greater: ";
        cin.clear();
    }

    return user_number;
}

double inputValidate(double user_number, double condition_number)
{
    while (!(cin >> user_number) || user_number < condition_number)
    {
        cout << "Your number must be "
             << condition_number
             << " or greater: ";
        cin.clear();
    }

    return user_number;
}

void getEmployeeInfo(const int NUM_EMPLOYEES,
                     const int empId[],
                     double hours[],
                     double payRate[],
                     double wages[])
{
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        cout << "Info for employee #" << empId[i] << " :" << endl;

        cout << "Hours worked =  ";
        hours[i] = inputValidate(hours[i]);

        cout << "Pay rate     = $";
        payRate[i] = inputValidate(payRate[i]);

        wages[i] = hours[i] * payRate[i];

        cout << endl;
    }
}

void displayWages(const int NUM_EMPLOYEES,
                  const int empId[],
                  const double wages[])
{
    cout << setprecision(2) << fixed;
    cout << "Results:" << endl;
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        cout << "Wages for Employee " << empId[i]
             << " = $"
             << wages[i]
             << endl;
    }
}
