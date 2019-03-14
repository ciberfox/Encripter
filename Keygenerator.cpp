// Discription - Encryption program to take a list of numbers and use them as a an encryption key to encrypt/decrypt a file.

#include < cstdlib > #include < iostream > #include < stdlib.h > #include < fstream > #include < sstream > #include < string > #include < cmath > #include "mersennetwister.h"

using namespace std;

int main(int argc, char * argv[]) {
  string sleep;
  long long x;
  long long count3 = 0;
  long long howmany = 0;
  long long p1;
  cout << "Inserisci la tua fonte." << "\n";
  cin >> x;
  cout << "Inserisci quanti numeri vuoi." << "\n";
  cin >> howmany;
  MTRand mtrand1(x);
  ofstream myfile1;
  myfile1.open("keyfile.txt", ios::out);
  if (!myfile1) {
    cout << "ERROR LINE 26\n";
    myfile1.close();
    cin >> sleep;
    exit(1); // terminate with error
  }
  count3 = -1;
  do {
    count3++;
    p1 = mtrand1.randInt(9999999);
    myfile1 << p1 << "\n";
  } while (count3 < howmany);
  myfile1.close();
  myfile1.clear();

}
