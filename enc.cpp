#include <iostream>
#include <fstream>
#include <string>

int main(){
    int b = 2531011;

    std::ifstream input_file;
    input_file.open("./english.txt", std::ios::in);
    std::ofstream output_file;
    output_file.open("./english-mod.seria_enc", std::ios::out | std::ios::binary);
    char tmp;

    while (input_file.read(&tmp,1)){
        char a = ((b ^ (b >> 15) ^ tmp) & 0xff);
        output_file.write(&a,1);
        b += 214013;
    }

    input_file.close();
    output_file.close();

    return 0;
}