#include<iostream>   // library for input and output  // مكتبة الادخال والاخراج
#include<string>     // library for string type       // مكتبة النصوص
#include<fstream>    // library for file handling     // مكتبة التعامل مع الملفات
#include<cmath>      // library for math operations   // مكتبة العمليات الرياضية
#include<vector>     // library for vectors           // مكتبة الفكتور
using namespace std; // to avoid writing std::        // لتجنب كتابة std في كل مرة

// structure to store user information
// هيكل لتخزين بيانات المستخدم
struct person {
    string name;      // user name // اسم المستخدم
    int age = 0;      // user age // عمر المستخدم
    float weight = 0.0f; // user weight // وزن المستخدم
    float height = 0.0f; // user height // طول المستخدم
    char gen;         // gender (M/F) // الجنس
};

// function to save records in a file
// دالة لحفظ النتائج في ملف
void saveRecord(string userName, string serviceType, float calcResult) {

    ofstream outFile("UserHistory.txt", ios::app);
    // open file in append mode
    // فتح الملف بوضع الاضافة حتى لا تنحذف البيانات القديمة

    if (outFile.is_open()) {

        outFile << " Name : " << userName << "|| Service : " << serviceType << "|| Result : " << calcResult << endl;
        // writing user information to the file
        // كتابة معلومات المستخدم في الملف

        outFile << "------------------------------------" << endl;

        outFile.close(); // close the file // اغلاق الملف
    }
    else {
        cerr << " Error : Could not save the record !" << endl;
        // error message if file cannot open
        // رسالة خطأ اذا لم يفتح الملف
    }
};

// function to display previous records
// دالة لعرض السجلات السابقة
void showHistory() {

    ifstream inFile("UserHistory.txt"); // open the file for reading // فتح الملف للقراءة
    string line; // variable to store each line // متغير لخزن كل سطر

    cout << "\n --- The Previous Records --- \n" << endl;

    if (inFile.is_open()) {

        while (getline(inFile, line)) { // read file line by line // قراءة الملف سطر سطر
            cout << line << endl;       // print the line // طباعة السطر
        }

        inFile.close(); // close the file // اغلاق الملف
    }
    else {
        cout << "No records found yet!" << endl;
        // message if file is empty or not created
        // رسالة اذا لم توجد سجلات
    }
}

// function to calculate BMI
// دالة لحساب مؤشر كتلة الجسم
float calculateBMI(float weightValue, float heightValue) {

    if (heightValue == 0) return 0;
    // prevent division by zero
    // منع القسمة على صفر

    return weightValue / (heightValue * heightValue);
    // BMI formula
    // معادلة حساب BMI
}

