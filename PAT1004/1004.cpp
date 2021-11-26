#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Student {
public:
    Student() {
        cin >> this->name;
        cin >> this->number;
        cin >> this->grade;

    }
    string getInformation() {
        return (this->name + " " + this->number);
    }
    int getGrade() {
        return grade;
    }
private:
    string name;
    string number;
    int grade;
};


int main() {
    vector<Student*> s;
    int n;
    cin >> n;
    int max = 0;
    int m = 0;
    int min = 1000;//如果为0部分测试通过不了
    int in = 0;
    for (int i = 0; i < n; ++i) {
        s.push_back(new Student);
    }
    for (int i = 0; i < n; ++i) {
        if (s[i]->getGrade() > max) {
            max = s[i]->getGrade();
            m = i;
        }
    }
    cout << s[m]->getInformation() << endl;
    for (int i = 0; i < n; ++i) {
        if (s[i]->getGrade() < min) {
            min = s[i]->getGrade();
            in = i;
        }
    }
    cout << s[in]->getInformation();
    //delete []s;
    //*s = NULL;
    return 0;
}
