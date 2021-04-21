struct namerec{
char last[15];
char first[15];
char middle[15];
};
struct payrecord{
int id;
struct namerec name;
float hours, rate;
float regular, overtime;
float gross, tax_withheld, net;
};
typedef struct payrecord payrecord;
void gotoxy(int x, int y);
void readName(payrecord payroll[], int i);
//- reads a single name.
void printName(payrecord payroll[], int i);
//- prints a single name.
void printSummary(double gross, double tax);
//- prints total tax gross pay and total tax withheld.
void readRecords(payrecord payroll[], int n);
//- reads payroll input data records until n records have been read.
void printRecords(payrecord payroll[], int n);
//- prints n payroll records.
double calcRecords(payrecord payroll[], int n, double *taxptr);
//- computes regular and overtime pay, and the tax to be withheld.
//- also cumulatively sums total gross pay and total tax withheld.	
//- passes the address of tax initialized to 0 and returns the gross
void menu();

