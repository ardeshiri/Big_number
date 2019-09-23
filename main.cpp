#include <iostream>
#include "Big_number.h"
using namespace std;

int main()
{
    Big_number bn{"146781412444424124991230142"};

    cout<< bn.str()<<endl;
    cout<< bn.size()<<endl;




    return 0;
}
