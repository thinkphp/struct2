/*
Pentru elevii clasei a 12-a, profesorul diriginte are nevoie de urmatoarele
informatii, pentru a calcula nota la purtare a unui elev: numele, prenumele,
numarul total de absente si numarul de absente motivate. Pentru fiecare 10
absente nemotivate, elevul pierde un punct la nota de la purtare.
Daca numarul absentelor nemotivate este mai mare decat 50, elevul primeste media 4. Realizati un program care calculeaza notele la purtare ale elevilor si
afiseaza o lista a elevilor ordonata descrescator dupa media de la purtare.

Input:

n = 6
     Ionescu Vlad 17 10
     Popescu Ion 24 1
     Ionescu Ana 8 6
     Alexe Maria 20 4
     Mitea Ilie 73 6
     Popescu Dan 12 12
Output:

     Ionescu Ana 10
     Ionescu Vlad 10
     Popescu Dan 10
     Alexe Maria 9
     Popescu Ion 8
     Mitea Ilie 4
*/
#include <iostream>
#include <cstring>
#define FIN "students.in"
#define FOUT "students.out"

using namespace std;

typedef unsigned int uint;
typedef struct Student {

       char name[100];
       uint media;
} S;

S arr[100], aux;
uint total_absences, //number total of absences
     unmotivated_absences, //unmotivated
     n;
char first[20],
     second[20];

void selectionmin(S *p, uint n) {

     for(int i = 1; i <= n - 1; ++i) {

         S min = p[i];

         int pos = i;

         for(int j = i + 1; j <= n ; ++j) {

            if(p[j].media > min.media) {

              min = p[j];

              pos = j;
            }
         }

         aux = p[pos];

         p[pos] = p[i];

         p[i] = aux;
     }
}

int main(int argc, char const *argv[]) {

  freopen(FIN, "r", stdin);

  freopen(FOUT, "w", stdout);

  cout<<"Number of students -> ";
  cin>>n;

  for(int i = 1; i <= n; ++i) {

      scanf("%s %s", first, second);

      strcat(arr[i].name, first);

      strcat(arr[i].name, " ");

      strcat(arr[i].name, second);

      scanf("%d %d", &total_absences, &unmotivated_absences);

      arr[i].media = 10 - (total_absences - unmotivated_absences)/10;

      if(arr[i].media < 5) arr[i].media = 4;
  }

  selectionmin(arr, n);

  cout<<"Output -> "<<endl;

  for(int i = 1; i <= n; ++i) {

     cout<<arr[i].name<<" "<<arr[i].media<<"\n";

  }
  return(0);
}
