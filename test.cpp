#include <iostream>
#include <vector>
#include <exception>
#include <iomanip>

using namespace std;

int main() {
    // 優化輸出，讓數字看起來比較漂亮
    cout << fixed << setprecision(1);
    cout << "===========================================\n";
    cout << " 開始實測你的電腦目前 vector<int> 的極限...\n";
    cout << "===========================================\n\n";

    // 從 1 億個 int 開始測試 (100,000,000)
    size_t target_elements = 100000000;
    size_t last_success = 0;

    while (true) {
        // 計算預估需要多少 MB 的記憶體 (每個 int 佔 4 Bytes)
        double memory_mb = (target_elements * sizeof(int)) / (1024.0 * 1024.0);
        double memory_gb = memory_mb / 1024.0;

        try {
            vector<int> test_vector;
            
            // resize 會強迫系統把每個位置都填入 0，這會實質佔用實體記憶體
            test_vector.resize(target_elements, 0);

            // 如果成功要到，記錄下來並嘗試加大挑戰
            last_success = target_elements;
            cout << "【成功】可容納 " << setw(10) << target_elements << " 個 int "
                 << "(約 " << setw(6) << memory_mb << " MB / " << memory_gb << " GB)\n";

            // 每次往上加 1 億個元素
            target_elements += 100000000;

        } catch (const bad_alloc& e) {
            // 當系統給不出「連續」記憶體時，就會跳進這裡
            cout << "\n===========================================\n";
            cout << "【止步！】記憶體分配失敗（觸發 bad_alloc 異常）\n";
            cout << "你的電腦當下無法提供 " << target_elements << " 個 int 的連續空間。\n";
            cout << "預估需要的連續記憶體為: " << memory_gb << " GB\n\n";

            if (last_success > 0) {
                double final_mb = (last_success * sizeof(int)) / (1024.0 * 1024.0);
                cout << "👉 實測安全極限大約在: " << last_success << " 個 int 左右\n";
                cout << "👉 最大連續可用記憶體約為: " << final_mb / 1024.0 << " GB\n";
            } else {
                cout << "👉 你的電腦現在連 1 億個 int (400MB) 都開不起來，可能記憶體被其他程式吃滿了。\n";
            }
            cout << "===========================================\n";
            break; // 結束迴圈
        }
    }

    return 0;
}