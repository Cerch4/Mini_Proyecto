#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "ListArr.h"
using namespace std;
int main() {
 /*
ListArr test(4);
  for (int i = 0; i < 20; i++) {
    test.insert_left(i);
    cout << "inserted " << test.head->data[0] << endl;
    // cout << "total "  << test.size() <<endl;
  }

  // cout << "total "  << test.size() <<endl;
//cout << test.size()<<endl;
  cout << test.find(100)<<endl;
test.print();
*/

srand(time(NULL)); 
  ofstream outfile("resultsListArr_left_10k.csv");
  outfile<<"n,time[ms]\n";
  int N = 200, n_1 = 1, k = 10, num_experiments = 10000;

  ListArr Test(64);

  for(int n = n_1; n <= N; n += k){
     // ListArr Test(64);
      //Test.insert_left(10);

      double total_time = 0;
      for(int i = 0; i < num_experiments; i++){
        auto start_time = chrono::high_resolution_clock::now();
          Test.insert_left(i);
        auto end_time = chrono::high_resolution_clock::now();
        auto single_execution_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
          total_time += single_execution_time;
      }
      double avg_time = total_time / num_experiments;
      outfile<<n<<" ,"<<avg_time<<endl;
  }
  outfile.close(); 

  return 0;
}