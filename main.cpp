#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "Interval.h"
#include "Node.h"
#include "IntervalTree.h"



int main() {
    //test1
    Interval Interval1(15, 20);
    Interval Interval2(10, 30);
    Interval Interval3(17, 19);
    Interval Interval4(5, 20);
    Interval Interval5(12, 15);
    Interval Interval6(30, 40);
    std::cout<<"Tree 1: \n";
    IntervalTree tree1;
    tree1.InsertInterval(Interval1);
    tree1.InsertInterval(Interval2);
    tree1.InsertInterval(Interval3);
    tree1.InsertInterval(Interval4);
    tree1.InsertInterval(Interval5);
    tree1.InsertInterval(Interval6);
    std::cout<<"Tree after insertion\n";
    tree1.inorder();
    tree1.DeleteInterval(Interval6);
    std::cout<<"Tree after deleting (30,40)\n";
    tree1.inorder();
    Interval Intervalll(3, 20);
    Interval Intervalx(12, 16);
    Interval Interval1x(0, 10);
    std::cout<<"\nTest case 1: \n";
    tree1.SearchInterval(Intervalll);
    std::cout<<"Test case 2: \n";
    tree1.SearchInterval(Intervalx);
    std::cout<<"Test case 3: \n";
    tree1.SearchInterval(Interval1x);


    std::cout << "--------------------------\n";
    //test2
    Interval Interval7(15, 40);
    Interval Interval8(10, 28);
    Interval Interval9(16, 23);
    Interval Interval10(5, 24);
    Interval Interval11(11, 16);
    Interval Interval12(18, 60);
    std::cout<<"Tree 2: \n\n";
    IntervalTree tree2;
    tree2.InsertInterval(Interval7);
    tree2.InsertInterval(Interval8);
    tree2.InsertInterval(Interval9);
    tree2.InsertInterval(Interval10);
    tree2.InsertInterval(Interval11);
    tree2.InsertInterval(Interval12);
    std::cout<<"Tree after insertion\n";
    tree2.inorder();
    tree2.DeleteInterval(Interval9);
    std::cout<<"Tree after deleting (16, 23)\n";
    tree2.inorder();
    Interval Interval13(9, 30);
    Interval Interval14(35, 70);
    Interval Interval15(6, 7);
    std::cout<<"\nTest case 4: \n";
    tree2.SearchInterval(Interval13);
    std::cout<<"Test case 5:\n";
    tree2.SearchInterval(Interval14);
    std::cout<<"Test case 6: \n";
    tree2.SearchInterval(Interval15);
    std::cout << "--------------------------\n";
    //test3
    Interval Interval18(1, 20);
    Interval Interval19(14, 39);
    Interval interva20(19, 23);
    Interval interva21(5, 60);
    Interval interva22(22, 52);
    Interval interva23(36, 43);
    std::cout<<"Tree 3: \n\n";
    IntervalTree tree3;
    tree3.InsertInterval(Interval18);
    tree3.InsertInterval(Interval19);
    tree3.InsertInterval(interva20);
    tree3.InsertInterval(interva21);
    tree3.InsertInterval(interva22);
    tree3.InsertInterval(interva23);
    std::cout<<"Tree after insertion\n";
    tree3.inorder();
    tree3.DeleteInterval(Interval9);
    std::cout<<"Tree after deleting (14,39)\n";
    tree3.inorder();
    Interval Interval8l(8, 46);
    Interval Intervalxx(7, 36);
    Interval Interval1xx(0, 17);
    std::cout<<"\nTest case 7: \n";
    tree3.SearchInterval(Interval8l);
    std::cout<<"Test case 8: \n";
    tree3.SearchInterval(Intervalxx);
    std::cout<<"Test case 9: \n";
    tree3.SearchInterval(Intervalxx);

    std::cout << "--------------------------\n";
    

    return 0;
}
