#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void runner(int disk, string a, string b)
{
    if (disk == 0)
        return;
    else
        cout << disk << " " << a << " " << b << endl;
}
void TOH3(int disk, string a, string b, string c)
{

    
        if (disk > 0)
        {
            TOH3(disk - 1 ,a, c, b);
            runner(disk, a, b);
            TOH3(disk - 1, c, b, a);
        }
    
}

void TOH4(int disk, string a, string b, string c, string d)
{

    if (disk == 0)
        return;
    if (disk == 1)
    {
        runner(disk, a, b);
        return;
    }

    TOH4(disk - 2, a, c, d, b);
    runner(disk - 1, a, d);
    runner(disk, a, b);
    runner(disk - 1, d, b);
    TOH4(disk - 2, c, b, a, d);
}
void TOH5(int disk, string a, string b, string c, string d, string e)
{
    if (disk == 1)
    {
        runner(disk, a, b);
        return;
    }
    if (disk >= 2)
    {
        TOH5(disk - 3, a, c, d, e, b);
        runner(disk - 2, a, e);
        runner(disk - 1, a, d);
        runner(disk, a, b);
        runner(disk - 1, d, b);
        runner(disk - 2, e, b);
        TOH5(disk - 3, c, b, a, d, e);
    }
}

void runnerfor3(int disk, int peg, string a, string b, string c)
{
    if (peg > 1)
    {
        runner(disk, a, b);
        runnerfor3(disk, peg - 1, b, c, a);
    }
}
void runnerfor4(int disk, int peg, string a, string b, string c, string d)
{
    if (disk == 1)
    {
        if (peg > 1)
        {
            runner(disk, a, b);
            runnerfor4(disk, peg - 1, b, c, d, b);
        }
    }
    if (disk == 2)
    {
        if (peg > 1)
        {
            runner(disk, a, b);
            runnerfor4(disk, peg - 1, b, c, d, b);
        }
    }
}
void runnerfor42(int disk, int peg, string a, string b, string c, string d)
{
    if (peg > 1)
    {
        runnerfor4(disk - 1, peg - 1, b, c, d, b);
        runner(disk, a, b);
        runnerfor4(disk - 1, peg - 1, b, c, d, b);
        runner(disk, a, b);
    }
}

void runnerfor1disk(int type, int peg, string a, string b, string c, string d, string e)
{
    if (type == 3)
    {
        if (peg > 1)
        {
            d = "";
            e = "";
            runner(1, a, b);
        }
    }
    if (type == 4)
    {
        if (peg > 1)
        {
            e = "";
            runner(1, a, b);
            runnerfor1disk(1, peg - 1, b, c, d, b, e);
        }
    }
}
int main(int argc, char **argv)
{
    string p = "3"; // argv(1)
    string d = "5"; // argv(2)
    // string file= argv(3);

    int pegs = stoi(p);
    int disks = stoi(d);
    bool onedisk = false;
    TOH3(3,"A", "C", "B");
    //  TOH4(disks, "A", "D", "B", "C");
    //  TOH5(disks, "A","E","B","C","D");

    // runnerfor3(1, 3, "A", "B", "C");
    // runnerfor42(2, 4, "A", "B", "C", "D");
    // runnerfor1disk(3, 3, "A","B","C","D","E");
}
