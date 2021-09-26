// BitChange.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "BitChange.h"
#include <iostream>
#include <bitset>
#include<string>
#include<vector>
using std::bitset;
using std::string;
using std::cout;
using std::endl;
using std::vector;


int BitChange2() {
    const int num = 256;

    string bitString(num, '0');
    bitset<256> bits(bitString);
    
    cout << bits << endl;

    return 0;
}

int calculateInt(string bitString, int k) {
    int value = 0;
    for (int i = 0; i < 8; ++i) {
        value = value * 2 + bitString[k + i] - '0';
    }
    return value;
}

//二进制字符串转unsigned char*
void bitString2UChar(string bitString, unsigned char* out) {
    for (int k = 0; k < bitString.size() / 8; ++k) {
        int tempInt = calculateInt(bitString, k * 8);
        out[k] = (unsigned char)tempInt;
    }
}
vector<unsigned char*> BitChange() {
    const int num = 16;
    
    vector<unsigned char*> vec;
    string bits(num,'0');
    for (int i = 0; i < num;++i) { 
        bits[i] = '0';
    }
    bits[num] = '\0';
    for (int i = 0; i < num;++i) {
        bits[i] = '1';
        for (int j = i + 1; j < num;++j) {
            bits[j] = '1';
            cout << bits << endl;

            unsigned char *c=new unsigned char[num/8];
            bitString2UChar(bits, c);
            vec.push_back(c);

            bits[j] = '0';
        }
        bits[i] = '0';
    }
    return vec;
}



int main()
{
    vector<unsigned char*> vec=BitChange();
    for (int i = 0; i < vec.size(); ++i) {
        unsigned char* c = vec[i];
        for (int t = 0; t < 16/8; ++t) {
            printf("%02x", c[t]);
        }
        printf("\n");
    }
    //std::cout << "Hello World!\n";
}