#ifndef ENCODING_H
#define ENCODING_H

#include "../item.h"

#include <iosteam>
#include <string>
#include <sstream>
/*
Barcode scanners use a type of encoding called UPC-A also known as SLLLLLLMRRRRRRE
There is another type known as UPC-E that supports FAR less digits and it generally not accepted.
For this application I will be focusing on UPC-A but feel free and add UPC-E if needed. And i will
add it if there enough demand. 

The core bar spacing are called "Modules" each module can either be white or black or space or bar.
there is also a mandatory "Quiet Zone" that sits on either side of the actuall code that is 9 Modules
in width that is completely space. The mandatory bars are as follows:

The start and end bars are 3 modules wide and are used by the scanner to know where everything is.

>Quiet Zone
>Start Guard - Bar-Space-Bar 
>5 L numbers
>Middle Guard (5) - Space-Bar-Space-Bar-Space
>5 R numbers
End Guard - Bar Space Bar
*/

class barcode{
    public: 
        //This is where the item itself is added to either and Item or a temporary item.
        //This is mostly used to sync the physical item with the system
        void AddBarcodeToItem(item *i){ 
            std::stringsteam ss;

            for (unsigned i=0; i < 5; i++){
                ss << this->leftNum[i];
            }

            int numA;
            ss >> numA;
            i->barcodeA = static_cast <long> (numA);

            ss.str(std::string());

            for (unsigned i=0; i < 5; i++){
                ss << this->rightNum[i];
            }

            int numB;
            ss >> numB;

            i->barcodeB = static_cast <long> (numB) ;

        }
    private:
        int leftNum[5];
        int rightNum[5];

}

#endif // !1