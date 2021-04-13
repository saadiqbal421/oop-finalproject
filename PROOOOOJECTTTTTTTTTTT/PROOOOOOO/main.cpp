
#include"Student.h"
int main()
{
	string  username, rollNo, password, cnic, qualification, fn, ln, firstName, lastName, fatherName, fatherproff, gender, address, feeSubmitted, bloodGroup, contactNo, parentcontact, email;
	int classNo, day = 0, month = 0, year = 0, sizeS = 0, sizeT = 0, choice = 0, opt, exit = 1, salary, tempSize;
	Date d, joiningDate, dateOfBirth;
	doctor  *ptrS, s;
	patient* ptrT, t,*teachers;
	appointment* ptrC, c;
	mainpage();
	system("cls");
B:cout << "\n\n\n";
	cout << "\t\t\t\t\t\n";
	cout << "\t\t\t\t    ---------------------------\n";
	cout << "\t\t\t\t    |Hospital MANAGEMENT SYSTEM|\n";
	cout << "\t\t\t\t    ---------------------------\n\n";
	cout << "\t\t\t\t\t1. Administrator\n\n"
		"\t\t\t\t\t2. Teacher\n\n"
		"\t\t\t\t\t3. Student\n\n"
		"\t\t\t\t\t4. Parent\n\n"
		"\t\t\t\t\t0. Exit\n\n"
		"\t\t\t\t\tChoice:-  ";
	cin >> opt;
	if (opt < 0 || opt>4)
	{
		system("cls");
		cout << "\n\n \t\t\t\tERROR: INVALID CHOICE!!\n";
	  goto B;
	}
	else
	{
		switch (opt)
		{
		case 1:
		{
			loginAdmin();

			int choice;
		A:cout << "\n\n\t\t\t1. Student Fuctionalities\n\n"
			"\t\t\t2. Teacher Functionalities\n\n"
			"\t\t\t3. Add Cousre\n\n"
			"\t\t\t4. View All Courses\n\n"
			"\t\t\t5. Assign Courses\n\n"
			"\t\t\t6. Go Back\n\n"
			"\t\t\tChoice: ";
		cin >> choice;
		if (choice < 1 || choice >6)
		{
			system("cls");
			cout << "\n\n \t\t\t\tERROR: INVALID CHOICE!!\n";
			goto A;
		}
		else
		{
			if (choice == 1)
			{
				system("cls");
				while (exit != 0)
				{

					cout << "\n\n\t\t\t1. Add a Student\n\n"
						"\t\t\t2. Edit Student Details\n\n"
						"\t\t\t3. View All Students\n\n"
						"\t\t\t4. Go Back\n\n"
						"\t\t\t0. To Exit\n\n"
						"\t\t\t Your Choice: ";
					cin >> choice;
					switch (choice)
					{
					case 0:
					{
						exit = 0;
						break;
					}
					case 1:
					{
						system("cls");
						cout << "\n\n\t\t\tHow many Doctors do you want to add? ";
						cin >> sizeS;
						ptrS = new doctor[sizeS]; 
						for (int i = 0; i < sizeS; i++)
						{
							ptrS[i].getData(ptrS, i);
							ptrS[i].rollno(sizeS, i,ptrS);
							//Writing Students Courses In Their Respective Files
							if (ptrS[i].get_classno() > 0 && ptrS[i].get_classno() <= 5)
							{
								ptrS[i].write_StudentCOURSES1_5(i,ptrS);
							}
							if (ptrS[i].get_classno() > 5 && ptrS[i].get_classno() <= 8)
							{
								ptrS[i].write_StudentCOURSES6_8(i,ptrS);
							}
							if (ptrS[i].get_classno() >= 9 && ptrS[i].get_classno() <= 10)
							{
								int major;
								cout << "Enter 1 For Biology As Your Major\nEnter 2 For Computer As Your Major : ";
								cin >> major;
								if (major == 1)
								{
									ptrS[i].write_StudentCOURSES9_10BIO(i,ptrS);
								}
								if (major == 2)
								{
									ptrS[i].write_StudentCOURSES9_10COMP(i,ptrS);
								}
							}
							ptrS[i].storedata(sizeS, i);
						}
						break;
					}
					case 2:
					{
						system("cls");
						int size = 0, i = 0;
						string name, n;
						ifstream fin;
						ofstream fout;
						doctor* ptr;
						size = s.getsize();
						ptr = new doctor[size];
						ptr = ptr->readFile(ptr, size);
						s.editstudent(ptr, size);
						break;
					}
					case 3:
					{
						doctor S;
						S.viewstudents();
						break;
					}
					case 4:
					{
						system("cls");
						goto A;
						break;
					}
					}
				}
			}
			if (choice == 2)
			{
				system("cls");
				while (exit != 0)
				{

				C:cout << "\n\n\t\t\t1. Add a Teacher\n\n"
					"\t\t\t2. Edit Teacher Details\n\n"
					"\t\t\t3. View All Teachers\n\n"
					"\t\t\t4. Go Back\n\n"
					"\t\t\t0. To Exit\n\n"
					"\t\t\t Your Choice: ";
				cin >> choice;
				if (choice < 0 || choice > 4)
				{
					cout << "Incorrect Option!!! :(\n";
					goto C;
				}
				switch (choice)
				{
				case 0:
				{
					exit = 0;
					break;
				}
				case 1:
				{
					system("cls");
					cout << "\n\n\t\t\tHow many patient do you want to add? ";
					cin >> sizeT;
					tempSize = sizeT;
					ptrT = new patient[sizeT];
					for (int i = 0; i < sizeT; i++)
					{
						cout << "Enter First Name :) : ";
						getline(cin, firstName);
						while (firstName == "")
						{
							getline(cin, firstName);
						}
						ptrT[i].set_firstName(firstName);
						cout << "Enter Last Name :) : ";
						getline(cin, lastName);
						while (lastName == "")
						{
							getline(cin, lastName);
						}
						ptrT[i].set_lastName(lastName);
						cout << "Enter Your Email Address :) : ";
						getline(cin, email);
						while (email == "")
						{
							getline(cin, email);
						}
						ptrT[i].set_Email(email);
						cout << "Enter Your Gender :) : ";
						getline(cin, gender);
						while (gender == "")
						{
							getline(cin, gender);
						}
						ptrT[i].set_gender(gender);
						cout << "Enter Your Contact Number :) : ";
						getline(cin, contactNo);
						while (contactNo == "")
						{
							getline(cin, contactNo);
						}
						ptrT[i].set_Contact(contactNo);
						cout << "Enter Your CNIC :) : ";
						getline(cin, cnic);
						while (cnic == "")
						{
							getline(cin, cnic);
						}
						ptrT[i].set_CNIC(cnic);
						cout << "Enter Your Salary :) : ";
						cin >> salary;
						ptrT[i].set_Salary(salary);
						cout << "Enter Your Address :) : ";
						getline(cin, address);
						while (address == "")
						{
							getline(cin, address);
						}
						ptrT[i].set_address(address);
						cout << "Enter Your Qualification like (Computer,Mechanical,Mathematics,Commerce) :) : ";
						getline(cin, qualification);
						while (qualification == "")
						{
							getline(cin, qualification);
						}
						ptrT[i].set_Qualification(qualification);
						cout << "Enter Your Joining Date :)\n";
						cout << "Enter Day :) : ";
						cin >> joiningDate.day;
						cout << "Enter Month :) : ";
						cin >> joiningDate.month;
						cout << "Enter Year :) : ";
						cin >> joiningDate.year;
						ptrT[i].set_Joining_Date(joiningDate.day, joiningDate.month, joiningDate.year);
						cout << "Enter Your Date Of Birth :)\n";
						cout << "Enter Day :) : ";
						cin >> dateOfBirth.day;
						cout << "Enter Month :) : ";
						cin >> dateOfBirth.month;
						cout << "Enter Year :) : ";
						cin >> dateOfBirth.year;
						ptrT[i].set_Date_Of_Birth(dateOfBirth.day, dateOfBirth.month, dateOfBirth.year);
						ptrT[i].storedata(sizeT, ptrT, i);
					}
					break;
				}
				case 2:
				{
					system("cls");
					int size = 0, i = 0;
					string name, n;
					ifstream fin;
					ofstream fout;
					patient* ptr1;
					size = t.getsize();
					ptr1 = new patient[size];
					ptr1 = ptr1->ReadFile(ptr1, size);
					t.editTeacher(ptr1, size);
					break;
				}
				case 3:
				{
					sizeT = t.getting_sizeFromFile();
					ptrT = new patient[sizeT];
					ptrT = ptrT->ReadFile(ptrT, sizeT);
					ptrT->view_Teachers(ptrT, sizeT);
					break;
				}
				case 4:
				{
					system("cls");
					goto A;
					break;
				}
				}
				}
				break;
			}
			if (choice == 3)
			{
				int sizeC;
				system("cls");
				string na;
				cout << "\t\tHow many appointments do you want to add? ";
				cin >> sizeC;
				ptrC = new appointment[sizeC];
				for (int i = 0; i < sizeC; i++)
				{
					cout << "Enter Course Name : ";
					getline(cin, na);
					while (na == "")
					{
						getline(cin, na);
					}
					ptrC[i].set_AppointmentName(na);
					cout << "Enter Course Code : ";
					getline(cin, na);
					while (na == "")
					{
						getline(cin, na);
					}
					ptrC[i].set_Appointmentid(na);
					cout << "Enter appointment id  : ";
					getline(cin, na);
				
					while (na == "")
					{
						getline(cin, na);
					}
					ptrC[i].set_Parentdepartment(na);
					ptrC[i].storeCourse(sizeC, ptrC, i);
				}
				goto A;
			}
			if (choice == 4)
			{
				int size = 0;
				appointment temp;
				size = temp.courseSize();
				appointment* ptrC = new appointment[size];
				ptrC->view_Courses(ptrC, size);
				goto A;
			}
			if (choice == 5)
			{
				int teacherNo, courseNo;
				sizeT = t.getting_sizeFromFile();
				ptrT = new patient[sizeT];
				cout << "Teacher's List \n";
				ptrT = ptrT->ReadFile(ptrT, sizeT);
				cout << "Number\tName\t\tQualification\n";
				for (int i = 0; i < sizeT; i++)
				{
					cout << i + 1 << "\t" << ptrT[i].get_firstName() << " " << ptrT[i].get_lastName() << "\t" << ptrT[i].get_Qualification() << endl;
				}
				//ptrT->view_Teachers(ptrT, sizeT);
				//============
				ifstream fin;
				ofstream fout;
				patient* teachers = new patient[sizeT];
				string temp;
				fin.open("Teacher_Course.txt");
				if (!fin)
				{
					cout << "File not Opened !!!\n";
				}
				//Reading All Data From The File And Storing It In Course Pointer(Course* ptr)
				else
				{
					int j = 0;
					int csize = 0;
					for (int i = 0; i < sizeT; i++)
					{
						teachers[i].read(fin);
					}
				}
				fin.close();
				//============
				cout << "Select Teacher Number From The Above List :) : ";
				cin >> teacherNo;
				teachers[teacherNo - 1].set_firstName(ptrT[teacherNo - 1].get_firstName());
				teachers[teacherNo - 1].set_lastName(ptrT[teacherNo - 1].get_lastName());
				cout << "Available Courses :-)\n";
				int size = 0;
				appointment tempp;
				size = tempp.courseSize();
				appointment* ptrC = new appointment[size];
				ptrC->view_Courses(ptrC, size);
				cout << "Select Course From Above List Of Courses :-)\n";
				cin >> courseNo;
				string tempCourse = "";
				appointment* ptrTemp;
				ptrTemp = new appointment[size];
				ptrTemp = ptrTemp->CourseTxt(ptrTemp, size);
				tempCourse = ptrTemp[courseNo - 1].get_AppointmentName();
				teachers[teacherNo - 1].assigncourse(tempCourse);
				//---------------------------------------
				fout.open("Teacher_Course.txt");
				for (int i = 0; i < sizeT; i++)
				{
					teachers[i].writeData(fout);
				}			
				goto A;
			}
			if (choice == 6)
			{
				system("cls");
				goto B;
			}

		}
		break;
		}
		case 2:
		{
			loginTeacher();
			t:cout << "\n\n\t\t\t\t1. View My Courses\n\n"
				"\t\t\t\t2. Add MARKS\n\n"
				"\t\t\t\t3. Go back\n\n"
				"\t\t\t\tChoice: ";
			cin >> choice;
			if (choice == 1)
			{
				int teacherNo, courseNo;
				sizeT = t.getting_sizeFromFile();
				ptrT = new patient[sizeT];
				cout << "Teacher's List \n";
				ptrT = ptrT->ReadFile(ptrT, sizeT);
				cout << "Number\tName\t\tQualification\n";
				for (int i = 0; i < sizeT; i++)
				{
					cout << i + 1 << "\t" << ptrT[i].get_firstName() << " " << ptrT[i].get_lastName() << "\t" << ptrT[i].get_Qualification() << endl;
				}
				cout << "Select Teacher Number From The Above List :) : ";
				cin >> teacherNo;
				//Reading TEACHER_COURSE FILES
				ifstream fin;
				ofstream fout;
				patient* teachers = new patient[sizeT];
				string temp;
				fin.open("Teacher_Course.txt");
				if (!fin)
				{
					cout << "File not Opened !!!\n";
				}
				//Reading All Data From The File And Storing It In Course Pointer(Course* ptr)
				else
				{
					int j = 0;
					int csize = 0;
					for (int i = 0; i < sizeT; i++)
					{
						teachers[i].read(fin);
					}
				}
				teachers[teacherNo - 1].getCoursecount();
				cout << "Teacher Name\tCourse\n";
				cout << teachers[teacherNo - 1].get_firstName() << " " << teachers[teacherNo - 1].get_lastName() << endl;
				teachers[teacherNo - 1].Get_Courses(teachers[teacherNo - 1].getCoursecount());
				fin.close();

				goto t;
			}
			if (choice == 2)
			{
				goto t;
			}
			//cout << "Module Under Development\n";
			goto B;
			break;
		}
		case 3:
		{
			int choice;
			loginStudent();
		m:cout << "\n\n\t\t\t\t1. View Assessment Marks\n\n"
			"\t\t\t\t2. View Fee Status\n\n"
			"\t\t\t\t3. Go back\n\n"
			"\t\t\t\tChoice: ";
		cin >> choice;
		if (choice == 1)
		{
			goto m;
		}
		if (choice == 2)
		{
			s.viewFeeStatus();
			goto m;
		}
		if (choice == 3)
		{
			system("cls");
			goto B;
		}
		break;
		}
		case 4:
		{
			cout << "Module Under Development\n";
			goto B;
			break;
		}
		}
	}
	system("pause");
	return 0;
}