#include <iostream>
#include <fstream>
#include <string>

int main(){
    int b = 2531011;

    std::ifstream input_file;
    input_file.open("./english.seria_enc", std::ios::in | std::ios::binary);
    std::ofstream output_file;
    output_file.open("./english.txt", std::ios::out);
    char tmp;

    while (input_file.read(&tmp,1)){
        output_file<<(char)( (b ^ (b >> 15) ^ tmp) & 0xff);
        b += 214013;
    }

    input_file.close();
    output_file.close();

    return 0;
}