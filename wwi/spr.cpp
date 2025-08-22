#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main ()
{
        int i=0;
        while (true)
        {
                i++;
                cout<<i<<endl;
                system(("echo " + to_string(i) + " | ./gen > test.txt").c_str());

                system("./test < test.txt > odp.txt");
                system("./brut < test.txt > good.txt");

                cout<< system("diff odp.txt good.txt");

        }
}
