#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    int numPositives = 0;
    int numNegatives = 0;
    int numZeroes = 0;
    float arraySize = arr.size();
    float ratioPositive = 0.0;
    float ratioNegative = 0.0;
    float ratioZero = 0.0;
    for (int i = 0; i < arr.size(); i++) {
        int currentValue = 0;
        currentValue = arr[i];
        if (currentValue > 0 ) {
            numPositives++;
        }
        else if (currentValue < 0 ) {
            numNegatives++;
        }
        else if (currentValue == 0) {
            numZeroes++;
        }
        else {
            cout << "ERROR: Unexpected value" << endl;
        }
    }
    float floatPositives = static_cast <float> (numPositives);
    float floatNegatives = static_cast <float> (numNegatives);
    float floatZeroes = static_cast <float> (numZeroes);
    //Determine ratio of positive elements in array
    ratioPositive = (floatPositives / arraySize);
    //Determine ratio of negative elements in array
    ratioNegative = (floatNegatives / arraySize);
    //Determine ratio of zero (0) elements in array
    ratioZero = (floatZeroes / arraySize);
    //Print each ratio separated by a newline with a precision of 6 decimals
    cout << setprecision(6) << ratioPositive << endl;
    cout << ratioNegative << endl;
    cout << ratioZero << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));
    if (n > 0 && n <= 100) {
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            if (arr_item >= -100 && arr_item <= 100) {
                arr[i] = arr_item;
            }
        }

        plusMinus(arr);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
