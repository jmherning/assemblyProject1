//
//  Memmory.hpp
//  CPU_EMU
//
//  Created by Douglas Sorensen on 10/2/18.
//  Copyright © 2018 Douglas Sorensen. All rights reserved.
//

#ifndef Memory_hpp
#define Memory_hpp

#include <stdio.h>

namespace CPU {
    
    typedef unsigned char byte;
    
    class Memory{
    public:
        const byte theMaxAddress; //The maximum address we can read and write from
        
    private:
        
        byte* theMemmorySpace; //Memory space being used
   
    public:
        //Constructors
        Memory(); //Default constructor
        ~Memory(); //Destructor
        
        //Functions of the Class
        void clear();  //Sets all memory values to zero;
        const byte& read(const byte& theAddress); // Reads the given address
        void write(const byte& theAddress, const byte& theValue); // Writes the value to th given address
        
        
    
    };
}

#endif /* Memmory_hpp */
