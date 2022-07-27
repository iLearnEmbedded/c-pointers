/*
Pointers can be interchangably used as arrays.
*/

#include <stdio.h>
#include <stdint.h>

uint32_t data[] = {0x12345678};
uint8_t * ptr_u8;
uint32_t * ptr_u32;
int main()
{
    ptr_u8  = (uint8_t *)data;
    ptr_u32 = data;
    for(int i=0;i<4;i++)
    {
        printf("ptr_u8[%d] = %02x \r\n",i,ptr_u8[i]);    
    }
    
    // pointer address display
    printf("ptr_u8   = %x\r\n",ptr_u8);
    printf("ptr_u8+1 = %x\r\n",ptr_u8+1);
    
    printf("ptr_u32   = %x\r\n",ptr_u32);
    printf("ptr_u32+1 = %x\r\n",ptr_u32+1);
    
    // pointer size display
    printf("sizeof(ptr_u8) = %d => %dbit machine\r\n",sizeof(ptr_u8),sizeof(ptr_u8)*8);
    printf("sizeof(ptr_u32) = %d => %dbit machine\r\n",sizeof(ptr_u32),sizeof(ptr_u32)*8);
    
    //endianness check through pointer
    uint16_t my_u16 = 0x0001;
    uint8_t * my_u8ptr = (uint8_t *)&my_u16;
    if(*(my_u8ptr) == 0x01)
    {
        printf("%04x: = %02x\r\n",my_u8ptr,(*(uint16_t *)my_u8ptr));
        printf("%04x: = %02x\r\n",my_u8ptr+1,(*(uint8_t *)(my_u8ptr+1)));
        printf("Little Endian : Difficult to read in memory window\r\n");
    }
    else
    {
        printf("%04x: = %02x\r\n",my_u8ptr,(*(uint16_t *)my_u8ptr));
        printf("%04x: = %02x\r\n",my_u8ptr+1,(*(uint8_t *)(my_u8ptr+1)));
        printf("Big Endian easy to read in memory window\r\n");
    }
    return 0;
}
