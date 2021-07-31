while (small != 0) {
        int diff = big-small;
        big = small;
        small = diff;
        cout << big << " " << small << " " << diff << endl;
    }