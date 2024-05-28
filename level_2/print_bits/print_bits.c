#include <unistd.h>


// Commented solution
void print_bits(unsigned char octet)
{
    int i = 8; // Initialize a counter variable i to 8
    unsigned char bit = 0; // Initialize a variable bit to 0

    while (i--) // Loop through each bit of octet
    {
        bit = (octet >> i & 1) + 48; // Shift the bit of octet to the right i times and use the bitwise AND operator with 1 to get the bit value. Then add 48 to convert the bit value to its ASCII representation ('0' or '1')
        write (1, &bit, 1); // Write the ASCII representation of the bit to the standard output (stdout)
    }
}

// Bitwise AND Operator (&) in C

// Bitwise binary AND performs logical operation on the bits in each position of a number in its binary form.

// Assuming that the two int variables "a" and "b" have the values 60 (equivalent to 0011 1100 in binary) and 13 (equivalent to 0000 1101 in binary), the "a & b" operation results in 13, as per the bitwise ANDing of their corresponding bits illustrated below −

//   0011 1100  
// & 0000 1101 
//   --------- 
// = 0000 1100 

// The binary number 00001100 corresponds to 12 in decimal.


// The Right Shift (>>) Operator

// The right shift operator is represented by the >> symbol. It shifts each bit in its left-hand operand to the right by the number of positions indicated by the right-hand operand. Any blank spaces generated while shifting are filled up by zeroes.

// Assuming that the int variable a has the value 60 (equivalent to 0011 1100 in binary), the "a >> 2" operation results in 15, as per the bitwise right-shift of its corresponding bits illustrated below −

// 0011 1100 >> 2 = 0000 1111

// The binary number 00001111 corresponds to 15 in decimal.


// Example with octect set to 3

// 3 == 00000011 in binary
// 1 == 00000001 in binary

int main()
{
	unsigned char octet = 3;

	// First loop - i = 7
	unsigned char bit = 0;
	write(1,&bit,1);

	// Second loop
	bit = (octet >> 7 & 1) + 48;
	write(1,&bit,1);

	// Third loop
	bit = (octet >> 6 & 1) + 48;
	write(1,&bit,1);

	// Forth loop
	bit = (octet >> 5 & 1) + 48;
	write(1,&bit,1);

	// Fifth loop
	bit = (octet >> 4 & 1) + 48;
	write(1,&bit,1);

	// Sixth loop
	bit = (octet >> 3 & 1) + 48;
	write(1,&bit,1);

	// Seventh loop
	bit = (octet >> 2 & 1) + 48;
	write(1,&bit,1);

	// Eigth loop
	bit = (octet >> 1 & 1) + 48;
	write(1,&bit,1);

	// Ninth loop [0-7 loop with i var]
	bit = (octet >> 0 & 1) + 48;
	write(1,&bit,1);

	// print_bits(octet);
	write(1,"\n",1);
}