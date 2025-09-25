#include <string>
#include <iostream>
#include <array>
#include <vector>

struct Student{
	std::string name;
	int student_id;
	std::array<float, 3> grades{};
	float average;

	void calculate_average() {
		average = (grades[0] + grades[1] + grades[2]) / 3;
	}
};

struct Class{
	std::vector<Student> students;
	void add_student(){
		Student new_student;
		std::cout << "Enter name \n";
		std::cin >> new_student.name;
		std::cout << "Enter ID \n";
		std::cin >> new_student.student_id;
		std::cout << "Enter grade 1 \n";
		std::cin >> new_student.grades[0];
		std::cout << "Enter grade 2 \n";
		std::cin >> new_student.grades[1];
		std::cout << "Enter grade 3 \n";
		std::cin >> new_student.grades[2];

		new_student.calculate_average();

		students.push_back(new_student);
	}

	void print_students() {
		for (int i = 0; i < students.size(); ++i) {
			std::cout << "Name: " << students[i].name << " Average grade: " << students[i].average << "\n";
		}
	}
};

int main(){
	Class classroom;
	classroom.add_student();
	classroom.add_student();
	classroom.print_students();

}