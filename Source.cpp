#include"files_mg.h"
#include"admin.h"
#include "Source.h"

using namespace std;
 Graph g; 


int main() 
{
    files_mg f;
    f.load_coarse_data_from_files();
    f.load_std_data_from_files(); 
    Admin admin1("ziad", "Alibaba123");
    admin1.admins.push_back(admin1);
    Student s;
    while (true)
    {
        cout << "---Welcome to the ain shams University Management System!---" << endl;
        // Prompt the user to select their role
        cout << "Are you a student or an admin?\n";
        cout << "1. Student\n";
        cout << "2. Admin\n";
        int choice;
        cin >> choice;
        system("cls");
        if (choice == 2) {
            while (true)
            {
                string adminname, adminpassword;
                cout << "Enter your name " << endl;
                cin >> adminname;
                cout << "Enter your pssword " << endl;
                cin >> adminpassword;

                if (admin1.adminLogin(adminname, adminpassword) == true) {
                    bool flag = true;
                    while (flag)
                    {
                        int adminchoice;
                        system("cls");
                        cout << "1- Add a new student " << endl;
                        cout << "2- Add a new course" << endl;
                        cout << "3- Enter the course prerequisites" << endl;
                        cout << "4- View List of all students in a specific course" << endl;
                        cout << "5- Add course grade for each student." << endl;
                        cout << "6- View List of all courses(Finished - Progressed) of a specific student." << endl;
                        cout << "7- Edit all course data." << endl;
                        cout << "8- to exit." << endl;

                        cin >> adminchoice;
                        switch (adminchoice)
                        {
                        case 1:{string name;
                            cout << "Enter the student's name " << endl;
                            cin >> name;
                            int id;
                            cout << "Enter his id " << endl;
                            cin >> id;
                            string password;
                            cout << "Enter his password " << endl;
                            cin >> password;
                            int max_hours_allowed;
                            cout << "Enter his max hours allowed " << endl;
                            cin >> max_hours_allowed;
                            set<string>finished_courses;
                            cout << "Enter number of his finished courses " << endl;
                            int numoffinished;
                            cin >> numoffinished;
                            cout << "Enter his finished courses " << endl;
                            for (int i = 0; i < numoffinished; i++) {
                                string c;
                                cin >> c;
                                finished_courses.insert(c);
                            }
                            vector<double> gradesfor_finished_courses;
                            cout << "Enter his finished courses' grades " << endl;
                            for (int i = 0; i < numoffinished; i++) {
                                double c;
                                cin >> c;
                                gradesfor_finished_courses.push_back(c);
                            }
                            set<string>inprogress_courses;
                            cout << "Enter the number of his inprogress courses " << endl;
                            int numofinprogress;
                            cin >> numofinprogress;
                            cout << "Enter his inprogress courses " << endl;
                            for (int i = 0; i < numofinprogress; i++) {
                                string c;
                                cin >> c;
                                inprogress_courses.insert(c);
                            }
                            string academic_year;
                            cout << "Enter his academic year " << endl;
                            cin >> academic_year;
                            admin1.add_student(name, id, password, max_hours_allowed, finished_courses, gradesfor_finished_courses, inprogress_courses, academic_year); 
                            break;
                        }
                        case 2: {
                            string name;
                            cout << "Enter the course's name " << endl;
                            cin >> name;
                            int code;
                            cout << "enter it's code " << endl;
                            cin >> code;
                            bool requirement_or_elective{};
                            cout << "If it's required enter 1 and 2 if it's elective" << endl;
                            int test;
                            cin >> test;
                            if (test == 1) {
                                requirement_or_elective = true;
                            }
                            else if (test == 2) {
                                requirement_or_elective = false;
                            }
                            int max_num_std;
                            cout << "Enter the maximum number of students allowed to attend the course" << endl;
                            cin >> max_num_std;
                            double hours;
                            cout << "Enter it's credit hours" << endl;
                            cin >> hours;
                            string instructor;
                            cout << "Enter the name of the course's intructor" << endl;
                            cin >> instructor;
                            Course c(name, code, requirement_or_elective, max_num_std, hours, instructor);
                            admin1.add_new_course(c);
                            break;
                        }
                        case 3: {
                            cout << "Enter the name of the course you want to edit" << endl;
                            string coursename;

                            cin >> coursename;
                            Course c;
                            for (auto it = Student::courses.begin(); it != Student::courses.end(); ++it) {
                                if (coursename == it->first) {
                                    c = it->second;
                                    cout << "We found your required course" << endl;
                                }
                            }
                            cout << "Enter the number of prerequisites you want to add to " << c.name << endl;
                            int num;
                            cin >> num;
                            cout << "Enter the prerequisites' names" << endl;
                            for (int i = 0; i < num; i++)
                            {
                                string name;
                                cin >> name;
                                admin1.Enter_course_prerequisite(c, name);

                            }
                            break;

                        }
                        case 4: {
                            cout << "Enter the course's name to view the list of all currently enrolled in it" << endl;
                            string name;
                            cin >> name;
                            Course c;
                            for (auto it = Student::courses.begin(); it != Student::courses.end(); ++it) {
                                if (name == it->first) {
                                    c = it->second;
                                    cout << "it is found" << endl;
                                }

                            }
                            admin1.View_List_of_all_students_in_a_specific_course(c);
                            cout << "Enter any number to end the process " << endl;
                            int id;
                            cin >> id;
                            break;
                        }
                        case 5: {
                            cout << "Enter student id " << endl;
                            int id;
                            cin >> id;
                            Student s;
                            for (auto it = Student::students.begin(); it != Student::students.end(); ++it) {
                                if (id == it->first) {
                                    s = it->second;
                                    cout << "" << endl;
                                }
                            }
                            admin1.addcoursegrade(s);
                            break;
                        }
                        case 6: {
                            cout << "enter student id " << endl;
                            int id;
                            cin >> id;
                            Student s;
                            for (auto it = Student::students.begin(); it != Student::students.end(); ++it) {
                                if (id == it->first) {
                                    s = it->second;
                                    cout << "it is found" << endl;
                                }
                            }
                            admin1.viewListOfStudCourses(s);
                            int v;
                            cout << "press any number" << endl;
                            cin >> v;
                            break;
                        }
                        case 7: {
                            cout << "enter name of course to edit" << endl;
                            string name;
                            cin >> name;
                            Course c;
                            for (auto it = Student::courses.begin(); it != Student::courses.end(); ++it) {
                                if (name == it->first) {
                                    c = it->second;
                                    cout << "it is found" << endl;
                                }
                            }
                            admin1.editCourseData(c);
                            break;
                        }
                        case 8: {
                            flag = false;
                            break;
                        }
                        default: { cout << "Invalid input, Please try again" << endl;
                            break; }
                        }
                        
                     
                    }
                    
                }
                else {
                    int nextdecision;
                    cin >> nextdecision;
                    if (nextdecision == 1) {
                        continue;
                    }
                    else if (nextdecision == 2) {
                        break;

                    }
                }
            }
            cout << "1- back " << endl;
            cout << "2- exit" << endl;
            int testcho;
            cin >> testcho;
            if (testcho == 1) {
                continue;
            }
            else if (testcho == 2)
            {
                break;
            }
        }
        //---------------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------------
        else if (choice == 1) {
            while (true)
            {
                string email;
                cout << "enter your email " << endl;
                cin >> email;
                int id;
                cout << "enter your id " << endl;
                cin >> id;
                string password;
                cout << " enter your password " << endl;
                cin >> password;
                if (s.login(email, id, password) == true) {
                    bool flag = true;
                    while (flag)
                    {
                        int choice;
                        system("cls");
                        cout << "1- View List of all available courses" << endl;
                        cout << "2- Filter courses" << endl;
                        cout << "3- View details of a specific course." << endl;
                        cout << "4- Register for a course." << endl;
                        cout << "5- View all his/her courses." << endl;
                        cout << "6- View his/her courses grades and cumulative GPA" << endl;
                        cout << "7- Edit his/her data." << endl;
                        cout << "8- to exit." << endl;
                        cin >> choice;
                        switch (choice)
                        {
                        case 1: {
                            s.View_List_of_all_available_courses(Student::students[id]);
                            cout << "sd";
                            int ifd;
                            cin >> ifd;
                            break;
                        }
                        case 2: {
                            s.filter_courses(Student::students[id]);
                            break;
                        }
                        case 3: {
                            cout << " enter name of course " << endl;
                            string namecourse;
                            cin >> namecourse;
                            Course c;
                            for (auto it = Student::courses.begin(); it != Student::courses.end(); ++it) {
                                if (namecourse == it->first) {
                                    c = it->second;
                                }
                            }
                            s.viewDetailsOfSpecificCourse(c);
                            cout << "press any number to back " << endl;
                            int n;
                            cin >> n;
                            break;
                        }
                        case 4: {
                            cout << "Enter the course's name that you want to register for " << endl;
                            string coursename;
                            cin >> coursename;
                            Course c;
                            for (auto it = Student::courses.begin(); it != Student::courses.end(); ++it) {
                                if (coursename == it->first) {
                                    c = it->second;
                                    cout << "Registration completed! " << endl;
                                }
                            }
                            s.registerCourse(Student::students[id], c);
                            cout << "Enter a number to break " << endl;
                            int n;
                            cin >> n;
                            break;
                        }
                        case 5: {
                            s.viewAllCourses(Student::students[id]);
                            cout << "Enter a number to break " << endl;
                            int n;
                            cin >> n;
                            break;
                        }
                        case 6: {
                            s.print_finished_course_grades(Student::students[id]);
                            s.get_cumulative_gpa(Student::students[id]);
                            int e;
                            cin >> e;
                            break;
                        }
                        case 7: {
                            s.edit_data(Student::students[id]);
                            int n;
                            cin >> n;
                            break;

                        }
                        case 8: {
                            flag = false;
                            break;
                        }
                        default: {
                            cout << "Invalid input, please try again " << endl;
                            break;
                        }

                            
                        }

                       
                       
                        
                        
                    }
                    break;
                }
                else {
                    int out_or_try_again;
                    cin >> out_or_try_again;
                    if (out_or_try_again == 1) {
                        continue;
                    }
                    else if (out_or_try_again == 2) {
                        break;

                    }
                }
            }
                cout << "1- Back " << endl;
                cout << "2- Exit" << endl;
                int testcho;
                cin >> testcho;
                if (testcho == 1) {
                    continue;
                }
                else if (testcho == 2)
                {
                    break;
                }
            }
        }
        f.save_course_data_into_files();
        f.save_std_data_into_files();
        return 0;
        
 }


