#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;


ZZ decrypt(const ZZ &ciphertext, const ZZ &d, const ZZ &n)
{
    ZZ M;
    PowerMod(M, ciphertext, d, n); // M = (ciphertext^d) mod n
    return M;
}


int main()
{
    // decryption  
    ZZ p, q, e, d, n;
    
    cout << "input p: ";
    cin >> p;
    
    cout << "input q: ";
    cin >> q;
    
    n = p * q;

    cout << "input e: ";
    cin >> e;
    
    char ciphertext[1024];   
    cout << "input ciphertext: ";
    cin.ignore();
    cin.getline(ciphertext, 1024);

    d = InvMod(e, (p - 1) * (q - 1));

    cout << "Decrypted message: ";

    for (size_t i = 0; i < strlen(ciphertext); i++)
    {
        ZZ c = to_ZZ(int(ciphertext[i]));
        ZZ m = decrypt(c, d, n);
        cout << char(to_int(m));
    }
    

}