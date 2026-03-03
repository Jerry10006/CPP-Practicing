#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // C++26 的預期值會是大於 202302L 的某個數字（目前通常顯示為 202400L 或更高）
    std::cout << "C++ Standard: " << __cplusplus << std::endl;
    return 0;
}
