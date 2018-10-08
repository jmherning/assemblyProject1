//
//  main.cpp
//  CPU_EMU
//
//  Created by Douglas Sorensen on 10/2/18.
//  Copyright © 2018 Douglas Sorensen. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;
#include "Memory.hpp"
#include "theCPU.hpp"
using namespace CPU;

int main() {
    
    cout << "Init Memory...";
    Memory* _theMemory = new Memory();
    
    cout << "Ready" << endl;
    //Prints out the size of memory by changing "byte" to an int so cout can read it
    cout << "Memory Size: " << (int)_theMemory->theMaxAddress << endl;
    
    cout << "Adding default maching code program..." << endl;
    //load0 value 1
    _theMemory->write(1, 1);
    _theMemory->write(2, 1);
    
    //load value 2
    _theMemory->write(3, 2);
    _theMemory->write(4, 2);
    
    //Add
    _theMemory->write(5, 3);
    
    //store from 12
    _theMemory->write(6, 5);
    _theMemory->write(7, 12);
    
    //print from 12
    _theMemory->write(8, 6);
    _theMemory->write(9, 12);
    
    //Beep
    _theMemory->write(10, 4);
    
    //Halt
    _theMemory->write(11, 0);
    
    
    //Change this to a yes or no string later
    cout << "Do you want to list the memory? Y/N: ";
    char yesNo;
    std::cin >> yesNo;
    if(yesNo == 'Y' || yesNo == 'y'){
        for(byte  currentAddress = 0; currentAddress < _theMemory->theMaxAddress; ++currentAddress){
            //Use int so cout can understand the "byte"
            cout << "Address ["<< (int)currentAddress << "] = " << (int)_theMemory->read(currentAddress) << endl;
        }
    }
    
    cout << "Creating the CPU...";
    TheCPU* _theCPU = new TheCPU(_theMemory);
    cout << "Ready" << endl;
    
    cout << "Starting..." << endl;
    _theCPU->run();
    cout << "Complete" << endl;
    
    delete _theCPU; //Delete CPU first becuase it uses theMemory
    delete _theMemory;
//    return 0;
}
