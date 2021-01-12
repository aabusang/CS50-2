#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./jpeg image\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 1;
    }

    unsigned char bytes[3];
    //read 3 bytes, read each byte only once, read it from a file
    // int chunks = fread(bytes, 3, 1, file);
    // printf("%i \n", chunks);
    fread(bytes, 3, 1, file);
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("Maybe jpeg\n");
    }
    else
    {
        printf("Not a jpeg\n");
    }
}