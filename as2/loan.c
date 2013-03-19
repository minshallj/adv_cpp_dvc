// loan.c
#include <iostream>
//#include <stdlib>

#include <math.h>
using namespace std;
// function prototypes
void get_loan(int * loan_amnt, double * interest, int * months, int * delay);
void calc_payments(int loan, double interest, int months, int delay, double * result);
void show_totals(double result, double total);

int main()
{
  int loan, months, delay;
  double interest, result;

  get_loan(&loan, &interest, &months, &delay);
  cout << loan << interest << months << delay << endl;
  calc_payments(loan, interest, months, delay, &result);
  show_totals(result, result*months);

  return 0;
}

void get_loan(int * loan_amnt, double * interest, int * months, int * delay)
{
  cout << "Please enter the loan, and interest: ";
  cin >> *loan_amnt;
  cin >> *interest;
  cout << "Please enter the number of months until you start payments: ";
  cin >> *months;
  cout << "Please enter the number of payments you wish to make: ";
  cin >> *delay;
}

void calc_payments(int loan, double interest, int months, int delay, double * result)
{
  
}

void show_totals(double result, double total)
{
  
}
