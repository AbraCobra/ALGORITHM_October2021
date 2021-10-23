#include <TXLib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void Fill_Array  (int data[], int size, int step);
void Print_Array (int data[], int size, const char title[]);
int Maximum (int data[], int size);
int Index_Minimum (int data[], int size);


int main ()
    {
    int data [20] = {};

    Fill_Array  (data, 20, 1);
    Print_Array (data, 20, "Maximum element and index of minimum element");

    return 0;
    }

void Fill_Array (int data[], int size, int step)
    {
    //srand(time(NULL));
    for (int i = 0; i < size; i += step)
        {
        assert (0 <= i && i < size);
        data[i] = rand()%RAND_MAX;
        }
    }

void Print_Array (int data[], int size, const char title[])
    {
    $y; printf ("\n%s", title);
    for (int i = 0; i < size; i ++)
            {
            $c; printf ("\n[%2d] =", i);
            $g; printf ("%8d", data[i]);
            if (i < size - 1) {$c; printf (", ");}
            }
    $r; printf ("\n value of maximum element   - %8d ",  (Maximum       (data, size)));
    $c; printf ("\n index of minimum element   - [%2d]", (Index_Minimum (data, size)));
    printf ("\n");
    }

int Maximum (int data[], int size)
    {
    int maxx = data[0];
    for (int i = 0; i < size; i++)
        {
        if (data[i] > maxx) maxx = data[i];
        }
    return maxx;
    }

int Index_Minimum (int data[], int size)
    {
    int minn = Maximum (data, size) ;
    int index = 0;
    for (int i = 0; i < size; i++)
        {
        if (data[i] < minn)
            {
            minn = data[i];
            index = i;
            }
        }
    return index;
    }
