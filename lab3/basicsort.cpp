#include "basicsort.h"
#include "convertfile.h"
#include <iostream>

void BasicSort::sort_main(FILE *f1)
{
    FILE* f2 = fopen("f2.dat", "wb"), * f3 = fopen("f3.dat", "wb");
    int a, b, x = 0, y = 0, z = 1, k, x2 = 1; fread(&b, sizeof (int), 1, f1); a = b;
    bool q = true, v = true;

    while (!feof(f1)) {
        if (a > b) {
            if (q) x++; else y++;
            if (q && x == z) { q = false; z = x + y; }
            else if (!q && y == z) { q = true; z = x + y; }
        }
        if (q) { fwrite(&b, sizeof (int), 1, f2); a = b; fread(&b, sizeof (int), 1, f1); }
        else { fwrite(&b, sizeof (int), 1, f3); a = b; fread(&b, sizeof (int), 1, f1); }
    }
    if (a <= b) if (q) { fwrite(&b, sizeof (int), 1, f2); x++; }
    else { fwrite(&b, sizeof (int), 1, f3); y++; }
    else {
        if (q) x++; else y++;
        if (q && x == z) { q = false; z = x + y; }
        else if (!q && y == z) { q = true; z = x + y; }
        if (q) { fwrite(&b, sizeof (int), 1, f2); x++; }
        else { fwrite(&b, sizeof (int), 1, f3); y++; }
    }
    fclose(f1); fclose(f2); fclose(f3); // Функція розподілила серії з початкового файлу в файли f1 i f2


   /* FILE* f = fopen("f2.dat", "r+b");
    while (!feof(f)) {
        int a;
        fread(&a, sizeof (int), 1, f);
        std::cout << a << " ";
    }
    fclose(f);


    f = fopen("f3.dat", "r+b");
    while (!feof(f)) {
        int a;
        fread(&a, sizeof (int), 1, f);
        std::cout << a << " ";
    }
    fclose(f);*/





    if (q) x = z; else y = z;
    int w = 3;
    if (q && x != 0 && y != 0) {
        f3 = fopen("f3.dat", "rb");
        fread(&b, sizeof (int), 1, f3);
    }
    else if (x != 0 && y != 0) {
        f2 = fopen("f2.dat", "rb");
        fread(&b, sizeof (int), 1, f2);
    }
    while (1)
    {
        std:: cout << "strart" << std::endl;
        if (x == 0 || y == 0) break;
        if (w == 3 && q) {
            f1 = fopen("f1.dat", "wb"); f2 = fopen("f2.dat", "rb");
            if (x > y) k = y; else k = x;
            step(f2, f3, f1, k, b, x2); w = 1;
            fclose(f1); fclose(f3);
        }
        else
            if (w == 1 && q) {
                f1 = fopen("f1.dat", "rb"); f3 = fopen("f3.dat", "wb");
                if (x > y) k = y; else k = x;
                step(f1, f2, f3, k, b, x2); w = 2;
                fclose(f2); fclose(f3);
            }
            else
                if (w == 2 && q) {
                    f2 = fopen("f2.dat", "wb"); f3 = fopen("f3.dat", "rb");
                    if (x > y) k = y; else k = x;
                    step(f3, f1, f2, k, b, x2); w = 3;
                    fclose(f1); fclose(f2);
                }
                else
                    if (w == 3 && !q) {
                        f1 = fopen("f1.dat", "wb"); f3 = fopen("f3.dat", "rb");
                        if (x > y) k = y; else k = x;
                        step(f3, f2, f1, k, b, x2); w = 1;
                        fclose(f1); fclose(f2);
                    }
                    else
                        if (w == 1 && !q) {
                            f1 = fopen("f1.dat", "rb"); f2 = fopen("f2.dat", "wb");
                            if (x > y) k = y; else k = x;
                            step(f1, f3, f2, k, b, x2); w = 2;
                            fclose(f2); fclose(f3);
                        }
                        else
                            if (w == 2 && !q) {
                                f2 = fopen("f2.dat", "rb"); f3 = fopen("f3.dat", "wb");
                                if (x > y) k = y; else k = x;
                                step(f2, f1, f3, k, b, x2); w = 3;
                                fclose(f1); fclose(f3);
                            }
        std::cout << x << " " << y << std::endl;
        if (x > y) { x = x - y; if (x == 0) break; }
        else { y = y - x; if (y == 0) break; }
    }
    if (q && w == 3) {
        fclose(f3);
        f1 = fopen("f1.dat", "wb"); f2 = fopen("f2.dat", "rb");
        while (feof(f2) == 0) { fread(&b, sizeof (int), 1, f2); fwrite(&b, sizeof (int), 1, f1); }
        fclose(f1); fclose(f2);
    }
    if (q && w == 2) {
        fclose(f1);
        f1 = fopen("f1.dat", "wb"); f3 = fopen("f3.dat", "rb");
        while (feof(f3) == 0) { fread(&b, sizeof (int), 1, f3); fwrite(&b, sizeof (int), 1, f1); }
        fclose(f1); fclose(f3);
    }
    if (q && w == 1) {
        fclose(f2);
    }
    if (!q && w == 3) {
        fclose(f2);
        f1 = fopen("f1.dat", "wb"); f3 = fopen("f3.dat", "rb");
        while (feof(f3) == 0) { fread(&b, sizeof (int), 1, f3); fwrite(&b, sizeof (int), 1, f1); }
        fclose(f1); fclose(f3);
    }
    if (!q && w == 2) {
        fclose(f1);
        f1 = fopen("f1.dat", "wb"); f2 = fopen("f2.dat", "rb");
        while (feof(f2) == 0) { fread(&b, sizeof (int), 1, f2); fwrite(&b, sizeof (int), 1, f1); }
        fclose(f1); fclose(f2);
    }
    if (!q && w == 1) {
        fclose(f3);
    }
}

