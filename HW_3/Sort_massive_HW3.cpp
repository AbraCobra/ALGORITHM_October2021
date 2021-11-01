#include <stdio.h>
#include <TXLib.h>
#include <vector>
#include <time.h>

#define  SIZE  10

#define ORIGIN_X  40
#define ORIGIN_Y  150
#define GapX      50
#define GapY      50

void Fill_Array        (int data[],  int step);
void Input_Array       (int data[]);
bool Check_Order       (int data[]);
void Control_Array     (int data[]);
void Draw_Blocks       (int data[], int y, COLORREF color_cube1, COLORREF color_cube2);
void Print_Array       (int data[], const char title[]);

void Choise_sort_Array (int data[], int y);
void Bubble_sort_Array (int data[], int y);
void Bubble_sort_Array_Original (int data[SIZE], int y);

int main()
    {
    int data [SIZE] = {};
    txCreateWindow (1000, 800);

    Fill_Array  (data, 1);
    Print_Array (data, " Original massive ");

    //Choise_sort_Array   (data, 170);
    //Bubble_sort_Array   (data, 220);
    Bubble_sort_Array_Original (data, 250);
    Print_Array (data, " Sorted   massive ");
    Control_Array (data);
    return 0;
    }

//======================================================

void Fill_Array (int data[SIZE], int step)
    {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i += step)
        {
        assert (0 <= i && i < SIZE);
        data[i] = rand()%15 + 7;
        }
    }

//======================================================

void Input_Array (int data[])
    {
    for (int i  = 0; i < SIZE; i ++)
        {
        assert (0 <= i && i < SIZE);
        int x = 0;
        scanf ("%d ", &x);
        data [i] = x;
        }
    }

//======================================================

bool Check_Order (int data[])
    {
    int i = 0;
    for (int i = 0; i < SIZE; i++)
        {
        assert (0 <= i     &&     i < SIZE);

        if (data[i] > data[i + 1]) return  false;

        }
    return true;
    }

//======================================================

void Control_Array (int data[])
    {
    if (Check_Order (data) == 1) printf ("Ascending!\n");
    else printf ("Not ascending!\n");
    }

//======================================================

 void Draw_Blocks (int data[SIZE], int y, COLORREF color_cube1, COLORREF color_cube2)
    {
    int x = 40;

    for (int i = 0; i < SIZE; i++)
        {
        if(data[i] <= data[i + 1])
            {
            txSetColor     (color_cube2, 3);
            txSetFillColor (color_cube1);
            }
        else
            {
            txSetColor     (color_cube1, 3);
            txSetFillColor (color_cube2);
            }
        txSelectFont   ("Times", 30, 9);
        txRectangle    (x, y, x + 35, y + 30);

        char str [10] = "";
        sprintf        (str, "%2d ", data[i]);
        txSetColor     (RGB (0, 0, 0),3);
        txSetFillColor (RGB (100, 10, 100));
        txTextOut      (x + 5, y + 2, str);

        x += GapX;
        }
    y += GapY;
    }

//======================================================

void Print_Array (int data[], const char title[])
    {
    $y; printf ("\n%s: ", title);

    for (int i = 0; i < SIZE; i ++)
            {
            assert (0 <= i && i < SIZE);
            if(data[i] <= data[i + 1])
                {
                $c; printf ("[%2d] = ", i);
                $g; printf ("%3d", data[i]);
                }
            else
                {
                $c; printf ("[%2d] = ", i);
                $y; printf("%2d ", data [i]);}
            if (i < SIZE - 1) {$c; printf (", ");}
            }

    printf ("\n");
    }

//======================================================

void Choise_sort_Array (int data[SIZE], int y)
    {
    for (int i = 0;  i < SIZE - 1;  i ++)
        {
        y += 50;
        for (int j = i + 1; j < SIZE; j++)
            {
            if (data[j] < data[i])
                {
                int tmp = data[j];
                data[j] = data[i];
                data[i] = tmp;
                }
            }
        Draw_Blocks (data, y, RGB ( 0, 204, 153), RGB ( 255, 255, 102));
        }
    printf ("\n");
    }

//======================================================

void Bubble_sort_Array (int data[SIZE], int y)
    {
    bool sorted_flag = false;
    int pass_counter = 0;

    while (not sorted_flag)
        {
        sorted_flag = true;

        for (int i = 0; i < (SIZE - 1) - pass_counter; ++ i)
            {
            y += 50;
            if (data[i] > data[i + 1])
                {
                int tmp = data [i + 1];
                data[i + 1] = data[i];
                data[i] = tmp;
                //std::swap (data[i], data[i + 1]);
                sorted_flag = false;
                }
            Draw_Blocks (data, y, RGB( 255, 120, 100), RGB( 10, 128, 10));
            }
        pass_counter += 1;
        printf ("\n");
        }
    }

void Bubble_sort_Array_Original (int data[SIZE], int y)
    {
    for (int i = 0; i < SIZE - 1; i ++)
        {
        y += 50;
        for (int j = SIZE - 2; j >= i; j --)
            {
            if (data[j] > data [j + 1])
                {
                int tmp = data[j];
                data[j] = data [j + 1];
                data [j + 1] = tmp;
                }
            }
        Draw_Blocks (data, y, RGB( 102, 255, 100), RGB(204, 102, 255));
        }
    printf ("\n");
    }
