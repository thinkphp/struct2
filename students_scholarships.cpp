#include <iostream>
#include <cstring>

using namespace std;

typedef struct student {
       char name[100];
       int media,
           bursa;
} Student;

Student arr[100];
int i, n;//number of students

int main(int argc, char const *argv[]) {

  int opt;
  char firstname[20],
       secondname[20];


  cout<<"MENU\n";
  cout<<"Add   : 1\n";
  cout<<"Search: 2\n";
  cout<<"List  : 3\n";
  cout<<"EXIT  : 4\n";
  do {

     cout<<"Choose = ";
     cin>>opt;

     switch(opt) {

            case 1:
            cout<<"Adding Students:\n";
            cout<<"First Name: ";
            cin>>firstname;
            cout<<"Second Name: ";
            cin>>secondname;
            strcat(firstname, " ");
            strcat(firstname, secondname);

            for(i = 0; i < n && strcmp(arr[i].name, firstname) <= 0; i++);

            for(int j = n - 1; j >= i; --j) {
                arr[j+1] = arr[j];
            }

            strcpy(arr[i].name, firstname);
            cout<<"Media: ";
            cin>>arr[i].media;
            cout<<"Bursa: ";
            cin>>arr[i].bursa;
            n++;//increase the number of students added
            cout<<"n = "<<n<<"\n";
            break;

            case 2:
            int j;

            cout<<"Searching by name =\n";
            char searchname[20], fn[20], sn[20];
            cin>>fn>>sn;
            strcpy(searchname, fn);
            strcat(searchname," ");
            strcat(searchname, sn);
            cout<<"Searching... "<<searchname<<"\n";
            i = 0;
            j = n - 1;

            int m, found;
            found = 0;

            while(i <= j && !found) {
                m = (i + j) / 2;
                if(!strcmp(arr[m].name, searchname)) {
                   found = 1;
                   cout<<"Founded!\n";
                   cout<<"Media -> "<<arr[m].media<<" Bursa -> "<<arr[m].bursa<<"\n";
                } else if(strcmp(arr[m].name, searchname) > 0) {
                   j = m - 1;
                } else {
                   i = m + 1;
                }
            }
            if(!found) cout<<"Not Found!";
            break;

            case 3:
            cout<<"Displaying Students:\n";
            for(int i = 0; i < n; ++i) cout<<i+1<<". ", cout<<arr[i].name<<" "<<arr[i].media<<" "<<arr[i].bursa<<"\n";
            if(n == 0) cout<<"No Students.\n";
            break;

            case 4:
            cout<<"Bye!";
            break;

            default:
            cout<<"Error!";
            break;
     }

  }while(opt!=4);

  return 0;
}