int main() {

y: // label to return to main menu
    // علامة للرجوع للقائمة الرئيسية

    person currentUser;
    // object from person structure
    // كائن من الهيكل person

    cout << " ============ Health Managment System ============" << endl;

    cout << " Enter a number to choose a service from the following : \n 1. Body Mass Index (BMI) . \n 2. Body Fat Percentage (BFP) . \n 3. Basal Metabolic Rate (BMR) . \n 4. Total Daily Energy Expenditure (TDEE).  \n 5. Last records . \n 6. Exit . " << endl;

    int menuChoice; // variable to store menu selection // متغير لحفظ اختيار القائمة

    cin >> menuChoice;

    switch (menuChoice) {
        //---------------------------- Case 1 ----------------------------BMI//
    case 1: {
        cout << " Welcome to the Body Mass Index (BMI) service ." << endl;
        // welcome message for BMI service
        // رسالة ترحيب لخدمة BMI

        cout << " You must enter the following : \n 1. Enter your name : " << endl;
        getline(cin >> ws, currentUser.name);
        // read user name including spaces
        // قراءة الاسم بما يشمل الفراغات

        int validName = 1;
        // flag to check if name is valid
        // علم لتحديد صحة الاسم

        for (int i = 0; i < currentUser.name.length(); i++) {
            if (!isalpha(currentUser.name[i]) && currentUser.name[i] != ' ')
                validName = 0;
            break;
        }

        if (validName == 1) {
            cout << " Valid name ." << endl; // valid name message // الاسم صحيح
        }
        else {
            cerr << " Invalid name ! Only letters allowed ." << endl;
            // error if invalid name // خطأ اذا الاسم غير صحيح
            getline(cin >> ws, currentUser.name);
            // re-enter name // إعادة ادخال الاسم
        }

        cout << " Welcome dear [" << currentUser.name << "] ." << endl;

        cout << " 2. You must choose a measure unit for the length : \n for : Centimeter --> (C) , for : Inches --> (I) . " << endl;

        float heightInput; // variable to read height input // متغير لحفظ الطول المدخل
        char heightUnit;   // variable for unit selection // متغير لاختيار الوحدة

        cin >> heightUnit;

        if (heightUnit == 'C' || heightUnit == 'c') {
            cout << "Enter your length in (cm) unit : " << endl;
            cin >> heightInput;
            currentUser.height = heightInput / 100.0f;
            // convert cm to meters // تحويل من سم الى متر
        }
        else if (heightUnit == 'I' || heightUnit == 'i') {
            cout << "Enter your length in (Inches) unit: " << endl;
            cin >> heightInput;
            currentUser.height = heightInput * 0.0254f;
            // convert inches to meters // تحويل انش الى متر
        }
        else {
            do {
                cerr << "Invalid input , Try again : " << endl;
                cin >> heightUnit;
            } while (heightUnit != 'I' && heightUnit != 'i' && heightUnit != 'C' && heightUnit != 'c');
        }

        cout << " 3. You must choose a unit for weight : for (pound) choose --> (P) , for (Kilo gram) choose --> (k) " << endl;

        char weightUnit;
        float poundWeight = 0.0f;

        cin >> weightUnit;

        if (weightUnit == 'K' || weightUnit == 'k') {
            cout << " || Enter your weight in (Kg) unit : " << endl;
            cin >> currentUser.weight;
        }
        else if (weightUnit == 'p' || weightUnit == 'P') {
            cout << " || Enter your weight in (pound) unit : " << endl;
            cin >> poundWeight;
            currentUser.weight = poundWeight * 0.453592f;
            // convert pounds to kg // تحويل من رطل الى كغ
        }
        else {
            do {
                cerr << "Invalid input , Please try again . " << endl;
                cin >> weightUnit;
            } while (weightUnit != 'K' && weightUnit != 'k' && weightUnit != 'P' && weightUnit != 'p');
        }

        float bmiResult = currentUser.weight / (currentUser.height * currentUser.height);
        // calculate BMI // حساب BMI

        cout << "Dear [" << currentUser.name << "] , Your BMI result is : " << bmiResult << " Kg/m*m" << endl;

        if (bmiResult < 18.5) cout << " Status : Underweight" << endl;
        else if (bmiResult < 24.9) cout << " Status : Healthy weight" << endl;
        else if (bmiResult < 29.9) cout << " Status : Overweight" << endl;
        else cout << " Status : Obesity " << endl;

        saveRecord(currentUser.name, "BMI", bmiResult);
        // save BMI result // حفظ نتيجة BMI

        char userAnswer;
        cout << "Do you like to calculate another service ? ( Y / N ) : " << endl;
        cin >> userAnswer;

        if (userAnswer == 'Y' || userAnswer == 'y') {
            goto y;
        }
        else if (userAnswer == 'N' || userAnswer == 'n') {
            goto x;
        }

    } break;
          //---------------------------- END Case 1 ----------------------------BMI//

          //---------------------------- Case 2 ----------------------------BFP//
    case 2: {
        cout << " Welcome to the Body Fat Percentage calculator (BFP) . " << endl;
        // welcome message for BFP
        // رسالة ترحيب لخدمة BFP

        cout << " 1. Enter your name : " << endl;
        getline(cin >> ws, currentUser.name);

        int validName = 1;

        for (int i = 0; i < currentUser.name.length(); i++) {
            if (!isalpha(currentUser.name[i]) && currentUser.name[i] != ' ')
                validName = 0;
            break;
        }

        if (validName == 1) {
            cout << " Valid name ." << endl;
        }
        else {
            cerr << " Invalid name ! Only letters allowed ." << endl;
            getline(cin >> ws, currentUser.name);
        }

        cout << " Welcome dear [" << currentUser.name << "] ." << endl;

        cout << " 2. Enter your age : " << endl;
        cin >> currentUser.age;

        cout << "Noted . \n || Choose a unit to enter your weight : for (pound) choose --> (P) , for (Kilo gram) choose --> (k) " << endl;

        char weightUnit;
        float poundWeight = 0.0f;
        cin >> weightUnit;

        if (weightUnit == 'K' || weightUnit == 'k') {
            cout << " Noted || Enter your weight in (Kg) unit : " << endl;
            cin >> currentUser.weight;
        }
        else if (weightUnit == 'P' || weightUnit == 'p') {
            cout << "Enter your weight in (Pound) unit : " << endl;
            cin >> poundWeight;
            currentUser.weight = poundWeight * 0.453592f;
        }
        else {
            do {
                cerr << "Invalid input , Please try again . " << endl;
                cin >> weightUnit;
            } while (weightUnit != 'K' && weightUnit != 'k' && weightUnit != 'P' && weightUnit != 'p');
        }

        cout << " 2. You must choose a measure unit for the length : \n for : Centimeter --> (C) , for : Inches --> (I) . " << endl;
        float heightInput;
        char heightUnit;
        cin >> heightUnit;

        if (heightUnit == 'C' || heightUnit == 'c') {
            cout << "Enter your length in (cm) unit : " << endl;
            cin >> heightInput;
            currentUser.height = heightInput / 100.0f;
        }
        else if (heightUnit == 'I' || heightUnit == 'i') {
            cout << "Enter your length in (Inches) unit: " << endl;
            cin >> heightInput;
            currentUser.height = heightInput * 0.0254f;
        }
        else {
            do {
                cerr << "Invalid input , Try again : " << endl;
                cin >> heightUnit;
            } while (heightUnit != 'I' && heightUnit != 'i' && heightUnit != 'C' && heightUnit != 'c');
        }

        float currentBMI = calculateBMI(currentUser.weight, currentUser.height);
        // calculate BMI first for BFP // حساب BMI اولا لحساب BFP

        float bfpResult = 0.0f;

        cout << "Enter your gender ( Either (M) Or (F) ) : " << endl;
        cin >> currentUser.gen;

        float genderValue = (currentUser.gen == 'M' || currentUser.gen == 'm') ? 1.0f : 0.0f;
        // male = 1 , female = 0 // ذكر =1 انثى=0

        bfpResult = (1.20 * currentBMI) + (0.23 * currentUser.age) - (10.8 * genderValue) - 5.4;
        // BFP formula // معادلة نسبة الدهون

        cout << "Your Body Fat percentage is : { " << bfpResult << "% } ." << endl;

        saveRecord(currentUser.name, "BFP", bfpResult);
        // save BFP result // حفظ نتيجة BFP

        char userAnswer;
        cout << "Do you like to calculate another service ? ( Y / N ) : " << endl;
        cin >> userAnswer;

        if (userAnswer == 'Y' || userAnswer == 'y') {
            goto y;
        }
        else if (userAnswer == 'N' || userAnswer == 'n') {
            goto x;
        }

    } break;
          //---------------------------- END Case 2 ----------------------------BFP//
    //---------------------------- Case 3 ----------------------------BMR//
case 3: {
    cout << " Welcome to the Body Metabolic Rate (BMR) . " << endl;
    // welcome message for BMR
    // رسالة ترحيب لخدمة BMR

    cout << " 1. Enter your name : " << endl;
    getline(cin >> ws, currentUser.name);

    int validName = 1;

    for (int i = 0; i < currentUser.name.length(); i++) {
        if (!isalpha(currentUser.name[i]) && currentUser.name[i] != ' ')
            validName = 0;
        break;
    }

    if (validName == 1) {
        cout << " Valid name ." << endl;
    }
    else {
        cerr << " Invalid name ! Only letters allowed ." << endl;
        getline(cin >> ws, currentUser.name);
    }

    cout << " Welcome dear [" << currentUser.name << "] ." << endl;

    cout << " 2. Enter your age : " << endl;
    cin >> currentUser.age;

    cout << "Noted . \n || Choose a unit to enter your weight : for (pound) choose --> (P) , for (Kilo gram) choose --> (k) " << endl;

    char weightUnit;
    float poundWeight = 0.0f;
    cin >> weightUnit;

    if (weightUnit == 'K' || weightUnit == 'k') {
        cout << " Noted || Enter your weight in (Kg) unit : " << endl;
        cin >> currentUser.weight;
    }
    else if (weightUnit == 'P' || weightUnit == 'p') {
        cout << "Enter your weight in (Pound) unit : " << endl;
        cin >> poundWeight;
        currentUser.weight = poundWeight * 0.453592f;
    }
    else {
        do {
            cerr << "Invalid input , Please try again . " << endl;
            cin >> weightUnit;
        } while (weightUnit != 'K' && weightUnit != 'k' && weightUnit != 'P' && weightUnit != 'p');
    }

    cout << " 2. You must choose a measure unit for the length : \n for : Centimeter --> (C) , for : Inches --> (I) . " << endl;
    float heightInput;
    char heightUnit;
    cin >> heightUnit;

    if (heightUnit == 'C' || heightUnit == 'c') {
        cout << "Enter your length in (cm) unit : " << endl;
        cin >> heightInput;
        currentUser.height = heightInput / 100.0f;
    }
    else if (heightUnit == 'I' || heightUnit == 'i') {
        cout << "Enter your length in (Inches) unit: " << endl;
        cin >> heightInput;
        currentUser.height = heightInput * 0.0254f;
    }
    else {
        do {
            cerr << "Invalid input , Try again : " << endl;
            cin >> heightUnit;
        } while (heightUnit != 'I' && heightUnit != 'i' && heightUnit != 'C' && heightUnit != 'c');
    }

    float bmrResult = 0.0f;
    float heightCM = currentUser.height * 100.0f;
    // convert height to cm for BMR formula // تحويل الطول للسنتيمتر

    cout << " Enter your gender : ( Either (M) Or (F) ) : " << endl;
    cin >> currentUser.gen;

    while (currentUser.gen != 'M' && currentUser.gen != 'm' && currentUser.gen != 'F' && currentUser.gen != 'f') {
        cerr << "Invalid input, Try again please: ";
        cin >> currentUser.gen;
    }

    if (currentUser.gen == 'M' || currentUser.gen == 'm') {
        bmrResult = (10.0f * currentUser.weight) + (6.25f * heightCM) - (5.0f * currentUser.age) + 5.0f;
    }
    else {
        bmrResult = (10.0f * currentUser.weight) + (6.25f * heightCM) - (5.0f * currentUser.age) - 161.0f;
    }

    cout << "Dear [" << currentUser.name << "], your BMR is: " << bmrResult << " Calories/Day." << endl;
    cout << "This is the energy your body needs to function at rest." << endl;

    saveRecord(currentUser.name, "BMR", bmrResult);
    // save BMR result // حفظ نتيجة BMR

    char userAnswer;
    cout << "Do you like to calculate another service ? ( Y / N ) : " << endl;
    cin >> userAnswer;
    if (userAnswer == 'Y' || userAnswer == 'y') {
        goto y;
    }
    else if (userAnswer == 'N' || userAnswer == 'n') {
        goto x;
    }

} break;
      //---------------------------- END Case 3 ----------------------------BMR//

      //---------------------------- Case 4 ----------------------------TDEE//
case 4: {
    cout << " Welcome to the Total Daily Energy Expenditure (TDEE) . " << endl;
    // welcome message for TDEE
    // رسالة ترحيب لخدمة TDEE

    cout << " 1. Enter your name : " << endl;
    getline(cin >> ws, currentUser.name);

    int validName = 1;
    for (int i = 0; i < currentUser.name.length(); i++) {
        if (!isalpha(currentUser.name[i]) && currentUser.name[i] != ' ')
            validName = 0;
        break;
    }
    if (validName == 1) {
        cout << " Valid name ." << endl;
    }
    else {
        cerr << " Invalid name ! Only letters allowed ." << endl;
        getline(cin >> ws, currentUser.name);
    }

    cout << " Welcome dear [" << currentUser.name << "] ." << endl;

    cout << " 2. Enter your age : " << endl;
    cin >> currentUser.age;

    cout << "Noted . \n || Choose a unit to enter your weight : for (pound) choose --> (P) , for (Kilo gram) choose --> (k) " << endl;

    char weightUnit;
    float poundWeight = 0.0f;
    cin >> weightUnit;

    if (weightUnit == 'K' || weightUnit == 'k') {
        cout << " Noted || Enter your weight in (Kg) unit : " << endl;
        cin >> currentUser.weight;
    }
    else if (weightUnit == 'P' || weightUnit == 'p') {
        cout << "Enter your weight in (pound) unit : " << endl;
        cin >> poundWeight;
        currentUser.weight = poundWeight * 0.453592f;
    }
    else {
        do {
            cerr << "Invalid input , Please try again . " << endl;
            cin >> weightUnit;
        } while (weightUnit != 'K' && weightUnit != 'k' && weightUnit != 'P' && weightUnit != 'p');
    }

    cout << " You must choose a measure unit for the length : \n for : Centimeter --> (C) , for : Inches --> (I) . " << endl;
    float heightInput;
    char heightUnit;
    cin >> heightUnit;

    if (heightUnit == 'C' || heightUnit == 'c') {
        cout << "Enter your length in (cm) unit : " << endl;
        cin >> heightInput;
        currentUser.height = heightInput / 100.0f;
    }
    else if (heightUnit == 'I' || heightUnit == 'i') {
        cout << "Enter your length in (Inches) unit: " << endl;
        cin >> heightInput;
        currentUser.height = heightInput * 0.0254f;
    }
    else {
        do {
            cerr << "Invalid input , Try again : " << endl;
            cin >> heightUnit;
        } while (heightUnit != 'I' && heightUnit != 'i' && heightUnit != 'C' && heightUnit != 'c');
    }

    float bmrResult = 0.0f;
    float heightCM = currentUser.height * 100.0f;

    if (currentUser.gen == 'M' || currentUser.gen == 'm') {
        bmrResult = (10.0f * currentUser.weight) + (6.25f * heightCM) - (5.0f * currentUser.age) + 5.0f;
    }
    else {
        bmrResult = (10.0f * currentUser.weight) + (6.25f * heightCM) - (5.0f * currentUser.age) - 161.0f;
    }

    cout << "\n --- Select your Activity Level --- \n 1. Sedentary (Little to no exercise) . \n 2. Lightly Active (1-3 days/week) . \n 3. Moderately Active (3-5 days/week) .\n 4. Very Active (6-7 days/week) .\n 5. Extra Active (Physical job or 2x training) ." << endl;

    int activityChoice;
    float activityFactor;

    cin >> activityChoice;

    switch (activityChoice) {
    case 1: activityFactor = 1.2f; break;
    case 2: activityFactor = 1.375f; break;
    case 3: activityFactor = 1.55f; break;
    case 4: activityFactor = 1.725f; break;
    case 5: activityFactor = 1.9f; break;
    default: activityFactor = 1.2f;
    }

    float tdeeResult = bmrResult * activityFactor;
    // calculate TDEE // حساب TDEE

    cout << "\nDear [" << currentUser.name << "]," << endl;
    cout << "Your BMR (Resting Energy): " << bmrResult << " Calories/Day." << endl;
    cout << "Your TDEE (Total Maintenance Calories): " << tdeeResult << " Calories/Day." << endl;
    cout << "------------------------------------------------" << endl;
    cout << "To lose weight: Eat around " << tdeeResult - 500 << " Calories." << endl;
    cout << "To gain weight: Eat around " << tdeeResult + 500 << " Calories." << endl;

    saveRecord(currentUser.name, "TDEE", tdeeResult);
    // save TDEE result // حفظ نتيجة TDEE

    char userAnswer;
    cout << "Do you like to calculate another service ? ( Y / N ) : " << endl;
    cin >> userAnswer;
    if (userAnswer == 'Y' || userAnswer == 'y') {
        goto y;
    }
    else if (userAnswer == 'N' || userAnswer == 'n') {
        goto x;
    }

} break;
      //---------------------------- END Case 4 ----------------------------TDEE//

      //---------------------------- Case 5 ----------------------------History//
case 5: {
    showHistory();
    // display previous records // عرض السجلات السابقة

    char userAnswer;
    cout << " Do you like to back to main menu ? ( Y / N ) : " << endl;
    cin >> userAnswer;

    if (userAnswer == 'Y' || userAnswer == 'y') {
        goto y;
    }
    else if (userAnswer == 'N' || userAnswer == 'n') {
        goto x;
    }

} break;
      //---------------------------- END Case 5 ----------------------------History//

      //---------------------------- Case 6 ----------------------------Exit//
case 6: {
x:
    cout << "Stay healthy! Goodbye ." << endl;
    // exit message // رسالة الخروج
} break;
      //---------------------------- END Case 6----------------------------Exit//

} // end of switch(menuChoice)
} // end of main()
