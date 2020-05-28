//
// Created by zhou on 2020/5/29.
//

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
    ofstream file0;
    ofstream file1;
    ofstream file2;
    ofstream file3;
    ofstream file4;
    ofstream file5;
    ofstream file6;

    file0.open("./array0");
    file1.open("./array1");
    file2.open("./array2");
    file3.open("./array3");
    file4.open("./array4");
    file5.open("./array5");

    file0<<"0\n";
    file1<<"1\n";
    file2<<"2\n";
    file3<<"3\n";
    file4<<"4\n";
    file5<<"5\n";

    srand(time(NULL));
	string size_ = argv[1];
    int size = stoi(size_);


    file0<<size;
    file1<<size;
    file2<<size;
    file3<<size;
    file4<<size;
    file5<<size;
    file0<<'\n';
    file1<<'\n';
    file2<<'\n';
    file3<<'\n';
    file4<<'\n';
    file5<<'\n';

    for(int i = 0; i<size; i++)
    {
        int temp = mrand48();
        file0<<temp;
        file1<<temp;
        file2<<temp;
        file3<<temp;
        file4<<temp;
        file5<<temp;
        file0<<'\n';
        file1<<'\n';
        file2<<'\n';
        file3<<'\n';
        file4<<'\n';
        file5<<'\n';
    }

    file1.close();
    file2.close();
    file3.close();
    file4.close();
    file5.close();
    file0.close();
    return 0;
}
