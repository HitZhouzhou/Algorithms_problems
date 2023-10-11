#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

int main() {
    int m = 5;
    ofstream outFile("output.txt");  // 创建文件输出流

    if (!outFile.is_open()) {
        cout << "Failed to open output.txt" << endl;
        return 1;
    }

    outFile << m << endl;  // 将 m 写入文件

    int cnt = 0;
    while (m--) {
        outFile << cnt + 1 << " " << 99999 << endl;

        for (int i = 1; i <= 99999; i++) {
            outFile << i << " ";
        }
        outFile << endl;

        cnt++;
    }

    outFile.close();  // 关闭文件输出流

    return 0;
}
