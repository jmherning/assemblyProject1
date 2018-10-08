//
//  theCPU.hpp
//  CPU_EMU
//
//  Created by Douglas Sorensen on 10/2/18.
//  Copyright © 2018 Douglas Sorensen. All rights reserved.
//

#ifndef theCPU_hpp
#define theCPU_hpp
#include "Memory.hpp"


#include <stdio.h>

namespace CPU {
  
    class TheCPU{
    public:
        const byte reservedAddress;
        const byte baseAddress;
        const byte addressCeiling;
        
    private:
        byte theProgramCounter;
        byte register0;
        byte register1;
        bool theOverFlowError;
        bool theUnderFlowError;
        bool signedMode;
        bool _halt;
        
        Memory* theMemory;
        
        //Functions
        const byte fetch();
        void decode(const byte& opCode);
        void halt();
        void add();
        void beep();
        void store();
        void print();
        
    public:
        //Constructors
        TheCPU(Memory* _theMemory);
        ~TheCPU(); //Destrcutor
        
        //Class Functions
        void reset();
        void run();
        
        
        
        
    };
}

#endif /* theCPU_hpp */
