


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

// 8bit
#define  Set_Bit(VAR,BIT)       ( VAR |= (1<<BIT))  // bit -> 1
#define  Clear_Bit(VAR,BIT)       ( VAR &= (~(1<<BIT))) // bit-> 0
#define  Tog_Bit(VAR,BIT)       ( VAR ^= (1<<BIT)) // bit 1->0  or  bit 0->1
#define  Get_Bit(VAR,BIT)       ( ( VAR >>BIT) & 1)

#define Set_Reg(REG)			(REG = 255) // port -> 1
#define Clr_Reg(REG)			(REG = 0)// port -> 0
#define Tog_Reg(REG)			(REG ^=255) // port 1->0  or  port 0->1




#endif /* BIT_MATH_H_ */