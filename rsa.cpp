#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ encrypt(const ZZ &message, const ZZ &e, const ZZ &n)
{
    ZZ C;
    PowerMod(C, message, e, n); // C = (message^e) mod n
    return C;
}

ZZ decrypt(const ZZ &ciphertext, const ZZ &d, const ZZ &n)
{
    ZZ M;
    PowerMod(M, ciphertext, d, n); // M = (ciphertext^d) mod n
    return M;
}

int main()
{
    ZZ p, q, n, phi, e, d;

    cout << "Do you want to choose prime numbers p and q? (y/n): ";
    char choice1;
    cin >> choice1;
    if (choice1 == 'n' || choice1 == 'N')
    {
        p = RandomPrime_ZZ(128);
        q = RandomPrime_ZZ(128);
        cout << "Using randomly generated primes for p and q" << endl;

    }
    else
    {
        // user chooses p and q
        cout << "Choose p: ";
        cin >> p;
        if (!ProbPrime(p))
        {
            cout << "p is not prime!" << endl;
            return 1;
        }

        cout << "Choose q: ";
        cin >> q;
        if (!ProbPrime(q))
        {
            cout << "q is not prime!" << endl;
            return 1;
        }

        if (p == q)
        {
            cout << "p and q must be different!" << endl;
            return 1;
        }
    }

    n = p * q;
    phi = (p - 1) * (q - 1);


    cout << endl << "n is: " << n << endl;
    cout << endl << "phi(n) is: " << phi << endl << endl;

    cout << "Do you want to choose e? (y/n): ";
    char ans;
    cin >> ans;

    if (ans == 'n' || ans == 'N')
    {
        cout << "Using common value e = 65537" << endl;
        e = ZZ(65537);
        if (GCD(e, phi) != 1 || e >= phi)
        {
            cout << "65537 is not valid for this phi" << endl;
            return 1;
        }
    }
    else
    {
        cout << "Choose e: (must satisfy 1 < e < phi and GCD(e, phi) = 1) ";
        cin >> e;
        if (e <= 1 || e >= phi || GCD(e, phi) != 1)
        {
            cout << "Invalid e" << endl;
            return 1;
        }
    }

    d = InvMod(e, phi); // must be in range (1, phi) and satisfy (e*d) mod phi = 1
    cout << endl << "d is: " << d << endl << endl;

    // encrypt and decrypt a message

    cout << "choose what you want to Encrypt/Decrypt:\n1. Integer\n2. Sentence\n";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        // integer encryption/decryption

        ZZ message, ciphertext, decrypted;

        cout << "Enter an integer between 0 and n-1: ";
        cin >> message;
        cout << endl;

        if (message < 0 || message >= n)
        {
            cout << "Message must satisfy 0 <= message < n" << endl;
            return 1;
        }

        ciphertext = encrypt(message, e, n);
        cout << endl <<"Ciphertext: " << ciphertext << endl << endl;

        decrypted = decrypt(ciphertext, d, n);
        cout << "Decrypted message: " << decrypted << endl;
    }
    else
    {
        // sentence encryption/decryption

        char message[1024];
        ZZ ciphertext[1024], decrypted[1024];
        
        cout << "Enter a sentence to encrypt: ";
        cin.ignore();
        cin.getline(message, 1024);
        int len = strlen(message);

        // encryption
        cout << endl << "Ciphertext: ";
        for (int i = 0; i < len; i++)
        {
            ciphertext[i] = encrypt(ZZ(int(message[i])), e, n);
            cout << ciphertext[i] << " ";
        }
        cout << endl << endl;

        // decryption
        cout << "Decrypted message: ";
        for (int i = 0; i < len; i++)
        {
            decrypted[i] = decrypt(ciphertext[i], d, n);
            cout << char(to_int(decrypted[i]));
        }
        cout << endl;
        
    }

    return 0;
}