 string name;
    int score[3];

    ofstream file("Student.csv");

    getline(cin, name);
    cin >> score[0] >> score[1] >> score[2];

    if(file.is_open()) {
        file << name << "," << score[0] << "," << score[1] << "," << score[2] << endl;
    }

    file.close();

    ifstream file1("Student.csv");

    string name1, tmp;
    int score1[3];

    getline(file1, tmp, ',');
    getline(file1, name1, ',');
    score1[0]=stoi(name1);
    getline(file1, name1, ',');
    score1[1]=stoi(name1);
    getline(file1, name1, ',');
    score1[2]=stoi(name1);

    cout << tmp << " " << score[0] <<" " << score[1] << " " << score[2] << " "<<endl;

    return 0;
