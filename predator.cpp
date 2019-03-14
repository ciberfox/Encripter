// Descrizione - Programma di criptazione

#include < cstdlib > 
#include < iostream > 
#include < stdlib.h > 
#include < fstream > 
#include < sstream > 
#include < string > 
#include < cmath > 
#include "mersennetwister.h"

// Dichiarazione Variabili
// Richiede nome del file
// Richiede se criptare o decriptare
// Gestione logica della risposta

using namespace std;

int main(int argc, char * argv[]) {

  string file2;
  string keyfile;
  // string file3;
  string answer;
  ifstream myfile1;
  long long numcount;
  long long seednum;
  long long seedarray[10000];
  long long keyarray[255];
  long long count;
  long long byteconversion;
  long long count2;
  int test;
  int p1;
  long long count3;
  fstream myfile2;
  // fstream myfile3;
  long long size1;
  long long size2;
  long long filesize;
  long long begin2;
  long long begin3;
  unsigned char buffer;
  char oldname;
  char newname;
  int x;

  string sleep;

  cout << "Nome del file chiave" << "\n";
  cin >> keyfile; // (string)
  cout << "Nome del file da criptare. Verrà sovrascritto!!!" << "\n";
  cin >> file2; // (string)
  //Cambio nome file
  // file2 = "1.bin";
  // cout << "File di destinazione" << "\n";
  // cin >> file3; // (string)
  // file3 = "2.bin";
  cout << "Scrivere si per criptare, no per decriptare" << "\n";
  cin >> answer; // (string)

  if (answer == "si") {
    // Avvia ciclo sul file chiavi
    myfile1.open("keyfile.txt", ios:: in );
    if (!myfile1) {
      cout << "ERROR LINE 44\n";
      myfile1.close();
      system("pause");
      exit(1); // terminate with error
    }
    // Crea array da file
    // Conta quante righe ci sono nel file
    numcount = -1;
    do {
      numcount++;
      myfile1 >> seednum;
      seedarray[numcount] = seednum;
    } while (!myfile1.eof());
    // end file loop
    myfile1.close();
    myfile1.clear();

    // avvia ciclo su array
    count = -1;
    do {
      count++;
      // leggo array
      byteconversion = seedarray[count];
      MTRand mtrand1(byteconversion);
      // Inizializzo array
      count3 = -1;
      do {
        count3++;
        keyarray[count3] = count3;
      } while (count3 < 255);
      // Creo chiavi per il ciclo
      count2 = -1;
      do {
        count2++;
        p1 = mtrand1.randInt(255);
        x = keyarray[count2];
        keyarray[count2] = keyarray[p1];
        keyarray[p1] = x;
      } while (count2 < 255);
      // esce dal ciclo
      // Apre file di destinazione
      myfile2.open(file2.c_str(), ios:: in | ios::out | ios::binary);
      if (!myfile2) {
        cout << "Errore alla linea 97.\n";
        system("pause");
        myfile2.close();
        myfile2.clear();
        exit(1); // esce con errore
      }
      // Apertura file di destinazione
      //          myfile3.open(file3.c_str(), ios:: out | ios:: binary);
      //          if (!myfile3)
      //          {
      //               cout << "Errore alla linea 107.\n";
      //               system("pause");
      //               myfile3.close();
      //               myfile3.clear();
      //               exit(1); // esce con errore
      //          }
      // get filesize of source file.
      myfile2.seekg(0, ios::beg);
      size1 = myfile2.tellg();
      myfile2.seekg(0, ios::end);
      size2 = myfile2.tellg();
      filesize = size2 - size1;
      // avvio secondo ciclo
      count2 = -1;
      do {
        // Leggo il file
        count2++;
        begin2 = myfile2.tellg();
        myfile2.seekg(count2);
        if (!myfile2) {
          myfile2.close();
          cout << "error in line 133.\n";
          system("PAUSE");
          exit(1);
        }
        myfile2.read(reinterpret_cast < char * > ( & buffer), 1);
        x = (int) buffer;
        // avvio ciclo su chiave
        count3 = -1;
        do {
          count3++;
          // Convero in bytecode
          if (x == count3) {
            x = keyarray[count3];
            break;
          }
        } while (count3 < 255);
        // Esce dal ciclo
        //Scrivo file
        buffer = (unsigned char) x;
        myfile2.seekp(count2);
        myfile2.write(reinterpret_cast < char * > ( & buffer), 1);
        begin2 = myfile2.tellp();
        // ripeto ciclo sul file per seconda chiave
      } while (count2 < filesize - 1);
      // close source file
      myfile2.close();
      myfile2.clear();
      // chiudo file
      //           myfile3.close();
      //           myfile3.clear();
      //           system("del 1.bin");
      //           system("rename 2.bin 1.bin");
      //           system("del 2.bin");
      // Ripete ciclo n volte quante chiavi create
      cout << count << " " << numcount << "\n";
    } while (count < numcount);
    cout << "File Encrypted" << "\n";
    cin >> sleep;
    exit(0);
  }

  if (answer == "no") {
    // Apro file criptato
    myfile1.open("keyfile.txt", ios:: in );
    if (!myfile1) {
      cout << "ERROR LINE 192\n";
      myfile1.close();
      system("pause");
      exit(1); // Esce con errore
    }
    // Loggo file con chiavi
    // Conto righe e genero array
    numcount = -1;
    do {
      numcount++;
      myfile1 >> seednum;
      seedarray[numcount] = seednum;
    } while (!myfile1.eof());
    // esco dal ciclo
    myfile1.close();
    myfile1.clear();

    // avvio ciclo su array
    count = numcount + 1;
    do {
      count--;
      // leggo array
      byteconversion = seedarray[count];
      //          srand (byteconversion);
      MTRand mtrand1(byteconversion);
      // inizializzo chiavi array
      count3 = -1;
      do {
        count3++;
        keyarray[count3] = count3;
      } while (count3 < 255);
      // creo indice ciclo
      count2 = -1;
      do {
        count2++;
        p1 = mtrand1.randInt(255);
        x = keyarray[count2];
        keyarray[count2] = keyarray[p1];
        keyarray[p1] = x;
      } while (count2 < 255);
      // chiudo ciclo
      // apro il file sorgente
      myfile2.open(file2.c_str(), ios:: in | ios::out | ios::binary);
      if (!myfile2) {
        cout << "Errore alla linea 97.\n";
        system("pause");
        myfile2.close();
        myfile2.clear();
        exit(1); // esco con errore
      }
      // Apro file destinazione
      //          myfile3.open(file3.c_str(), ios:: out | ios:: binary);
      //          if (!myfile3)
      //          {
      //               cout << "Errore linea 107.\n";
      //               system("pause");
      //               myfile3.close();
      //               myfile3.clear();
      //               exit(1); // esce con errore
      //          }
      // Leggo dimmensione file
      myfile2.seekg(0, ios::beg);
      size1 = myfile2.tellg();
      myfile2.seekg(0, ios::end);
      size2 = myfile2.tellg();
      filesize = size2 - size1;
      // Avvio secondo ciclo
      count2 = -1;
      do {
        // Leggo file sorgente
        count2++;
        begin2 = myfile2.tellg();
        myfile2.seekg(count2);
        if (!myfile2) {
          myfile2.close();
          cout << "errore alla riga 133.\n";
          system("PAUSE");
          exit(1);
        }
        myfile2.read(reinterpret_cast < char * > ( & buffer), 1);
        x = (int) buffer;
        // avvio ciclo su chiavi
        count3 = -1;
        do {
          count3++;
          // lavoro sul bytecode
          if (x == keyarray[count3]) {
            x = count3;
            break;
          }
        } while (count3 < 255);
        // ecse dal ciclo
        //scrivo file di destinazione
        buffer = (unsigned char) x;
        myfile2.seekp(count2);
        myfile2.write(reinterpret_cast < char * > ( & buffer), 1);
        begin2 = myfile2.tellp();
        // ripete ciclo per n volte quante chiavi
      } while (count2 < filesize - 1);
      // chiudo file sorgente
      myfile2.close();
      myfile2.clear();
      // chiudo file destinazione
      //           myfile3.close();
      //           myfile3.clear();
      //           system("del 1.bin");
      //           system("rename 2.bin 1.bin");
      //           system("del 2.bin");

      // crea ciclo su indici array
      cout << count << " " << numcount << "\n";
    } while (count > 0);
    cout << "File Decriptato" << "\n";
    cin >> sleep;
    exit(0);
  }
}
