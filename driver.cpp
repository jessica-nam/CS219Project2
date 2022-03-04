/**
    CS 219 Section 1001 Programming Project 2
    @file driver.cpp
    @author Jessica Nam
    @version 2.0 3/3/2022
*/
#include <iostream>
#include <sstream> //string stream
#include <fstream> //input file stream
#include <cstdint> //for the unsigned type uint32_t

using namespace std;

int main(){

        ifstream file;
        char temp;

        cout<< "Please enter the text file: ";
	string textfile;
        cin>> textfile; // user inputs name of text file they would like to test
        cout<< endl;

        file.open(textfile); // opens the file

        if(file){

                while(file.good()){
                        stringstream ss1, ss2;

			string num;
			uint32_t num1;
			uint32_t num2;
			uint32_t sum;
			uint32_t andval;
			uint32_t asr; // The challenge is to trick C into doing an ASR on a uint32_t. When C does a right shift on a signed type, it does ASR.
			uint32_t lsr; // When C does a right shift (>> operator) on an unsigned type, it does LSR. 
			uint32_t lsl;
			uint32_t notval;
			uint32_t orr;
			uint32_t sub;
			uint32_t xorval;
			string command; // ADD

			// file format
                        file >> command >> temp >> temp >> num;
                        ss1 << hex << num;
			ss1 >> num1;
                        file >> temp >> temp >> num;
                    	ss2 << hex << num;
			ss2 >> num2;

                        if(command == "ADD"){ // Read ADD function from file
                                sum = num1 + num2;
                                cout<< "The sum of 0x" << num1 << " + 0x" << num2 << " = 0x" << hex << sum << endl;
                        }
			if(command == "AND"){
				andval = num1 & num2;
				cout<< "The bitwise AND of the operands 0x" << num1 << " AND 0x" << num2 << " = 0x" << hex << andval << endl;
			}
			if(command == "ASR"){
				asr = num1>>1;
				cout<< "The 1-bit arithmetic shift right on the first operand 0x" << num1 << " is = 0x" << hex << asr << endl;
			}
			if(command == "LSR"){
				asr = num1>>1;
				cout<< "The 1-bit logical shift right on the first operand 0x" << num1 << " is = 0x" << hex << lsr << endl;
			}
			if(command == "LSL"){
				lsl = num1<<1;
				cout<< "The 1-bit logical shift left on the first operand 0x" << num1 << " is = 0x" << hex << lsl << endl;
			}
			if(command == "NOT"){
				notval = !num1;
				cout<< "The bitwise NOT of the first operand 0x" << num1 << " is = 0x" << hex << notval << endl;
			}
			if(command == "ORR"){
				orr = num1||num2;
				cout<< "The bitwise ORR of the operands 0x" << num1 << " and  " << num2 << " is = 0x" << hex << orr << endl;
			}
			if(command == "SUB"){
				sub = num1 - num2;
				cout<< "Subtracting the second operand 0x" << num2 << " from the first operand 0x" << num1 << " is = 0x" << hex << sub << endl;
			}
			if(command == "XOR"){
				xorval = num1^num2;
				cout<< "The bitwise XOR of the operands 0x" << num1 << " and  " << num2 << " is = 0x" << hex << xorval << endl;
			}
				
                }

                file.close();   
        }
        else{
		// if filename is incorrect or nonexistent 
                cout<< "\nFile does not exist!!!" << endl; 
        }

        return 0;

}
