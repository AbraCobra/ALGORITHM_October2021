//==================================================================================//
//                ***Programm of visualization some sortings***                     //
//                                                                                  //
//                 Abramova Irina       2022, gym.36 Krasnodar                      //
//==================================================================================//
#include "TXLib.h"
#include "Sortings.h"

struct Grid
    {
    int left_edgeX;
    int left_edgeY;
    int right_edgeX;
    int right_edgeY;
    int scaleX;
    int scaleY;
    char label_graph [12];

    void Draw_grid (int size_massive, int number_operations);
    };

struct ButtonType
    {
    char name[20];
    int x, y;
    COLORREF colortext;

    void Draw_button (ButtonType buttons[]);
    };



void Cycling();
void Title_Sort                   (int x, int y, int size, int high, COLORREF color_title, char name[]);
void Gradient();
void Visualization_Shell_sort     (int data[], int current_size);
void Visualization_Bubble_sort    (int data[], int current_size);
void Visualization_Insertion_sort (int data[], int current_size);
void Visualization_Selection_sort (int data[], int current_size);
void Visualization_Quick_Sort     (int data[], int current_size);
int ButtonCheckClick              (int x, int y, int mouse_x, int mouse_y);
void Choise_Button                (struct ButtonType buttons[], int data[], Grid win_compare, Grid win_swap);
void Gradient();



int main()
{
txCreateWindow (WIDTH_WINDOW, HEIGHT_WINDOW);

Cycling();

return 0;
}


void Cycling()
    {
    int size_massive = 500;
    int number_operations = 5000;
    int data[1000]={};


    Grid win_compare = {90, 120, 580, 390, 20, 10, "comparisons"};
    Grid win_swap    = {90, 490, 580, 760, 20, 10, "swaps"};


    ButtonType buttons[7] = {"Selection_sort   ", 660, 100,  RGB(255, 128, 128),
                             "  Bubble_sort    ", 660, 200,  RGB( 34, 145, 255),
                             "  Insert_sort    ", 660, 300,  RGB(255,  89, 255),
                             "  Shell_sort     ", 660, 400,  RGB(  0, 240,   0),
                             "  Quick_Sort     ", 660, 500,  RGB(255, 255,   0),
                             "    Clear        ", 660, 600,  RGB(128, 255, 255),
                             "    Exit         ", 660, 700,  RGB(255, 102, 102),};
    Gradient();
    win_compare.Draw_grid  (size_massive, number_operations);
    win_swap.Draw_grid     (size_massive, number_operations);
    buttons[7].Draw_button (buttons);

    while(!txGetAsyncKeyState (VK_ESCAPE))
        {
        Choise_Button (buttons, data, win_compare, win_swap);
        }

    }


void Grid::Draw_grid (int size_massive, int number_operations)
    {
    txSetColor      (RGB (153, 217, 234), 2);
    txSetFillColor  (RGB (153, 217, 234));

    txLine (left_edgeX,  left_edgeY,  left_edgeX, right_edgeY);
    txLine (left_edgeX, right_edgeY, right_edgeX, right_edgeY);

    POINT arrowY [3] = {{left_edgeX - 3, left_edgeY + 20}, {left_edgeX + 3, left_edgeY + 20}, {left_edgeX, left_edgeY}};
    txPolygon (arrowY, 3);

    POINT arrowX [3] = {{right_edgeX - 20, right_edgeY - 3}, {right_edgeX - 20, right_edgeY + 3}, {right_edgeX, right_edgeY}};
    txPolygon (arrowX, 3);

    txSelectFont  ("Arial", 10, 6);
    char strY [6] = "";
    char strX [5] = "";

    int price_divX = ROUND ((right_edgeX - left_edgeX)/scaleX);
    int price_divY = ROUND ((right_edgeY - left_edgeY)/scaleY);
    int step = 0;

    for (int i = 0; i < scaleY; i += 1)
        {
        txLine    ((left_edgeX - 5), right_edgeY - i*price_divY, (left_edgeX + 5), right_edgeY - i*price_divY);
        sprintf   (strY, "%d", i*price_divY*(number_operations/(right_edgeY - left_edgeY)));
        txTextOut ((left_edgeX - 40), right_edgeY - 5 - i*price_divY, strY);
        }

    for (int i = 0; i < scaleX; i += 1)
        {
        txLine      ((left_edgeX + i*price_divX), right_edgeY - 5, (left_edgeX + i*price_divX), right_edgeY + 5);
        sprintf     (strX, "%d", i*price_divX*(size_massive/(right_edgeX - left_edgeX)));
        txTextOut   ((left_edgeX - 5 + i*price_divX), right_edgeY + 20, strX);
        step += 5;
        }


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

    txSetColor (RGB (205, 114, 19));
    int prew_x = left_edgeX;
    int prew_y = right_edgeY;
    int gap_x = 5;
    int gap_y = price_divY;

    for (int i = 0; i < scaleY; i += 1)
        {
        prew_x = left_edgeX;
        for (int j = 0; j < (right_edgeX - left_edgeX)/5; j += 1)
            {
            txLine (prew_x, prew_y, prew_x + 2, prew_y);
            prew_x += gap_x;
            }
        prew_y -= gap_y;
        }

 //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


    txSelectFont  ("Arial",20, 10);
    char str_title [20] = "";
    sprintf   (str_title, "%s", label_graph);
    txTextOut ((left_edgeX  +  200), left_edgeY - 20, str_title);

    txSetColor      (RGB (153, 217, 234), 2);
    txSetFillColor  (RGB (153, 217, 234));
    txSelectFont    ("Arial", 12, 6);

    char labelOY[30] = "Number of operations";
    char labelOX[30] = "Size";

    txTextOut (left_edgeX  - 25, left_edgeY  - 20, labelOY);
    txTextOut (right_edgeX - 30, right_edgeY + 10, labelOX);
    }


