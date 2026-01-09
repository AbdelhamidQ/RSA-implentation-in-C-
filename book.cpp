#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

int encrypt(int message, int e, int n)
{
   ZZ M = to_ZZ(message);
   ZZ E = to_ZZ(e);
   ZZ N = to_ZZ(n);
   ZZ C = PowerMod(M, E, N);
   return to_int(C);
}

int decrypt(int ciphertext, int d, int n)
{
   ZZ C = to_ZZ(ciphertext);
   ZZ D = to_ZZ(d);
   ZZ N = to_ZZ(n);
   ZZ M = PowerMod(C, D, N);
   return to_int(M);
}


int main()
{
   int p, q, n, phi, e, d;

   cout << "Enter a Prime number for p: ";
   cin >> p;
   cout << "Enter a Prime number for q: ";
   cin >> q;

   n = p * q;
   cout << " n is: " << n << endl;
   
   phi = (p - 1) * (q - 1);
   cout << "totient is: " << phi << endl;

   // find candidate values for e (most commonly used is 65537)
   cout << "Candaidate values for e are: ";
   for (int i = 1; i < phi; i++)
   {
      if (GCD(i, phi) == 1)
         {
            cout << i << " ";
         }
   }
   cout << endl;

   cout << "Select a value for e from the preceding candidates: ";
   cin >> e;
   
   // find candidate values for d
   cout << "Candidate values for d are: ";
   for (int i = 1; i < phi; i++)
   {
      if ((e * i) % phi == 1)
      {
         cout << i << " ";
      }
   }
   cout << endl;

   cout << "Select a value for d from the preceding candidates: ";
   cin >> d;

   // encryption
   cout << "Enter a non-negative integer less than \"" << n << "\" to encrypt: ";
   int message;
   cin >> message;

   int ciphertext = encrypt(message, e, n);
   cout << "the ciphertext is: " << ciphertext << endl;

   // decryption
   int decrypted_message = decrypt(ciphertext, d, n);
   cout << "the decrypted plaintext is: " << decrypted_message << endl;


   // sentence encryption/decryption
   char text[256];
   cout << "Enter a sentence to encrypt: ";
   cin.ignore();
   cin.getline(text, 256);

   // encrypt the sentence ( ASCII values )
   int cipertext[256];
   int len = strlen(text);
   for (int i = 0; i < len; i++){
      cipertext[i] = encrypt(int(text[i]), e, n);
   }
   cout << endl;

   cout << "the cipertext is: ";
   for (int i = 0; i < len; i++){
      cout << (char)cipertext[i] << " ";
   }
   cout << endl;

   // decrypt the sentence
   cout << "the decrypted plaintext is: ";
   for (int i = 0; i < len; i++){
      int m = decrypt(cipertext[i], d, n);
      cout << (char)m;
   }
   cout << endl;
}