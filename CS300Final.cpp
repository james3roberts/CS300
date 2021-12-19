#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>  

using namespace std;
// Class to read the csv file
// information found on thispointer.com
class csvReader
{
    std::string fileName;
    std::string delimeter;

public:
    csvReader(std::string filename, std::string delm = ",") : fileName(filename), delimeter(delm)
    {
    }
    // Function to fetch data from csv file
    std::vector<std::vector<std::string>> getData();
};
// parse the csv file
std::vector<std::vector<std::string>> csvReader::getData()
{
    std::ifstream file(fileName);
    std::vector<std::vector<std::string>> dataList;
    std::string line = "";
    // iterate each line and split content using delimeter
    while (getline(file, line))
    {
        std::vector<std::string> vec;

        dataList.push_back(vec);
    }
    // close the file
    file.close();
    return dataList;
}

// build the welcome menu
// going to use flag as the variable to act as the boolean
// variable to produce true or false
int main()
{
    cout << "Welcome to the course Planner" << endl;
    while (true)
    {
        int flag;
        string flag2;
        flag = 0;
        cout << "1. Load DataStructure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit." << endl;
        cout << "What would you like to do?" << endl;
        cin >> flag;
        // Set up the exit
        if (flag == 9)
        {
            cout << "Thank you for using the course planner!" << endl;
            break;
        }
        // I could not remember how to do all the not active numbers in one shot
        else if (flag == 4)
        {
            cout << flag << " is not a valid option!" << endl;
        }
        else if (flag == 5)
        {
            cout << flag << " is not a valid option!" << endl;
        }
        else if (flag == 6)
        {
            cout << flag << " is not a valid option!" << endl;
        }
        else if (flag == 7)
        {
            cout << flag << " is not a valid option!" << endl;
        }
        else if (flag == 8)
        {
            cout << flag << " is not a valid option!" << endl;
        }

        else if (flag == 1)
        {
            // Make object
            // Information from thispointer.com
            // It is not reading or not displaying the information form the csv file
            csvReader reader("Parser.csv");
            // get the data from the file
            // This may not be working
            std::vector<std::vector<std::string>> dataList = reader.getData();
            // print contents on screen
            // This is not working.
            for (std::vector<std::string> vec : dataList)
            {
                for (std::string data : vec)
                {
                    std::cout << data << " , ";
                }
                std::cout << std::endl;

                // sort in to alphabetical order
                sort(dataList.begin(), dataList.end());
            }

            return 0;
        }

        else if (flag == 2)
        {
            cout << "Here is a sample schedule: " << endl;
            cout << "CSCI100,Introduction to Computer Science" << endl;
            cout << "CSCI101, Introduction to Programming in C++" << endl;
            cout << "CSCI200, Data Structures" << endl;
            cout << "CSCI301, Advanced Programming in C++" << endl;
            cout << "CSCI300, Introduction to Algorithms" << endl;
            cout << "CSCI350, Operating Systems" << endl;
            cout << "CSCI400, Large Software Development" << endl;
            cout << "MATH201, Discrete Mathematics" << endl;
        }
        else if (flag == 3)
        {
            cout << "What course do you want to know about? " << endl;
            cin >> flag2;
            transform(flag2.begin(), flag2.end(), flag2.begin(), ::tolower);
            if (flag2 == "csci400")
            {
                cout << "CSCI400, Large Software Development. \n Prerequisites: CSIC301,CSCI350" << endl;
            }
            else if (flag2 == "csci350")
            {
                cout << "CSCI350, Operating Systems\n Prerequisites: CSCI300" << endl;
            }
            else if (flag2 == "csci300")
            {
                cout << "CSCI300, Introduction to Algorithms\n Prerequisites: CSCI200, MATH201" << endl;
            }
            else if (flag2 == "csci301")
            {
                cout << "CSCI301, Advanced Programmin in C++\n Prerequisites: CSCI101" << endl;
            }
            else if (flag2 == "csci200")
            {
                cout << "CSCI200, Data Structures\n Prerequisites: CSCI101" << endl;
            }
            else if (flag2 == "csci101")
            {
                cout << "CSCI101, Introduction to Programmin in C++\n Prerequisites: CSCI100" << endl;
            }
            else if (flag2 == "csci100")
            {
                cout << "CSCi100, Introduction to Computer Science\n Prerequisites: NONE" << endl;
            }
            else if (flag2 == "math201")
            {
                cout << "MATH201, Discrete Mathematics\n Prerequisites: NONE" << endl;
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}