#include <TXLib.h>
#include <stdio.h>
#include <assert.h>

void Fill_Array  (int data[], int size, int step);
void Print_Array (int data[], int size, const char title[]);
void Interchange (int data[], int size, int step);

int main ()
    {
    int data [20] = {};

    Fill_Array  (data, 20, 1);
    Print_Array (data, 20, "Original massive");
    Interchange (data, 20, 1);
    Print_Array (data, 20, " After  changing");

    printf ("\n");
    return 0;
    }

void Fill_Array (int data[], int size, int step)
    {
    for (int i = 0; i < size; i += step)
        {
        assert (0 <= i && i < size);
        data[i] = rand()/((float)RAND_MAX)*100 + i;
        }
    }

void Interchange (int data[], int size, int step)
    {
    int separator = size/2;
    for (int i = 0; i < separator; i ++)
        {
        assert (0 <= i && i < size);

        int temp = data [i + separator];
        data[i + separator] = data [i];
        data [i] = temp;
        }
    }

void Print_Array (int data[], int size, const char title[])
    {
    $y; printf ("\n%s:  ", title);

    for (int i = 0; i < size; i ++)
        {
        $g; printf ("%2d", data[i]);
        $r; printf (",");
        }
    }

