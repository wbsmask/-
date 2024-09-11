#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

class student {
protected:
    double id;
    string name;
    double age;
    string gender;
    double num;
    static int count;
    double sub_score[50];
public:
    student() :id(0), name(""), age(0), gender(""), num(0), sub_score() {}
    void menu();
    void record(int);
    void add(int);
    void show();
    void find();
    void sort();
    void Delete();
    void change();
    void ave();
    friend ostream& operator <<(ostream&, student&);
};

int student::count = 0;
static int n = 0;
static student stu[100];

ostream& operator <<(ostream& output, student & a)
{
    output << "学号:" << a.id << endl
           << "姓名:" << a.name << endl
           << "年龄:" << a.age << endl
           << "性别:" << a.gender << endl
           << "课程分数:";
    for (int j = 0; j < a.num; j++) {
            output << a.sub_score[j] << endl;
    
    }
    return output;
}

void student::menu() {   //菜单
    int choice;
    do {
        cout << " " << "功能菜单：" << endl;
        cout << "|" << "学生信息 录入" << "|" << "输入1" << endl;
        cout << "|" << "学生信息 新增" << "|" << "输入2" << endl;
        cout << "|" << "学生信息 显示" << "|" << "输入3" << endl;
        cout << "|" << "学生信息 查询" << "|" << "输入4" << endl;
        cout << "|" << "学生信息 排序" << "|" << "输入5" << endl;
        cout << "|" << "学生信息 删除" << "|" << "输入6" << endl;
        cout << "|" << "学生信息 修改" << "|" << "输入7" << endl;
        cout << "|" << "平均成绩 计算" << "|" << "输入8" << endl;
        cin >> choice;

        switch (choice) {
        case 1:    //功能一
            cout << "需录入学生信息人数：";
            cin >> count;
            for (int i = 0; i < count; i++) {
                cout << endl << "当前已录入学生人数: " << n << endl << endl;
                n++;
                record(i);
            }
            break;
        case 2:   //功能二
            int add_count;
            cout << endl << "新增加学生信息人数：";
            cin >> add_count;
            for (int i = 0; i < add_count; i++) {
                cout << "当前已录入学生人数: " << n << endl << endl;
                n++;
                add(i);
            }
            count += add_count;
            break;
        case 3:  //功能三
            show();
            break;

        case 4: //功能四
            find();
            break;
        case 5: //功能五
            sort();
            break;
        case 6: //功能六
            Delete();
            break;
        case 7://功能七
            change();
            break;
        case 8://功能八
            ave();
            break;
        default:
            cout << "无效选择，请重新输入。" << std::endl;
        }
        cout << "是否继续操作？（y/n）";
        char continueChoice;
        cin >> continueChoice;
        if (continueChoice != 'y' && continueChoice != 'Y') return;

    } while (1);
}

void student::record(int i) {     //录入学生信息
    ofstream outfile;
    outfile.open("学生信息.txt", ios::app);
    if (!outfile) {
        cerr << "文件打开失败，请重试" << endl;
        exit(1);
    }
    cout << "输入学号："; cin >> stu[i].id;
    cout << "输入姓名："; cin >> stu[i].name;
    cout << "输入年龄："; cin >> stu[i].age;
    cout << "输入性别(b/g)："; cin >> stu[i].gender;
    cout << "课程数"; cin >> stu[i].num;
    cout << "请输入" << stu[i].num << "门课程成绩：" << endl;
    for (int j = 0; j < stu[i].num; j++) 
    cin >> stu[i].sub_score[j];
    outfile << endl << "学号:" << stu[i].id << endl << "姓名:" << stu[i].name << endl
        << "年龄:" << stu[i].age << endl << "性别:" << stu[i].gender << endl
        << "课程数:" << stu[i].num << endl;
    for (int j = 0; j < stu[i].num; j++) {
        outfile << "课程" << j + 1 << "分数: " << stu[i].sub_score[j] << endl;
    }
    outfile.close();
}

