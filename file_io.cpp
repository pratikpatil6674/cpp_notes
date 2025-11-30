#include "include.h"
#include <filesystem>
#include <fstream>

void raw_string_literals(){
    std::string name1{R"(abc\bfc\dfd\vdf)"}; // syntax to ignore escape characters: R"(myString)", cant handle quotations
    std::string name2{R"QUOT(abc"dfd")QUOT"}; // create custom delimters of max 16 chars to handle quotations e.g QUOT
}

void fs(){
    namespace fs = std::filesystem;

    // working dir
    fs::path wd(fs::current_path());
    print("Working dir is ", wd);
    wd /= "file_io.cpp"; // "/" is overloaded
    print("Working file is ", wd);

    // print contents of a directory
    fs::path p{"/home/pratik/Documents/cplusplus"}; // dir path
    fs::directory_iterator begin{p};
    fs::directory_iterator end{};
    while(begin != end){
        print(*begin);
        begin++;
    }

    // file name
    fs::path p1{"/home/pratik/Documents/cplusplus/file_io.cpp"}; // filepath
    if(p1.has_filename()){
        print(p1.filename());  //prints "file_io.cpp"
    }

}
void file_read(){
    std::ifstream input{"temp.txt"};
    if(!input.is_open()){
        print("Cannot open the file");
    }
    println("Current position is :", input.tellg()); // tellg is tell get pointer location
    std::string data;
    std::getline(input, data);
    println("Current position is :", input.tellg()); // tellg is tell get pointer location
    
    if(input.eof()){ // check eofbit
        input.clear(); // because seekg() cannot seek away from the end of stream
    }
    input.seekg(0, std::ios::beg); // three options for seeking: beg, cur, end. Use negative offset with end
    println("Now the position is :", input.tellg()); // tellg is tell get pointer location

    char ch{};
    while(input.get(ch)){
        print(ch);
    }
    println();

    input.close();
    println("Data read from file is : ", data);
}

void file_write(){
    std::ofstream output{"temp.txt"};
    output << "hello world! ";
    output << 10; 
    println("Now the position is :", output.tellp()); // tellp is tell put pointer location
    output.seekp(0,std::ios::beg);
    println("Now the position is :", output.tellp()); // tellp is tell put pointer location
    output << 3.14; // overwrite beginning chars
    output.close();
}

void binary_io(){
    struct Record
    {
        int age;
        char name[10];
    };

    std::ofstream binWrite{"records.mybin",std::ios::binary | std::ios::out};
    Record r1;
    r1.age = 23;
    strcpy(r1.name, "person");

    binWrite.write((const char*)&r1, sizeof(Record));
    binWrite.close(); //important

    std::ifstream binRead{"records.mybin",std::ios::binary | std::ios::in};

    Record r2;
    binRead.read((char*)&r2, sizeof(Record));
    println("Read from file: ", r2.age, r2.name);
    binRead.close();
}
int main(){
    // fs();
    // file_write();
    // file_read();
    binary_io();
}

/*
File stream objects can check stream state flags
| Flag    | Meaning                          | function    |
| ------- | -------------------------------- | ----------- |
| goodbit | no error                         | bool good() |
| badbit  | irrecoverable stream error       | bopol bad() |
| failbit | IO operation failed              | bool fail() |
| eofbit  | end of file reached during input | bool eof()  |

All these bits are set to true, except goodbit, which is set to false, when no more characters can be read from a file.
eof character is not added to binary files.
*/
