#include <bits/stdc++.h>
#include <cpuid.h>

using F = uint32_t;

static void cpu(F X, F Y, F msg[4]) {
    __cpuid_count(X, Y, msg[0], msg[1], msg[2], msg[3]);
}

int main() {
    F data[4];
    char msg[50];

    for (int i = 0; i < 3; ++i) {
        cpu(0x80000002 + i, 0, data);

        for (int j = 0; j < 4; ++j) {
            reinterpret_cast<F *>(msg)[i * 4 + j] = data[j];
        }
    }

    std::cout << msg;
}