void student::add(int i) {    //增加学生信息
    ofstream outfile;
    outfile.open("学生信息.txt", ios::app);
    if (!outfile) {
        std::cerr << "文件打开失败，请重试" << std::endl;
        exit(1);
    }
    cout << "输入学号："; cin >> stu[count+i].id;
    cout << "输入姓名："; cin >> stu[count + i].name;
    cout << "输入年龄："; cin >> stu[count + i].age;
    cout << "输入性别(b/g)："; cin >> stu[count + i].gender;
    cout << "课程数"; cin >> stu[count + i].num;
    cout << "请输入" << stu[count + i].num << "门课程成绩：" << endl;
    for (int i = 0; i < stu[count + i].num; i++) {
        cin >> stu[i].sub_score[i];
    }
    outfile << endl << "学号:" << stu[count + i].id << endl << "姓名:" << stu[count + i].name << endl
        << "年龄:" << stu[count + i].age << endl << "性别:" << stu[count + i].gender << endl
        << "课程数:" << stu[count + i].num << endl;
    for (int j = 0; j < stu[i].num; j++) {
        outfile << "课程" << j + 1 << "分数: " << stu[i].sub_score[j] << endl;
    }
    outfile.close();
}

void student::show() {     //显示学生信息
    ifstream infile("学生信息.txt", ios::in);
    if (!infile) {
        std::cerr << "文件打开失败，请重试" << std::endl;
        exit(1);
    }
    string line;
    while (getline(infile, line)) {/*逐行读取数据*/
        cout << line << endl;
    }
    infile.close();
}

void student::find() {
    int option;
    int i = 0;
    cout << "选择查询方式：" << endl;
    cout << "1. 按学号查询" << endl;
    cout << "2. 按姓名查询" << endl;
    cin >> option;
    bool found = false;
    if (option == 1) {
        cout << "输入查找的学生的学号：" << endl;
        int find_id;
        cin >> find_id;
        while (true) {
            if (stu[i].id == find_id) {
                cout << stu[i];
                found = true;  /*在found变为true之前，如果条件不满足，不会执行第一个break。第一个break是在找到学生信息（即found被设置为true）后才执行的，目的是跳出循环。*/
                break;
            }
            i++;
            if (i > 100) {
                cout << "未找到该学号的学生信息。" << endl;
                break;
            }
        }
    }
    if (option == 2) {
        cout << "输入查找的学生的姓名：" << endl;
        string find_name;
        cin >> find_name;
        while (true) {
            if (stu[i].name == find_name) {
                cout << stu[i];
                found = true;
                break;
            }
            i++;
            if (i > 100) {
                cout << "未找到该学号的学生信息。" << endl;
                break;
            }
        }
    }
    if (!found && (option == 1 || option == 2)) {
        cout << "未找到该学生信息。" << endl;
    }
}

void student::sort() {
    cout << "选择排序方式：" << endl;
    cout << "1. 按学号排序" << endl;
    cout << "2. 按年龄排序" << endl;
    int option;
    cin >> option;

    if (option == 1) {                               
        for (int i = 0; i < count - 1; i++) {                       // 先对数组中的学生信息进行排序
            for (int j = i + 1; j < count; j++) {
                if (stu[i].id > stu[j].id) {
                    student temp = stu[i];
                    stu[i] = stu[j];
                    stu[j] = temp;
                }
            }
        }
        ofstream outfile("学生信息.txt", ios::trunc);              //对文本中的学生信息进行排序更新
        if (!outfile) {
            cerr << "文件打开失败，请重试" << endl;
            exit(1);
        }
        for (int i = 0; i < count; i++) {
            outfile << endl << "学号:" << stu[i].id << endl << "姓名:" << stu[i].name << endl
                << "年龄:" << stu[i].age << endl << "性别:" << stu[i].gender << endl
                << "课程数:" << stu[i].num << endl;
            for (int j = 0; j < stu[i].num; j++) {
                outfile << "课程" << j + 1 << "分数: " << stu[i].sub_score[j] << endl;
            }
        }
        outfile.close();
    }
    if (option == 2) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (stu[i].age > stu[j].age) {
                    student temp = stu[i];
                    stu[i] = stu[j];
                    stu[j] = temp;
                }
            }
        }
        ofstream outfile("学生信息.txt", ios::trunc);
        if (!outfile) {
            cerr << "文件打开失败，请重试" << endl;
            exit(1);
        }
        for (int i = 0; i < count; i++) {
            outfile << endl << "学号:" << stu[i].id << endl << "姓名:" << stu[i].name << endl
                << "年龄:" << stu[i].age << endl << "性别:" << stu[i].gender << endl
                << "课程数:" << stu[i].num << endl;
            for (int j = 0; j < stu[i].num; j++) {
                outfile << "课程" << j + 1 << "分数: " << stu[i].sub_score[j] << endl;
            }
        }
        outfile.close();
    }
    else {
        cout << "无效选择。" << endl;
    }
}

