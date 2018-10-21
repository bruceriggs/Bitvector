#include "BitVector.h"
#include <cstring>
#include <iostream>
using std::cout;
// Constructor
BitVector::BitVector(const int numBits) {
    // How many bits we have
    this->numBits = numBits;

    // How many bytes cover this amount of bits?
    int charCount = bytesNeeded(numBits);

    // Allocate the chars
    bits = new char[charCount];

    // Everything starts out as 0
    memset(bits, 0, sizeof(char)*charCount);
}

// Destructor
BitVector::~BitVector() {
    // Delete any living bits
    if (bits != nullptr) {
        delete[] bits;
        bits = nullptr;
    }
    numBits = 0;
}

// Copy Constructor
BitVector::BitVector(const BitVector& rhs) {
    bits = nullptr;
    numBits = rhs.numBits;
    if (numBits > 0) {
        // Allocate
        bits = new char[bytesNeeded(numBits)];
        // Copy over the information
        memcpy(bits, rhs.bits, bytesNeeded(numBits));
    }
}

// Assignment Operator
BitVector& BitVector::operator=(const BitVector& rhs) {
    if (&rhs != this) {
        // Clear the old data
        if (bits != nullptr) {
            delete[] bits;
            bits = nullptr;
        }

        numBits = rhs.numBits;
        if (numBits > 0) {
            bits = new char[bytesNeeded(numBits)];
            // Copy over the information MANUALLY
            memcpy(bits, rhs.bits, bytesNeeded(numBits));
        }
    }
    return *this;
}

bool BitVector::get(const int index) const {
    // Which bool?
    int boolIndex = index / 8;
    // Which bit?
    int bitIndex = index % 8;
    // Return it
    return (bits[boolIndex] & (1 << bitIndex)) > 0;
}

void BitVector::set(const int index, const bool newValue) {
    // Only set if given a valid index
    if (index <= numBits - 1 && index >= 0) {
        // Determine which bool index
        int boolIndex = index / 8;
        // Determine which Bit index
        int bitIndex = index % 8;
        if (newValue) {
            // Turn on
            bits[boolIndex] |= (1 << bitIndex);
        }
        else {
            // Turn off
            bits[boolIndex] &= ~(1 << bitIndex);
        }
    }
}

int BitVector::bytesNeeded(const int numBits) const {
    return (numBits <= 8 ? 1 : (numBits % 8 == 0) ? numBits / 8 : (numBits / 8) + 1);
}

bool BitVector::operator[](const int index) const {
    // Don't validate the number, just crash if given a bad index
    int boolIndex = index / 8;
    int bitIndex = index % 8;
    return (bits[boolIndex] & (1 << bitIndex)) > 0;
}

/*BitVector::BitVectorHelper BitVector::operator[](const int index) {
// Don't safety check, just crash if given bad index
return BitVectorHelper(this, index);
}*/

void BitVector::setAll(const bool newValue) {
    // How many bytes cover this amount of bits?
    int charCount = bytesNeeded(numBits);

    // Everything starts out as 0
    memset(bits, (newValue ? 255 : 0), sizeof(char)*charCount);
}

void BitVector::resize(int newNumBits) {
    // Different amount of bytes?
    if (bytesNeeded(numBits) != bytesNeeded(newNumBits)) {
        int bytesToCopy = (bytesNeeded(numBits) < bytesNeeded(newNumBits) ? numBits : newNumBits);
        // Allocate the new array
        char* newBits = new char[bytesNeeded(newNumBits)];
        // Zero out the new memory
        memset(newBits, 0, bytesNeeded(newNumBits));
        //memcpy(newBits, bits, bytesNeeded(bytesToCopy));
        // Old amount used every single bit?
        if (numBits % 8 == 0) {
            // Copy over the old bytes
            memcpy(newBits, bits, bytesNeeded(bytesToCopy));
        }
        // Old amount only used SOME bits
        else {
            // Manually copy over old bits
            int boolIndex, bitIndex;
            for (int ii = 0; ii < numBits; ++ii) {
                // Which bool?
                boolIndex = ii / 8;
                // Which bit?
                bitIndex = ii % 8;
                if ((bits[boolIndex] & (1 << bitIndex)) > 0) {
                    // Turn on
                    newBits[boolIndex] |= (1 << bitIndex);
                }
                else {
                    // Turn off
                    newBits[boolIndex] &= ~(1 << bitIndex);
                }
            }
        }
        // Delete the old
        delete[] bits;
        bits = newBits;
    }
    numBits = newNumBits;
}