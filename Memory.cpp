//
//  Memmory.cpp
//  CPU_EMU
//
//  Created by Douglas Sorensen on 10/2/18.
//  Copyright © 2018 Douglas Sorensen. All rights reserved.
//

#include "Memory.hpp"

namespace CPU {
    //Default constructor
    Memory::Memory():theMaxAddress(255), theMemmorySpace(new byte[theMaxAddress]){
        clear(); //Clears memory
    }
    //Destructor
    Memory::~Memory(){
        if(theMemmorySpace != nullptr){
            delete [] theMemmorySpace;
            theMemmorySpace = nullptr;
        }
    }
    
    void Memory::clear(){
        //Sets all memory values to zero;
        for (byte i = 0; i < theMaxAddress; ++i){
            theMemmorySpace[i] = 0;
        }
    }
    
    const byte& Memory::read(const byte& theAddress){
        // Reads the given address
        return theMemmorySpace[theAddress];
    }
    
    void Memory::write(const byte& theAddress, const byte& theValue){
        // Writes the value to th given address
        theMemmorySpace[theAddress] = theValue;
    }
}
