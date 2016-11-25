#include <fstream>
#include <iostream>
using namespace std;

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+,./:;<=>?@[]^_`{|}~'";

char data[] = "AAKusAB([;AF`ZTAHmdqAAAAAAAAQ@AAA/NAAA/NAABbOAAB^mAAAAAAIt,eAFzx7AJKQ1AK{^aAAAAAAA#cnAAAAAAAf7%AK,fNAAAAAAIr<JAF1rrAJHMsAK{^aAAAAAAA$E{AAA(vAAgkVAK.H8AAA(vABj?hAA$FBAAwU)AAML;AAA,(AAML;AAwU)AA#/uABkhiAC,'RAC,tUABkLAAA#dqAAvwZAByOBABkK;ABnp7ABpjGAAJ!UAIB;dAABWQABk?DABk>?ABm|6AAAAAACoH`ACx7NACn58AAADvAAD;<AAP.xAA3pOABD~PACX,uAEn8pADAKRAC~R+AARHaAAQe+AAP<*AAE0gAFb1P";

int get_ord(char ch) {
    int i=0; for (; i<366; i++) if (alphabet[i] == ch) break; return i;
}

int pow(int n, int e) { if (e <= 0) return 1; return n * pow(n, e-1); }

int main()
{
    ofstream f("arecibo.txt");

    for (int i=0; i < 365; i+=5) {
        int nr=0;
        for (int j=0; j < 5; j++)
            nr+=get_ord(data[i+4-j]) * pow(91, j);

        for (int j=22; j>=0; j--) {
            int bit = (nr >> j) & 1;
            f<<bit;
        }

        f<<endl;
    }

    return 0;
}