void student::Delete() {
    int option;
    cout << "选择删除方式：" << endl;
    cout << "1. 按学号删除" << endl;
    cout << "2. 按姓名删除" << endl;
    cin >> option;

    ifstream infile("学生信息.txt", ios::in);
    if (!infile) {
        std::cerr << "文件打开失败，请重试" << std::endl;
        exit(1);
    }

    ofstream outfile("temp.txt", ios::out);
    if (!outfile) {
        std::cerr << "临时文件创建失败，请重试" << std::endl;
        exit(1);
    }

    string line;
    bool found = false;

    if (option == 1) {
        cout << "输入要删除的学生的学号：" << endl;
        int find_id;
        cin >> find_id;
        while (getline(infile, line)) {
            if (line.find("学号:") != string::npos) {
                int id = stoi(line.substr(line.find(":") + 1));
                getline(infile, line);
                string name = line.substr(line.find(":") + 1);
                getline(infile, line);
                double age = stod(line.substr(line.find(":") + 1));
                getline(infile, line);
                string gender = line.substr(line.find(":") + 1);
                getline(infile, line);
                double num = stod(line.substr(line.find(":") + 1));
                double sub_scores[50];
                for (int j = 0; j < num; j++) {
                    getline(infile, line);
                }

                if (id != find_id) {
                    outfile << endl << "学号:" << id << endl << "姓名:" << name << endl
                        << "年龄:" << age << endl << "性别:" << gender << endl
                        << "课程数:" << num << endl;
                    for (int j = 0; j < num; j++) {
                        outfile << "课程" << j + 1 << "分数: " << sub_scores[j] << endl;
                    }
                }
                else {
                    found = true;
                }
            }
        }
    }
    if (option == 2) {
        cout << "输入要删除的学生的姓名：" << endl;
        string find_name;
        cin >> find_name;
        while (getline(infile, line)) {
            if (line.find("学号:") != string::npos) {
                int id = stoi(line.substr(line.find(":") + 1));
                getline(infile, line);
                string name = line.substr(line.find(":") + 1);
                getline(infile, line);
                double age = stod(line.substr(line.find(":") + 1));
                getline(infile, line);
                string gender = line.substr(line.find(":") + 1);
                getline(infile, line);
                double num = stod(line.substr(line.find(":") + 1));
                double sub_scores[50];
                for (int j = 0; j < num; j++) {
                    getline(infile, line);
                }

                if (name != find_name) {
                    outfile << endl << "学号:" << id << endl << "姓名:" << name << endl
                        << "年龄:" << age << endl << "性别:" << gender << endl
                        << "课程数:" << num << endl;
                    for (int j = 0; j < num; j++) {
                        outfile << "课程" << j + 1 << "分数: " << sub_scores[j] << endl;
                    }
                }
                else {
                    found = true;
                }
            }
        }
    }

    infile.close();
    outfile.close();

    if (found) {
        remove("学生信息.txt");
        rename("temp.txt", "学生信息.txt");
        cout << "学生信息删除成功。" << endl;
    }
    else {
        remove("temp.txt");
        cout << "未找到该学生信息，无法删除。" << endl;
    }
}

