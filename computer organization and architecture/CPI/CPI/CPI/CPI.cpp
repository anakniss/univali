// CPI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

string define_mnemonic(string opcode, bool special) {
    if (special) {
        if (opcode == "100000") {
            return "ADD";
        }
        else if (opcode == "100001") {
            return "ADDU";
        }
        else if (opcode == "100100") {
            return "AND";
        }
        else if (opcode == "011010") {
            return "DIV";
        }
        else if (opcode == "011011") {
            return "DIVU";
        }
        else if (opcode == "001001") {
            return "JALR";
        }
        else if (opcode == "001000") {
            return "JR";
        }
        else if (opcode == "010000") {
            return "MFHI";
        }
        else if (opcode == "010010") {
            return "MFLO";
        }
        else if (opcode == "010001") {
            return "MTHI";
        }
        else if (opcode == "010011") {
            return "MTLO";
        }
        else if (opcode == "011000") {
            return "MULT";
        }
        else if (opcode == "011001") {
            return "MULTU";
        }
        else if (opcode == "100111") {
            return "NOR";
        }
        else if (opcode == "100101") {
            return "OR";
        }
        else if (opcode == "000000") {
            return "SLL";
        }
        else if (opcode == "000100") {
            return "SLLV";
        }
        else if (opcode == "101010") {
            return "SLT";
        }
        else if (opcode == "101011") {
            return "SLTU";
        }
        else if (opcode == "000011") {
            return "SRA";
        }
        else if (opcode == "000111") {
            return "SRAV";
        }
        else if (opcode == "000010") {
            return "SRL";
        }
        else if (opcode == "000110") {
            return "SRLV";
        }
        else if (opcode == "100010") {
            return "SUB";
        }
        else if (opcode == "100011") {
            return "SUBU";
        }
        else if (opcode == "100110") {
            return "XOR";
        }
        else if (opcode == "001100") {
            return "SYSCALL";
        }
    }
    else {
        if (opcode == "100011") {
            return "LW";
        }
        else if (opcode == "101011") {
            return "SW";
        }
        else if (opcode == "101001") {
            return "SH";
        }
        else if (opcode == "101000") {
            return "SB";
        }
        else if (opcode == "100101") {
            return "LHU";
        }
        else if (opcode == "100001") {
            return "LH";
        }
        else if (opcode == "100100") {
            return "LBU";
        }
        else if (opcode == "100000") {
            return "LB";
        }
        else if (opcode == "001111") {
            return "LUI";
        }
        else if (opcode == "001000") {
            return "JR";
        }
        else if (opcode == "001001") {
            return "JALR";
        }
        else if (opcode == "000011") {
            return "JAL";
        }
        else if (opcode == "000010") {
            return "J";
        }
        else if (opcode == "000101") {
            return "BNE";
        }
        else if (opcode == "000110") {
            return "BLEZ";
        }
        else if (opcode == "000111") {
            return "BGTZ";
        }
        else if (opcode == "000100") {
            return "BEQ";
        }
        else if (opcode == "001001") {
            return "ADDIU";
        }
        else if (opcode == "001000") {
            return "ADDI";
        }
        else if (opcode == "001101") {
            return "ORI";
        }
        else if (opcode == "001010") {
            return "SLTI";
        }
    }
}

int calculate_cycles(string mnemonic) {
    if (mnemonic == "LBU" || mnemonic == "LW") {
        return 5;
    }
    else if (mnemonic == "MULTU") {
        return pow(65, 5);
    }
    else if (mnemonic == "DIVU") {
        return pow(65, 6);
    }
    else {
        return 4;
    }
}

struct InstructionsData {
    int numCycles;
    int count;
    bool isSpecial;
    string opcode;
};

int main()
{
    unordered_map<string, InstructionsData> instructions;
    string line, opcode, opcode_r, mnemonic;
    int numInstructions = 0;
    float cpi;

    ifstream fin("instructions.txt");

    if (!fin) {
        cout << "File cannot be opened";
    }

    while (getline(fin, line)) {
        opcode = line.substr(0, 6);

        // r-type instructions
        if(opcode == "000000") {
            opcode_r = line.substr(26, 6);
            mnemonic = define_mnemonic(opcode_r, 1);
            int cycles = calculate_cycles(mnemonic);
            if (instructions.find(mnemonic) == instructions.end()) {
                InstructionsData data{};
                data.numCycles = cycles;
                data.isSpecial = 1;
                data.count = 1;
                data.opcode = opcode_r;
                instructions[mnemonic] = data;
            }
            else {
                auto data = instructions[mnemonic];
                data.numCycles += cycles;
                data.count++;
                instructions[mnemonic] = data;
            }
        }
        else {
            mnemonic = define_mnemonic(opcode, 0);
            int cycles = calculate_cycles(mnemonic);
            if (instructions.find(mnemonic) == instructions.end()) {
                InstructionsData data{};
                data.numCycles = cycles;
                data.isSpecial = 0;
                data.count = 1;
                data.opcode = opcode;
                instructions[mnemonic] = data;
            }
            else {
                auto data = instructions[mnemonic];
                data.numCycles += cycles;
                data.count++;
                instructions[mnemonic] = data;
            }
        }      
    }

    int totalCycles = 0;
    for (auto& it : instructions) {
        cout << "OPCODE: " << it.second.opcode << endl;
        cout << "INSTRUCTION: " << it.first << endl;
        cout << "NUMBER OF CYCLES: " << it.second.numCycles << endl;
        cout << "OCCURRENCES: " << it.second.count << endl;
        cout << endl;
        totalCycles += it.second.numCycles;
        numInstructions += it.second.count;
    }

    cout << "-------------------------------" << endl;
    cpi = float(totalCycles) / numInstructions;
    cout << "Total of Cycles: " << totalCycles << endl;
    cout << "Number of Instructions: " << numInstructions << endl;
    cout << "CPI: " << cpi << endl;

    fin.close();

    return 0;
}