void ButtonType::Draw_button (struct ButtonType buttons[])
    {
    for (int i = 0; i < 6; i ++)
        {
        txSetColor      (buttons[i].colortext, 3);
        txSetFillColor  (RGB (0, 50, 121));
        txRectangle (buttons[i].x, buttons[i].y, buttons[i].x + WIDTH_BUTTON, buttons[i].y + HEIGHT_BUTTON);
        Title_Sort  (buttons[i].x + 35, buttons[i].y + 15, 26, 12, buttons[i].colortext, buttons[i].name);
        }
    }

void Title_Sort (int x, int y, int size, int high, COLORREF color_title, char name[])
    {
    txSetColor    (color_title);
    txSelectFont  ("Arial", size, high);
    char str [20] = "";
    sprintf (str, "%s", name);
    txTextOut (x, y, str);
    }

void Gradient()
    {
    for (int grad = 1; grad < 250; grad ++)
        {
        txSetColor     (RGB (0 + 0.3*grad, 0 + 0.3*grad, 30 + 0.3*grad));
        txSetFillColor (RGB (0 + 0.3*grad, 0 + 0.3*grad, 30 + 0.3*grad));

        POINT fon [4] = {{  0, HEIGHT_WINDOW  - 4*grad}, {  0, HEIGHT_WINDOW + 10 - 4*grad},
                         {WIDTH_WINDOW, HEIGHT_WINDOW + 10 - 4*grad}, {WIDTH_WINDOW, HEIGHT_WINDOW  - 4*grad}};
        txPolygon (fon, 4);
        }
    }

int ButtonCheckClick (int x, int y, int mouse_x, int mouse_y)
    {
    if (fabs (x - mouse_x) <= WIDTH_BUTTON)
        if (fabs (y - mouse_y) <= HEIGHT_BUTTON)
            if (GetAsyncKeyState (VK_LBUTTON))
                {
                return 1;
                };
    return 0;
    }

void Visualization_Shell_sort   (int data[], int current_size)
    {
    int count = 0;
    while (count < 90)
        {
        Fill_Array (data, current_size);
        Shell_Sort (data, current_size);
        current_size += 2;
        count += 2;
        }
    }

void Visualization_Bubble_sort  (int data[], int current_size)
    {
    int count = 0;
    while (count < 90)
        {
        Fill_Array        (data, current_size);
        Bubble_sort_Array (data, current_size);
        current_size += 2;
        count += 2;
        }
    }

void Visualization_Insertion_sort (int data[], int current_size)
    {
    int count = 0;
    while (count < 90)
        {
        Fill_Array        (data, current_size);
        Insertion_Sort    (data, current_size);
        current_size += 2;
        count += 2;
        }
    }

void Visualization_Selection_sort (int data[], int current_size)
    {
    int count = 0;
    while (count < 90)
        {
        Fill_Array        (data, current_size);
        Selection_Sort    (data, current_size);
        current_size += 2;
        count += 2;
        }
    }

void Visualization_Quick_Sort (int data[],  int current_size)
    {
    int count = 0;
    while (count < 90)
        {
        Fill_Array        (data, current_size);
        Quick_Sort        (data, 0, current_size - 1);
        current_size += 2;
        count += 2;
        }
    }


void Choise_Button (struct ButtonType buttons[], int data[], Grid win_compare, Grid win_swap)
    {

    for (int i = 0; i < 7; i ++)
        {
        if (ButtonCheckClick (buttons[0].x, buttons[0].y, txMouseX(), txMouseY()) == true)
            {
            Visualization_Selection_sort (data, 5);
            Title_Sort  (10, 20, 36, 14, buttons[0].colortext, buttons[0].name);
            }
        if (ButtonCheckClick (buttons[1].x, buttons[1].y, txMouseX(), txMouseY()) == true)
            {
            Visualization_Bubble_sort  (data, 5);
            Title_Sort  (210, 20, 36, 14, buttons[1].colortext, buttons[1].name);
            }
        if (ButtonCheckClick (buttons[2].x, buttons[2].y, txMouseX(), txMouseY()) == true)
            {
            Visualization_Insertion_sort  (data, 5);
            Title_Sort  (400, 20, 36, 14, buttons[2].colortext, buttons[2].name);
            }
        if (ButtonCheckClick (buttons[3].x, buttons[3].y, txMouseX(), txMouseY()) == true)
            {
            Visualization_Shell_sort   (data, 5);
            Title_Sort  (580, 20, 36, 14, buttons[3].colortext, buttons[3].name);
            }
        if (ButtonCheckClick (buttons[4].x, buttons[4].y, txMouseX(), txMouseY()) == true)
            {
            Visualization_Quick_Sort   (data, 5);
            Title_Sort  (750, 20, 36, 14, buttons[4].colortext, buttons[4].name);
            }
        if (ButtonCheckClick (buttons[5].x, buttons[5].y, txMouseX(), txMouseY()) == true)
            {
            txClear();
            Gradient();
            win_compare.Draw_grid  (500, 5000);
            win_swap.Draw_grid     (500, 5000);
            buttons[7].Draw_button (buttons);
            }
        }
    }

