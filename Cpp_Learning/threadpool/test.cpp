#include <iostream>
#include "threadpool.h"

int main() {
    ThreadPool pool(4);
    for (int i = 0; i < 10; ++i) {
        pool.addTask([i] {
            std::cout << "Task " << i << " running in thread " 
                      << std::this_thread::get_id() << std::endl;
        });
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));  // 简单等一下
}

// int main() {
//     ThreadPool pool(4);
//     std::vector< std::future<int> > results;

//     for(int i = 0; i < 8; ++i) {
//         results.emplace_back(
//             pool.addTask([i] {
//                 std::cout << "hello " << i << std::endl;
//                 std::this_thread::sleep_for(std::chrono::seconds(1));
//                 std::cout << "world " << i << std::endl;
//                 return i*i;
//             })
//         );
//     }

//     for(auto && result: results)
//         std::cout << result.get() << ' ';
//     std::cout << std::endl;
    
//     return 0;
// }