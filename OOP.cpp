#include <iostream>
using std::string;

/** 
 * @brief An Abstract Class, contains a Virtual Function (obligatory to use)
 * Whoever needs to use "class Employee" needs to sign "AskForPromotion" too
 */
class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};


/**
 * @brief Each time i need to add an Employee i use this class (this model/blueprint)
 * User defined type
 */

class Hello
{

};
class Employee: AbstractEmployee
{
private:
    // Encpsulated
    string Company;
    int Age;
protected:
    // Derived classes have access to the name, not only using getters and setters.
    string Name;
public:
    // Encapsulation: Setters & Getters
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }
    void setAge(int age)
    {
        //validation rule
        if (age >= 18)
        {
            Age = age;
        }
        else
        {
            std::cout << "Only 18 and above!";
        }
        
    }
    int getAge()
    {
        return Age;
    }

    // Function of type void
    void IntroduceYouself()
    {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    // Constructor needs to be (1.Same name as the class) (2.No return type) (3.public) till now
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    void AskForPromotion()
    {
        if (Age > 30)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << " sorry no promotion!" << std::endl;
    }

    // Thid virtual method will check if there is an ovveride method implemented in the derived classes, if yes they will be implemtned directly
    virtual void Work()
    {
        std::cout << Name << " is checking email, task backlog, performing tasks... " << std::endl;
    }

};

class Developer:public Employee // we putted public to be able to access properties in the main class
{
private:
    string FavProgLang;
public:
    void setFavProgLang(string favproglang)
    {
        FavProgLang = favproglang;
    }
    string getFavProgLan()
    {
        return FavProgLang;
    }

    // Constructor for Developer class. Since developer inherited from employee class, for the constructor we put (:Employee(...)) because Employee will take care of those 3 vars.
    Developer(string name, string company, int age, string favproglang) 
        : Employee(name, company, age)
    {
        FavProgLang = favproglang;
    }

    void FixBug()
    {
        std::cout << Name << " fixed bug using " << FavProgLang << std::endl;
    }

    void Work()
    {
        std::cout << Name << " is writing " << FavProgLang << " code" << std::endl;
    }
}; 

class Teacher:public Employee
{
public:
    string Subject;
    void PrepareLesson()
    {
       std::cout << Name << " is preparing " << Subject << " lesson" << std::endl; 
    }

    // Constructor
    Teacher(string name, string company, int age,string subject) 
        : Employee(name, company, age)
    {
        Subject = subject;
    }

    void Work()
    {
        std::cout << Name << " is teaching " << Subject << std::endl;
    }
};


int main()
{
    /** 1
     * @DefaultConstructor
     * If we did not specify any values and NO CONSTRUCTOR WAS CREATED a default constructor will be created automatically to fill the values inside the function that we created
     */
    //Employee employee00 = Employee("Anis", "TriWare", 20);
    // employee00.Name = "Anis";
    // employee00.Company = "TriWare";
    // employee00.Age = 20;
    //employee00.IntroduceYouself();



    /** 2
     * @DefaultConstructor
     * If we did not specify any values and NO CONSTRUCTOR WAS CREATED a default constructor will be created automatically to fill the values inside the function that we created
     */
    //Employee employee01 = Employee("John", "Youtube", 31);
    // employee01.Name = "John";
    // employee01.Company = "Youtube";
    // employee01.Age = 30;
    //employee01.IntroduceYouself();

    //employee00.setAge(10);

    //employee00.AskForPromotion();
    //employee01.AskForPromotion();

    Developer dev00 = Developer("Anis", "TriWare", 55, "C++");
    //dev00.FixBug();
    //dev00.AskForPromotion();
    //dev00.Work();

    Teacher teach00 = Teacher("Josh", "TheSchool", 42, "Chemistry");
    //teach00.PrepareLesson();
    //teach00.AskForPromotion();
    //teach00.Work();

    Employee* e1 = &dev00;
    Employee* e2 = &teach00;

    e1->Work();
    e2->Work();
}