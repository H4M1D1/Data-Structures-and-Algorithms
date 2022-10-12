/****************************************************
You can use this file to test if your code is working
properly by designing your own test case and test code.
****************************************************/

#include <iostream>
#include <string>

using namespace std;

string get_status_str(bool status)
{
    return status ? "TEST PASSED" : "TEST FAILED";
}

int main()
{
    int grade = 0;
//    SequentialListTest seq_test;
//    DoublyLinkedListTest linked_test;
//    PolynomialTest poly_test;

    string seq_test_descriptions[10] = {
            "Test1: New empty list is valid",
            "Test2: insert_front() and insert_back() on zero-element list",
            "Test3: select() and search() work properly",
            "Test4: remove_front() and remove_back() on one-element list",
            "Test5: Inserting too many elements should fail",
            "Test6: insert_front() keeps moving elements forward",
            "Test7: inserting at different positions in the list",
            "Test8: try to remove too many elements, then add a few elements",
            "Test9: lots of inserts and deletes, all of them valid",
            "Test10: lots of inserts and deletes, some of them invalid"};

    bool seq_test_results[10];
    seq_test_results[0] = seq_test.test1();
    seq_test_results[1] = seq_test.test2();
    seq_test_results[2] = seq_test.test3();
    seq_test_results[3] = seq_test.test4();
    seq_test_results[4] = seq_test.test5();
    seq_test_results[5] = seq_test.test6();
    seq_test_results[6] = seq_test.test7();
    seq_test_results[7] = seq_test.test8();
    seq_test_results[8] = seq_test.test9();
    seq_test_results[9] = seq_test.test10();

    cout << "SEQUENTIAL LIST TESTING RESULTS \n";
    cout << "******************************* \n";
    for (int i = 0; i < 10; ++i)
    {
        cout << seq_test_descriptions[i] << endl
             << get_status_str(seq_test_results[i]) << endl;
        if (seq_test_results[i])
            grade += 3;
    }
    grade += 10;
    cout << endl
         << "Total grade: " << grade << endl << endl;



}
