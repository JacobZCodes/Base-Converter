#include <stdio.h>
#include <stdlib.h>
#include <math.h> // pow func
#include <string.h> // strlen

int sizeNum = 1; // helper global var for findLength func


int findLength(int num) { 
    if (num / 10 == 0) {
        // Copy sizeNum to temp var and reset sizeNum to 1
        int size = sizeNum;
        sizeNum = 1;
        return size;
    }
    sizeNum++;
    findLength(num / 10);
}

int findBinaryLength(int num) { 
    int count = 0;
    while (1 == 1) {
        if (pow((double)2, (double)count) > num) {
            count--;
            break;
        }
        count++;
    }
    return count + 1;
}

char *hexAscii = "0123456789ABCDEF";
char getHexVal(int num) {
    return hexAscii[num];
    // switch(num) {
    //     case 10:
    //         return 'A';
    //     case 11:
    //         return 'B';
    //     case 12:
    //         return 'C';
    //     case 13:
    //         return 'D';
    //     case 14:
    //         return 'E';
    //     case 15:
    //         return 'F';
    //     default:
    //         return (num + 48);
    // }
}

int getDecVal (char hex) {
    switch(hex) {
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C':
            return 12;
        case 'D':
            return 13;
        case 'E':
            return 14;
        case 'F':
            return 15;
        default:
            return '?';
    }
}

char* decToHex(char* hex, int maxLength, int dec) {
    int length = findLength(dec);
    if (length > maxLength) {
        printf("ERROR - Num is too big\n");
        *hex = 0;
        return hex;
    }
    for (int i=1; i<length; ++i) {
        hex[length - (1 + i)] = getHexVal(dec % 16);
        dec /= 16;
    }
    return hex;
}

void decToOct(char* oct, int dec) {
    int length = findLength(dec);
    // oct = malloc(sizeof(int) * length);
    printf("len - %d\n", length);
    int i;
    for (i=0; i<length; ++i) {
        oct[length - (1 + i)] = (dec % 8) + 48;
        dec /= 8;
    }
    oct[i] = 0; 
    // for (int i=0; i<length; ++i) {
    //     printf("%d", oct[i]);
    // }
    // printf("\n");
    // free(oct);
}

void decToBin(char* bin, int dec) { // TO DO - Finish this
    int length = findBinaryLength(dec);
    for (int i=0; i<length; ++i) {
        bin[length - (1 + i)] = (dec % 2) + 48;
        dec /= 2;
    }
    for (int i=0; i<length; ++i) {
        printf("%d", bin[i]);
    }
    printf("\n");
    free(bin);
}

void hexToDec(char* hex) {
    int length = strlen(hex);
    int dec = 0;
    for (int i=0; i<length; i++) {
        int num = (int) hex[i] - 48;
        int multiplier = pow((double)16, (double) length-(i+1));
        dec += (num * multiplier);
    }
    printf("%d\n", dec);
}

void octToDec(char* oct) {
    int length = strlen(oct);
    int dec = 0;
    for (int i=0; i<length; i++) {
        int num = (int) oct[i] - 48;
        int multiplier = pow((double)8, (double) length-(i+1));
        dec += (num * multiplier);
    }
    printf("%d\n", dec);
}

void binToDec(char* bin) {
    int length = strlen(bin);
    int dec = 0;
    for (int i=0; i<length; i++) {
        int num = (int) bin[i] - 48;
        int multiplier = pow((double)2, (double) length-(i+1));
        dec += (num * multiplier);
    }
    printf("%d\n", dec);
}

// TO DO H->O, H->B, O->H, O->B, B->H, B->O
void hexToOctal(char* hex) {
    // H->D, D->O

}

void printCharArray(char* arr, int size) {
    for (int i=0; i<size; ++i) {
        printf("%c", arr[i]);
    }
    printf("\n");
}
int convertCharArray(char* charArray) { // TODO - fix sloppy variables
    int convertedNum = 0;
    int length = strlen(charArray);
    for (int i=0; i<length; ++i) {
        int newNum = charArray[i] - 48;
        int multiplier = pow((double) 10, (double) length-(i+1));
        convertedNum += newNum * pow((double) 10, (double) length-(i+1));
    }
    return convertedNum;
}
#define MAXLENGTH 40

void main() { // TO DO -- HAVE ALL FUNCS RETURN ARRAYS, ERRROR HANDLING, EXPAND CONVERSION POSSIBILITES (H->B, etc), TRUNCATE CONDITIONALS INTO HANDLE FUNCTIONS
    // while (1) {
    //     char initialType;
    //     char conversionType;
    //     char number[30];// arbitrary large size for a numerical value
    //     printf("Enter the base for your number (D,H,O,B): ");
    //     scanf(" %c", &initialType);
    //     if (initialType != 'D' && initialType != 'H' && initialType != 'O' && initialType != 'B') {
    //         printf("ERROR: Invalid base type\n");
    //         continue;
    //     }
    //     printf("Enter your number: ");
    //     scanf("%s", &number);
    //     printf("Enter the base to be converted to (D,H,O): ");
    //     scanf(" %c", &conversionType);
    //     if (conversionType != 'D' && conversionType != 'H' && conversionType !='O' && conversionType != 'B') {
    //         printf("ERROR: Invalid base type\n");
    //         continue;
    //     }

    //     // Converting to decimal
    //     if (initialType == 'H' && conversionType == 'D'){
    //         hexToDec(number);
    //     }
    //     else if (initialType == 'O' && conversionType == 'D'){
    //         octToDec(number);
    //     }
    //     else if (initialType == 'B' && conversionType == 'D') {
    //         binToDec(number);
    //     }
    //     // Converting from decimal
    //     if (initialType == 'D' && conversionType == 'H'){
    //         decToHex(convertCharArray(number));
    //     }
    //     else if (initialType == 'D' && conversionType == 'O'){
    //         decToOct(convertCharArray(number));
    //     }
    //     else if (initialType == 'D' && conversionType == 'B') {
    //         decToBin(convertCharArray(number));
    //     }

    // }
    // char* hex = decToHex(1560);
    // printCharArray(hex, hex[0]);
    // hex[4] = * * * * * * * ......* ->>>>> 42
                // 1 2 3 4 5 6 0
    // int test = 42    4 2
    char hex[MAXLENGTH];
    int test = 42;
    decToHex(hex,MAXLENGTH,123456);
    printf("%s\n", hex);
    printf("%d\n", test);

}
