/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
//1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    // (~x & y) | (x & ~y)
    // double negate then apply De Morgan's laws
    return ~( ~(~x & y) & ~(x & ~y) );
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    // 100...0
    return (1 << 31);
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    // Tmax        011...11
    // Tmax+1=Tmin 100...00
    // Tmax^Tmin   111...11
    //  (~111...1) 000...00
    // !(~111...1) 000...01
    int allones = !(~(x ^ (x + 1)));

    // both Tmax and -1 return 1 for allones
    // check if x is not -1
    int not_neg_one = !!(x + 1);

    return allones & not_neg_one;
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    // mask x with 0xAAAAAAAA to extract all odd-numbered bits in x
    // check if masked x is equal to mask
    int mask = 0xAA;
    mask = (mask << 8) | 0xAA;
    mask = (mask << 8) | 0xAA;
    mask = (mask << 8) | 0xAA;
    // mask is now 0xAAAAAAAA
    return !((x & mask) ^ mask);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    // see lecture
    // negate(Tmin) = Tmin because of overflow
    return ~x + 1;
}
//3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    // get all numbers in the format 0x0000003x
    int starts_with_03 = !((x >> 4) ^ 0x3);

    // check if lowest 4 bits == 0 to catch 0 to 7
    int bit3_zero = (x >> 3) ^ 1;

    // check if bit2 and bit1 are 00 to catch 8 and 9
    int bit2and1_zeros = ((x >> 2) ^ 1) & ((x >> 1) ^ 1);

    return starts_with_03 & (bit3_zero | (bit2and1_zeros));
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    // mask_y = 111...1 if x else 000...0
    int mask_y = ~((!x) << 31 >> 31);

    // mask_z = 000...0 if x else 111...1
    int mask_z = ~mask_y;

    return (y & mask_y) | (z & mask_z);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    // x == y
    int eq = !(x ^ y);

    // extract sign bits
    int sign_x = (x >> 31) & 1;
    int sign_y = (y >> 31) & 1;

    // if x is -ve and y is +ve, always x < y
    int neg_pos = sign_x & (!sign_y);

    // if x is +ve and y is -ve, always x > y
    int pos_neg = (!sign_x) & sign_y;

    // x < y, x - y < 0
    int minus = ((x + (~y) + 1) >> 31) & 1;

    return eq | ((!pos_neg) & (neg_pos | minus));
}
//4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
    // only x is 0 such that sign bit of (x | negate(x)) is 0
    // for all other values, sign bit is 1
    // (1 >> 31) + 1 = 111...1 + 1 = 000...0
    return ((x | (~(x) + 1)) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    // find highbit (leftmost bit that == 1)
    int mask = x >> 31;
    int bit16, bit8, bit4, bit2, bit1, bit0;

    // flip x if x < 0
    x = (x & ~(mask)) | (~x & mask);

    // cut x into two halves
    // if highbit is in first half, cut first half into two halves
    // vice versa
    // repeat until x has 1 bit left
    bit16 = !!(x >> 16) << 4;
    x >>= bit16;
    bit8 = !!(x >> 8) << 3;
    x >>= bit8;
    bit4 = !!(x >> 4) << 2;
    x >>= bit4;
    bit2 = !!(x >> 2) << 1;
    x >>= bit2;
    bit1 = !!(x >> 1);
    x >>= bit1;
    bit0 = x;

    // add 1 to highbit for sign bit
    return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
}
//float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    int sign = (uf >> 31);
    int exp = (uf >> 23) & 0xFF;
    int frac = (uf << 9) >> 9;

    // exp == 111...1
    if (!(exp ^ 0xFF)) {
        // NaN or +-inf
        return uf;
    }

    // exp == 000...0
    if (!exp) {
        // denorm
        // multiply frac by 2
        return (sign << 31) | (frac << 1);
    }

    // normal
    // add 1 to exp
    return (sign << 31) | ((exp + 1) << 23) | (frac);
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    int sign = (uf >> 31);
    int exp = (uf >> 23) & 0xFF;
    // int frac = (uf << 9) >> 9;
    int power = exp - 127;

    // exp == 111...1
    if (!(exp ^ 0xFF)) {
        // NaN or +-inf
        return 1 << 31;
    }

    // exp == 000...0
    if (!exp) {
        // denorm
        return 0;
    }

    // normal
    // if power < 0, abs( (int)f ) < 1, return 0;
    if (power < 0) {
        return 0;
    }

    // prevent 1 << (power % 32) by compiler
    if (power > 31) {
        power = 31;
    }

    if (sign) {
        return ~(1 << power) + 1;
    }
    return 1 << power;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    int exp = x + 127;
    if (exp >= 255) {
        // 2.0^x is too big, return +inf
        return 0x7F800000;
    }
    if (exp <= 0) {
        // 2.0^x is too small, return 0
        return 0;

    }
    return exp << 23;
}
