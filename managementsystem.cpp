#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;

struct person {
    string name;
    int age = 0;
    float weight = 0.0f;
    float height = 0.0f;
    char gen;
};
void saveRecord(string nm, string calcType, float result) {
    ofstream outFile("UserHistory.txt", ios::app);

    if (outFile.is_open()) {

        outFile << " Name : " << nm << "\n Service : " << calcType << "\n Result : " << result << endl;
        outFile << "------------------------------------" << endl;
        outFile.close();
    }
    else {
        cerr << "Error: Could not save the record!" << endl;
    }
};
void showHistory() {
    ifstream inFile("UserHistory.txt");
    string line;

    cout << "\n --- The Previous Records --- \n" << endl;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << "No records found yet!" << endl;
    }
}
float calculateBMI(float w, float h) {
    if (h == 0) return 0;
    return w / (h * h);
}
int main() {
y:
    person user;
    cout << " ============ Health Managment System ============" << endl;
    cout << " Enter a number to choose a service from the following : \n  1. Body Mass Index (BMI) . \n 2. Body Fat Percentage (BFP) . \n 3. Basal Metabolic Rate (BMR) . \n 4. Total Daily Energy Expenditure (TDEE).  \n 5. Last records . \n 6. Exit . " << endl;
    int x;
    cin >> x;
    switch (x) {
    case 1: {//---------------------------- Case 1 ----------------------------BMI//
        cout << " Welcome to the Body Mass Index (BMI) service ." << endl;
        cout << " You must enter the following : \n 1. Enter your name : " << endl;
        getline(cin >> ws, user.name);
        int validname = 1;
        for (int i = 0; i < user.name.length(); i++) {
            if (!isalpha(user.name[i]) && user.name[i] != ' ')
                validname = 0;
            break;
        }
        if (validname == 1) {
            cout << " Valid name ." << endl;
        }
        else {
            cerr << " Invalid name ! Only letters allowed ." << endl;
            getline(cin >> ws, user.name);
        }
        cout << " Welcome dear [" << user.name << "] ." << endl;

        cout << " 2. You must choose a measure unit for the length : \n for : Centimeter --> (C) , for : Inches --> (I) . " << endl;
        float i_cm;
        char c;
        cin >> c;
        if (c == 'C' || c == 'c') {
            cout << "Enter your length in (cm) unit : " << endl;
            float i_cm;
            cin >> i_cm;
            user.height = i_cm / 100.0f; ;
        }
        else if (c == 'I' || c == 'i') {
            cout << "Enter your length in (Inches) unit: " << endl;
            cin >> i_cm;
            user.height = i_cm * 0.0254f;
        }
        else {
            do {
                cerr << "Invalid input , Try again : " << endl;
                cin >> c;
            } while (c != 'I' && c != 'i' && c != 'C' && c != 'c');
        }
        cout << " 3. You must choose a unit for weight : for (pound) choose --> (l) , for (Kilo gram) choose --> (k) " << endl;
        char w;
        float lbs = 0.0f;
        cin >> w;
        if (w == 'K' || w == 'k') {
            cout << " || Enter your weight in (Kg) unit : " << endl;
            cin >> user.weight;
        }
        else if (w == 'L' || w == 'l') {
            cout << " || Enter your weight in (lbs) unit : " << endl;
            cin >> lbs;
            user.weight = lbs * 0.453592f;
        }
        float bmi = user.weight / (user.height * user.height);

        cout << "Dear [" << user.name << "] , Your BMI result is : " << bmi << " Kg/m*m" << endl;
        if (bmi < 18.5) cout << " Status : Underweight" << endl;
        else if (bmi < 24.9) cout << " Status : Healthy weight" << endl;
        else if (bmi < 29.9) cout << " Status : Overweight" << endl;
        else cout << " Status : Obesity " << endl;

        saveRecord(user.name, "BMI", bmi);


        char a;
        cout << "Do you like to calculate another service ? ( Y / N ) : " << endl;
        cin >> a;
        if (a == 'Y' || a == 'y') {
            goto y;
        }
        else if (a == 'N' || a == 'n') {
            goto x;
        }
        /*Done : 1. name . 2. weight . 3. height . */
    }break; //---------------------------- END Case 1 ----------------------------BMI//
    case 2: { //---------------------------- Case 2 ----------------------------BFP//
        cout << " Welcome to the Body Fat Percentage calculator (BFP) . " << endl;
        cout << " 1. Enter your name : " << endl;
        getline(cin >> ws, user.name);
        int validname = 1;
        for (int i = 0; i < user.name.length(); i++) {
            if (!isalpha(user.name[i]) && user.name[i] != ' ')
                validname = 0;
            break;
        }
        if (validname == 1) {
            cout << " Valid name ." << endl;
        }
        else {
            cerr << " Invalid name ! Only letters allowed ." << endl;
            getline(cin >> ws, user.name);
        }
        cout << " Welcome dear [" << user.name << "] ." << endl;
        cout << " 2. Enter your age : " << endl;
        cin >> user.age;
        cout << "Noted . \n || Choose a unit to enter your weight : for (pound) choose --> (l) , for (Kilo gram) choose --> (k) " << endl;
        char w;
        float lbs = 0.0f;
        cin >> w;
        if (w == 'K' || w == 'k') {
            cout << " Noted || Enter your weight in (Kg) unit : " << endl;
            cin >> user.weight;
        }
        else if (w == 'L' || w == 'l') {
            cout << "Enter your weight in (lbs) unit : " << endl;
            cin >> lbs;
            user.weight = lbs * 0.453592f;
        }
        cout << " 2. You must choose a measure unit for the length : \n for : Centimeter --> (C) , for : Inches --> (I) . " << endl;
        float i_cm;
        char c;
        cin >> c;
        if (c == 'C' || c == 'c') {
            cout << "Enter your length in (cm) unit : " << endl;
            float i_cm;
            cin >> i_cm;
            user.height = i_cm / 100.0f; ;
        }
        else if (c == 'I' || c == 'i') {
            cout << "Enter your length in (Inches) unit: " << endl;
            cin >> i_cm;
            user.height = i_cm * 0.0254f;
        }
        else {
            do {
                cerr << "Invalid input , Try again : " << endl;
                cin >> c;
            } while (c != 'I' && c != 'i' && c != 'C' && c != 'c');
        }
        float current_bmi = calculateBMI(user.weight, user.height);
        float bfp = 0.0f;
        cout << "Enter your gender ( Either (M) Or (F) ) : " << endl;
        cin >> user.gen;
        float genval = (user.gen == 'M' || user.gen == 'm') ? 1.0f : 0.0f;
        bfp = (1.20 * current_bmi) + (0.23 * user.age) - (10.8 * genval) - 5.4;

        cout << "Your Body Fat percentage is : { " << bfp << "% } ." << endl;

        saveRecord(user.name, "BFP", bfp);


        char a;
        cout << "Do you like to calculate another service ? ( Y / N ) : " << endl;
        cin >> a;
        if (a == 'Y' || a == 'y') {
            goto y;
        }
        else if (a == 'N' || a == 'n') {
            goto x;
        }
        /*Done : 1. Name . 2. age . 3. weight . 4. height . 5. gender .*/
    }break; //---------------------------- END Case 2 ----------------------------BFP//
    case 3: { //---------------------------- Case 3 ----------------------------BMR//
        cout << " Welcome to the Body Metabolic Rate (BMR) . " << endl;
        cout << " 1. Enter your name : " << endl;
        getline(cin >> ws, user.name);
        int validname = 1;
        for (int i = 0; i < user.name.length(); i++) {
            if (!isalpha(user.name[i]) && user.name[i] != ' ')
                validname = 0;
            break;
        }
        if (validname == 1) {
            cout << " Valid name ." << endl;
        }
        else {
            cerr << " Invalid name ! Only letters allowed ." << endl;
            getline(cin >> ws, user.name);
        }
        cout << " Welcome dear [" << user.name << "] ." << endl;
        cout << " 2. Enter your age : " << endl;
        cin >> user.age;
        cout << "Noted . \n || Choose a unit to enter your weight : for (pound) choose --> (l) , for (Kilo gram) choose --> (k) " << endl;
        char w;
        float lbs = 0.0f;
        cin >> w;
        if (w == 'K' || w == 'k') {
            cout << " Noted || Enter your weight in (Kg) unit : " << endl;
            cin >> user.weight;
        }
        else if (w == 'L' || w == 'l') {
            cout << "Enter your weight in (lbs) unit : " << endl;
            cin >> lbs;
            user.weight = lbs * 0.453592f;
        }
        cout << " 2. You must choose a measure unit for the length : \n for : Centimeter --> (C) , for : Inches --> (I) . " << endl;
        float i_cm;
        char c;
        cin >> c;
        if (c == 'C' || c == 'c') {
            cout << "Enter your length in (cm) unit : " << endl;
            float i_cm;
            cin >> i_cm;
            user.height = i_cm / 100.0f; ;
        }
        else if (c == 'I' || c == 'i') {
            cout << "Enter your length in (Inches) unit: " << endl;
            cin >> i_cm;
            user.height = i_cm * 0.0254f;
        }
        else {
            do {
                cerr << "Invalid input , Try again : " << endl;
                cin >> c;
            } while (c != 'I' && c != 'i' && c != 'C' && c != 'c');
        }
        float bmr = 0.0f;
        float h_cm = user.height * 100.0f;

        cout << " Enter your gender : ( Either (M) Or (F) ) : " << endl;
        cin >> user.gen;
        while (user.gen != 'M' && user.gen != 'm' && user.gen != 'F' && user.gen != 'f') {
            cerr << "Invalid input, Try again please: ";
            cin >> user.gen;
        }
        if (user.gen == 'M' || user.gen == 'm') {
            bmr = (10.0f * user.weight) + (6.25f * h_cm) - (5.0f * user.age) + 5.0f;
        }
        else {
            bmr = (10.0f * user.weight) + (6.25f * h_cm) - (5.0f * user.age) - 161.0f;
        }

        cout << "Dear [" << user.name << "], your BMR is: " << bmr << " Calories/Day." << endl;
        cout << "This is the energy your body needs to function at rest." << endl;

        saveRecord(user.name, "BMR", bmr);


        char a;
        cout << "Do you like to calculate another service ? ( Y / N ) : " << endl;
        cin >> a;
        if (a == 'Y' || a == 'y') {
            goto y;
        }
        else if (a == 'N' || a == 'n') {
            goto x;
        }
    }break;//---------------------------- END Case 3 ----------------------------BMR//
    case 4: { //---------------------------- Case 4 ----------------------------TDEE//
        cout << " Welcome to the Total Daily Energy Expenditure (TDEE) . " << endl;
        cout << " 1. Enter your name : " << endl;
        getline(cin >> ws, user.name);
        int validname = 1;
        for (int i = 0; i < user.name.length(); i++) {
            if (!isalpha(user.name[i]) && user.name[i] != ' ')
                validname = 0;
            break;
        }
        if (validname == 1) {
            cout << " Valid name ." << endl;
        }
        else {
            cerr << " Invalid name ! Only letters allowed ." << endl;
            getline(cin >> ws, user.name);
        }
        cout << " Welcome dear [" << user.name << "] ." << endl;
        cout << " 2. Enter your age : " << endl;
        cin >> user.age;
        cout << "Noted . \n || Choose a unit to enter your weight : for (pound) choose --> (l) , for (Kilo gram) choose --> (k) " << endl;
        char w;
        float lbs = 0.0f;
        cin >> w;
        if (w == 'K' || w == 'k') {
            cout << " Noted || Enter your weight in (Kg) unit : " << endl;
            cin >> user.weight;
        }
        else if (w == 'L' || w == 'l') {
            cout << "Enter your weight in (lbs) unit : " << endl;
            cin >> lbs;
            user.weight = lbs * 0.453592f;
        }
        cout << " You must choose a measure unit for the length : \n for : Centimeter --> (C) , for : Inches --> (I) . " << endl;
        float i_cm;
        char c;
        cin >> c;
        if (c == 'C' || c == 'c') {
            cout << "Enter your length in (cm) unit : " << endl;
            float i_cm;
            cin >> i_cm;
            user.height = i_cm / 100.0f; ;
        }
        else if (c == 'I' || c == 'i') {
            cout << "Enter your length in (Inches) unit: " << endl;
            cin >> i_cm;
            user.height = i_cm * 0.0254f;
        }
        else {
            do {
                cerr << "Invalid input , Try again : " << endl;
                cin >> c;
            } while (c != 'I' && c != 'i' && c != 'C' && c != 'c');
        }
        float bmr = 0.0f;
        float h_cm = user.height * 100.0f;
        if (user.gen == 'M' || user.gen == 'm') {
            bmr = (10.0f * user.weight) + (6.25f * h_cm) - (5.0f * user.age) + 5.0f;
        }
        else {
            bmr = (10.0f * user.weight) + (6.25f * h_cm) - (5.0f * user.age) - 161.0f;
        }
        cout << "\n --- Select your Activity Level --- \n 1. Sedentary (Little to no exercise) . \n 2. Lightly Active (1-3 days/week) . \n 3. Moderately Active (3-5 days/week) .\n 4. Very Active (6-7 days/week) .\n 5. Extra Active (Physical job or 2x training) " << endl;
        int o;
        float aFac;
        cin >> o;
        switch (o) {
        case 1: aFac = 1.2f; break;
        case 2: aFac = 1.375f; break;
        case 3: aFac = 1.55f; break;
        case 4: aFac = 1.725f; break;
        case 5: aFac = 1.9f; break;
        default: aFac = 1.2f;
        }
        float tdee = bmr * aFac;

        cout << "\nDear [" << user.name << "]," << endl;
        cout << "Your BMR (Resting Energy): " << bmr << " Calories/Day." << endl;
        cout << "Your TDEE (Total Maintenance Calories): " << tdee << " Calories/Day." << endl;
        cout << "------------------------------------------------" << endl;
        cout << "To lose weight: Eat around " << tdee - 500 << " Calories." << endl;
        cout << "To gain weight: Eat around " << tdee + 500 << " Calories." << endl;

        saveRecord(user.name, "TDEE", tdee);


        char a;
        cout << "Do you like to calculate another service ? ( Y / N ) : " << endl;
        cin >> a;
        if (a == 'Y' || a == 'y') {
            goto y;
        }
        else if (a == 'N' || a == 'n') {
            goto x;
        }
    }break; //---------------------------- END Case 4 ----------------------------TDEE//
    case 5: { //---------------------------- Case 5 ----------------------------History//
        showHistory();
        char a;
        cout << " Do you like to back to main menu ? ( Y / N ) : " << endl;
        cin >> a;
        if (a == 'Y' || a == 'y') {
            goto y;
        }
        else if (a == 'N' || a == 'n') {
            goto x;
        }
    } break; //---------------------------- END Case 5 ----------------------------History//

    case 6: { //---------------------------- Case 6 ----------------------------Exit//
    x:
        cout << "Stay healthy! Goodbye [" << user.name << "]." << endl;

    } break; //---------------------------- END Case 6----------------------------Exit//
    } // Switch (x)
} // main().