void BasicSort::step(FILE *f1, FILE *f2, FILE *f3, int k, int &b2, int &x2)
{
    int a1, b1, a2 = b2, i, x1 = 1; fread(&b1, sizeof (int), 1, f1); a1 = b1;
    for (i = 0; i < k; i++) {
        while ((a1 <= b1 && x1) || ((a2 <= b2) && x2)) {
            if (a1 > b1 && x2) { fwrite(&b2, sizeof (int), 1, f3); a2 = b2; x2 = fread(&b2, sizeof (int), 1, f2); }
            else if (a2 > b2 && x1) { fwrite(&b1, sizeof (int), 1, f3); a1 = b1; x1 = fread(&b1, sizeof (int), 1, f1); }
            else if (b1 < b2 && x1) { fwrite(&b1, sizeof (int), 1, f3); x1 = fread(&b1, sizeof (int), 1, f1); }
            else if (x2) { fwrite(&b2, sizeof (int), 1, f3); a2 = b2; x2 = fread(&b2, sizeof (int), 1, f2); }
            else if (!x2) { fwrite(&b1, sizeof (int), 1, f3); x1 = fread(&b1, sizeof (int), 1, f1); }
            else if (!x1) { fwrite(&b2, sizeof (int), 1, f3); a2 = b2; x2 = fread(&b2, sizeof (int), 1, f2); }
            //std::cout << a1 << " " << x1 << std::endl;
            //std::cout << a2 << " " << x2 << std::endl;
        }
        a1 = b1; a2 = b2;
    }
    b2 = b1; x2 = x1;
}

BasicSort::BasicSort(std::string path): _file_path(path)
{

}

void BasicSort::Sort()
{
    ConvertFile conv;
    if (_file_path[_file_path.size() - 3] == 't') {
        sort_main(conv.FromTxtToBin(_file_path));
    } else sort_main(fopen(_file_path.c_str(), "r+b"));
    fclose(conv.FromBinToTxt("f1.dat"));
}
