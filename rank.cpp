#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Subject {
    std::string name;
    int marks;
};

struct Student {
    std::string name;
    std::vector<Subject> subjects;
    int totalMarks;
};

struct Class {
    std::string stream;
    int classNumber;
    std::vector<Student> students;
};

// Function to calculate the total marks of a student
void calculateTotalMarks(Student& student) {
    student.totalMarks = 0;
    for (const auto& subject : student.subjects) {
        student.totalMarks += subject.marks;
    }
}

// Function to compare students based on total marks for sorting
bool compareStudents(const Student& a, const Student& b) {
    return a.totalMarks > b.totalMarks;
}

int main() {
    // Create classes for Bio and Math streams
    Class bioClass{"Bioscience", 1, {}};
    Class mathClass{"Mathematics", 1, {}};

    // Read student data from a file or initialize it as needed
    // ...

    // Calculate total marks for each student
    for (auto& student : bioClass.students) {
        calculateTotalMarks(student);
    }

    for (auto& student : mathClass.students) {
        calculateTotalMarks(student);
    }

    // Sort students based on total marks
    std::sort(bioClass.students.begin(), bioClass.students.end(), compareStudents);
    std::sort(mathClass.students.begin(), mathClass.students.end(), compareStudents);

    // Display and write results to a file
    std::ofstream outputFile("rank_results.txt");
    if (outputFile.is_open()) {
        outputFile << "School Rank:\n";

        // Display and write Bio stream results
        outputFile << "\nBioscience Stream:\n";
        for (size_t i = 0; i < bioClass.students.size(); ++i) {
            outputFile << "Rank " << i + 1 << ": " << bioClass.students[i].name << " (Total Marks: " << bioClass.students[i].totalMarks << ")\n";
        }

        // Display and write Math stream results
        outputFile << "\nMathematics Stream:\n";
        for (size_t i = 0; i < mathClass.students.size(); ++i) {
            outputFile << "Rank " << i + 1 << ": " << mathClass.students[i].name << " (Total Marks: " << mathClass.students[i].totalMarks << ")\n";
        }

        outputFile.close();
    } else {
        std::cerr << "Error: Unable to open the output file." << std::endl;
        return 1;
    }

    std::cout << "Results written to rank_results.txt" << std::endl;

    return 0;
}