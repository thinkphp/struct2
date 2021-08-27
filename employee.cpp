#include <iostream>
#include <cstring>
#define FIN "employee.in"
#define FOUT "employee.out"

using namespace std;

typedef unsigned int uint;

typedef struct Emp {
       char name[30];
       char company[50];
       uint salary;
} employee;

employee arr[100];//we have 100 employee in this company

void countingsort(employee *emp, uint n) {

     employee C[100];
     uint B[n+1];
     for (int i = 0; i < n; i++) {
         C[i] = emp[i];
     }
     for(uint i = 0; i < n; ++i) {
       B[i] = 0;
     }
     for(int i = 0; i < n - 1; ++i) {
         for(int j = i + 1; j < n; ++j) {
             if(arr[j].salary > arr[i].salary) {
               B[i]+=1;
             } else {
               B[j]+=1;
             }
         }
     }
     for(uint i = 0; i < n; ++i) {
       arr[B[i]] = C[i];
     }
}

int main(int argc, char const *argv[]) {

  uint n;//stored the number of employee
  char fname[30], sname[30], comp[50];
  uint sal;

  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);

  cin>>n;
  for(int i = 0; i < n; ++i) {
    cin>>fname>>sname>>comp>>sal;
    strcpy(arr[i].name, fname);
    strcat(arr[i].name, " ");
    strcat(arr[i].name, sname);
    strcpy(arr[i].company, comp);
    arr[i].salary  = sal;
  }
  countingsort(arr, n);

  for(int i = 0; i < n; ++i) cout<<(i+1)<<". "<<arr[i].name<<" "<<arr[i].company<<" "<<arr[i].salary<<"\n";

  return 0;
}
