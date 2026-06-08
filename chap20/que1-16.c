#include <stdio.h>

typedef __uint32_t DWORD;
typedef __uint16_t WORD;
typedef __uint8_t BYTE;

union regs{
    struct {
        DWORD EAX, EBX, ECX, EDX;
    } dword;
    struct {
        WORD AX, :16, BX, : 16, CX, : 16, DX;
    } word;

    struct {
        BYTE al, ah, :8, : 8, bl, bh, : 8, : 8, cl, ch, : 8, : 8, dl, dh;
    } byte;
};

int main(void)
{
    union regs r1 = { 0, 0, 0, 0};
    r1.dword.EAX = 0x12345678;
    r1.word.BX = 0xabcd;
    r1.byte.dl = 0x12;
    r1.byte.dh = 0xef;

    printf("EAX: %x, AX: %hx, al: %hx, ah: %hx\n", r1.dword.EAX, r1.word.AX, r1.byte.al, r1.byte.ah);
    printf("EBX: %x, BX: %hx, bl: %hx, bh: %hx\n", r1.dword.EBX, r1.word.BX, r1.byte.bl, r1.byte.bh);
    printf("ECX: %x, CX: %hx, cl: %hx, ch: %hx\n", r1.dword.ECX, r1.word.CX, r1.byte.cl, r1.byte.ch);
    printf("EDX: %x, DX: %hx, dl: %hx, dh: %hx\n", r1.dword.EDX, r1.word.DX, r1.byte.dl, r1.byte.dh);

    return 0;
}