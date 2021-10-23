#include <TXLib.h>
#include <stdio.h>
#include <assert.h>

void Fill_Array  (int data[], int size, int step);
void Print_Array (int data[], int size, const char title[]);
void Reverse (int data[], int size);

int main ()
    {
    int data [20] = {};

    Fill_Array  (data, 20, 1);
    Print_Array (data, 20, "Original massive");
    Reverse (data, 20);
    printf ("\n");
    Print_Array (data, 20, "After  reversing");
    printf ("\n");
    return 0;
    }

void Fill_Array (int data[], int size, int step)
    {
    for (int i = 0; i < size; i += step)
        {
        assert (0 <= i && i < size);
        data[i] = i;
        }
    }

void Reverse (int data[], int size)
    {
for (int i = 0; i < size/2; i ++)
        {
        int temp = data[size - i - 1];
        data[size - i - 1] = data[i];
        data[i] = temp;
        }
     }

void Print_Array (int data[], int size, const char title[])
    {
    $y; printf ("\n%s:  ", title);
    for (int i = 0; i < size; i ++)
        {
        $g; printf ("%02d", data[i]);
        $r; printf (",");
        }
    }

