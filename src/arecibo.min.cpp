#include <fstream>
char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+,./:;<=>?@[]^_`{|}~'";
char d[] = "AAKusAB([;AF`ZTAHmdqAAAAAAAAQ@AAA/NAAA/NAABbOAAB^mAAAAAAIt,eAFzx7AJKQ1AK{^aAAAAAAA#cnAAAAAAAf7%AK,fNAAAAAAIr<JAF1rrAJHMsAK{^aAAAAAAA$E{AAA(vAAgkVAK.H8AAA(vABj?hAA$FBAAwU)AAML;AAA,(AAML;AAwU)AA#/uABkhiAC,'RAC,tUABkLAAA#dqAAvwZAByOBABkK;ABnp7ABpjGAAJ!UAIB;dAABWQABk?DABk>?ABm|6AAAAAACoH`ACx7NACn58AAADvAAD;<AAP.xAA3pOABD~PACX,uAEn8pADAKRAC~R+AARHaAAQe+AAP<*AAE0gAFb1P";

int p(int n,int e){if(e<=0)return 1;return n*p(n, e-1);}
int i,j,k,nr;
int main()
{
    std::ofstream f("arecibo.txt");

    for (;i<365;i+=5) {
        nr=0;
        for (j=0;j<5;j++) {
            for (k=0;k<366;k++)if(a[k]==d[i+4-j])break;
            nr+=k*p(91, j);
        }

        for (j=22;j>=0;j--)f<<(nr>>j&1);
        f<<'\n';
    }

    return 0;
}