void student::change() {
    int option;
    cout << "选择修改方式：" << endl;
    cout << "1. 按学号修改" << endl;
    cout << "2. 按姓名修改" << endl;
    cin >> option;

    ifstream infile("学生信息.txt", ios::in);
    if (!infile) {
        std::cerr << "文件打开失败，请重试" << std::endl;
        exit(1);
    }

    ofstream outfile("temp.txt", ios::out);
    if (!outfile) {
        std::cerr << "临时文件创建失败，请重试" << std::endl;
        exit(1);
    }

    string line;
    bool found = false;

    if (option == 1) {
        cout << "输入要修改的学生的学号：" << endl;
        int find_id;
        cin >> find_id;
        while (getline(infile, line)) {
            if (line.find("学号:") != string::npos) {
                int id = stoi(line.substr(line.find(":") + 1));
                getline(infile, line);
                string name = line.substr(line.find(":") + 1);
                getline(infile, line);
                double age = stod(line.substr(line.find(":") + 1));
                getline(infile, line);
                string gender = line.substr(line.find(":") + 1);
                getline(infile, line);
                double num = stod(line.substr(line.find(":") + 1));
                double sub_scores[50];
                for (int j = 0; j < num; j++) {
                    getline(infile, line);
                }

                if (id == find_id) {
                    found = true;
                    cout << "输入新的学号："; cin >> id;
                    cout << "输入新的姓名："; cin >> name;
                    cout << "输入新的年龄："; cin >> age;
                    cout << "输入新的性别(b/g)："; cin >> gender;
                    cout << "输入新的课程数："; cin >> num;
                    cout << "请输入" << num << "门课程成绩：" << endl;
                    for (int j = 0; j < num; j++) {
                        cin >> sub_scores[j];
                    }
                }

                outfile << endl << "学号:" << id << endl << "姓名:" << name << endl
                    << "年龄:" << age << endl << "性别:" << gender << endl
                    << "课程数:" << num << endl;
                for (int j = 0; j < num; j++) {
                    outfile << "课程" << j + 1 << "分数: " << sub_scores[j] << endl;
                }
            }
        }
    }
    if (option == 2) {
        cout << "输入要修改的学生的姓名：" << endl;
        string find_name;
        cin >> find_name;
        while (getline(infile, line)) {
            if (line.find("学号:") != string::npos) {
                int id = stoi(line.substr(line.find(":") + 1));
                getline(infile, line);
                string name = line.substr(line.find(":") + 1);
                getline(infile, line);
                double age = stod(line.substr(line.find(":") + 1));
                getline(infile, line);
                string gender = line.substr(line.find(":") + 1);
                getline(infile, line);
                double num = stod(line.substr(line.find(":") + 1));
                double sub_scores[50];
                for (int j = 0; j < num; j++) {
                    getline(infile, line);
                }

                if (name == find_name) {
                    found = true;
                    cout << "输入新的学号："; cin >> id;
                    cout << "输入新的姓名："; cin >> name;
                    cout << "输入新的年龄："; cin >> age;
                    cout << "输入新的性别(b/g)："; cin >> gender;
                    cout << "输入新的课程数："; cin >> num;
                    cout << "请输入" << num << "门课程成绩：" << endl;
                    for (int j = 0; j < num; j++) {
                        cin >> sub_scores[j];
                    }
                }

                outfile << endl << "学号:" << id << endl << "姓名:" << name << endl
                    << "年龄:" << age << endl << "性别:" << gender << endl
                    << "课程数:" << num << endl;
                for (int j = 0; j < num; j++) {
                    outfile << "课程" << j + 1 << "分数: " << sub_scores[j] << endl;
                }
            }
        }
    }

    infile.close();
    outfile.close();

    if (found) {
        remove("学生信息.txt");
        rename("temp.txt", "学生信息.txt");
        cout << "学生信息修改成功。" << endl;
    }
    else {
        remove("temp.txt");
        cout << "未找到该学生信息，无法修改。" << endl;
    }
}

void student::ave() {
    double average = 0;
    cout << "总成绩平均成绩:" << endl;
    for (int i = 0; i < count; i++)
        for (int j = 0; j < num; j++)
            average += stu[i].sub_score[j];
    average = (double)average / count;
    cout << average << endl;

    cout << "单科成绩平均分:" << endl;
    average = 0;
    for (int i = 0; i < count; i++)
        average += stu[i].sub_score[0];
    average = (double)average / count;
    cout << average << endl;
    for (int i = 0; i < count; i++)
        average += stu[i].sub_score[1];
    average = (double)average / count;
    cout << average << endl;
}

int main() {
    student stu;
    stu.menu();
    return 0;
}

