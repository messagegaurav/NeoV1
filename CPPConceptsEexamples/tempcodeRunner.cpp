    string str[] = {"Gaurav", "Neo", "Trinity"};
    vector<string> myStringVec(str->begin(), str->end());
    for (auto itr : myStringVec)
        cout << "\n myStringVec: " << itr << endl;