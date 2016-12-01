#include <fstream>
using namespace std;

char data[] = "#MC#-%C'E+H5MML'######S##&3##&3##(3##*S#####S[S;C#/3W;S=aaaB####'##%####%##$a##B####SS[;C+#3W/?=aaaB####'&#%#&##%&#$a&#B#&##+$#''&#+&&#3#T&##&/##T&#&&#3'%#++&#'3&#'3$#++%#3'#&#&#/#+]S#+%##+2C#+:5>#J,BQ*$:#($>+($B+($3+0C#####1%##1KM81#-7##-##2C##b[#&C1#)#&#0#(3<C/;437+4+G+$('#$%'#$#'##5C#AB6;";

ofstream f("arecibo.txt");

int main()
{
    for (int i=0; i<sizeof(data)/sizeof(char)-1; i++) {
        int num = data[i]-35;

        for (int j=5-(i % 4 == 3); j>=0; j--)
            f<<((num >> j) & 1);

        if (i % 4 == 3)
            f<<endl;
    }
}
