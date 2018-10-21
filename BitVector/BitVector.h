#ifndef BITVECTOR_H_
#define BITVECTOR_H_

class BitVector {
private:
    // Members
    int numBits;
    char* bits;

    // Helper functions
    int bytesNeeded(int numBits) const;

public:

    class BitVectorHelper {
    private:
        BitVector* spawner;
        int index;
        BitVectorHelper& operator=(const BitVectorHelper& rhs) { return *this; }
    public:
        BitVectorHelper(BitVector* theSpawner, int theIndex) { spawner = theSpawner; index = theIndex; }
        void operator=(bool value) { spawner->set(index, value); }
    };

    // Constructor
    BitVector(const int numBits = 8);
    // Destructor
    ~BitVector();
    // Copy Constructor
    BitVector(const BitVector& rhs);
    // Assignment Operator
    BitVector& operator=(const BitVector& rhs);

    // Returns the number of bits the vector has
    inline int size() const { return numBits; }

    // Sets all bools to the passed in value
    void setAll(const bool newValue);

    // Resizes the vector to have enough bytes for the passed in bool amount
    void resize(int newNumBits);


    // Easy Access
    bool get(const int index) const;
    void set(const int index, const bool newValue);

    // Can only have 1 function out of these 2 following functions...
    bool operator[](const int index) const; // Doesn't work (getter)
                                            //BitVectorHelper operator[](const int index); // Works (setter)
};


#endif // BITVECTOR_H_
