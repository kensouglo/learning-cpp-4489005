// Learning C++ 
// Challenge 06_03
// Upgrade to work with files, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"
#include <fstream>

void initialize(StudentRecords&);

int main(){
    int id;
    StudentRecords SR;
    
    initialize(SR);

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    SR.report_card(id);
    
    std::cout << std::endl << std::endl;
    return (0);
}

void initialize(StudentRecords& srec){

    std::ifstream inFile_students;
    inFile_students.open("students.txt");
    std::string stdents;
    std::string stdent_name_stdents;
    int stdent_id_stdents;

    if (inFile_students.fail())
        std::cout << std::endl << "File not found!" << std::endl;
    else{
        while (!inFile_students.eof()){
            getline(inFile_students, stdents);
            stdent_id_stdents = stoi(stdents);
            getline(inFile_students, stdents);
            stdent_name_stdents = stdents;
            srec.add_student(stdent_id_stdents, stdent_name_stdents);                                       
        }
        inFile_students.close();
    }        

    std::ifstream inFile_courses;
    inFile_courses.open("courses.txt");
    std::string crses;
    std::string crse_name_crses;
    int crse_id_crses;
    float crse_cred_crses;

    if (inFile_courses.fail())
        std::cout << std::endl << "File not found!" << std::endl;
    else{
        while (!inFile_courses.eof()){
            getline(inFile_courses, crses);
            crse_id_crses = stoi(crses);
            getline(inFile_courses, crses);
            crse_name_crses = crses;
            getline(inFile_courses, crses);
            crse_cred_crses = stof(crses);            
            srec.add_course(crse_id_crses, crse_name_crses,crse_cred_crses);                                       
        }
        inFile_courses.close();
    }  

    std::ifstream inFile_grades;
    inFile_grades.open("grades.txt");
    std::string grdes;
    int stdent_id_grdes;
    int crse_id_grdes;
    char grde_grades;

    if (inFile_grades.fail())
        std::cout << std::endl << "File not found!" << std::endl;
    else{
        while (!inFile_grades.eof()){
            getline(inFile_grades, grdes);
            stdent_id_grdes = stoi(grdes);
            getline(inFile_grades, grdes);
            crse_id_grdes = stoi(grdes);
            getline(inFile_grades, grdes);
            grde_grades = grdes[0];            
            srec.add_grade(stdent_id_grdes, crse_id_grdes,grde_grades);                                       
        }
        inFile_grades.close();
    } 
}
