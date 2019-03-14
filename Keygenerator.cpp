// Descrizione - Software di genereazione chiavi

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include "mersennetwister.h"


using namespace std;

int main (int argc, char *argv[])
{
     string sleep;
     long long x;
     long long count3 = 0;
     long long howmany = 0;
     long long p1;
     cout << "Inserisci chiave numerica." << "\n";
     cin >> x;
     cout << "Numero di chiavi da generare." << "\n";
     cin >> howmany;
     MTRand mtrand1( x );
     ofstream myfile1;
     myfile1.open("keyfile.txt",ios::out);
     if (!myfile1)
     {
          cout << "ERROR LINE 26\n";
          myfile1.close();
          cin >> sleep;
          exit(1); // Controllo d'errore
     }
     count3 = -1;
     do
     {
          count3++;
          p1 = mtrand1.randInt( 9999999 );
          myfile1 << p1 << "\n";
     } while(count3 < howmany);
     myfile1.close();
     myfile1.clear();

}
