#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class String{
    public:
        static string to_string(int a);
};

string String::to_string(int a){
    ostringstream number;
    number << a;
    return number.str();
}

class Date{
    private:
        int day;
        int month;
        int year;

    public:
    	Date(){ //constructor
            day = 1;
            month = 1;
            year = 1900;
        }

        void initialize(int, int, int);
        string get_formatted_date(int day, int month, int year);
};

void Date::initialize (int day1, int month1, int year1){
    if(day1<=31 && day1>0 && month1 >0 && month1<13 && year1 >1900){
        month = month1;
        day = day1;
    }
    else{
        cout << "Your parameters are incorrect" << endl;
    }
}

string Date::get_formatted_date(int day, int month, int year){
    return String::to_string(year)+ ',' + String::to_string(month) +'-' + String::to_string(day);
}

class Student{
    private:
        string first_name;
        string last_name;
        Date birth_date;
        string faculty_name;
        string student_id;

    public:
        static int unique_number;

        Student(string fn, string ln, string faculty){ //constructor
            first_name = fn;
            last_name = ln;
            faculty_name = faculty;
            student_id = "AUA_" + faculty_name + "_" + String::to_string(unique_number);
            unique_number++;
        }

        Student (Student & student) { //copy constructor
            faculty_name = student.faculty_name;
            student_id = "AUA_"+faculty_name+"_" + String::to_string(unique_number);
            unique_number++;
        }

        void set_birth_date(int day, int month, int year){
            birth_date.initialize(day, month, year);
        }

        void set_name(string fn, string sn){
            first_name = fn;
            last_name = sn;
        }

        string get_birth_date(){
            return birth_date.get_formatted_date();
        }

        string get_first_name(){
            return first_name;
        }

        string get_last_name(){
            return last_name;
        }

        string get_id(){
            return student_id;
        }
        string get_name(){
            string name = first_name + " " + last_name;
            return name;
        }
};

int main(){
Student s("Aram", "Grigoryan", "CS"); //constructor
s.set_birth_date(12, 7, 1995);

Student d(s); //copy constructor
d.set_name("Anna", "Sargsyan");
d.set_birth_date(1, 5, 1995);

std::cout << "Below is the information about the registered students"
<< std::endl;
std::cout << s.get_name() << " " << s.get_id()<< std::endl;
std::cout << s.get_birth_date() << std::endl;

std::cout << d.get_name() << " " << d.get_id()<< std::endl;
std::cout << d.get_birth_date() << std::endl;

}
