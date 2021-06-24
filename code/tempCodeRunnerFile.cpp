; i < n; ++i)
        if (i + z[i] == n) {
            print(s.substr(i, z[i]));
            break;
        }