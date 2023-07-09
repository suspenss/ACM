#include <iostream>

namespace io {
    struct read {
        static constexpr int M = 1 << 23;
        char buf[M], *S = buf, *P = buf, c, l;

        inline char gc() {
            return (S == P && (P = (S = buf) + fread(buf, 1, M, stdin), S == P) ? EOF : *S++);
        }
        template<typename T>
        read &operator>>(T &x) {
            for (c = 0; !isdigit(c); c = gc()) {
                l = c;
            }

            for (x = 0; isdigit(c); c = gc()) {
                x = x * 10 + c - '0';
            }

            return x = (l ^ 45) ? x : -x, *this;
        }
    } in;
}    // namespace io
