// Discription - Encryption program to take a list of numbers and use them as a an encryption key to encrypt/decrypt a file.

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include "mersennetwister.h"

// declare variables
// ask for name of key file
// ask if encryption/decryption
// if encryption goto encryption
// if decryption goto decryption

using namespace std;

int main (int argc, char *argv[])
{

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

cout << "Nome del file con la chiave" << "\n";
cin >> keyfile; // (string)
cout << "Qualè il file da criptare. Verrà sovrascritto!!!" << "\n";
cin >> file2; // (string)
// file2 = "1.bin";
// cout << "What is the destination file" << "\n";
// cin >> file3; // (string)
// file3 = "2.bin";
cout << "Ha criptato oggi? Se scrivi no vai alla decrptazione" << "\n";
cin >> answer; // (string)

if (answer == "si")
{
     // open file start file loop
     myfile1.open("keyfile.txt",ios::in);
     if (!myfile1)
     {
          cout << "ERROR LINE 44\n";
          myfile1.close();
          system("pause");
          exit(1); // terminate with error
     }
          // read key file to array
          // count numbers in file as read to array
     numcount = -1;
     do
     {
          numcount++;
          myfile1 >> seednum;
          seedarray[numcount] = seednum;
     }while (!myfile1.eof());
     // end file loop
     myfile1.close();
     myfile1.clear();

     // start array loop
     count = -1;
     do
     {
          count++;
          // read array
          byteconversion = seedarray[count];
          MTRand mtrand1( byteconversion );
          // initialize key array
          count3 = -1;
          do
          {
               count3++;
               keyarray[count3] = count3;
          } while(count3 < 255);
          // create key with key loop
          count2 = -1;
          do
          {
               count2++;
               p1 = mtrand1.randInt( 255 );
               x = keyarray[count2];
               keyarray[count2] = keyarray[p1];
               keyarray[p1] = x;
          } while (count2 < 255);
          // end key loop
          // open source file
          myfile2.open(file2.c_str(), ios:: in | ios:: out | ios:: binary);
          if (!myfile2)
          {
               cout << "Error in line 97.\n";
               system("pause");
               myfile2.close();
               myfile2.clear();
               exit(1); // terminate with error
          }
          // open destination file
//          myfile3.open(file3.c_str(), ios:: out | ios:: binary);
//          if (!myfile3)
//          {
//               cout << "Error in line 107.\n";
//               system("pause");
//               myfile3.close();
//               myfile3.clear();
//               exit(1); // terminate with error
//          }
          // get filesize of source file.
          myfile2.seekg(0, ios::beg);
          size1 = myfile2.tellg();
          myfile2.seekg(0, ios::end);
          size2 = myfile2.tellg();
          filesize = size2 - size1;
          // start second loop (Here we encrypt the file)
          count2 = -1;
          do
          {
              // read source file
              count2++;
              begin2 = myfile2.tellg();
              myfile2.seekg(count2);
              if (!myfile2)
              {
                   myfile2.close();
                   cout << "error in line 133.\n";
                   system("PAUSE");
                   exit(1);
              }
              myfile2.read( reinterpret_cast<char*>( &buffer ),1);
              x = (int)buffer;
              // start key loop
              count3 = -1;
              do
              {    count3++;
                   // use file byte to get encryption byte
                   if (x == count3)
                   {
                        x = keyarray[count3];
                        break;
                   }
              }while(count3 < 255);
              // exit key loop
              //write to destination file
              buffer = (unsigned char)x;
              myfile2.seekp(count2);
              myfile2.write( reinterpret_cast<char*>( &buffer ),1);
              begin2 = myfile2.tellp();
              // repreat key loop until entirefile encrypted
           } while (count2 < filesize - 1);
           // close source file
           myfile2.close();
           myfile2.clear();
           // close destination file
//           myfile3.close();
//           myfile3.clear();
//           system("del 1.bin");
//           system("rename 2.bin 1.bin");
//           system("del 2.bin");
     // repeat array loop till all numbers used up
           cout << count << " " << numcount << "\n";
     } while(count < numcount);
     cout << "File Encrypted" << "\n";
     cin >> sleep;
     exit(0);
}

if (answer == "no")
{
     // open file start file loop
     myfile1.open("keyfile.txt",ios::in);
     if (!myfile1)
     {
          cout << "ERROR LINE 192\n";
          myfile1.close();
          system("pause");
          exit(1); // terminate with error
     }
          // read key file to array
          // count numbers in file as read to array
     numcount = -1;
     do
     {
          numcount++;
          myfile1 >> seednum;
          seedarray[numcount] = seednum;
     }while (!myfile1.eof());
     // end file loop
     myfile1.close();
     myfile1.clear();

     // start array loop
     count = numcount + 1;
     do
     {
          count--;
          // read array
          byteconversion = seedarray[count];
//          srand (byteconversion);
          MTRand mtrand1( byteconversion );
          // initialize key array
          count3 = -1;
          do
          {
               count3++;
               keyarray[count3] = count3;
          } while(count3 < 255);
          // create key with key loop
          count2 = -1;
          do
          {
               count2++;
               p1 = mtrand1.randInt( 255 );
               x = keyarray[count2];
               keyarray[count2] = keyarray[p1];
               keyarray[p1] = x;
          } while (count2 < 255);
          // end key loop
          // open source file
          myfile2.open(file2.c_str(), ios:: in | ios:: out | ios:: binary);
          if (!myfile2)
          {
               cout << "Error in line 97.\n";
               system("pause");
               myfile2.close();
               myfile2.clear();
               exit(1); // terminate with error
          }
          // open destination file
//          myfile3.open(file3.c_str(), ios:: out | ios:: binary);
//          if (!myfile3)
//          {
//               cout << "Error in line 107.\n";
//               system("pause");
//               myfile3.close();
//               myfile3.clear();
//               exit(1); // terminate with error
//          }
          // get filesize of source file.
          myfile2.seekg(0, ios::beg);
          size1 = myfile2.tellg();
          myfile2.seekg(0, ios::end);
          size2 = myfile2.tellg();
          filesize = size2 - size1;
          // start second loop (Here we encrypt the file)
          count2 = -1;
          do
          {
              // read source file
              count2++;
              begin2 = myfile2.tellg();
              myfile2.seekg(count2);
              if (!myfile2)
              {
                   myfile2.close();
                   cout << "error in line 133.\n";
                   system("PAUSE");
                   exit(1);
              }
              myfile2.read( reinterpret_cast<char*>( &buffer ),1);
              x = (int)buffer;
              // start key loop
              count3 = -1;
              do
              {    count3++;
                   // use file byte to get encryption byte
                   if (x == keyarray[count3])
                   {
                        x = count3;
                        break;
                   }
              }while(count3 < 255);
              // exit key loop
              //write to destination file
              buffer = (unsigned char)x;
              myfile2.seekp(count2);
              myfile2.write( reinterpret_cast<char*>( &buffer ),1);
              begin2 = myfile2.tellp();
              // repreat key loop until entirefile encrypted
           } while (count2 < filesize - 1);
           // close source file
           myfile2.close();
           myfile2.clear();
           // close destination file
//           myfile3.close();
//           myfile3.clear();
//           system("del 1.bin");
//           system("rename 2.bin 1.bin");
//           system("del 2.bin");

     // repeat array loop till all numbers used up
           cout << count << " " << numcount << "\n";
     } while(count > 0);
     cout << "File Decrypted" << "\n";
     cin >> sleep;
     exit(0);
}
}


