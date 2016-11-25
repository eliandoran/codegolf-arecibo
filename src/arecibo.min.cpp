#include <fstream>
using namespace std;

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+,./:;<=>?@[]^_`{|}~'";

char data[] = "AAKusAB([;AF`ZTAHmdqAAAAAAAAQ@AAA/NAAA/NAABbOAAB^mAAAAAAIt,eAFzx7AJKQ1AK{^aAAAAAAA#cnAAAAAAAf7%AK,fNAAAAAAIr<JAF1rrAJHMsAK{^aAAAAAAA$E{AAA(vAAgkVAK.H8AAA(vABj?hAA$FBAAwU)AAML;AAA,(AAML;AAwU)AA#/uABkhiAC,'RAC,tUABkLAAA#dqAAvwZAByOBABkK;ABnp7ABpjGAAJ!UAIB;dAABWQABk?DABk>?ABm|6AAAAAACoH`ACx7NACn58AAADvAAD;<AAP.xAA3pOABD~PACX,uAEn8pADAKRAC~R+AARHaAAQe+AAP<*AAE0gAFb1P";

int pow(int n, int e) { if (e <= 0) return 1; return n * pow(n, e-1); }

int i,j,k,nr;
int main()
{
    ofstream f("arecibo.txt");

    for (i=0; i < 365; i+=5) {
        nr=0;
        for (j=0; j < 5; j++) {
            for (k=0; k<366; k++) if (alphabet[k] == data[i+4-j]) break;
            nr+=k * pow(91, j);
        }

        for (j=22; j>=0; j--) f<<(nr >> j & 1);
        f<<endl;
    }

    return 0;
}
