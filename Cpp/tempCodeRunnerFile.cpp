for (auto it : pmp)
    {
        cout << it.first << ": ";
        for (auto iter : it.second)
            cout << iter << " ";
        cout << endl;
    }
    cout << endl;
    for (auto it : smp)
    {
        cout << it.first << ": ";
        for (auto iter : it.second)
            cout << iter << " ";
    }