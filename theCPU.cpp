//
//  theCPU.cpp
//  CPU_EMU
//
//  Created by Douglas Sorensen on 10/2/18.
//  Copyright © 2018 Douglas Sorensen. All rights reserved.
//

#include "theCPU.hpp"
#include <iostream>

namespace CPU {
    
    //Constructors
    TheCPU::TheCPU(Memory* _theMemory):reservedAddress(0),baseAddress(1),addressCeiling(253),theProgramCounter(0), register0(0), register1(0),theOverFlowError(false),theUnderFlowError(false),signedMode(false), theMemory(_theMemory),_halt(false){
        
    }
    //Destrcutor
    TheCPU::~TheCPU(){
        theMemory = nullptr;
    }
    //Functions
    void TheCPU::reset(){
        _halt = false;
        theProgramCounter = baseAddress;
        theOverFlowError = false;
        theUnderFlowError = false;
        signedMode = false;
    }
    
    const byte TheCPU::fetch(){
        byte l_opcode = 0;
        l_opcode = theMemory->read(theProgramCounter);
        ++theProgramCounter;
        if(theProgramCounter > addressCeiling){
            halt();
        }
        return l_opcode;
    }
    
    void TheCPU::halt(){
        _halt = true;
    }
    
    void TheCPU::add(){
        register0 = register0 + register1;
    }
    
    void TheCPU::beep(){
        std::cout << '\a';
    }
    
    void TheCPU::store(){
        //Loads the target address into register 1
        register1 = theMemory->read(theProgramCounter);
        ++theProgramCounter; //Skip memeory location
        //Write the register 0
        theMemory->write(register1, register0);
        //Address then value
    }
    
    void TheCPU::print(){
        //Load address into register 1
        register1 = theMemory->read(theProgramCounter);
        ++theProgramCounter;
        //The value in the register is now the value to load
        register0 = theMemory->read(register1);
        std::cout << (int)register0 << std::endl; //Output
        
        
    }
    
    void TheCPU::decode(const byte& opCode){
       
        if(_halt) return; //Incase the system is pre-halted
        
        switch(opCode){
            //Halt
            case 0:
                halt();
                break;
            //Load 1
            case 1:
                register0 = theMemory->read(theProgramCounter);
                ++theProgramCounter;
                break;
            //Load 2
            case 2:
                register1 = theMemory->read(theProgramCounter);
                ++theProgramCounter; //Skips past the data
                break;
            //Add
            case 3:
                add();
                break;
            //Beep
            case 4:
                beep();
                break;
            //Store
            case 5:
                store();
                break;
            //print operation
            case 6:
                print();
                break;
                
        }
    }
    
    void TheCPU::run(){
        //While nothing is stoping us, keep chugging along
        while(!_halt){
            theMemory->write(reservedAddress, fetch());//Fetchs into the resersved memory
            decode(theMemory->read(reservedAddress)); //Decodes from the reserved memory
            
        }
        
    }
}
