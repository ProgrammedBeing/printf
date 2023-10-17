#include <stdio.h>
#include <unistd.h>
/**
 * _putchar - Writes the character to output
 * @c: Character
 *
 * Return: If succesful, 1 else 0.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}
